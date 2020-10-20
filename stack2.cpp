/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-20 09:40:31
 * @Website: https://grimoire.cn
 * @Description: 栈【数组实现】
 * @symbol_custom_string_obkoro1: Copyright 2020 Mr.Sen All rights reserved.
 */

#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 1e3 + 10;

typedef struct stackNode
{
    int top;
    int node[MAXSIZE];
}stackNode;

int pop(stackNode &s)
{
    if (s.top < 1) return -1;
    s.top --;
    return s.node[s.top];
}

void push(stackNode &s, int value)
{
    s.node[s.top] = value;
    s.top++;
}

int main()
{
    stackNode s;
    s.top = 0;
    cout << pop(s) << endl;
    push(s, 12);
    push(s, 45);
    push(s, 55);
    cout << pop(s) << endl;
    cout << pop(s) << endl;
    cout << pop(s) << endl;
    cout << pop(s) << endl;

    return 0;
}
