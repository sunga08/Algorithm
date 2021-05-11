## 소스코드

```c++
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
const int MAX = 200000; //10
int visited[MAX];
int dist[MAX];
int from[MAX];

void print(int n, int m) {
    if (n != m) {
        print(n, from[m]);
    }
    cout << m << " ";
}

void print2(int n, int m) {
    stack<int> ans;
    for (int i = m; i != n; i = from[i]) {
        ans.push(i);
    }
    ans.push(n);

    while (!ans.empty()) {
        int tmp = ans.top();
        cout << tmp<<" ";
        ans.pop();
    }
}

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

        if (cur + 1 < MAX && !visited[cur + 1]) { //x+1
            visited[cur + 1] = true;
            q.push(cur + 1);
            dist[cur + 1] = dist[cur] + 1;
            from[cur + 1] = cur;
        }

        if (cur - 1 >= 0 && !visited[cur - 1]) { //x-1
            visited[cur - 1] = true;
            q.push(cur - 1);
            dist[cur - 1] = dist[cur] + 1;
            from[cur - 1] = cur;
        }

        if (cur * 2 < MAX && !visited[cur * 2]) { //2X
            visited[cur * 2] = true;
            q.push(cur * 2);
            dist[cur * 2] = dist[cur] + 1;
            from[cur * 2] = cur;
        }
    }

    cout << dist[k] << "\n";
    print2(n, k);

    return 0;
}

```

## 참고
**🔑BFS로 최단거리를 이동하는 방법을 출력하는 문제🔑**

**이동한 곳 저장하기**
- BFS를 수행하면서 어떤 위치가 어디서부터 왔는지를 기록 : ``from[다음 위치] = cur``
- 방문한적이 없는 다음 지점은 cur를 통해서 가야 최단거리이다.
  - ``from[i]`` = i가 어디에서 와서 최단거리를 계산했는가
  - next가 cur에서 온 것이므로 i=next(다음위치)로 정의
  - n -> ? -> ? -> from[m] -> m
 
**<출력 방법1 : 재귀호출> </br>**

``print()``
- print(n,m)은 n에서 m을 가는 방법 출력
- 재귀적으로 줄여나가면 n==from[m]이 되게 되고, n부터 출력하게 된다.

**<출력 방법2 : 스택 사용>**

``print2()``
- i=m부터 스택에 push 👉 i=from[m]으로 바꿔가며 계속해서 push하면 스택에는 n이 top이 되도록 저장됨
- 그대로 pop하면서 출력
