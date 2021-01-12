#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm> //abs
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, pre, now, dif;
    scanf("%d", &n);
    scanf("%d", &pre);
    vector<int> check(n); //벡터: 초기값 = 0
    for (int i = 1; i < n; i++) {
        scanf("%d", &now);
        //**범위 확인 후 check 배열이 0인지 확인해야 함
        if (dif > 0 && dif < n && check[dif] == 0) {//dif의 범위 확인
            check[dif] = 1;
        }
        else {
            printf("No\n");
            return 0;
        }
        pre = now;
    }
    printf("YES\n");
    
    /*for (int i = 1; i < n; i++) {
        scanf("%d", &now);
        dif = abs(now - pre);
        if (dif >= n) {
            printf("NO\n");
            return 0;
        }
        if (check[dif] == 0) check[dif] = 1;
        else {
            printf("NO\n");
            return 0;
        }
        pre = now;
    }
    printf("YES\n");*/

    return 0;
}

