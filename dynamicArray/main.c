#include<stdio.h>
#include"dynamicArray.h"
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 20
#define DEFAULT_NUM 5

typedef struct stuInfo
{
    int age;
    char sex;
}stuInfo;




int main()
{
    /*静态数组:1.不够灵活2.可能会有浪费的情况*/
    dynamicArray array;
    /*初始化*/
    dynamicArrayInit(&array, BUFFER_SIZE);
#if 0
    /*插入数组*/
    dynamicArrayInserData(&array, 3);
    for (int idx = 1; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInserData(&array, 21);
    }

    /*获取动态数组大小*/
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n", size);

    int val = 0;
    for (int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx &val);
        printf("size:%d\n", val);
    }

    /*删除指定*/
    dynamicArrayDeletData(&array);


    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n", size);

    val = 0;
    for (int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx &val);
        printf("size:%d\n", val);
    }
#elif 0

    int buffer[DEFAULT_NUM] = {1, 2, 3};
    for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInserData(&array, (void *)&buffer[idx]);
        
    }
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n", size);

    int *val = NULL;
    for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val:%d\n", *val);
    }
#elif 0
    int idx = 0;
   for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInserData(&array, (void *)&buffer[idx]);
        
    }
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n", size);

    int *val = NULL;
    for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val:%d\n", *val); 
    }





#endif


    stuInfo stu1, stu2,stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'm';

    stu3.age = 30;
    stu3.sex = 'f';

    stuInfo buffer[DEFAULT_NUM] = {stu1, stu2, stu3};
    for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInserData(&array, (void *) &buffer[idx]);
    }
   

    int size = 0;
    dynamicArrayInserData(&array, &size);
    printf("size:%d\n", size);

    stuInfo info;
    for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&info);
        printf("info.age:%d\tinfo.sex%d\n",info.age, info.sex);
    }
    return 0;
}