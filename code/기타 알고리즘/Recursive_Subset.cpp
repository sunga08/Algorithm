#include <iostream>
#include <vector>

using namespace std;
//재귀호출을 사용해서 부분집합과 부분집합의 원소 개수 출력

vector<int> v = { 3,5,7 };
vector<bool> b(v.size());

void subset(int n, int cnt) {
	if (n == v.size()) { //배열 사이즈보다 커질때 stop
		for (int i = 0; i < v.size(); i++) {
			if (b[i]) printf("%d ", v[i]); //true인 인덱스만 출력
		}
		printf(" => cnt=%d \n",cnt);
		return;
	}

	b[n] = true; //선택하고 다음으로 가기
	subset(n + 1, cnt+1); //선택했을때 count+1 ( cnt++ (X) )

	b[n] = false; //선택하지 않고 다음으로 가기
	subset(n + 1, cnt);
}

int main()
{
	subset(0,0);
	return 0;
}

