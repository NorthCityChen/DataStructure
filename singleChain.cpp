/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-20 09:17:58
 * @Website: https://grimoire.cn
 * @Description: 单链表
 * @Copyright 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode{
    int data;
    LNode *next;
}*LinkList, LNode;

LinkList creatList(int len)
{
    // 尾插法创建链表
    LinkList Head = new LNode;
    LinkList Tail = new LNode;
    Head -> next = NULL; Tail = Head;

    while (len--)
    {
        LinkList node = new LNode;
        cin >> node -> data;
        node -> next = NULL;
        Tail -> next = node;
        Tail = node;
    }
    return Head;
}

LinkList creatListTail(int len)
{
    // 头插法创建单链表
    LinkList Head = new LNode;
    Head -> next = NULL;
    while(len--)
    {
        LinkList node = new LNode;
        cin >> node -> data;
        node -> next = Head -> next;
        Head -> next = node;
    }
    return Head;
}

void print(LinkList L)
{
    while (L -> next)
    {
        L = L -> next;
        printf("%d ", L -> data);
    }
    cout << endl;
    return ;
}

int getElem(LinkList Head, int index)
{
    // 头结点作为零号节点
    while (index-- && Head -> next)
        Head = Head -> next;
    if (index != -1) return -1;
    return Head -> data;
}

void insertList(LinkList &L, int index, int value)
{
    // 在index插入value
    LinkList s = L;
    index--; 
    // 这里提前自减是为了寻找插入点前面一个节点
    while (index-- && s -> next)
        s = s -> next;
    if (index != -1) return ;

    LinkList node = new LNode;
    node -> data = value;
    node -> next = s -> next;
    s -> next = node;

    return ;
}

void deleteListNode(LinkList &L, int index)
{
    LinkList s = L;
    index--; 
    // 这里提前自减是为了寻找插入点前面一个节点
    while (index-- && s -> next)
        s = s -> next;
    if (index != -1) return ;

    LinkList d = s -> next;
    s -> next = d -> next;
    delete d;
    return ;
}

int main()
{
    LinkList L = creatList(5);
    // LinkList L = creatListTail(5);
    print(L);
    // insertList(L, 5, 99);
    deleteListNode(L, 3);
    print(L);
    // cout << getElem(L, -2) << endl;
    return 0;
}