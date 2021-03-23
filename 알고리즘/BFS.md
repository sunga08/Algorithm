## 인접 행렬로 나타낸 그래프 탐색
```c++
#include <iostream>
#include <queue>

using namespace std;
#define X first //행
#define Y second //열
int board[502][502] = {0,}; //1이면 파란칸, 0이면 빨간칸
bool vis[502][502]; //방문 여부 저장
int n = 7, m = 10; //행과 열의 갯수
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0,1,0,-1 };

int main(void) 
{
    queue<pair<int, int>> Q;
    vis[0][0] = 1;
    Q.push(make_pair(0, 0));
    
    while(!Q.empty()) { //큐가 빌 때 까지
        pair<int,int> cur = Q.front(); //큐의 front를 cur에 저장하고 pop
        Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            //좌표가 범위 안에 있는지 확인
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            //vis가 1인 경우(이미 방문) 통과, board가 0일 경우 통과
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            //위 조건이 아닐 경우 방문표시 & 큐에 push
            vis[nx][ny] = 1; 
            Q.push(make_pair(nx, ny));
        }

    }
    return 0;
}
```

## 인접 리스트로 나타낸 그래프 탐색
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>> graph, vector<bool>& check) {
    queue<int> q;

    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        printf("%d ", tmp);
        for (int i = 0; i < graph[tmp].size(); i++) {
            if (check[graph[tmp][i]] == false) {
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true; 
            }
        }
    }
    
}

int main()
{
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);

    vector<vector<int>> graph(n + 1);
    vector<bool> check(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(start, graph, check);

    return 0;
}
```
