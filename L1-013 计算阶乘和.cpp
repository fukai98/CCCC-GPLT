/*
L1-013 计算阶乘和 (10 分)
对于给定的正整数N，需要你计算 S=1!+2!+3!+...+N!。
输入格式：
输入在一行中给出一个不超过10的正整数N。
输出格式：
在一行中输出S的值。
输入样例：
3
输出样例：
9
*/

#include <iostream>
using namespace std;
int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int tmp = 1;
        for (int j = 1; j <= i; ++j) tmp *= j;
        sum += tmp;
    }
    cout << sum;
    return 0;
}
