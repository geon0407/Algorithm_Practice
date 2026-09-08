"""Build a deterministic index from local BaekjoonHub files; no network calls."""
import re
from pathlib import Path
from urllib.parse import quote
from collections import Counter

START = '<!-- AUTO-STATS:START -->'
END = '<!-- AUTO-STATS:END -->'
LANG = {'.cpp': 'C++', '.cc': 'C++', '.c': 'C', '.py': 'Python', '.java': 'Java', '.js': 'JavaScript', '.ts': 'TypeScript', '.sql': 'SQL', '.cs': 'C#', '.go': 'Go', '.rs': 'Rust', '.swift': 'Swift', '.kt': 'Kotlin', '.rb': 'Ruby'}
PLATFORMS = {'Programmers': 'Programmers', '프로그래머스': 'Programmers', 'SWEA': 'SWEA', '백준': 'BOJ', 'BOJ': 'BOJ'}

def label(text):
    return re.sub(r'\s+', ' ', text).strip().replace('|', '&#124;').replace('<', '&lt;').replace('>', '&gt;').replace('[', '&#91;').replace(']', '&#93;')

def link(path, root):
    return quote(path.relative_to(root).as_posix(), safe='/')

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

def render(root):
    records = collect(root)
    lines = ['## 풀이 현황', '', f'**총 {len(records)}문제** · 저장된 정답 코드 기준, 동일 플랫폼의 문제 번호 중복 제외', '', '| 플랫폼 | 난이도 | 문제 수 |', '| --- | --- | ---: |']
    counts = Counter((r['platform'], r['level']) for r in records)
    for platform, level in dict.fromkeys((r['platform'], r['level']) for r in records):
        display = f'Lv. {level}' if platform == 'Programmers' else level
        lines.append(f'| {platform} | {label(display)} | {counts[platform, level]} |')
    for platform in dict.fromkeys(r['platform'] for r in records):
        subset = [r for r in records if r['platform'] == platform]
        lines += ['', f'## {platform} · {len(subset)}문제', '', '| 난이도 | 번호 | 문제 | 코드 | 해설 |', '| --- | ---: | --- | --- | --- |']
        for r in subset:
            level = f"Lv. {r['level']}" if platform == 'Programmers' else r['level']
            codes = ' · '.join(f'[{LANG[p.suffix.lower()]}]({link(p, root)})' for p in r['sources'])
            notes = ' · '.join(f'[해설]({link(p, root)})' for p in r['notes']) or '—'
            parent = r['sources'][0].parent
            lines.append(f"| {label(level)} | {r['number']} | [{r['title']}]({link(parent, root)}/) | {codes} | {notes} |")
    return '\n'.join(lines)

def update(root):
    path = root / 'README.md'
    original = path.read_text(encoding='utf-8') if path.exists() else '# Algorithm_Practice\n'
    if original.count(START) != original.count(END) or original.count(START) > 1:
        raise ValueError('README 자동 생성 영역 마커가 손상되었습니다.')
    block = START + '\n' + render(root) + '\n' + END
    if START in original:
        before, remainder = original.split(START)
        old, after = remainder.split(END)
        result = before + block + after
    else:
        result = original.rstrip() + '\n\n' + block + '\n'
    if result != original:
        path.write_text(result, encoding='utf-8')
    return len(collect(root))

if __name__ == '__main__':
    print(f'Indexed {update(Path(__file__).resolve().parents[1])} problems.')
