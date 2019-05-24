#pragma once
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
	int* arr;
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

int frontQueue(Queue *q)
{
	if(q->size > 0)
		return q->arr[0];
	return 0;
}

int backQueue(Queue *q)
{
	if(q->size > 0)
		return q->arr[q->size-1];
	return 0;
}

void pushQueue(Queue *q, int val)
{
	int* tmp = malloc(sizeof(int)*q->size);
	memcpy(tmp, q->arr, sizeof(int)*q->size);
	free(q->arr);
	q->size++;
	q->arr = malloc(sizeof(int)*q->size);
	memcpy(q->arr, tmp, sizeof(int)*(q->size-1));
	free(tmp);
	q->arr[q->size-1] = val;
}

void popQueue(Queue *q)
{
	q->size--;
	int* tmp = malloc(sizeof(int)*q->size);
	memcpy(tmp, q->arr + 1, sizeof(int)*q->size);
	free(q->arr);
	q->arr = malloc(sizeof(int)*q->size);
	memcpy(q->arr, tmp, sizeof(int)*q->size);
	free(tmp);
}

void copyQueue(Queue *q1, Queue *q2)
{
	free(q2->arr);
	q2->arr = (int*)malloc(sizeof(int)*q1->size);
	memcpy(q2->arr, q1->arr, sizeof(int)*q1->size);
	q2->size = q1->size;

}
