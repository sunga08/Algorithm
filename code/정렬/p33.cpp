#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int max = v[i];
        int maxidx = i;
        for(int j=i+1;j<n;j++){
            if (max < v[j]) {
                max = v[j];
                maxidx = j;
            }
        }
        int temp = v[i];
        v[i] = v[maxidx];
        v[maxidx] = temp;
    }
    int cnt = 1, i = 1;
    for (i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            cnt++;
        }
        if (cnt == 3) break;
    }

    printf("%d", v[i]);

    return 0;
}
