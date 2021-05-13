## 소스 코드
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, v;
vector<int> graph[1001];
bool check[1001];
void dfs(int x) {
    check[x] = true;
    printf("%d ", x);
    for(int i=0;i<graph[x].size();i++){ //i=0부터 시작!!
        int next = graph[x][i];
        if (!check[next]) {
            dfs(next);
        }
    }
}

void bfs(int x) {
    queue<int> q;
    check[x] = true;
    q.push(x);
    
    while (!q.empty()) {
        int cur = q.front();
        printf("%d ", cur);
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (!check[graph[cur][i]]) { //check[i] 아님
                int z = graph[cur][i];
                check[z] = true;
                q.push(z);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    printf("\n");
    fill(check, check+1001, false);
    bfs(v);

    return 0;
}
```

## 참고
graph, check 배열 범위 1001까지!!! </br>
fill 함수에서도 두번째 인자 check+**1001** !!! </br>
인접리스트에서 작은 숫자부터 탐색해야 할 때는 정렬 먼저 해줘야 한다. 

오랜만에 구현했더니 헷갈림 6_6;;


## JAVA
```java
import java.util.*;

public class Main {
    static boolean[] visited;
    public static void main(String[] args){
        int n, m, start;

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        start = sc.nextInt();

        visited = new boolean[n+1];
        ArrayList<Integer>[] graph = (ArrayList<Integer>[]) new ArrayList[n+1];
        for(int i=1;i<=n;i++){
            graph[i] = new ArrayList<>();
        }

        for(int i=0;i<m;i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph[u].add(v);
            graph[v].add(u);
        }

        for(int i=1;i<=n;i++){
            Collections.sort(graph[i]);
        }

        dfs(graph, start);
        System.out.println();

        visited = new boolean[n+1];

        bfs(graph, start);
        System.out.println();
    }

    public static void dfs(ArrayList<Integer>[] graph, int start){
        visited[start] = true;
        System.out.print(start+" ");
        for(int i=0;i<graph[start].size();i++){
            int next = graph[start].get(i);
            if(!visited[next]){
                dfs(graph, next);
            }
        }
    }

    public static void bfs(ArrayList<Integer>[] graph, int start){
        Queue<Integer> q = new LinkedList<>();
        visited[start] = true;
        q.add(start);

        while(!q.isEmpty()){
            int cur = q.poll();
            System.out.print(cur+" ");
            for(int i=0;i<graph[cur].size();i++){
                int next = graph[cur].get(i);
                if(!visited[next]){
                    visited[next]=true;
                    q.add(next);
                }
            }
        }
    }
}
```
