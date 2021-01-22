#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
using namespace std;

//반복문 이용
int BinarySearch(vector<int> v, int key) {
    int start = 0;
    int end = v.size();
    int mid;

    while (start <= end) { //start 인덱스와 end 인덱스가 교차되면 종료
        mid = (start + end) / 2;
        if (v[mid] == key) {
            return mid;
        }
        else if (key < v[mid]) end = mid - 1; //mid 기준 왼쪽 선택
        else start = mid + 1; //mid 기준 오른쪽 선택
    }

    return -1;
}

//재귀 함수 이용
int BinarySearch_Recursive(vector<int> v, int key, int start, int end) {
    if (start > end) return -1;
    int mid = (start + end) / 2;
    if (v[mid] == key) return mid;
    else if (v[mid] > key) return BinarySearch_Recursive(v, key, start, mid - 1);
    else return BinarySearch_Recursive(v, key, mid + 1, end);
}


int main()
{
    vector<int> v(100);
    vector<string> v2 = { "public", "class", "vector","do", "return" };
 
    //중복되지 않게 난수 발생
    for (int i = 0; i < 100; i++) {
        v[i] = rand() % 100 + 1;
        for (int j = 0; j < i; j++) {
            if (v[j] == v[i]) {
                i--;
                break;
            }
        }  
    }
    
    sort(v.begin(),v.end());
    printf("index: %d \n", BinarySearch(v, 30));
    printf("index(recursive): %d \n", BinarySearch_Recursive(v, 30, 0, v.size()-1));

    //문자열 정렬
    sort(v2.begin(), v2.end());

    /*for (int i = 0; i < v2.size(); i++) {
        printf("%s ", v2[i].c_str());
    }*/

    return 0;
}
