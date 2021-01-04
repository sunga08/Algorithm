
#include <iostream>

int main()
{
    char a[31];
    int cnt = 0;
    scanf("%s", &a);
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == '(') cnt++;
        else if (a[i] == ')') cnt--;
        if (cnt < 0) break;
    }

    if (cnt == 0) printf("YES");
    else printf("NO");

    return 0;
}


