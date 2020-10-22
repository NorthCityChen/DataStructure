/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-22 15:55:47
 * @Description: 栈的模板类
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class StackNode
{
private:
    //const int MAXSIZE = 1e3 + 10;
    int top;
    T *base;

public:
    StackNode()
    {
        // this->top=0;
        const int MAXSIZE = 1e3 + 10;
        // this->base = (T *)calloc(MAXSIZE, sizeof(T));
        this->base = new T[MAXSIZE];
        this->top = 0;
    }
    ~StackNode()
    {
        this->top = 0;
    }
    int pop()
    {
        if (top < 1)
            return -1;
        top--;
        return base[top];
    }

    void push(T value)
    {
        base[top] = value;
        top++;
    }
    bool is_empty()
    {
        if (this->top == 0)
            return true;
        return false;
    }
};


void exchange(int x, int n)
{
    StackNode<int> s;
    int tmp = 0;
    while (x)
    {
        // cout << "Hello world" << endl;
        tmp = x % n;
        s.push(tmp);
        x /= n;
    }
    if (s.is_empty())
    {
        cout << "0" << endl;
    }
    while (!s.is_empty())
    {
        cout << s.pop();
    }
    cout << "(" << n << ")" <<endl;
    return ;
}

int main()
{
    // cout << "Hello world" << endl;
    int x, n;
    cin >> x >> n;
    cout << x << "(10)=";
    exchange(x, n);
    // printf("%d\n", s.back());
    return 0;
}