#include <iostream>
#include <vector>

using namespace std;

vector<int> temp;
void mergeSort(vector<int>& v, int start, int end);
void merge(vector<int>& v, int start, int mid, int end);

int main()
{
    vector<int> v = { 3,2,7,4,1,5 };
    temp.assign(v.size(), 0);

    mergeSort(v, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }

    return 0;
}

void mergeSort(vector<int>& v, int start, int end) { //벡터 주소값을 넘겨 주어야 함
    if (start >= end) return;
    int mid = (start + end) / 2;

    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);

    merge(v, start, mid, end);

}

void merge(vector<int>& v, int start, int mid, int end) { //벡터 주소값을 넘겨 주어야 함

    for (int i = start; i <= end; i++) {
        temp[i] = v[i];
    }
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end) {
        if (temp[i] < temp[j]) {
            v[k++] = temp[i++];
        }
        else {
            v[k++] = temp[j++];
        }
    }

    while (i <= mid) v[k++] = temp[i++];
    while (j <= end) v[k++] = temp[j++];

}



