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
    INVALID_ACCESS,
};
#define DEFAULT_SIZE 10
/*静态函数前置声明*/
static int expandDyanmicCapacity(dynamicArray *pArray);
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
    /*分配空间*/
    pArray->data = (ELEMENTTYPE * )malloc(sizeof(ELEMENTTYPE) * capacity);
    if(pArray-> data == NULL)
    {
        return MALLOC_ERROR;
    }
    /*清除脏数据*/
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);
    /*初始化动态数组的参数属性*/
    pArray->data = 0;
    pArray->capacity = capacity;
}

/*动态数组插入数据(默认查到数组的末尾)*/
int dynamicArrayInserData(dynamicArray *pArray,ELEMENTTYPE val)
{

    return dynamicArrayAppointPosInserData(pArray, pArray->len, val);
}
/*动态数组扩容*/
static int expandDyanmicCapacity(dynamicArray *pArray)
{
    int ret = 0;
    int needexpandCapacity = pArray->capacity + (pArray->capacity >> 1);

    ELEMENTTYPE * tmpPtr = pArray->data;
    pArray->data = malloc(sizeof(ELEMENTTYPE) * needexpandCapacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    /*把之前的数据全部拷贝过来*/
    for (int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }
    /*释放以前的内容，避免内存泄漏*/
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }
    /*更新动态数组的容量*/
    pArray->capacity = needexpandCapacity;
    return ret;
}
/*动态数组插入数组，在指定位置插入*/
int dynamicArrayAppointPosInserData(dynamicArray *pArray,ELEMENTTYPE val, int pos)
{
    /*判断指针为空*/
    if (pArray == NULL)
    {
        return NULL_PTR;
    }
    /*判断位置的合法性*/
    if (pos < 0 ||pos > pArray->len)
    {
        return INVALID_ACCESS;
    }
    /*数组扩容的临界值：数组大小的1.5倍开始扩容*/
    if (pArray->len  +(pArray->len >> 1) >= pArray->capacity)
    {
        /*开始扩容*/
        expandDyanmicCapacity(pArray);
    }
    for (int idx = pArray->len; idx < pos; idx--)
    {
        pArray->data[idx + 1] = pArray->data[idx];
    }
    
    
    /*找打对应的值，填入数组中*/
    pArray->data[pos] = val;
    /*数组的大小加一*/
    (pArray->len)++;
    return ON_SUCCCESS;
}

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