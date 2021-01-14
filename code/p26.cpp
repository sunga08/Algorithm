#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

//4,5번 time limit
int main()
{
    freopen("input.txt", "rt", stdin);
    int n, cnt = 0;
    scanf("%d", &n);
    vector<int> a(n + 1);
    //vector<int> b(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("1 ");
    for (int i = 1; i < n; i++) {
        //scanf("%d", &a[i]);
        cnt = 0;
        //for (int j = 0; j < i; j++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] <= a[j])
                cnt++;
        }
        //b[i] = cnt+1;
        printf("%d ", cnt + 1);
    }


    

    return 0;
}

