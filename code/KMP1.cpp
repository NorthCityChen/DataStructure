/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-11-19 21:49:01
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

// int nextVal[N];

int* getNext(string pattern)
{
    // memset(nextVal, 0, sizeof(nextVal));
    int* nextVal = new int[N];

    int k = -1, i = 0;
    nextVal[0] = -1;

    while (i < pattern.length() - 1)
    {
        if (k == -1 || pattern[i] == pattern[k])
        {
            if (pattern[++i] == pattern[++k])
            {
                nextVal[i] = nextVal[k];
            }
            else nextVal[i] = k;
        }
        else k = nextVal[k];
    }
    return nextVal;
}

int KMP(string cmp, string pattern)
{
    if (pattern == "") return 0;
    int *nextVal = getNext(pattern);
    for (int i = 0; i<pattern.length(); i++)
    {
        cout << nextVal[i] << " ";
    }
    cout << endl;
    int i = 0, j = 0, cnt = 0;
    // 这里把 cmp.length() 转换为 int 型是因为cmp.length 
    // 返回的是unsigned long 型 不能和负数做比较
    while (i < int(cmp.length()) && j < int(pattern.length()))
    {
        if (j == -1 || cmp[i] == pattern[j])
        {
            j++, i++;
        }
        else
        {
            j = nextVal[j];
        }
        cnt++;
    }
    cout << "CNT:" << cnt << endl;
    if (j == pattern.length())
    {
        return i-j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string cmp, pattern;
    cin >>  cmp >> pattern;
    cout << KMP(cmp, pattern) << endl;
    // int *NextVal = getNext(pattern);
    // for (int i =0 ; i<pattern.length();i++)
    // {
    //     cout << NextVal[i] << " ";
    // }
    cout << endl;
    return 0;
}