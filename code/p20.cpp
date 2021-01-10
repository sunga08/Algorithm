#pragma warning (disable: 4996)
#include <iostream>

int A[100];
int B[100];
int main()
{
    freopen("input.txt", "rt", stdin);
    int n, res;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < n; i++) {
        res = (A[i] - B[i] + 2) % 3;
        if (res == 2) {
            printf("D\n");
        }
        else if (res == 1) {
            printf("B\n");
        }
        else if (res == 0) {
            printf("A\n");
        }
    }

    return 0;
}
