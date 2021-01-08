// p14.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arr[100];
int reverse(int x) {
	int res=0, rev=0;
	for (int i = x; i > 0; i /= 10) {
		res = i % 10; //1의 자리 숫자 뽑아냄
		rev = rev * 10 + res;
	}

	return rev;
}

bool isPrime(int x) {
	bool isPrime = true;

	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			isPrime = false;
			break;
		}
	}
	//printf("%d : \n", x, isPrime);

	return isPrime;
}


int main()
{
	int N, res = 0, rev = 0;
	bool isprime = false;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}


	for (int i = 0; i < N; i++) {
		res = reverse(arr[i]);
		//printf("res: %d ", res);
		isprime = isPrime(res);
		if (isprime == true) {
			printf("%d ", res);
		}
	}

	return 0;
}
