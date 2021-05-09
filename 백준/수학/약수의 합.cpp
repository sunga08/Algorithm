#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  
    //1~MAX까지 약수의 합 구해서 저장
    vector<long long> d(MAX+1, 1); //d[n] = n의 약수의 합
    for (int i = 2; i <= MAX; i++) { //i = 약수
      for (int j = 1; i * j <= MAX; j++) {
        d[i * j] += i; //i를 약수로 갖는 수에 더하기
      }
    }

    //약수의 합의 합 구해서 저장
    vector<long long> s(MAX + 1);
    for (int i = 1; i <= MAX; i++) {
      s[i] = s[i - 1] + d[i];
    }

    //테스트케이스에 해당하는 인덱스 값 출력 (scanf, printf 사용하면 틀림)
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << s[n] << '\n';
    }

    return 0;
}
