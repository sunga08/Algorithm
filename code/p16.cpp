#include <iostream>
#include <algorithm> //exit(0) 사용을 위함

//ASCII코드값 이용
//각 문자열에 대한 알파벳 배열 만들어서 두 배열의 cnt값을 비교
//문자열 배열 하나만 사용
int a1[52];
int a2[52];
char s1[101];
//char s2[101];
int main()
{
    bool isAna = true;
    scanf("%s", &s1);
    //scanf("%s", &s2);

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] >= 65 && s1[i] <= 90) {
            a1[s1[i] - 65]++;
        }
        else if (s1[i] >= 97 && s1[i] <= 122) {
            a1[s1[i] - 71]++;
        }
    }

    scanf("%s", &s1);
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] >= 65 && s1[i] <= 90) {
            a2[s1[i] - 65]++;
        }
        else if (s1[i] >= 97 && s1[i] <= 122) {
            a2[s1[i] - 71]++;
        }
    }

    ////s1에 대한 알파벳 배열
    //for (int i = 0; s1[i] != '\0'; i++) {
    //    if (s1[i] >= 65 && s1[i] <= 90) {
    //        a1[s1[i] - 65]++;
    //    }
    //    else if (s1[i] >= 97 && s1[i] <= 122) {
    //        a1[s1[i] - 71]++;
    //    }
    //}

    ////s2에 대한 알파벳 배열
    //for (int i = 0; s2[i] != '\0'; i++) {
    //    if (s2[i] >= 65 && s2[i] <= 90) {
    //        a2[s2[i] - 65]++;
    //    }
    //    else if (s2[i] >= 97 && s2[i] <= 122) {
    //        a2[s2[i] - 71]++;
    //    }
    //}


    for (int i = 0; i < 52; i++) {
        if (a1[i] != a2[i]) {
            printf("NO\n");
            exit(0); //아나그램이 아니면 바로 프로그램 종료
            //isAna = false;
            //break;
        }
    }

    printf("YES\n");


    return 0;
}