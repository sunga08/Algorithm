#include <iostream>
#include <queue>

using namespace std;
int n, m;
int map[101][101];
bool visited[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny]==1 && !visited[nx][ny]) {
                q.push({ nx,ny });
                map[nx][ny] = map[cur.first][cur.second] + 1;
                visited[nx][ny] = true;
                //if(nx==n-1 && ny==m-1) return;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    bfs(0,0);

    printf("%d", map[n-1][m-1]);


    return 0;
}
