/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-24 19:04:30
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
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
    if (MAXSIZE == s.top)
    {
        cout << "FULL STACK !!!" << endl;
        exit(0);
    }
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
