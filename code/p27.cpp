#pragma warning (disable:4996)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, temp, k;
    scanf("%d", &n);
    vector<int> check(n + 1);

    //모든 수에 대하여 소인수 분해 => 배열 count
    for (int i = 2; i <= n; i++) {
        temp = i; //i는 for문 돌아야 하므로 건들면 안됨
        k = 2;
        while (1) {
            if (temp % k == 0) {
                temp /= k;
                check[k]++;
            }
            else {
                k++;
            }
            if (temp == 1) break;
        }
    }



    printf("%d! = ", n);
    for (int i = 1; i <= n; i++) {
        if (check[i] != 0)
            printf("%d ", check[i]);
    }

    return 0;
}
