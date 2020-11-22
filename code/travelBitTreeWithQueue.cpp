/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-11-19 16:30:32
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <iostream> 
#include <queue> // 引入队列头文件
using namespace std;
typedef struct Bnode /* 定义二叉树存储结构 */
{
    char data;
    struct Bnode *lchild, *rchild;
} Bnode, *Btree;
void Createtree(Btree &T) /* 创建二叉树函数 */
{                         // 按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树
    char ch;
    cin >> ch;
    if (ch == '@')
        T = NULL; // 递归结束，建空树
    else
    {
        T = new Bnode;
        T->data = ch;          // 生成根结点
        Createtree(T->lchild); // 递归创建左子树
        Createtree(T->rchild); // 递归创建右子树
    }
    return;
}
bool Leveltaverse(Btree T)
{
    Btree p;
    if (!T)
        return false;
    queue<Btree> Q;
    // 创建一个普通队列 (先进先出)，里面存放指针类型
    Q.push(T);         // 根指针入队
    while (!Q.empty()) // 如果队列不空
    {
        p = Q.front(); // 取出队头元素
        Q.pop();       // 队头元素出队
        cout << p->data;
        if (p->lchild)
            Q.push(p->lchild); // 左孩子指针入队
        if (p->rchild)
            Q.push(p->rchild); // 右孩子指针入队
    }
    return true;
}
int main()
{
    Btree mytree;
    Createtree(mytree);   // 创建二叉树
    Leveltaverse(mytree); // 层次遍历二叉树 r
    return 0;
}