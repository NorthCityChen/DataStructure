/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-22 16:47:28
 * @Description: 队列【循环队列实现】
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved
 */

#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 1e3 + 10;

typedef struct queueNode
{
    int front, rear;
    int base[MAXSIZE];
}queueNode;

queueNode creatQueue()
{
    queueNode s;
    s.front = 0;
    s.rear = 0;
    return s;
}

int size(queueNode s)
{
    return (s.rear - s.front + MAXSIZE) % MAXSIZE;
}

void push(queueNode &s, int value)
{
    if ((s.rear+1) % MAXSIZE == s.front)
    {
        // 栈满
        cout << "FULL QUEUE !!!" << endl;
        return ;
    }
    s.base[s.rear] = value;
    s.rear = ++s.rear % MAXSIZE;
    return ;
}

void pop(queueNode &s)
{
    if (s.rear == s.front)
    {
        // 空栈
        cout << "EMPTY QUEUE !!!" << endl;
        return ;
    }
    s.front = ++s.front % MAXSIZE;
    return ;
}

int back(queueNode s)
{
    if (s.rear == s.front)
    {
        cout << "EMPTY QUEUE!!!" << endl;
        return -1;
    }
    return s.base[s.front];
}

int main()
{
    queueNode s= creatQueue();
    int x;
    while (cin >> x && x != 0)
    {
        push(s, x);
    }
    while (size(s))
    {
        cout << back(s) << " ";
        pop(s);
    }
    cout << endl;

    return 0;
}