/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-22 19:52:48
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXQSIZE 1000 ///队列的最大长度
typedef int QElemType;
typedef struct
{
    QElemType *base;
    int front;
    int rear;
} SqQueue;
int InitQueue(SqQueue &Q)
{
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base)
        return 0;
    Q.front = Q.rear = 0;
    return 1;
}
int EnQueue(SqQueue &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return 0;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return 1;
}
int DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return 0;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return 1;
}
int GetQueue(SqQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return 0;
    e = Q.base[Q.front];
    return 1;
}
int main()
{
    int n;
    cin >> n;
    SqQueue Q;
    InitQueue(Q);
    //EnQueue(Q,0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << "  ";
        printf("%2d  ", 1);
        ///cout<<1<<"  ";
        for (int k = 3; k <= i; k++)
        {
            int x, e;
            DeQueue(Q, x);
            GetQueue(Q, e);
            EnQueue(Q, x + e);
            printf("%2d  ", x + e);
        }
        if (i != 1)
        {
            printf("%2d  ", 1);
        }
        EnQueue(Q, 1);
        cout << endl;
    }
    return 0;
}