#pragma warning (disable:4996)
#include <iostream>
//#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, idx, max = -21470000, pre=0, rank=0, cnt=0;
    scanf("%d", &n);
    //vector<int> v(n);
    //vector<int> res(n);
    int v[100];
    int res[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        res[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i] < v[j]) res[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}
