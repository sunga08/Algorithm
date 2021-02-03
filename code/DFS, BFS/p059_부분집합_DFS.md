# DFS 부분집합

```
#include <iostream>
#include <vector>

using namespace std; 
vector<int> ch;
int input;
void DFS(int n) {
    
    if (n == input + 1) {
        for (int i = 1; i <= input; i++) {
            if (ch[i] == 1) printf("%d ", i);
        }
        printf("\n");
        return;
    }

    ch[n] = 1; //현재 인덱스 선택함
    DFS(n + 1); //왼쪽으로 가기
    ch[n] = 0; //현재 인덱스 선택 안함
    DFS(n + 1); //오른쪽으로 가기
}


int main()
{

    scanf("%d", &input);
    ch.assign(input+1, 0);
    DFS(1);

    return 0;
}
```

![부분집합dfs](https://user-images.githubusercontent.com/53103434/106748733-f94ae880-6668-11eb-8a10-9a9394e65e3d.jpg)
