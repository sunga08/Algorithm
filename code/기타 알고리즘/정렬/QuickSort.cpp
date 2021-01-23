#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& v, int start, int end);

int main()
{
	vector<int> v = { 3,2,7,4,1,5 };

	quickSort(v, 0, v.size() - 1);

	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}

void swap(vector<int>& v, int n1, int n2) {
	int temp = v[n1];
	v[n1] = v[n2];
	v[n2] = temp;
}

void quickSort(vector<int>& v, int start, int end) {
	if (start < end) {
		int i = start + 1, j = end, pivot = start;
		//i는 pivot보다 큰 값 찾기
		//j는 pivot보다 작은 값 찾기
		while (i <= j) {
			while (i <= end && v[i] < v[pivot]) i++;
			while (j >= 0 && v[j] > v[pivot]) j--;
			if (i < j) {
				swap(v, i, j);
				/*int temp = v[i];
				v[i] = v[j];
				v[j] = temp;*/
			}
		}

		swap(v, pivot, j);
		/*int temp = v[pivot];
		v[pivot] = v[j];
		v[j] = temp;*/

		quickSort(v, start, j-1);
		quickSort(v, j + 1, end);

	}
}
