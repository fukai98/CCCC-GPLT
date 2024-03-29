/*
L1-008 求整数段和 (10 分)
给定两个整数A和B，输出从A到B的所有整数以及这些数的和。
输入格式：
输入在一行中给出2个整数A和B，其中−100≤A≤B≤100，其间以空格分隔。
输出格式：
首先顺序输出从A到B的所有整数，每5个数字占一行，每个数字占5个字符宽度，向右对齐。最后在一行中按Sum = X的格式输出全部数字的和X。
输入样例：
-3 8
输出样例：
   -3   -2   -1    0    1
    2    3    4    5    6
    7    8
Sum = 30
*/

#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int start, end;
    int cnt = 0;
    int sum = 0;
    cin >> start >> end;
    for (int i = start; i <= end; ++i) {
        ++cnt;
        sum += i;
        printf("%5d", i);
        if (cnt == 5) {
            cnt = 0;
            cout << endl;
        }
        if (i == end && cnt != 0) cout << endl;
    }
    cout << "Sum = " << sum;
    return 0;
}
