
#include <iostream>

// Time Limit
// 40 = 1 x 40
//      2 x 20
//      4 x 10
//      5 x 8  => 왼쪽 숫자만 확인하면 됨
// 289 = 1 x 289
//       17 x 17 => 289까지 볼 필요 없이 17까지만 확인하면 됨
int main()
{
    int N, cnt = 0;
    bool flag; //1일때 소수
    scanf("%d", &N);

    //1은 어차피 소수가 아님

    for (int i = 2; i <= N; i++) {
        flag = 1;
        for (int j = 2; j*j <= i; j++) { //제곱근 이후로는 볼 필요 없음
            if (i % j == 0) {
                flag = 0; //소수가 아니라고 판단
                break;
            }
        }
        if (flag == 1) {
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}
