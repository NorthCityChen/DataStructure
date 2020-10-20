/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-20 09:17:48
 * @Website: https://grimoire.cn
 * @Description: 栈【单链表实现】
 * @symbol_custom_string_obkoro1: Copyright 2020 Mr.Sen All rights reserved.
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
    if (s -> next == NULL) return -1;
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
    push(s, 12);
    push(s, 13);
    cout << pop(s) << endl;
    cout << pop(s) << endl;
    cout << pop(s) << endl;
    return 0;
}