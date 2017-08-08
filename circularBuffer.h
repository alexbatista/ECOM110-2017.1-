
#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

//#include <stdint.h>
//https://stackoverflow.com/questions/827691/how-do-you-implement-a-circular-buffer-in-c
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum{
	NORMAL,
	FULL,	
	EMPTY
} status;

typedef struct circular_buffer
{
    void *buffer;     // data buffer
    void *buffer_end; // end of data buffer
    size_t capacity;  // maximum number of items in the buffer
    size_t count;     // number of items in the buffer
    size_t sz;        // size of each item in the buffer
    void *head;       // pointer to head
    void *tail;       // pointer to tail
} circular_buffer;

void cb_init(circular_buffer *cb, size_t capacity, size_t sz);
void cb_free(circular_buffer *cb);
status cb_push_back(circular_buffer *cb, const void *item);
status cb_pop_front(circular_buffer *cb, void *item);

#endif
