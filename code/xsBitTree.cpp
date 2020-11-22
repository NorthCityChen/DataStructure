/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-11-17 20:49:56
 * @Description: 
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
} * BitTree, BitNode;

typedef struct BitThrNode
{
    char data;
    BitThrNode *LChild, *RChild;
    bool LTag, RTag;
} BitThrNode, *BitThrTree;

BitThrTree Pre = NULL;

void MidLogTree(BitThrTree T)
{
    if (T != NULL)
    {
        MidLogTree(T->LChild);
        cout << T->data << " ";
        MidLogTree(T->RChild);
    }
    // cout << endl;
}

void CreatTree(BitThrTree &T)
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
        T = new BitThrNode;
        T->data = data;
        CreatTree(T->LChild);
        CreatTree(T->RChild);
    }
    return;
}

void change(BitThrTree T)
{
    if (T)
    {
        change(T->LChild);
        if (!T->LChild)
        {
            T->LChild = Pre;
            T->LTag = true;
        }
        else
        {
            T->LTag = false;
        }
        if (!Pre->RChild)
        {
            Pre->RTag = true;
            Pre->RChild = T;
        }
        else
        {
            Pre->RTag = false;
        }
        Pre = T;
        change(T->RChild);
    }
    return;
}

void InOrderThreading(BitThrTree &Thrt, BitThrTree T)
{
    Thrt = new BitThrNode;
    Thrt->LTag = false;
    Thrt->RTag = true;
    Thrt->RChild = Thrt;

    if (!T)
    {
        Thrt->LChild = Thrt;
    }
    else
    {
        Thrt->LChild = T;
        Pre = Thrt;
        change(T);
        Pre->RChild = Thrt;
        Pre->RTag = true;
        Thrt->RChild = Pre;
    }
    return;
}

void print(BitThrTree T)
{
    BitThrTree p = T->LChild;
    while (p != T)
    {
        while (p->LTag == false)
            p = p->LChild;
        cout << p->data << " ";
        while (p->RTag == true && p->RChild != T)
        {
            p = p->RChild;
            cout << p->data << " ";
        }
        p = p->RChild;
    }
    cout << endl;
}

int main()
{
    // BitTree T = new BitNode;
    BitThrTree P = new BitThrNode;
    BitThrTree T = new BitThrNode;

    CreatTree(T);
    MidLogTree(T);
    cout << endl;
    InOrderThreading(P, T);
    print(P);
    
    return 0;
}