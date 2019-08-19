/*
L1-064 估值一亿的AI核心代码 (20 分)
以上图片来自新浪微博。
本题要求你实现一个稍微更值钱一点的 AI 英文问答程序，规则是：
无论用户说什么，首先把对方说的话在一行中原样打印出来；
消除原文中多余空格：把相邻单词间的多个空格换成 1 个空格，把行首尾的空格全部删掉，把标点符号前面的空格删掉；
把原文中所有大写英文字母变成小写，除了 I；
把原文中所有独立的 can you、could you 对应地换成 I can、I could—— 这里“独立”是指被空格或标点符号分隔开的单词；
把原文中所有独立的 I 和 me 换成 you；
把原文中所有的问号 ? 换成惊叹号 !；
在一行中输出替换后的句子作为 AI 的回答。
输入格式：
输入首先在第一行给出不超过 10 的正整数 N，随后 N 行，每行给出一句不超过 1000 个字符的、以回车结尾的用户的对话，对话为非空字符串，仅包括字母、数字、空格、可见的半角标点符号。
输出格式：
按题面要求输出，每个 AI 的回答前要加上 AI: 和一个空格。
输入样例：
6
Hello ?
 Good to chat   with you
can   you speak Chinese?
Really?
Could you show me 5
What Is this prime? I,don 't know
输出样例：
Hello ?
AI: hello!
 Good to chat   with you
AI: good to chat with you
can   you speak Chinese?
AI: I can speak chinese!
Really?
AI: really!
Could you show me 5
AI: I could show you 5
What Is this prime? I,don 't know
AI: what Is this prime! you,don't know
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//改变大写字母，标点符号，以及空格
void BasicChange(string &s) {
    int flag = -1;
    string tmp;
    for (int i = 0; i < s.length(); ++i) {
        if (isupper(s[i]) && s[i] != 'I') {
            s[i] = tolower(s[i]);
        } else if (s[i] == '?') {
            s[i] = '!';
        }
        if (s[i] != ' ') {
            flag = 1;
        } else {
            if (flag != -1) flag = 0;
        }
        if (flag == 1) {
            tmp += s[i];
        } else if (flag == 0) {
            if ((isdigit(s[i + 1]) || isalpha(s[i + 1])) && i + 1 < s.length())
                tmp += " ";
        }
    }
    s = tmp;
}
//替换单词
void MoreChange(string &s) {
    vector<string> v;
    int flag = -1;
    string tmp = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag == 1) {
            tmp += s[i];
            if (i == s.length() - 1) {
                v.push_back(tmp);
            }
        } else {
            v.push_back(tmp);
            tmp = "";
        }
    }
    s = "";
    for (int i = 0; i < v.size(); ++i) {
        /*
不能直接用一下注释中的方法，因为can和you不一定是单独存在的！！！
可能会出现 ,can you,,,  这也要变为 ,I can,,,
        if(v[i] == "can" && v[i+1] == "you"){
            v[i] = "I";
            v[i+1] = "can";
        } else if(v[i] == "could" && v[i+1] == "you") {
            v[i] = "I";
            v[i+1] = "could";
        } else if(v[i] == "me") {
            v[i] = "you";
        } else if(v[i][0] == 'I' && !isalpha(v[i][1])) {
            v[i] = "you" + v[i].substr(1);
        }
*/
        if (v[i].find("can") != string::npos &&
            v[i + 1].find("you") != string::npos &&
            !isalpha(v[i][v[i].find("can") - 1]) &&
            !isalpha(v[i][v[i].find("can") + 3]) &&
            !isalpha(v[i + 1][v[i + 1].find("you") - 1]) &&
            !isalpha(v[i + 1][v[i + 1].find("you") + 3])) {
            v[i] = v[i].substr(0, v[i].find("can")) + "I";
            v[i + 1] = "can" + v[i + 1].substr(v[i + 1].find("you") + 3);
        } else if (v[i].find("could") != string::npos &&
                   v[i + 1].find("you") != string::npos &&
                   !isalpha(v[i][v[i].find("could") - 1]) &&
                   !isalpha(v[i][v[i].find("could") + 5]) &&
                   !isalpha(v[i + 1][v[i + 1].find("you") - 1]) &&
                   !isalpha(v[i + 1][v[i + 1].find("you") + 3])) {
            v[i] = v[i].substr(0, v[i].find("could")) + "I";
            v[i + 1] = "could" + v[i + 1].substr(v[i + 1].find("you") + 3);
        } else if (v[i].find("me") != string::npos &&
                   !isalpha(v[i][v[i].find("me") - 1]) &&
                   !isalpha(v[i][v[i].find("me") + 2])) {
            v[i] = v[i].substr(0, v[i].find("me")) + "you" + v[i].substr(v[i].find("me") + 2);
        } else if (v[i].find("I") != string::npos &&
                   !isalpha(v[i][v[i].find("I") - 1]) &&
                   !isalpha(v[i][v[i].find("I") + 1])) {
            v[i] = v[i].substr(0, v[i].find("I")) + "you" + v[i].substr(v[i].find("I") + 1);
        }
        if (i == 0) {
            s += v[i];
        } else {
            s += " " + v[i];
        }
    }
}
int main() {
    string s;
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        cout << s << endl;
        BasicChange(s);
        MoreChange(s);
        cout << "AI: " << s << endl;
    }
    return 0;
}
