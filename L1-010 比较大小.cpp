/*
L1-010 比较大小 (10 分)
本题要求将输入的任意3个整数从小到大输出。
输入格式:
输入在一行中给出3个整数，其间以空格分隔。
输出格式:
在一行中将3个整数从小到大输出，其间以“->”相连。
输入样例:
4 2 8
输出样例:
2->4->8
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> a(3);
    for (int i = 0; i < 3; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[0];
    for (int i = 1; i < 3; ++i) cout << "->" << a[i];
    return 0;
}
