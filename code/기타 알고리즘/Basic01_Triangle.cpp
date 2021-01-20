#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<char>> v;

    for (int i = 0; i < 3; i++) {
        vector<char> v2(i+1);
        v.push_back(v2);
        for (int j = 0; j <v2.size(); j++) {
            v[i][j] = '*';
            printf("%c",v[i][j]);
        }
        printf("\n");
    }
}

