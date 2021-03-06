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
