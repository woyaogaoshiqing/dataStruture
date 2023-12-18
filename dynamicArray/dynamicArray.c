#include"dynamicArray.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*状态码*/
enum STATUS_CODE
{
    ON_SUCCCESS,
    NULL_PTR,
    MALLOC_ERROR,
};
#define DEFAULT_SIZE 10
/*动态数组的初始化*/
void dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    /*避免传入非法值*/
    if (pArray == NULL)
    {
        return 0;
    }
    if(capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }
    pArray->data = (ELEMENTTYPE * )malloc(sizeof(ELEMENTTYPE) * capacity);
    if(pArray-> data == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);
    /*初始化动态数组的参数属性*/
    pArray->data = 0;
    pArray->capacity = capacity;
}

/*动态数组插入数据(默认查到数组的末尾)*/
int dynamicArrayInserData(dynamicArray *pArray,ELEMENTTYPE val);

/*动态数组插入数组，在指定位置插入*/
int dynamicArrayAppointPosInserData(dynamicArray *pArray,ELEMENTTYPE val, int pos);

/*动态数组修改指定位置的数据*/
int dynamicArrayModifyAppointInserData(dynamicArray *pArray,ELEMENTTYPE val, int pos);

/*动态数组删除数据（默认情况下删除最后末尾的数据）*/
int dynamicArrayDeletData(dynamicArray *pArray);

/*动态数组删除指定位置数据*/
int dynamicArrayDeleAppointPosData(dynamicArray *pArray, int pos);

/*动态数组销毁*/
int dynamicArrayDestroy(dynamicArray *pArray);

/*动态数组删除指定的元素*/
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val);


/*获取大小*/
int dynamicArrayGetSize(dynamicArray *pArray, int * pSize);

/*获取容量*/
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity);