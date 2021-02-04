#include <iostream>
#include <vector>
using namespace std;


int n;
vector<int> v;
vector<int> v2;
vector<int> v_sum;
void DFS(int num) {
	if (num == n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (v2[i] == 1) {
				sum += v[i];
				printf("%d ", v[i]);
			}
		}
		printf("    %d\n", sum);
		for (int i = 0; i < v_sum.size(); i++) {
			if (v_sum[i] == sum) {
				printf("YES");
				exit(0);
			}
		}
		v_sum.push_back(sum);

		return;
	}

	v2[num] = 1;
	DFS(num + 1);
	v2[num] = 0;
	DFS(num + 1);
}

int main()
{
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	v2.assign(n, 0);
	DFS(0);
	printf("NO");
	return 0;
}
