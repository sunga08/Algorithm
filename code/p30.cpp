#include <iostream>

int main()
{
    int n;
    scanf("%d", &n);
    int lt = 1, pt = 1, rt = 1, k = 1;
    int cnt = 0;

    while (lt != 0) {
        pt = (n / k) % 10;
        lt = n / (k * 10);
        rt = n % k;

        if (pt > 3) cnt += (lt + 1) * k;
        else if (pt == 3) cnt += (lt * k) + (rt + 1);
        else cnt += lt * k;

        k *= 10;
    }

    printf("%d", cnt);


    return 0; 
}
