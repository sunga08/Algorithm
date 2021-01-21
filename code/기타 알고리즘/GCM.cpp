#pragma warning(disable:4996)
#include <iostream>

//최대 공약수
//(12, 8) ⇒ 12 % 8 = 4  ⇒  8 % 4 = 0  ⇒ 4 % 0 ⇒ return 4
int GCM(int num1, int num2) {
    
    if (num2 == 0) return num1;
    return GCM(num2, num1 % num2);
}
//최소 공약수 
int LCM(int num1, int num2) {
    return (num1 * num2) / GCM(num1, num2);
}


int main()
{
    printf("%d  %d", GCM(12, 8),LCM(12,8));
    return 0;
}

