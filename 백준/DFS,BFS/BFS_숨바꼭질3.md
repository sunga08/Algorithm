## 접근 방법
큐를 사용하는 BFS는 **가중치가 1**일 때만 **최단거리**를 구할 수 있다. </br>

- 갈 수 있는 곳을 탐색하면서 거리가 0, 1, 2 ... 인 것을 차례로 큐에 저장하는데, </br>
가중치가 0 또는 1이면 이렇게 거리 순서로 저장되지 않기 때문에 큐를 사용해서 최단 거리를 구할 수 없다.

따라서, **Queue를 2개 사용**하거나 **Deque**를 사용해 구현해야 한다.

## 소스코드
### 1) queue 2개 사용하는 방법

- 큐를 거리에 따라 분리: ``현재 큐``와 ``다음 큐``
  - +0초 방법이면 현재 큐에, +1초 방법이면 다음 큐에 저장
  - 현재 큐에서 방문할 수 있는 곳을 모두 방문 👉 다음 큐를 현재 큐로 바꾸고 새로운 다음 큐 생성
```c++
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000000;
int location[MAX];
bool visited[MAX];

int main()
{
    int n, k;
    cin >> n >> k;

    queue<int> q;
    queue<int> next_q;
    q.push(n);
    location[n] = 0;
    visited[n] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur * 2 < MAX && !visited[cur * 2]) { // cur-1, cur+1 보다 먼저 수행되어야 함
             q.push(cur * 2);
             visited[cur * 2]=true;
             location[cur * 2] = location[cur];
           
        }
        if (cur - 1 >= 0 && !visited[cur-1]) {
            next_q.push(cur - 1);
            visited[cur - 1] = true;
            location[cur - 1] = location[cur] + 1;
           
        }

        if (cur + 1 < MAX && !visited[cur + 1]) {
             next_q.push(cur + 1);
             visited[cur + 1]=true;
             location[cur + 1] = location[cur] + 1;          
        }


        if (q.empty()) {
            q = next_q;
            next_q = queue<int>();
        }
    }

    printf("%d\n", location[k]);

    return 0;
}
```

### 2) Deque를 사용하는 방법

- 큐를 2개 사용하는 대신, 현재 큐에 넣는 것(=가중치 0)을 Deque의 앞에, 다음 큐에 넣는 것(=가중치 1)을 Deque의 뒤에 넣어준다.

```c++
#include <iostream>
#include <deque>

using namespace std;

const int MAX = 1000000;
int location[MAX];
bool visited[MAX];

int main()
{
    int n, k;
    cin >> n >> k;

    dequeue<int> q;
    q.push_back(n);
    location[n] = 0;
    visited[n] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur * 2 < MAX && !visited[cur * 2]) { // cur-1, cur+1 보다 먼저 수행되어야 함
             q.push_front(cur * 2);
             visited[cur * 2]=true;
             location[cur * 2] = location[cur];
           
        }
        if (cur - 1 >= 0 && !visited[cur-1]) {
            q.push_back(cur - 1);
            visited[cur - 1] = true;
            location[cur - 1] = location[cur] + 1;
           
        }

        if (cur + 1 < MAX && !visited[cur + 1]) {
             q.push_back(cur + 1);
             visited[cur + 1]=true;
             location[cur + 1] = location[cur] + 1;          
        }

    }

    printf("%d\n", location[k]);

    return 0;
}
```
