/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-11-19 21:33:06
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include<bits/stdc++.h>
using namespace std;
int* get_next(string pattern)
{
    //get next array and return a point
    int size=pattern.length();
    int* next=new int[size];
    //动态申请一块空间
    next[0]=-1;
    //给零号位初始化为-1，当零号位不能匹配时整体后移一位
    int j=0,k=-1;
    while (j<pattern.length()-1)
    {
        if (k==-1||pattern[j]==pattern[k])
        {
            if (pattern[++j]==pattern[++k])
            {
                next[j]=next[k];
            }
            else next[j]=k;
        }
        else k=next[k];
    }
    return next;
}

int KMP(string cmp, string pattern)
{ 
    if(pattern == "") 
        return 0; 
    
    int* next = get_next(pattern);
    for (int i = 0; i < pattern.length(); i++)
    {
        cout << next[i] << " ";
    }
    cout << endl;

    int i=0;
    int j=0; 
    int cnt=0;
    while(i < int(cmp.length()) && (j < int(pattern.length())))
    {
        if(j == -1 || cmp[i] == pattern[j])
        {
            i++;j++; 
        }
        else
        {
            j = next[j];
        }
        cnt++;
    }
    cout<<"cnt="<<cnt<<endl;
    if(j == pattern.length())
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
    string cmp,pattern;
    int number1,number2;
    cin>>cmp>>pattern;
    cout<<KMP(cmp,pattern);
    return 0;
}