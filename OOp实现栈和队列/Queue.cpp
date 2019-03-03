#include "Queue.h"



static int IsFull(pQueue que)
{
	assert(que != NULL);

	if ((que->tail + 1) % SIZE == que->head)
	{
		return TRUE;
	}

	return FALSE;
}

static int IsEmpty(pQueue que)
{
	assert(que != NULL);

	if (que->head == que->tail)
	{
		return TRUE;
	}

	return FALSE;
}



void InitQueue(pQueue que)
{
	assert(que != NULL);

	que->data = (ElemType*)malloc(sizeof(ElemType)* SIZE);
	assert(que->data != NULL);

	que->head = que->tail = 0;
}


int PushQue(pQueue que, ElemType val)
{
	assert(que != NULL);

	if (IsFull(que))
	{
		return FALSE;
	}

	que->data[que->tail++] = val;
	que->tail %= SIZE;

	return TRUE;
}

int PopQue(pQueue que, ElemType *res)
{
	assert(que != NULL && que->data != NULL);

	if (IsEmpty(que))
	{
		return FALSE;
	}

	*res = que->data[que->head++];
	que->head %= SIZE;

	return TRUE;
}

void DestroyQue(pQueue que)
{
	assert(que != NULL);

	free(que->data);
	que->data = NULL;
	que->head = que->tail = 0;
}