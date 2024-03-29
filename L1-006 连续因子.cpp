/*
L1-006 连续因子 (20 分)
一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。
给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。
输入格式：
输入在一行中给出一个正整数 N（1<N<2^31）
输出格式：
首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 因子1*因子2*……*因子k 的格式输出最小的连续因子序列，
其中因子按递增顺序输出，1 不算在内。
输入样例：
630
输出样例：
3
5*6*7
*/

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n, max_n, first = 0, len = 0;
    cin >> n;
    max_n = sqrt(n);
    for (int i = 2; i <= max_n; ++i) {
        int j, tmp = 1;
        for (j = i; j <= max_n; ++j) {
            tmp *= j;
            if (n % tmp != 0) break;
        }
        if (j - i > len) {
            len = j - i;
            first = i;
        }
    }
    if (first == 0) {
        cout << 1 << endl << n;
    } else {
        cout << len << endl;
        cout << first;
        for (int i = first + 1; i < first + len; ++i) {
            cout << "*" << i;
        }
    }
    return 0;
}
