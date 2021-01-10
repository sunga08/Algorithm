#pragma warning(disable: 4996)  
#include <iostream>

int arr[100];
int main()
{
    freopen("input.txt", "rt", stdin);
    int n, max=-1, cnt=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    max = arr[n - 1];//max를 arr[n-1]로 먼저 초기화

    for (int i = n-1; i >= 0; i--) {
        if (arr[i] > max) {
            max = arr[i];
            cnt++;
        }
    }

    //printf("%d", cnt - 1);
    printf("%d", cnt);

    return 0;
}
