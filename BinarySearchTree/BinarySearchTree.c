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
    /*初始化树*/
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
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
#if 0
    if (val1 < val2)
    {
        return -1;
    }
    else if()
    {

    }
#endif
}
/*二叉搜索树的插入*/
int BinarySearchTreeInser(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;
    if (pBstree->size == 0)
    {
        /*更新树节点*/
        (pBstree->size)++;
        pBstree->root->data = val;
        return ret;
    }
    /*指向根节点*/
    BSTreeNode * traveNode = pBstree->root;
    BSTreeNode * parentNode = pBstree->root;
    int cmp = 0;
    while (traveNode->data != NULL)
    {
        /*标记父节点*/
        parentNode = traveNode;
        cmp = val - traveNode->data;
        if (cmp < 0)
        {
            traveNode = traveNode->left;
        }
        if (cmp > 0)
        {
            traveNode = traveNode->right;
        }
        else
        {
            /*插入元素 = 遍历到的节点*/
            return ret;
        }
    }
    /**/
    BSTreeNode * newBstNode = malloc(sizeof(BSTreeNode) * 1);
    if (newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL; 
    }
    newBstNode->data = val;
    if (cmp < 0)
    {
        parentNode->left = newBstNode;
    }
    else
    {
        parentNode->right = newBstNode;
    }
    (pBstree->size)++;
    return ret;
}