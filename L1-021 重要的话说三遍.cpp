/*
L1-021 重要的话说三遍 (5 分)
这道超级简单的题目没有任何输入。
你只需要把这句很重要的话 —— “I'm gonna WIN!”——连续输出三遍就可以了。
注意每遍占一行，除了每行的回车不能有任何多余字符。
输入样例：
无
输出样例：
I'm gonna WIN!
I'm gonna WIN!
I'm gonna WIN!
*/

#include <iostream>
using namespace std;
int main() {
    for (int i = 0; i < 3; ++i) cout << "I'm gonna WIN!" << endl;
    return 0;
}
