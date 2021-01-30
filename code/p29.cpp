#include <iostream>


int main()
{
    int n, cnt=0;
    scanf("%d", &n);

    //모든 자리수 확인하기
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        while (tmp != 0) {
            int j = tmp % 10;
            if (j == 3) cnt++;
            tmp = tmp / 10;
        }
    }


    printf("%d", cnt);
    return 0;
}
