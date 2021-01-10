#pragma warning(disable: 4996)
#include <iostream>

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, m, temp, cnt=0, max = -2147000;
    bool isAlarm=false;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp > m) {
            cnt++;
            isAlarm = true;
        }
        else cnt = 0;

        if (cnt > max) max = cnt;
    }

    //if (isAlarm == false) printf("-1");
    if (max == 0) printf("-1");
    else printf("%d", max);

    return 0;
}
