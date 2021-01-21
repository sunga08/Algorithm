#pragma warning(disable:4996)
#include <iostream>
#include <vector>

using namespace std;
int arr[9];
bool check[9];

void subset(int n, int cnt) {
    
    if (n == 9) { // n==9 && n==7 => n!=7일땐 if문 진입하지 못해서 return 될 수가 없음
        if (cnt == 7) {
            int sum = 0;
            for (int i = 0; i < 9; i++) {
                if (check[i] == true) {
                    sum += arr[i];
                }
            }
            if (sum == 100) {
                for (int i = 0; i < 9; i++) {
                    if (check[i] == true) printf("%d\n", arr[i]);
                }
            }
        }
        return; //위치**
    }

    check[n] = true;
    subset(n + 1, cnt + 1);

    check[n] = false;
    subset(n + 1, cnt);

}


int main()
{
    freopen("input.txt", "rt", stdin);
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }

    subset(0, 0);

    return 0;
}
