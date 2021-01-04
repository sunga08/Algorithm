
#include <iostream>

int a[50001];
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j = j + i) {
            a[j]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

