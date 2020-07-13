# q

A few C++ queue implementations. I'm writing these as a little exercise for myself, that's all. 

## ArrayQueue

An array is used to store all the values of the queue. For this, an index keeps track of the index of the next free space.
This means that it points past the end if the array is not large enough. In that case the size of the array is doubled on the
next enqueue call.

```
array: [   ]
index:   ^

-> enqueue 5
array: [ 5 ]
index:     ^

-> enqueue 7
array: [ 5 7 ]
index:       ^

-> enqueue 2
array: [ 5 7 2 _ ]
index:         ^

-> enqueue 1
array: [ 5 7 2 1 ]
index:           ^
```

## LinkedListQueue

Just uses a linked list.
