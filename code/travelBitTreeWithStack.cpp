/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-11-19 16:08:24
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
typedef struct BitThrNode
{
    char data;
    BitThrNode *LChild, *RChild;
    // bool LTag, RTag;
} BitThrNode, *BitThrTree;

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
        this->base = new T[MAXSIZE];
        this->top = 0;
    }
    ~StackNode()
    {
        this->top = 0;
    }
    T pop()
    {
        if (top < 1)
            return NULL;
        top--;
        return base[top];
    }

    void push(T value)
    {
        base[top] = value;
        top++;
    }
    int size()
    {
        return top;
    }
};

void travel(BitThrTree T)
{
    StackNode<BitThrTree> S;
    BitThrTree P = T;
    BitThrTree Q = new BitThrNode;
    while (P || S.size())
    {
        if (P){
            S.push(P);
            P = P->LChild;
        }
        else
        {
            Q = S.pop();
            cout << Q->data << " ";
            P = Q->RChild;
        }
    }
}

int main()
{
    BitThrTree T;
    CreatTree(T);
    travel(T);
    cout << endl;
    return 0;
}