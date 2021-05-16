## 재귀호출을 사용한 구현 (그래프)
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
## 2차원 배열에서의 DFS
### 특정 depth까지만 탐색
```c++
#include <iostream>

using namespace std;
int board[10][10];
bool check[10][10];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dfsCnt = 0;
void dfs(int x, int y, int cnt) {
    if (cnt == 4) { //depth=4까지 탐색
        dfsCnt++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!check[nx][ny] && nx>=0 && nx<10 && ny>=0 && ny<10) {
            check[nx][ny] = true;
            dfs(nx, ny, cnt + 1);
            check[nx][ny] = false;
        }
    }
}

int main()
{
    dfs(0,0,1);
    cout << dfsCnt; // (0,0)에서 DFS 수행하여 depth=4인 경우의 수

    return 0;
}
```

## 배열에서 DFS
타겟 문자열까지 가는 거리(횟수)의 최소값 👉 프로그래머스 단어변환 문제
```java
class Solution {
    boolean[] checked;
    int answer = 51;
  
    public int solution(String begin, String target, String[] words) {
        checked=new boolean[words.length];
        dfs(begin, target, 0, words);

        return answer;
    }
    
    public void dfs(String present, String target, int count, String[] words){
        if(present.equals(target)){ //현재 문자열과 타겟 문자열이 일치하면 dfs 끝
            answer = (answer>count)?count:answer; 
            return;
        }
        
        for(int i=0;i<words.length;i++){
            if(!checked[i] && check(present, words[i])){ 
                checked[i]=true;
                dfs(words[i], target, count+1, words);
                checked[i]=false;
            }
        }
        
    }
    
}
```
