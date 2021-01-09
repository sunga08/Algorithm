#include <iostream>

//주의: 1은 소수가 아님
//배열 사용하지 않아도 됨
int arr[100];
int reverse(int x) {
	int res = 0, rev = 0;
	for (int i = x; i > 0; i /= 10) {
		res = i % 10; //1의 자리 숫자 뽑아냄
		rev = rev * 10 + res;
	}

	//	while문 사용

	/*while (x > 0) {
		res = x % 10;
		rev = res * 10 + res;
		x = x / 10;
	}*/

	return rev;
}

bool isPrime(int x) {
	bool isPrime = true;

	//if (x == 1) isPrime = false;
	if (x == 1) return false;

	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			isPrime = false;
			break;
		}
	}

	return isPrime;
}


int main()
{
	int N, res = 0, rev = 0, num;
	bool isprime = false;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		res = reverse(num);

		//더 간단하게
		//isprime = isPrime(res);
		//if (isprime == true) {
		if (isPrime(res)) {
			printf("%d ", res);
		}
	}

	//배열 사용
	//for (int i = 0; i < N; i++) {
	//	scanf("%d", &arr[i]);
	//}


	//for (int i = 0; i < N; i++) {
	//	res = reverse(arr[i]);
	//		printf("res: %d \n", res);
	//	isprime = isPrime(res);
	//	if (isprime == true) {
	//		printf("%d ", res);
	//	}
	//}

	return 0;
}
