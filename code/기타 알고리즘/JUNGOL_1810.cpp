#pragma warning(disable:4996)
#include <iostream>

int count(int num) { //num을 2진수로 표현했을 때 1의 갯수
    int count = 0;
    int n = num;
    //각 자릿수를 1과 &연산 => 비트를 오른쪽으로 하나씩 shift 하므로 각 자리수가 1일때만 연산결과가 1이 나옴
    while (n > 0) {
        if ((n & 1) == 1) { //2^0 자리 비트가 1인 경우 
            count++;
        }
        n = n >> 1; //오른쪽으로 1bit 이동(1/2감소)
    }
    return count;
}


int main()
{
    //freopen("input.txt", "rt", stdin);
    int arr[9];
    
    for (int i = 0; i < 9; i++) {
        scanf("%d\n", &arr[i]);
    }
    

    for (int i = 0; i < (1 << 9); i++) { //2^9 만큼 반복 (원소가 7개인 배열의 부분집합 갯수)
        
        if (count(i) == 7) { //부분집합 원소가 7개인 경우 (1의 갯수만큼 1<<j(=2^j)와 연산시 1이 나옴)
            int sum = 0;
            for (int j = 0; j < 9; j++) { 
                if ((i & (1 << j)) != 0) { //count(i)=7인 i와 2^j가 & 연산을 해서 1이 나오는 j를 인덱스로 갖는 원소 7개가 선택됨
                    sum += arr[j];
                }
            }
            //sum=100일때 위와 같은 for문을 한 번 더 반복해서 출력
            if (sum == 100) {
                for (int j = 0; j < 9; j++) {
                    if ((i & (1 << j)) != 0) printf("%d\n", arr[j]);
                }
                break;
            }
        }
    }

    return 0;
}
