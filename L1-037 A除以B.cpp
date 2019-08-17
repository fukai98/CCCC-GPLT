/*
L1-037 A除以B (10 分)
真的是简单题哈 —— 给定两个绝对值不超过100的整数A和B，要求你按照“A/B=商”的格式输出结果。
输入格式：
输入在第一行给出两个整数A和B（−100≤A,B≤100），数字间以空格分隔。
输出格式：
在一行中输出结果：如果分母是正数，则输出“A/B=商”；如果分母是负数，则要用括号把分母括起来输出；如果分母为零，则输出的商应为Error。输出的商应保留小数点后2位。
输入样例1：
-1 2
输出样例1：
-1/2=-0.50
输入样例2：
1 -3
输出样例2：
1/(-3)=-0.33
输入样例3：
5 0
输出样例3：
5/0=Error
*/

#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << a << "/";
    if (b < 0) {
        cout << "(" << b << ")=";
    } else {
        cout << b << "=";
    }
    if (b == 0) {
        cout << "Error";
        return 0;
    }
    printf("%.2lf", (double)a / (double)b);
    return 0;
}
