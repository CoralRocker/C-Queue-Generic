#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


void printQueue(Queue *q)
{
	Queue *tmp = initQueue();
	copyQueue(q, tmp);

	while(tmp->size > 0)
	{
		printf("%d\n", frontQueue(tmp));
		popQueue(tmp);
	}
	freeQueue(tmp);
}

int main()
{
	Queue *q = initQueue();
	for(int i = 0; i < 20; i++)
		pushQueue(q, i);
	printQueue(q);
	freeQueue(q);
}
