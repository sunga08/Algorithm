#include <iostream>

int main()
{
    int input, i1, i2, i3;
    int answer, a1, a2, a3;
    int strike = 0, ball = 0;

    scanf("%d", &input);
    i1 = input / 100;
    i2 = input % 100 / 10;
    i3 = input % 100 % 10;

    while (strike != 3) {
        strike = 0, ball = 0;
        scanf("%d", &answer);
        a1 = answer / 100;
        a2 = answer % 100 / 10;
        a3 = answer % 100 % 10;

        if (a1 == i1) {
            strike++;
        }
        else if (a1 == i2 || a1 == i3) {
            ball++;
        }

        if (a2 == i2) {
            strike++;
        }
        else if (a2 == i1 || a1 == i3) {
            ball++;
        }

        if (a3 == i3) {
            strike++;
        }
        else if (a3 == i1 || a3 == i2) {
            ball++;
        }

        printf("%dstrike %dball", strike, ball);
    }


    /*int n1, n2, n3;
    int a1, a2, a3;
    int strike=0, ball = 0;

    scanf("%d %d %d", &n1, &n2, &n3);

    while (strike!=3) {
        strike = 0, ball = 0;
        scanf("%d %d %d", &a1, &a2, &a3);
        
        if (a1 == n1) {
            strike++;
        }
        else if (a1 == n2 || a1 == n3) {
            ball++;
        }

        if (a2 == n2) {
            strike++;
        }
        else if (a2 == n1 || a1 == n3) {
            ball++;
        }

        if (a3 == n3) {
            strike++;
        }
        else if (a3 == n1 || a3 == n2) {
            ball++;
        }

        printf("%dstrike %dball", strike, ball);
    }*/
    



    return 0;
}


