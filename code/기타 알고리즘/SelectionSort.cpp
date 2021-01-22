#include <iostream>
#include <vector>

using namespace std;

//맨 앞부터 현재 인덱스와 이후의 배열 값을 비교하면서 최소값을 찾고, 현재값과 최소값을 swap

vector<int> swap(vector<int> v, int i, int j) {
    int tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;

    return v;
}

vector<int> SelectionSort(vector<int> v) {
    
    for (int i = 0; i < v.size()-1; i++) { //**범위**
        int minIdx=i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[minIdx] > v[j]) 
                minIdx = j;        
        }
        v = swap(v, i, minIdx);
    }

    return v;
}


int main()
{
    vector<int> v = { 3,1,8,4,5 };
    v = SelectionSort(v);

    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }

    return 0;
}

