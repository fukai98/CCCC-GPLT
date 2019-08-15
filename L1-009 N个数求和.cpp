/*
L1-009 N个数求和 (20 分)\
本题的要求很简单，就是求N个数字的和。麻烦的是，这些数字是以有理数分子/分母的形式给出的，你输出的和也必须是有理数的形式。
输入格式：
输入第一行给出一个正整数N（≤100）。随后一行按格式a1/b1 a2/b2 ...给出N个有理数。题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。
输出格式：
输出上述数字和的最简形式 —— 即将结果写成整数部分 分数部分，其中分数部分写成分子/分母，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输出分数部分。
输入样例1：
5
2/5 4/15 1/30 -2/60 8/3
输出样例1：
3 1/3
输入样例2：
2
4/3 2/3
输出样例2：
2
输入样例3：
3
1/3 -1/6 1/8
输出样例3：
7/24
*/

#include <cstdio>
#include <cstdlib>
using namespace std;
//求最大公约数
int gcd(int a, int b) {
    int tmp;
    while (a % b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
}
int main() {
    int n, a, b, suma = 0, sumb = 1, gcd_value;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d/%d", &a, &b);
        gcd_value = (a == 0 || b == 0) ? 1 : gcd(abs(a), abs(b));
        a = a / gcd_value;
        b = b / gcd_value;
        gcd_value = (suma == 0 || sumb == 0) ? 1 : gcd(abs(suma), abs(sumb));
        suma = suma / gcd_value;
        sumb = sumb / gcd_value;
        suma = suma * b + a * sumb;
        sumb = sumb * b;
    }
    int integer = suma / sumb;
    suma = suma % sumb;
    gcd_value = (suma == 0 || sumb == 0) ? 1 : gcd(abs(suma), abs(sumb));
    suma = suma / gcd_value;
    sumb = sumb / gcd_value;
    if (integer != 0) {
        printf("%d", integer);
        if (suma != 0) printf(" ");
    }
    if (suma != 0) printf("%d/%d", suma, sumb);
    if (integer == 0 && suma == 0) printf("0");
    return 0;
}
