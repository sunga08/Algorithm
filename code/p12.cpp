#include <iostream>

int main()
{
	int N, i=10, j=1, cnt=0;
	scanf("%d", &N);
	
	while (true) {
		if (N >= i-1) {
			cnt += j * 9 * (i/10);
			i = i * 10;
			j++;
		}
		else if (N < i - 1) {
			cnt += (N - ((i / 10) - 1))* j;
			break;
		}
	}

	printf("%d", cnt);

	return 0;
}
