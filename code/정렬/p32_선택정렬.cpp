#pragma warning(disable:4996)
#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int n, a[100];
	scanf("%d", &n);
	//vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n-1; i++) {
		int minidx=i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[minidx]) {
				minidx = j;
			}
		}

		int temp = a[i];
		a[i] = a[minidx];
		a[minidx] = temp;

	}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
