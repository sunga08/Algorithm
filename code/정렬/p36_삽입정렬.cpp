#include <iostream>

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, a[101];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++) {
        int key = a[i], j = i-1;
        while(a[j] > key) {
            a[j + 1] = a[j];            
            j--;
        }
        a[j + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
