#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_
/*避免头文件重复包含*/
typedef int ELEMENTTYPE;

typedef struct dynamicArray
{
    ELEMENTTYPE * data;     /*数组的空间*/
    int len;                /*数组的大小*/
    int capacity;           /*数组的容量*/
}dynamicArray;


/*API application program interface*/
/*动态数组的初始化*/
void dynamicArrayInit();

/*动态数组插入数据(默认查到数组的末尾)*/
int dynamicArrayInserData();

/*动态数组插入数组，在指定位置插入*/
int dynamicArrayAppointInserData();

/*动态数组修改指定位置的数据*/
int dynamicArrayModifyAppointInserData();

/*动态数组删除数据（默认情况下删除最后末尾的数据）*/
int dynamicArrayDeletData();

/*动态数组删除指定位置数据*/
int dynamicArrayDeleAppointPosData();

/*动态数组销毁*/
int dynamicArrayDestroy();

/*获取大小*/
int dynamicArrayGetSize();

/*获取容量*/
int dynamicArrayGetCapacity();



#endif// __DYNAMIC_ARRAY_H_