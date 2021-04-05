// 브루트포스-그냥 다 해보기
#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int arr[9];
    int sum = 0; //모든 키의 합
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    sort(arr, arr + 9); //먼저 정렬해주면 결과를 따로 정렬하지 않아도 됨
    
    //전체 키 합에서 두 명의 키를 빼서 100이 되는 경우 찾기 => O(N^2)
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k == i || k == j) continue;
                    printf("%d\n", arr[k]);
                }
                return 0;
            }
        }
    }

    return 0;
}
