/*
L1-023 输出GPLT (20 分)
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按GPLTGPLT....这样的顺序输出，并忽略其它字符。
当然，四种字符（不区分大小写）的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按GPLT的顺序打印，直到所有字符都被输出。
输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
输入样例：
pcTclnGloRgLrtLhgljkLhGFauPewSKgt
输出样例：
GPLTGPLTGLTGLGLL
*/

#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int G = 0, P = 0, L = 0, T = 0;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'G' || s[i] == 'g') {
            ++G;
        } else if (s[i] == 'P' || s[i] == 'p') {
            ++P;
        } else if (s[i] == 'L' || s[i] == 'l') {
            ++L;
        } else if (s[i] == 'T' || s[i] == 't') {
            ++T;
        }
    }
    while (G > 0 || P > 0 || L > 0 || T > 0) {
        if (G > 0) cout << "G";
        if (P > 0) cout << "P";
        if (L > 0) cout << "L";
        if (T > 0) cout << "T";
        --G;
        --P;
        --L;
        --T;
    }
    return 0;
}
