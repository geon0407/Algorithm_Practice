"""Build a deterministic index from local BaekjoonHub files; no network calls."""
import re
from pathlib import Path
from urllib.parse import quote
import os

START = '<!-- AUTO-STATS:START -->'
END = '<!-- AUTO-STATS:END -->'
LANG = {'.cpp': 'C++', '.cc': 'C++', '.c': 'C', '.py': 'Python', '.java': 'Java', '.js': 'JavaScript', '.ts': 'TypeScript', '.sql': 'SQL', '.cs': 'C#', '.go': 'Go', '.rs': 'Rust', '.swift': 'Swift', '.kt': 'Kotlin', '.rb': 'Ruby'}
PLATFORMS = {'Programmers': 'Programmers', '프로그래머스': 'Programmers', 'SWEA': 'SWEA', '백준': 'BOJ', 'BOJ': 'BOJ'}

def label(text):
    return re.sub(r'\s+', ' ', text).strip().replace('|', '&#124;').replace('<', '&lt;').replace('>', '&gt;').replace('[', '&#91;').replace(']', '&#93;')

def link(path, root):
    return quote(Path(os.path.relpath(path, root)).as_posix(), safe='/')

def collect(root):
    records = {}
    for folder in sorted(root.iterdir()):
        if folder.name not in PLATFORMS or not folder.is_dir():
            continue
        platform = PLATFORMS[folder.name]
        for difficulty in sorted(folder.iterdir()):
            if not difficulty.is_dir():
                continue
            for problem in sorted(difficulty.iterdir()):
                match = re.match(r'^(\d+)\.(.+)$', problem.name)
                if not problem.is_dir() or not match:
                    continue
                sources = sorted(p for p in problem.iterdir() if p.is_file() and p.suffix.lower() in LANG)
                if not sources:
                    continue
                number, title = match.groups()
                key = (platform, number)
                record = records.setdefault(key, dict(platform=platform, number=number, title=label(title), level=difficulty.name, sources=[], notes=[]))
                record['sources'].extend(sources)
                notes = problem / 'NOTES.md'
                if notes.is_file():
                    record['notes'].append(notes)
    return sorted(records.values(), key=lambda r: (r['platform'], int(re.search(r'\d+', r['level']).group()) if re.search(r'\d+', r['level']) else 999, r['level'], int(r['number'])))

def difficulty_key(name):
    tiers = {'Unrated': 0, 'Bronze': 1, 'Silver': 2, 'Gold': 3, 'Platinum': 4, 'Diamond': 5, 'Ruby': 6}
    if name in tiers:
        return (tiers[name], name)
    match = re.search(r'\d+', name)
    return (int(match.group()) if match else 999, name)


def level_name(platform, level):
    return f'Lv. {level}' if platform == 'Programmers' else level


def write_section(path, content, title):
    original = path.read_text(encoding='utf-8') if path.exists() else title + '\n'
    if (original.count(START) != original.count(END) or original.count(START) > 1
            or (START in original and original.index(START) > original.index(END))):
        raise ValueError(f'자동 생성 영역 마커를 확인하세요: {path}')
    block = START + '\n' + content + '\n' + END
    if START in original:
        before, rest = original.split(START)
        _, after = rest.split(END)
        result = before + block + after
    else:
        result = original.rstrip() + '\n\n' + block + '\n'
    if result != original:
        path.write_text(result, encoding='utf-8')


def update(root):
    root = root.resolve()
    records = collect(root)
    summary = ['## 풀이 현황', '', f'**총 {len(records)}문제** · 동일 플랫폼의 문제 번호 중복 제외', '',
               '| 플랫폼 | 문제 수 | 목록 |', '| --- | ---: | --- |']
    level_rows = ['', '### 난이도별 바로가기', '', '| 플랫폼 | 난이도 | 문제 수 |', '| --- | --- | ---: |']
    for folder in sorted(root.iterdir()):
        if folder.name not in PLATFORMS or not folder.is_dir():
            continue
        platform = PLATFORMS[folder.name]
        # A duplicate ID belongs to the folder containing its first indexed source.
        subset = [r for r in records if r['sources'][0].parent.parent.parent == folder]
        summary.append(f'| {platform} | {len(subset)} | [난이도 목록]({link(folder / "README.md", root)}) |')
        overview = [f'[← 전체 현황]({link(root / "README.md", folder)})', '', f'**{len(subset)}문제**', '',
                    '| 난이도 | 문제 수 |', '| --- | ---: |']
        difficulties = sorted((d for d in folder.iterdir() if d.is_dir()),
                              key=lambda d: difficulty_key(d.name))
        for difficulty in difficulties:
            items = [r for r in subset if r['level'] == difficulty.name]
            # Refresh an existing generated page after its last solution is removed.
            existing = difficulty / 'README.md'
            managed = existing.exists() and START in existing.read_text(encoding='utf-8')
            if not items and not managed:
                continue
            display = label(level_name(platform, difficulty.name))
            overview.append(f'| [{display}]({link(existing, folder)}) | {len(items)} |')
            level_rows.append(f'| {platform} | [{display}]({link(existing, root)}) | {len(items)} |')
            table = [f'[← {platform} 목록]({link(folder / "README.md", difficulty)}) · [전체 현황]({link(root / "README.md", difficulty)})', '',
                     f'**{len(items)}문제**', '', '| 번호 | 문제 | 코드 | 해설 |', '| ---: | --- | --- | --- |']
            for r in items:
                codes = ' · '.join(f'[{LANG[p.suffix.lower()]}]({link(p, difficulty)})' for p in r['sources'])
                notes = ' · '.join(f'[해설]({link(p, difficulty)})' for p in r['notes']) or '—'
                parent = r['sources'][0].parent
                table.append(f"| {r['number']} | [{r['title']}]({link(parent, difficulty)}/) | {codes} | {notes} |")
            write_section(existing, '\n'.join(table), f'# {platform} · {display}')
        write_section(folder / 'README.md', '\n'.join(overview), f'# {platform}')
    write_section(root / 'README.md', '\n'.join(summary + level_rows), '# Algorithm_Practice')
    return len(records)


if __name__ == '__main__':
    print(f'Indexed {update(Path(__file__).resolve().parents[1])} problems.')
