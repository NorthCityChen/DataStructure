/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-23 10:55:21
 * @Description: 这题没写完呢！！！
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class StackNode
{
private:
    int top;
    T *base;

public:
    StackNode()
    {
        const int MAXSIZE = 1e3 + 10;
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

    T front()
    {
        return base[top - 1];
    }
};

int pro(char c)
{
    int vis[256];
    memset(vis, 0, sizeof(vis));

    vis['+'] = 4;
    vis['-'] = 4;
    vis['*'] = 3;
    vis['/'] = 3;
    vis['('] = 1;
    vis[')'] = 1;
    
    return vis[c];
}

char math(string str)
{
    StackNode<char> s1;
    StackNode<char> s2;

    s2.push('#');
    for (auto x:str)
    {
        if (x != '#' && pro(x) == 0)
        {
            s1.push(x);
        }
        else
        {
            int m ;
        }
        
    }
}

int main()
{
    cout << "Not Finished yet." << endl;
    return 0;
}