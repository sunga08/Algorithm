#include <iostream>

int main()
{
    int N, num, ans, sum=0;
    
    scanf("%d", &N);

    for (int i = 0; i < N ; i++) {
        sum = 0;
        scanf("%d %d", &num, &ans); 
        for (int j = 1; j <= num; j++) {
            sum += j;
        }
        if (ans == sum) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
    
}

