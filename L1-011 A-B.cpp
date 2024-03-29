/*
L1-011 A-B (20 分)
本题要求你计算A−B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B所包含的字符全删掉，剩下的字符组成的就是字符串A−B。
输入格式：
输入在2行中先后给出字符串A和B。两字符串的长度都不超过10^4，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。
输出格式：
在一行中打印出A−B的结果字符串。
输入样例：
I love GPLT!  It's a fun game!
aeiou
输出样例：
I lv GPLT!  It's  fn gm!
*/

#include <iostream>
#include <string>
using namespace std;
int Times[256] = {0};  //用来存放b中各个字符是否出现或出现的次数
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.length(); ++i) Times[b[i]] = 1;
    for (int i = 0; i < a.length(); ++i) {
        if (Times[a[i]] == 1) continue;
        cout << a[i];
    }
    return 0;
}
