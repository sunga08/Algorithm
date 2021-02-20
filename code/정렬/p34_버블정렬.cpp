#pragma warning(disable:4996)
#include <iostream>


int main()
{
	freopen("input.txt", "rt", stdin);
	int n, a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i -1; j++) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}

