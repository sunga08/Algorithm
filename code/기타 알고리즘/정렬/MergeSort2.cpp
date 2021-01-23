#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& v, int s, int e);
void merge(vector<int>& v, int s1, int e1, int s2, int e2);

int main()
{
    vector<int> v = { 3,2,7,4,1,5 };

    merge_sort(v, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }

    return 0;
}

void merge_sort(vector<int>& v, int s, int e) {
    if (s == e) return;
    int mid = (s + e) / 2;
    merge_sort(v, s, mid);
    merge_sort(v, mid + 1, e);
    merge(v, s, mid, mid + 1, e);
}

//merge 할 때 임시벡터 생성해서 정렬된 결과 담기 => 정렬 후 원래 벡터에 복사
void merge(vector<int>& v, int s1, int e1, int s2, int e2) {
    int i = s1, j=s2, k = 0;
    vector<int> temp((e1 - s1) + (e2 - s2) + 2); //s1~e2 크기의 벡터 할당

    while (i <= e1 && j <= e2) {
        if (v[i] < v[j]) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }

    while (i <= e1) temp[k++] = v[i++];
    while (j <= e2) temp[k++] = v[j++];

    k = 0;

    for (int i = s1; i <= e2; i++) {
        v[i] = temp[k++];
    }
}
