#ifndef __QUEUE_H
#define __QUEUE_H


#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int  ElemType;

#define SIZE 10
#define TRUE 1
#define FALSE 0


typedef struct queue
{
	ElemType *data;
	int head;
	int tail;
}queue, *pQueue;

void InitQueue(pQueue que);

int PushQue(pQueue que, ElemType val);

int PopQue(pQueue que, ElemType *res);

void DestroyQue(pQueue que);




#endif