/*
L1-028 判断素数 (10 分)
本题的目标很简单，就是判断一个给定的正整数是否素数。
输入格式：
输入在第一行给出一个正整数N（≤ 10），随后N行，每行给出一个小于2^​31的需要判断的正整数。
输出格式：
对每个需要判断的正整数，如果它是素数，则在一行中输出Yes，否则输出No。
输入样例：
2
11
111
输出样例：
Yes
No
*/

#include <cmath>
#include <iostream>
using namespace std;
bool IsPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        //注意这里一定要使用sqrt函数，否则容易超时！！！
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (IsPrime(tmp)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
