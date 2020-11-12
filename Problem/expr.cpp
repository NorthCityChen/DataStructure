/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-25 09:01:53
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

stack<char> s1;
stack<char> s2;

bool isValue(char x)
{
    if (x >= '0' && x <= '9')
        return true;
    return false;
}

char pro(char t1, char t2)
{
    char f;
    switch (t2)
    {
    case '+':
    case '-':
        if (t1 == '(' || t1 == '#')
            f = '<';
        else
            f = '>';
        break;
    case '*':
    case '/':
        if (t1 == '*' || t1 == '/' || t1 == ')')
            f = '>';
        else
            f = '<';
        break;
    case '(':
        // if (t1 == ')')
        //     return ERROR;
        // else
        f = '<';
        break;
    case ')':
        switch (t1)
        {
        case '(':
            f = '=';
            break;
        // case '#':
        //     return ERROR;
        //     break;
        default:
            f = '>';
        }
        break;
    case '#':
        switch (t1)
        {
        case '#':
            f = '=';
            break;
        // case '(':
        //     return ERROR;
        //     break;
        default:
            f = '>';
        }
        break;
    }
    return f;
}

int main()
{
    char str[500];
    //memset(0,sizeof(str));
    cin >> str;
    s2.push('#'); //OPR
    //str[strlen(str)]='#';
    for (int i = 0; i < strlen(str); i++)
    {
        if (isValue(str[i]))
        {
            //s1.push(str[i]);
            cout << str[i];
        }
        else if (pro(s2.top(), str[i]) == '<') //判断栈顶的优先级与即将插入元素
        {
            s2.push(str[i]);
            //cout << "S2:" << str[i] << endl;
        }
        else if (pro(s2.top(), str[i]) == '>')
        {
            while (pro(s2.top(), str[i]) == '>')
            {
                char value = s2.top();
                //s1.push(value);
                s2.pop();
                // s2.push(str[i]);
                //cout << "S1:" << value << endl;
                cout << value;
            }
            if (pro(s2.top(), str[i]) == '<')
                s2.push(str[i]);
            else if (pro(s2.top(), str[i]) == '=')
                s2.pop();
        }
        else
        {
            s2.pop();
        }
    }
    // cout << "Hello world" << endl;
    // while (s1.size())
    // {
    //     cout << s1.top() << endl;
    //     s1.pop();
    // }
    // cout << "Hello world" << endl;
    // while (s2.size())
    // {
    //     cout << s2.top() << endl;
    //     s2.pop();
    // }
    return 0;
}