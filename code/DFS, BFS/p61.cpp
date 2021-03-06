#include <iostream>

int a[11], n, m, cnt=0;

void DFS(int level, int val) {
    if (level == n + 1) {
        if (val == m) cnt++;
        return;
    }
    else {
        DFS(level + 1, val + a[level]);
        DFS(level + 1, val - a[level]);
        DFS(level + 1, val);
    }

}


int main()
{
    freopen("input.txt", "rt", stdin);
    scanf("%d %d", & n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    DFS(1, 0);
    if (cnt == 0) printf("-1\n");
    else printf("%d\n", cnt);

    return 0;
}
