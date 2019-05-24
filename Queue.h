#pragma once
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
	void** arr;
	int size;
}Queue;

Queue* initQueue()
{
	Queue *q = malloc(sizeof(Queue));
	q->arr = NULL;
	q->size = 0;
	return q;
}

void freeQueue(Queue *q)
{
	free(q->arr);
	free(q);
}

void* frontQueue(Queue *q)
{
	if(q->size > 0)
		return q->arr[0];
	return 0;
}

void* backQueue(Queue *q)
{
	if(q->size > 0)
		return q->arr[q->size-1];
	return 0;
}

void pushQueue(Queue *q, void* val)
{
	void** tmp = malloc(sizeof(void*)*q->size);
	memcpy(tmp, q->arr, sizeof(void*)*q->size);
	free(q->arr);
	q->size++;
	q->arr = malloc(sizeof(void*)*q->size);
	memcpy(q->arr, tmp, sizeof(void*)*(q->size-1));
	free(tmp);
	q->arr[q->size-1] = val;
}

void popQueue(Queue *q)
{
	q->size--;
	void** tmp = malloc(sizeof(void*)*q->size);
	memcpy(tmp, q->arr + 1, sizeof(void*)*q->size);
	free(q->arr);
	q->arr = malloc(sizeof(void*)*q->size);
	memcpy(q->arr, tmp, sizeof(void*)*q->size);
	free(tmp);
}

void copyQueue(Queue *q1, Queue *q2)
{
	free(q2->arr);
	q2->arr = (void**)malloc(sizeof(void*)*q1->size);
	memcpy(q2->arr, q1->arr, sizeof(void*)*q1->size);
	q2->size = q1->size;

}
