#include <iostream>
#include <vector>

using namespace std;

//매번 연속된 두 개의 인덱스를 비교하여 이전 인덱스가 현재 인덱스보다 크면 swap ⇒ 맨 마지막에 가장 큰 값
//(전체 배열 크기 - 현재까지 순환한 바퀴 수) 만큼 반복
vector<int> BubbleSort(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 1; j < v.size() - i; j++)
            if (v[j] < v[j - 1]) {
                int tmp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tmp;
            }
    }
    
    return v;

}

int main()
{
    vector<int> v = { 3,2,4,8,5,1 };

    v = BubbleSort(v);

    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
