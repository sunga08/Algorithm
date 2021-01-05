#include <iostream>

//정확히 어떤 자연수가 몇 번 쓰였는지는 알 필요 없음
//총 자릿수만 세면 됨

int main() {
    int N, temp, cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i <= N; i++) {
        temp = i;
        //자릿수 세기
        while (temp > 0) {
            temp = temp / 10;
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}


/*int cnt[10];
int main()
{
    int N, a, sum=0;
    
    scanf("%d", &N);


    for (int i = 1; i <= N; i++) {
        if (i < 10) {
            cnt[i]++;
        }
        else if(i>=10){
            for (int j = i; j > 0; j=j / 10) {
                a = j % 10;
                cnt[a]++;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        sum += cnt[i];
    }

    printf("%d", sum);

    return 0;
}*/

