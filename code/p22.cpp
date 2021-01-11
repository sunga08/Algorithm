#pragma warning(disable:4996)
#include <iostream>
#include <vector>
//int arr[100001];
//배열 사용하면 input이 작을 때는 메모리 낭비
//이중 for문 사용하면 Time Limit
int main()
{
    //freopen("input.txt", "rt", stdin);
    int n, k, sum=0, max=-21470000;
    scanf("%d %d", &n, &k);
    std::vector<int> a(n); //크기가 n인 1차원 배열
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    max = sum;

    for (int i = k; i < n ; i++) {
        sum = sum + a[i] - a[i - k];
        if (sum > max) max = sum;
    }


    //for (int i = 0; i < n - k+1; i++) {
    //    sum = 0;
    //    for (int j = i; j < i+k; j++) {
    //        sum += arr[j];       
    //    }
    //    printf("%d \t", sum);
    //    if (sum > max) max = sum;
    //}
    
    printf("%d\n", max);

    return 0;
}

