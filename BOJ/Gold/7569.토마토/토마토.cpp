#include <stdio.h>
#include <queue>
using namespace std;

const int Flag = 999999999;
struct Point {
    int x, y, z;
};

int width, height, length;
int map[100][100][100];
queue<Point> que;
int cnt;

Point make_Point(int z, int y, int x) {
    Point p;
    p.z = z;
    p.y = y;
    p.x = x;
    return p;
}

int bfs()
{
    Point p;
    int dz[6] = { -1, 1, 0, 0, 0, 0 };
    int dy[6] = { 0, 0, -1, 1, 0, 0 };
    int dx[6] = { 0, -0, 0, 0, -1, 1 };

    while (!que.empty()) {
        p = que.front();
        que.pop();

        for (int i = 0; i < 6; i++) {
            Point next = make_Point(p.z + dz[i], p.y + dy[i], p.x + dx[i]);

            if (next.z >= 0 && next.z < length && next.y >= 0
                    && next.y < height && next.x >= 0 && next.x < width) {
                if (map[next.z][next.y][next.x] == 0) {
                    map[next.z][next.y][next.x] = map[p.z][p.y][p.x] + 1;
                    que.push(next);
                    cnt--;
                }
            }
        }
    }

    if (cnt <= 0)        return map[p.z][p.y][p.x] - Flag - 1;
    return -1;
}

int main()
{
    scanf("%d %d %d", &width, &height, &length);

    for (int z = 0; z < length; z++) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                scanf("%d", &map[z][y][x]);

                if (map[z][y][x] == 1) {
                    que.push(make_Point(z, y, x));
                    map[z][y][x] += Flag;
                }
                else if (map[z][y][x] == 0)    cnt++;
            }
        }
    }

    printf("%d\n", bfs());

    return 0;
}
