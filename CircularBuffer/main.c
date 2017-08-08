#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "circularBuffer.h"

#define TIME_WAIT_MS 100000
#define RB_CAPACITY 80
#define RB_SIZE 1


int main (){

	int finalArray[20] = {0};
	circular_buffer *cb = malloc(sizeof(circular_buffer));

	srand(time(NULL));
	int r = (int) rand(); // returns a pseudo-random integer between 0 and RAND_MAX
	
	
	cb_init(cb,RB_CAPACITY,RB_SIZE);	
	
	if(cb){
		printf("\n\nThe size of the circular buffer is %ld bytes\n\n\n",cb->capacity);

		printf("Generating values for the ring buffer...\n\n");
		while(cb_push_back(cb,&r) != FULL){
			r = (int) rand();
			printf("Putting %d in the ring buffer...\n",r);
			usleep(TIME_WAIT_MS);
		}

		memcpy(finalArray, cb->buffer, cb->capacity);

		printf("The content of the array in hex is\n");
		printf("====================================\n");
		for(int j=0; j < 20; j++){
			printf("finalArray[%d] = 0x%x\n",j,finalArray[j]);
		}

		printf("\nThe content of the ringBuffer in hex is\n");
		printf("====================================\n");
		for(int j=0; j < 20; j++){
			printf("ringBuffer[%d] = 0x%x\n",j,*((int *)cb->buffer+j));
		}
	}
	else{
		printf("Failure to alloc the circular buffer\n");
	}
	//cb_free(cb);
 return 0;
}
