#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<int> stack;
    
    if(s[0]==')') return false;
    else{
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') stack.push(0);
            else if(s[i]==')'&& !stack.empty()) stack.pop();
        }
    }
    
    if(stack.empty()) answer=true;

    return answer;
}
