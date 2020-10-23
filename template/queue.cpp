/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-23 10:50:19
 * @Description: 循环队列【模板类】
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class queueNode
{
private:
    typedef struct Node
    {
        int front, rear;
        T *base;
    } Node;

    Node s;
    int MAXSIZE;

public:
    queueNode()
    {
        s.front = 0;
        s.rear = 0;
        MAXSIZE = 1e3 + 10;
        s.base = new T[MAXSIZE];
        // return s;
    }
    ~queueNode()
    {
        s.front = 0;
        s.rear = 0;
        // memset(s.base, 0, sizeof(s.base));
        delete &s;
    }
    int size()
    {
        return (s.rear - s.front + MAXSIZE) % MAXSIZE;
    }
    void push(T value)
    {
        if ((s.rear + 1) % MAXSIZE == s.front)
        {
            // 栈满
            cout << "FULL QUEUE !!!" << endl;
            return;
        }
        s.base[s.rear] = value;
        s.rear = ++s.rear % MAXSIZE;
        return;
    }
    T pop()
    {
        if (s.rear == s.front)
        {
            // 空栈
            cout << "EMPTY QUEUE !!!" << endl;
            return -1;
        }
        int loc = s.front;
        s.front = ++s.front % MAXSIZE;
        return s.base[loc];
    }
    T back()
    {
        if (s.rear == s.front)
        {
            cout << "EMPTY QUEUE!!!" << endl;
            return -1;
        }
        return s.base[s.front];
    }
};

int main()
{
    queueNode<int> s;
    s.push(12);
    s.push(22);
    cout << s.pop() << " " << s.pop() << endl;
    cout << s.back() << endl;
    return 0;
}