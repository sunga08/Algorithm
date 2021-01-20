#pragma warning(disable:4996)
#include <iostream>

//소인수 분해 이용 => 2,5의 갯수만 구하기
//곱하기 10(=2x5)이 될 때 마다 0이 하나씩 증가하므로 2,5의 갯수 중 작은 것이 답
int main()
{
	int n, cnt2=0,cnt5=0, result;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int num = i;
		while (num != 1) {
			if (num % 2 == 0) {
				num = num / 2;
				cnt2++;
			}
			else if (num % 5 == 0) {
				num = num / 5;
				cnt5++;
			}
			else  break;
		}
	}

	if (cnt2 <= cnt5) result = cnt2;
	else result = cnt5;

	printf("%d \n", result);

	return 0;
}

