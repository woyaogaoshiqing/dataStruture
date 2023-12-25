#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#define ELEMENTTYPE int
typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode *left;       /*左子树*/
    struct BSTreeNode *right;      /*右子树*/

    struct BSTreeNode *parent;      /*父节点*/
}BSTreeNode;


typedef struct BinarySearchTree
{
    /*根节点*/
    BSTreeNode * root;
    /*树的节点*/
    int size;
}BinarySearchTree;

/*二叉搜索树的初始化*/
int BinarySearchTreeInit(BinarySearchTree **pBstree);

/*二叉搜索树的插入*/
int BinarySearchTreeInser(BinarySearchTree **pBstree, ELEMENTTYPE val);
#endif