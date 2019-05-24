#pragma once
#include <stdlib.h>
#include <string.h>

/* Struct to hold the Queue */
typedef struct Queue {
	void** arr;
	int size;
}Queue;

/* Initializes a Queue object so that all information stored therein is either NULL or zero.
 * Uses malloc to allocate memory for the Queue, so the freeQueue method be used to prevent memory
 * leaks.
 */
Queue* initQueue()
{
	Queue *q = malloc(sizeof(Queue));
	q->arr = NULL;
	q->size = 0;
	return q;
}

/* Free the Queue array and Queue itself.
 */
void freeQueue(Queue *q)
{
	free(q->arr);
	free(q);
}

/* Return the element in the front of the queue. (index 0)
 */
void* frontQueue(Queue *q)
{
	if(q->size > 0)
		return q->arr[0];
	return 0;
}

/* Return the last element in the queue. (index size-1)
 */
void* backQueue(Queue *q)
{
	if(q->size > 0)
		return q->arr[q->size-1];
	return 0;
}

/* Adds an element to the back of the queue
 */
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

/* Removes first element in queue.
 * WARNING: REMOVES FIRST ELEMENT, INSTEAD OF BACK ELEMENT!
 */
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

/* Copies the data from one Queue to another.
 */
void copyQueue(Queue *src, Queue *dst)
{
	free(dst->arr);
	dst->arr = (void**)malloc(sizeof(void*)*src->size);
	memcpy(dst->arr, src->arr, sizeof(void*)*src->size);
	dst->size = src->size;
}
