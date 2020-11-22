/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-11-19 20:09:20
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */


#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int match(string origin, string pattern)
{
    for (int i = 0; i < origin.length(); i++)
    {
        // cout << i << endl;
        // int cmp = i;
        for (int j = 0, k = i; j <pattern.length(); j++)
        {
            if (origin[k] == pattern[j])
            {
                k++;
                if ( j == pattern.length()-1)
                {
                    return i;
                }
            }
            else
            {
                break;
            }
            
        }
        
    }
    return -1;
}
int main()
{
    cout << match("asdfghj", "fgh") << endl;
    return 0;
}