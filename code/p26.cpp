#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

//데이터가 더 커지면 합병정렬 사용해야 됨
//4,5번 time limit (Release 모드로 컴파일시 통과)
//앞 사람들 중 자신보다 크거나 같은 사람 count => 내 등수 = count+1
int main()
{
    freopen("input.txt", "rt", stdin);
    int n, cnt = 0;
    scanf("%d", &n);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("1 ");
    for (int i = 1; i < n; i++) {
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

