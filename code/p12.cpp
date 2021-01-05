#include <iostream>

int main(void) {
	int n, sum = 0, c = 1, d = 9, res = 0;
	scanf("%d", &n);
	while (sum + d < n) {
		res = res + (c * d);
		sum = sum + d;
		c++;
		d = d * 10;
	}

	res = res + ((n - sum) * c);
	printf("%d", res);

	return 0;
}


//내 풀이
/*int main()
{
	int N, i = 10, j = 1, cnt = 0;
	scanf("%d", &N);

	while (true) {
		if (N >= i - 1) {
			cnt += j * 9 * (i / 10);
			i = i * 10;
			j++;
		}
		else if (N < i - 1) {
			cnt += (N - ((i / 10) - 1)) * j;
			break;
		}
	}

	printf("%d", cnt);

	return 0;
}*/

