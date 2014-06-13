//
//  main.m
//  DataStructureAndAlgorithm
//
//  Created by hepeilin on 13-12-12.
//  Copyright (c) 2013年 minfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "LinearList.h"

int main(int argc, const char * argv[])
{
    
    SNode  *nodeA = initSnode();
    SNode  *nodeB = initSnode();
    SNode  *nodeC = NULL;
    mergeList(*nodeA, *nodeB, nodeC);
    showSnode(nodeC);
	
    /*
    insertSnode(nodeA, 4, 12);
    showSnode(nodeA);
    */
    
    
    /*

    SNode  *nodeB = initSnode();
    SNode  *nodeC = NULL;
    mergeList(*nodeA, *nodeB, nodeC);
    showSnode(nodeC);
     
*/
    return 0;
}

