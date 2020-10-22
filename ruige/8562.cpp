/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-22 15:07:20
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct stackNode
{
    int data;
    stackNode *next;
}*LinkStack, stackNode;

LinkStack creatStack()
{
    LinkStack s = new stackNode;
    s -> next = NULL;
    return s;
}

int pop(LinkStack &s)
{
    if (s -> next == NULL) return 0;
    // 防止空栈时继续弹出
    LinkStack node = s -> next;
    s -> next = node -> next;
    int value = node -> data;
    delete node;
    return value;
}

void push(LinkStack &s, int value)
{
    LinkStack node = new stackNode;
    node -> next = s -> next;
    node -> data = value;
    s -> next = node;

    return ; 
}
int main()
{
    LinkStack s = creatStack();
    int x;
    while (cin >> x && x != 0)
    {
        push(s, x);
    }
    while (x = pop(s))
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}