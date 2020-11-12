/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-11-12 20:37:30
 * @Description: 二叉树
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

typedef struct BitNode
{
    char data;
    BitNode *LChild, *RChild;
}*BitTree, BitNode;

// 先序创建二叉树
void CreatTree(BitTree &T)
{
    T = NULL;
    char data;
    cin >> data;
    if (data == '@')
    {
        T = NULL;
        // return ;
    }
    else
    {
        T = new BitNode;
        T->data = data;
        CreatTree(T->LChild);
        CreatTree(T->RChild);
    }
    return ;
}

// 中序遍历
void MidLogTree(BitTree T)
{
    if (T != NULL)
    {
        MidLogTree(T->LChild);
        cout << T->data << " ";
        MidLogTree(T->RChild);
    }
}

// 先序遍历
void PreLogTree(BitTree T)
{
    if (T != NULL)
    {
        cout << T->data << " ";
        PreLogTree(T->LChild);
        PreLogTree(T->RChild);
    }
}

// 后序遍历
void BeLogTree(BitTree T)
{
    if (T != NULL)
    {
        BeLogTree(T->LChild);
        BeLogTree(T->RChild);
        cout << T->data;
    }
}

// 求树高度
int HeiTree(BitTree T)
{
    if (T == NULL) return 0;
    else
    {
        int m = HeiTree(T->LChild);
        int n = HeiTree(T->RChild);

        return max(m, n) + 1;
    }
}

// 复制树
void CopyBitTree(BitTree &T, BitTree &NewT)
{
    if (T == NULL)
    {
        NewT = NULL;
        return ;
    }
    else
    {
        NewT = new BitNode;
        NewT->data = T->data;
        CopyBitTree(T->LChild, NewT->LChild);
        CopyBitTree(T->RChild, NewT->RChild);
    }
}

// 计算节点数
int CountBitTree(BitTree T)
{
    if (T == NULL) return 0;
    else return CountBitTree(T->LChild) + CountBitTree(T->RChild) + 1;
}

// 计算叶子节点数
int CountBitTreeLeaves(BitTree T)
{
    if (T == NULL) return 0;
    if (T->LChild == NULL && T->RChild == NULL) return 1;

    return CountBitTreeLeaves(T->LChild) + CountBitTreeLeaves(T->RChild);
}

int main()
{
    // Sample Input: ABD@@E@@CF@@G@@
    BitTree T = new BitNode;
    CreatTree(T);
    // PreLogTree(T);
    // cout << endl;
    // MidLogTree(T);
    // cout << endl;
    // cout << CountBitTree(T) << endl;
    // cout << HeiTree(T) << endl;
    // BeLogTree(T);
    cout << CountBitTreeLeaves(T);
    return 0;
}

