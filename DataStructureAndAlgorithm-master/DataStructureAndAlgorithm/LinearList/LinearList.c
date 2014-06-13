//
//  LinearList.c
//  DataStructureAndAlgorithm
//
//  Created by hepeilin on 13-12-12.
//  Copyright (c) 2013年 minfo. All rights reserved.
//

#include <stdio.h>
#include "LinearList.h"
#include<stdlib.h>


void linearListDemo()
{
    int location = 0;
    ElemType    data = 0;
    
    printf("开始初始化数组\n");
    SNode *node = initSnode();
    printf("链表长度为:%d\n",length(node));
    printf("链表内容为:\n");
    showSnode(node);
    printf("请输入位置以查询链表的值:\n");
    scanf("%d",&location);
    SNode *locNode = getnum(node, location);
    printf("查询的链表的值为=%d\n",locNode->data);
    
    printf("请输入要查找的元素：");
    scanf("%d",&data);
    SNode *daNode = locaSnode(node, data);
    if (daNode != NULL) {
        printf("查找成功");
    }
    
    do {
        printf("向链表中插入数据\n");
        printf("请输入插入的位置:");
        scanf("%d",&location);
        printf("请输入插入的内容:");
        scanf("%d",&data);
    } while (insertSnode(node, location, data) == NULL);
    
    
    printf("向链表中删除数据\n");
    printf("请输入删除的位置:");
    scanf("%d",&location);
    delSnode(node, location);
    
}


//nodeA nodeB按非递减排列 归并后的nodeC也按非递减排列
void mergeList(SNode nodeA,SNode nodeB,SNode *nodeC)
{
   
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    int lenA = length(&nodeA);
    int lenB = length(&nodeB);
    
    printf("nodeA长度为=%d,nodeB长度为=%d",lenA,lenB);
    
    nodeC = (SNode*)malloc(sizeof(SNode));
    nodeC->data=0;
    nodeC->next = NULL;
      
    
    while (i < lenA && j < lenB)
    {
        SNode *data1 = getnum(&nodeA, i);
        SNode *data2 = getnum(&nodeB, j);
        
        if (data1->data < data2->data) {
            
            printf("插入的值为=%d",data1->data);
            insertSnode(nodeC, k, data1->data);
                k++;
                i++;
            
        }
        else
        {
            printf("插入的值为=%d",data2->data);

             insertSnode(nodeC,k, data2->data);
                k++;
                j++;
        }
        
    }
    
    
    while (i < lenA) {
            SNode *data1 = getnum(&nodeA, i);
            insertSnode(nodeC, k++, data1->data);
            i++;
    }
    
    while (j < lenB) {
            SNode *data2 = getnum(&nodeB, j);
            insertSnode(nodeC, k++, data2->data);
            j++;
    }
    
    printf("---%d\n",nodeC->data);
    showSnode(nodeC);
 
}

//合并两张链表
SNode *unionLinearList(SNode *nodeA,SNode *nodeB)
{
    if (nodeA == NULL || nodeB == NULL) {
        printf("链表有一个为空");
        return NULL;
    }
    
    SNode						*node;
	node = nodeA;
    
    while (node->next != NULL) {
       node=node->next;
    }

    node->next = nodeB;
   
    return nodeA;
    
}

//初始化链表 头插法建立链表
SNode *initSnode()
{
    SNode									*initSnode = NULL;
	SNode									*initSnodeHead = NULL;
	SNode									*initSnodeTemp = NULL;
    int											 i = 0;
	ElemType                                     initData = 0;
	int										     len = 0;
	int											 type = 0;
	initSnode = (SNode *)malloc(sizeof(SNode));
	initSnodeHead = initSnode;
    if(initSnode == NULL)
	{
		printf("链表初始化不成功！\n");
		getchar();
		getchar();
		exit(0);
	}
	initSnode -> next = NULL;
	initSnode -> data = 0;
    printf("输入0则用头插法建立链表，输入1则用尾插法建立链表！");
    scanf("%d",&type);
    switch(type)
    {
        case 0:
            printf("\n请输入链表的长度:");
            scanf("%d",&len);
            for(i = 0;i < len;i++)
            {
                initSnodeTemp = (SNode *)malloc(sizeof(SNode));
                if(initSnodeTemp == NULL)
                {
					printf("分配空间失败\n");
					getchar();
				    getchar();
				    exit(0);
                }
                printf("请输入数据第%d个数据=",i+1);
                scanf("%d",&initData);
                initSnodeTemp -> data = initData;
                initSnodeTemp -> next= initSnode -> next; //使用头插法建立链表
                initSnode -> next = initSnodeTemp;
            }
            break;
            
        case 1:
            printf("\n请输入链表的长度:");
            scanf("%d",&len);
            for(i = 0;i < len;i++)
            {
                initSnodeTemp = (SNode *)malloc(sizeof(SNode));
                if(initSnodeTemp == NULL)
                {
					printf("分配空间失败\n");
					getchar();
				    getchar();
				    exit(0);
                }
                printf("请输入数据第%d个数据=",i+1);
                scanf("%d",&initData);
                initSnodeTemp -> data = initData;
                initSnode -> next = initSnodeTemp ;//使用尾插法建立链表	
                initSnode = initSnodeTemp;
            }
            initSnode -> next = NULL;
            break;
        default:
            printf("\n你输入了非法的数字");
            return NULL;
            
    }
    
	return initSnodeHead;
    
}

SNode *init(int length)
{
    SNode  *head=NULL;
    SNode  *body=NULL;
    head = (SNode*)malloc(sizeof(SNode));
    head->data = 0;
    head->next = NULL;
    
    for (int i = 0; i <= length; i++)
    {
        SNode *tmp = (SNode *)malloc(sizeof(SNode));
        tmp  -> data = 0;
        tmp -> next = body;//使用尾插法建立链表
        body = tmp;
       

    }
      head -> next = body;
    return head;
}

//获取链表长度
int  length(SNode *snode)
{
	SNode                             *lenSnode  = NULL;
	int								  len = 0;
    
    
	lenSnode = snode->next;
    
    while (lenSnode != NULL) {
        
         lenSnode = lenSnode->next;
         len++;
    }

    
    
	return len;
}

//获取链表值
/* 0 获取第一个值 以此类推*/
SNode * getnum(SNode *snode,int num)
{
	int									len  = 0;
	int									getnum = 0;
    SNode                               *tmpNode = NULL;
    tmpNode = snode;
	len = length(snode);
	if(num<0||num>len)
	{
		printf("要查找的位置不对！\n");
		return  NULL;
	}
	if(len == 0)
	{
		printf("要查找的表示空表！\n");
		return NULL;
	}
    
    tmpNode = tmpNode->next;
    
	for(getnum = 0;getnum < num;getnum++)
	{
		tmpNode = tmpNode ->next;
	}
	return tmpNode;
    
}


//根据元素查找相应的数据
SNode *locaSnode(SNode *snode,ElemType num)
{
	SNode							*locaSnode   = NULL;
	locaSnode = snode -> next;
	while(locaSnode !=NULL)
	{
		if(locaSnode ->data == num)
			return  locaSnode;
		locaSnode  = locaSnode -> next;
	}
	
    return NULL;
	
}

//向链表中插入数据
SNode * insertSnode( SNode *snode, int i, ElemType num)
{
	SNode					*insertSnode = NULL;
	SNode					*insertSnodePos = NULL;
	//SNode					*insertSnodeData = NULL;
    
	int                             len = 0;
	int								insertpos = 0;
	insertSnode = snode ;
	len = length(snode);
	if(i<0||i>len)
	{
		printf("要插入的位置不正确！\n");
		return snode;
	}
	// insertSnodeData = locaSnode(snode,num);
    
    /*
	if(insertSnodeData != NULL &&insertSnodeData->data == num)
	{
		printf("要插入的数据已经存在！\n");
		getchar();
		getchar();
		return snode;
	};
     */

    
	for(insertpos=0;insertpos < i;insertpos++)
	{
		insertSnode = insertSnode->next;
	}
	insertSnodePos =(SNode *)malloc(sizeof(SNode));
	insertSnodePos->data = num;
	insertSnodePos ->next =insertSnode -> next;
	insertSnode ->next = insertSnodePos;
	return snode;
    
    
}

//删除链表中的某个元素
SNode *delSnode(SNode *snode,int delpos)
{
	SNode								*delSnode = NULL;
	SNode								*tempSnode = NULL;
	int										len = 0;
	int										i = 0;
	delSnode = snode;
	len = length(snode);
	if(delpos<0||delpos>len)
	{
		printf("删除位置不合法！\n");
		return snode;
	}
	for(i=0;i < delpos;i++)
	{
		tempSnode = delSnode;
		delSnode = delSnode->next;
	}
	tempSnode->next = delSnode -> next;
	free(delSnode);
    printf("删除成功！\n");
	return snode;
}

//打印链表
void showSnode(SNode *snode)
{
    //当用此函数来显示使用头插法创建的链表时候 会不正确显示，原因在于头插法链表创建的方法导致这个问题
 
    if (snode == NULL) {
        printf("链表为空值，无法打印");
        return;
    }
    
	SNode						*showSnode = NULL;
	showSnode = snode->next;
	if(showSnode == NULL)
	{
		printf("要显示的链表为空\n");
		getchar();
		getchar();
		exit(0);
	}
	while(showSnode !=NULL)
	{
		printf("%d\n",showSnode->data);
		showSnode = showSnode ->next;
	}
    
}



