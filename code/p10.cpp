
#include <iostream>

int digit_sum(int x) {
    int sum = 0;

    while (x > 0) {
        sum += x % 10;
        x = x / 10;
    }
    return sum;
}

int main()
{
    int N, num, res, sum=0, max=-2147000000;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        sum = digit_sum(num);
        if (sum > max) {
            max = sum;
            res = num;
        }
        else if (sum == max) {
            if (num > res) res = num;
        }
    }
    printf("%d", res);

    return 0;
}


