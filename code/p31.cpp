#pragma warning(disable:4996)
#include <iostream>
#include <string>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    char s[10];
    int c=0, h=0, i, pos;
    scanf("%s", &s);

    
    if (s[1] == 'H') {
        c=1;
        pos = 1;
    }
    else {
        for (i = 1; s[i] != 'H'; i++) {
            c = c * 10 + (s[i] - 48);
        }
        pos = i;
    }
    
    if (s[pos + 1] == '\0') h = 1;
    else {
        for (i = pos + 1; s[i] != '\0'; i++) {
            h = h * 10 + (s[i] - 48);
        }
    }
    printf("%d\n", c * 12 + h);
   
    return 0;
}
