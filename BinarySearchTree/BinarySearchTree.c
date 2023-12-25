#include"BinarySearchTree.h"
#include<stdio.h>
#include<stdlib.h>
enum STATUSCODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVAILD_ACCESS,
    NOT_FIND,
};
/*二叉搜索树的初始化*/
int BinarySearchTreeInit(BinarySearchTree **pBstree)
{
    int ret = 0;
    
    BinarySearchTree * bstree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree)*1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);
    {
    bstree->root = NULL;
    bstree->size = 0;
    }
    /*分配根节点*/
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);
    /*初始化根节点*/
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;
    }
    return ret;
}

/*二叉搜索树的插入*/
int BinarySearchTreeInser(BinarySearchTree **pBstree, ELEMENTTYPE val)
{

}