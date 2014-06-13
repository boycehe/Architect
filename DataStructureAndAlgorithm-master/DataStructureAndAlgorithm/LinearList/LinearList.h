//
//  LinearList.h
//  DataStructureAndAlgorithm
//
//  Created by hepeilin on 13-12-12.
//  Copyright (c) 2013年 minfo. All rights reserved.
//

/*
    链表初始化中 带头结点的链表结构
    所有的方法都是按照这种结构来编写
 */

#ifndef DataStructureAndAlgorithm_LinearList_h
#define DataStructureAndAlgorithm_LinearList_h

#define ElemType int

typedef struct node
{
    ElemType       data;
    struct node    *next;
    
}SNode;
//初始化
SNode *init(int length);
//nodeA nodeB按非递减排列 归并后的nodeC也按非递减排列
void mergeList(SNode nodeA,SNode nodeB,SNode *nodeC);
SNode *getnum(SNode *snode,int num);
//演示方法
void linearListDemo();
//合并两张链表 nodeA链表 已经不再是原来的nodeA了
SNode *unionLinearList(SNode *nodeA,SNode *nodeB);
//初始化链表 头插法建立链表
SNode *initSnode();
//删除链表中的某个元素
SNode *delSnode(SNode *snode,int delpos);
//打印列表
void showSnode(SNode *snode);
//向链表中插入数据
SNode * insertSnode( SNode *snode, int i, ElemType num);
//根据元素查找相应的数据
SNode *locaSnode(SNode *snode,ElemType num);
//获取链表值
SNode * getnum(SNode *snode,int num);
//获取链表长度
int  length(SNode *snode);

#endif
