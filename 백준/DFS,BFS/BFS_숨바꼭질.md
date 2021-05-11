## 소스코드
X+1, X-1, 2X 방법으로 이동하는 곳이 갈 수 있는 곳인지 확인 => 큐에 넣고 거리 증가
```c++
#include <iostream>
#include <queue>

using namespace std;
const int MAX = 200000; //10
int visited[MAX];
int dist[MAX];
int main()
{
    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == k) break;
        
        if (cur+1<MAX && !visited[cur + 1]) { //x+1
            visited[cur + 1] = true;
            q.push(cur + 1);
            dist[cur + 1] = dist[cur] + 1;
        }

        if (cur-1>=0 && !visited[cur - 1]) { //x-1
            visited[cur - 1] = true;
            q.push(cur - 1);
            dist[cur - 1] = dist[cur] + 1;
        }

        if (cur*2<MAX && !visited[cur * 2]) { //2X
            visited[cur * 2] = true;
            q.push(cur * 2);
            dist[cur * 2] = dist[cur] + 1;
        }
    }

    printf("%d", dist[k]);
    return 0;
}
```
❓ 이전에 다른 방법으로 방문한 적이 있는 지점은 방문 못하는데, 다른 방식으로 그 지점에 방문한 경우가 최소가 될 수도 있는거 아님? </br>

👉 아님. 서로 다른 방식으로 같은 지점에 방문해도 그 지점에서 부터 전개되는 방식은 이전과 똑같게 됨. </br>
그리고 이후에 다른 방식으로 방문한 거리 보다 이전에 방문한 것이 최소가 될 수 밖에 없음. 따라서 방문하지 못하는 것이 맞다.
