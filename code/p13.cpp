
#include <iostream>

//자연수 최대 길이는 100이므로 int에 저장 못함 => 배열 사용(문자열로 입력 받음)
//ASCII코드 사용해서 문자열 -> 숫자로 바꾸기

int a[10];
int main()
{
    char input[101];
    int max; //최대 자릿수(인덱스)
    int cnt_max = -1; //등장 횟수

    scanf("%s", &input);

    for (int i = 0; input[i] != '\0'; i++) {
        a[input[i] - 48]++;
    }

    for (int i = 0; i < 10; i++) {
        if (cnt_max <= a[i]) { // '='도 포함 : 0->9로 읽으면서 최댓값이 같으면 무조건 나중에 읽은 인덱스가 큼.
            max = i;
            cnt_max = a[i];
        }

    }

    printf("%d", max);

    return 0;
}

