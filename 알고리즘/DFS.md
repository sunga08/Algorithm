## 재귀호출을 사용한 구현
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<vector<int>> graph, vector<bool>& check) {
    check[start] = true; //방문 표시
    printf("%d ", start);

    //한 노드에 연결된 노드들을 하나씩 확인
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        
        //방문하지 않은 노드면 방문하기(dfs 수행)
        if (check[next] == false) {
            dfs(next, graph, check);
        }
    }
}

int main()
{
    int n, m, start; //노드, 간선, 시작점
    scanf("%d %d %d", &n, &m, &start);

    vector<vector<int>> graph(n + 1);
    vector<bool> check(n + 1);

    //그래프 형성
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        //양방향 그래프이므로 (u,v),(v,u) 모두 표시
        graph[u].push_back(v); 
        graph[v].push_back(u);
    }

    //하나의 정점에서 다음을 탐색할 때 노드 값에 순차적으로 접근하기 위하여 정렬
    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start, graph, check);

    return 0;

}
```

## 스택을 사용한 구현
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

void dfs(int start, vector<vector<int>> graph, vector<bool> check) {
    stack<int> s;
    s.push(start);
    check[start] = true;
    printf("%d ", start);

    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (check[next] == false) {
                printf("%d ",next);
                check[next] = true;
                s.push(cur);
                s.push(next);
                break;
            }
        }
    }
}


int main()
{
    int n, m, start;
    cin >> n >> m >> start;
    vector<vector<int>> graph(n + 1);
    vector<bool> check(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start, graph, check);

    return 0;
}
```
