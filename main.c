#include <stdio.h>
#include <stdlib.h>
#include "circularBuffer.h"

int main (){

	int finalArray[20];
	circular_buffer *cb = malloc(sizeof(circular_buffer));

	srand(time(NULL));
	char r = (char) rand(); // returns a pseudo-random integer between 0 and RAND_MAX
	
	
	cb_init(cb,80,1);	
	
	if(cb){
		printf("The size of the circular buffer is %ld\n",cb->capacity);
	}
	else{
		printf("Failure to alloc the circular buffer\n");
	}

	while(cb_push_back(cb,&r) != FULL){
		r = (char) rand();
		printf("The value of r is %d\n",r);
	}

	memcpy(finalArray, cb->buffer, cb->capacity);

	printf("The content of the array in hex is\n");
	for(int j=0; j < sizeof(finalArray); j++){
		printf("finalArray[%d] = 0x%x\n",j,finalArray[j]);
	}
	
	printf("The content of the ring Buffer is\n");
        for(int i=0; i < cb->capacity; i++){
               // printf("cb at %d = %x\n",i,*(*(cb->head+i)));
        }

	
	cb_free(cb);
 return 0;
}
