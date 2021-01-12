#pragma warning(disable:4996)
#include <iostream>

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, a, tmp=-1, cnt=0, max = -1;
    scanf("%d", &n);
    //scanf("%d", &a); //처음 숫자를 아예 먼저 읽기
    //for (int i = 2; i <= n; i++) { //2~n (n-1개)
    for (int i = 0; i < n; i++) { //0~n-1 (n개)
        scanf("%d", &a);

        if (a >= tmp) {
            cnt++;
            if (cnt > max) max = cnt;
        }
        else {
            cnt = 1;
        }
        
        tmp = a;
    }
    printf("%d", max);

    return 0;
}

