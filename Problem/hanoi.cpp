/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-20 10:07:09
 * @Website: https://grimoire.cn
 * @Description: 汉诺塔
 * @symbol_custom_string_obkoro1: Copyright 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 1e3 + 10;
int m = 0;

typedef struct stackNode
{
    int top;
    string name;
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

void print(stackNode a)
{
    cout << a.name << ": ";
    while (a.top)
    {
        cout << pop(a) << " ";
    }
    cout << endl;
}
void move(stackNode &a, stackNode &b)
{
    int value = pop(a);
    push(b, value);
    cout << "Step:" << ++m << " " << a.name << "->" << b.name << endl;
    print(a);
    print(b);
}

void hanoi(int n, stackNode &a, stackNode &b, stackNode &c)
{
    if (n == 1) move(a, c);
    else
    {
        hanoi(n - 1, a, c, b);
        move(a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    stackNode a, b, c;
    a.top = 0, b.top = 0, c.top = 0;
    a.name = "A", b.name = "B", c.name = "C";
    int n = 5;
    for (int i = n; i > 0; i--)
    {
        push(a, i);
    }
    hanoi(n, a, b, c);
    return 0;
}