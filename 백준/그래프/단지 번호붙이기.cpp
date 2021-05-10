#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int map[26][26];
int visited[26][26];
vector<int> houseCnt;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 1;
int house = 0;
void dfs(int x, int y) {
    visited[x][y] = true;
    map[x][y] = cnt;
    house++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny]==false && map[nx][ny]==1 && nx >= 0 && nx < n && ny >= 0 && ny < n) {
            dfs(nx, ny);
        }
    }
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && visited[i][j]==false) {
                cnt++;
                house = 0;
                dfs(i, j);
                houseCnt.push_back(house);
            }
        }
    }

    sort(houseCnt.begin(), houseCnt.end());

    printf("%d\n", cnt - 1);
    for (int i = 0; i < houseCnt.size(); i++) {
        printf("%d\n", houseCnt[i]);
    }

    return 0;
}
