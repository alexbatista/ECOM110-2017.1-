#include "circularBuffer.h"
#include <stdio.h>

void cb_init(circular_buffer *cb, size_t capacity, size_t sz)
{
    cb->buffer = malloc(capacity * sz);
    if(cb->buffer == NULL){
        // handle error
			printf("Error no malloc\n");			
		}

    cb->buffer_end = (char *)cb->buffer + capacity * sz;
    cb->capacity = capacity;
    cb->count = 0;
    cb->sz = sz;
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
}

void cb_free(circular_buffer *cb)
{
	free(cb->buffer);
	free(cb->buffer_end);
	free(cb->head);
	free(cb->tail);
	free(cb);
    // clear out other fields too, just to be safe
}

status cb_push_back(circular_buffer *cb, const void *item)
{
	status statusRingBuffer;
    if(cb->count == cb->capacity){
        printf("The ring buffer is full\n");
		statusRingBuffer = FULL;
    }else{
		statusRingBuffer = NORMAL;
	}
    memcpy(cb->head, item, cb->sz);
    cb->head = (char*)cb->head + cb->sz;
    if(cb->head == cb->buffer_end)
        cb->head = cb->buffer;
    cb->count++;

	return statusRingBuffer;
}

status cb_pop_front(circular_buffer *cb, void *item)
{
	status statusRingBuffer;

    if(cb->count == 0){
		statusRingBuffer = EMPTY;
        // handle error
    }else{
		statusRingBuffer = NORMAL;
	} //TODO Treat errors here when the buffer is empty!
    memcpy(item, cb->tail, cb->sz);
    cb->tail = (char*)cb->tail + cb->sz;
    if(cb->tail == cb->buffer_end)
        cb->tail = cb->buffer;
    cb->count--;

	return statusRingBuffer;
}

/*void printRingBufferInteger(int a[],circular_buffer *cb){
	memcpy(a,cb,sizeof(int));
	for(int j = 0; j < sizeof(a); j++){
		printf("array[%d]: %d",j,a[j]);
	}
}
*/
