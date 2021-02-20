#pragma warning(disable:4996)
#include <iostream>

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, a[100], a1[100], a2[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int j = 0, k= 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            a1[j] = a[i];
            j++;
        }
        else if (a[i] > 0) {
            a2[k] = a[i];
            k++;
        }
    }

    for (int i = 0; i < j; i++) {
        printf("%d ", a1[i]);
    }
    for (int i = 0; i < k; i++) {
        printf("%d ", a2[i]);
    }

    return 0;
}
