#include <iostream>
#include <stack>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int n, k;
    stack<int> s;
    scanf("%d %d", &n, &k);

    while (n != 0) {
        s.push(n % k);
        n = n / k;
    }

    while (!s.empty()) {
        if (k == 16) { //16진수인 경우
            if (s.top() >= 10) { //10이상이면 ASCII코드 사용해서 문자로 출력되도록 함
                char c = s.top() + 55;
                printf("%c", c);
            }
            else {
                printf("%d", s.top());
            }
        }

        else {
            printf("%d", s.top());
        }
        s.pop();
    }

    return 0;
}
