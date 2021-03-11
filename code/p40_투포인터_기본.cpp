#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int n1, n2, point1 = 0, point2 = 0;
    scanf("%d", &n1);
    vector<int> v1(n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &v1[i]);
    }
    scanf("%d", &n2);
    vector<int> v2(n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &v2[i]);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());


    vector<int> v3;
    while (1) {
        if (point1 >= v1.size() || point2 >= v2.size()) break;

        if (v1[point1] < v2[point2]) {
            point1++;
        }
        else if (v1[point1] > v2[point2]) point2++;
        else if (v1[point1] == v2[point2]) {
            v3.push_back(v1[point1]);
            point1++;
            point2++;
        }
    }

    sort(v3.begin(), v3.end());

    for (int i = 0; i < v3.size(); i++) {
        printf("%d ", v3[i]);
    }

    return 0;
}
