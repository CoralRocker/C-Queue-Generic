# C-Queue

# Accessor Methods
|Method|Usage|
|:-:|:-|
|int frontQueue(Queue *q)|frontQueue(q) where q is the Queue object. Returns the first object in the Queue.|
|int backQueue(Queue *q)|backQueue(q) where q is the Queue object. Returns the last object in the Queue.|
|Direct Access|q->arr[index] where q is the Queue object and index is th index of the value you wish to retrieve.|
|int size|q->size where q is the Queue object. Is the variable holding the size of the Queue.|

# Modifier Methods
|Method|Usage|
|:-:|:-|
|void pushQueue(Queue *q, int val)|pushQueue(q, num) where q is the Queue object, and num is the value to insert. Inserts given value into a new element in the back of the Queue.|
|void popQueue(Queue *q)|popQueue(q) where q is the Queue object. Removes the first element in the Queue.|
|void copyQueue(Queue *src, Queue *dst)|copyQueue(q1, q2) where q1 and q2 are both Queue objects. The contents of q1 are copied to q2.|

