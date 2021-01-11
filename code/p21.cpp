#pragma warning(disable:4996)
#include <iostream>

int main()
{
    //freopen("input.txt", "rt", stdin);
    int a[10], b[10];
    int sumA = 0, sumB = 0;
    int tmp=-1;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (a[i] == b[i]) {
            sumA++;
            sumB++;
        }
        else if (a[i] > b[i]) {
            sumA += 3;
            tmp = 0;
        }
        else if (a[i] < b[i]) {
            sumB += 3;
            tmp = 1;
        }
    }

    printf("%d %d \n", sumA, sumB);
    if (sumA != sumB) {
        if (sumA > sumB) printf("%c", 'A');
        else printf("%c", 'B');
    }
    else {
        if (tmp == 0) printf("%c", 'A');
        else if (tmp == 1) printf("%c", 'B');
        else printf("%c", 'D');
    }

    return 0;
}

