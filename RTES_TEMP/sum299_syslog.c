#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>
#include <syslog.h>


static struct timespec current_time = {0, 0};

void* add_100_numbers (void* ptr)
{
	uint16_t* ptr_2 = (uint16_t*) ptr;
	uint8_t i = 0;
	uint32_t result=0;
	for(i=0;i<100;i++)
	{
		result += *(ptr_2+i);
	} 
	*(ptr_2+100) = result;
	return (void *)ptr_2+200;
}

void main()
{
	pthread_t thread_1,thread_2,thread_3;
	uint16_t array_1[101],array_2[101],array_3[101],counter=0;
	uint8_t i=0,ret_1=0,ret_2=0,ret_3=0;
	uint16_t result=0;
	void *sum_1,*sum_2,*sum_3;
	for(i=0;i<100;i++)
	{
		array_1[i]=counter;
		counter++;
	}
	for(i=0;i<100;i++)
	{
		array_2[i]=counter;
		counter++;
	}
	for(i=0;i<100;i++)
	{
		array_3[i]=counter;
		counter++;
	}
	ret_1 = pthread_create(&thread_1, NULL, add_100_numbers, (void*)array_1);
	ret_2 = pthread_create(&thread_2, NULL, add_100_numbers, (void*)array_2);
	ret_3 = pthread_create(&thread_3, NULL, add_100_numbers, (void*)array_3);

	pthread_join(thread_1,&sum_1);
	pthread_join(thread_2,&sum_2);
	pthread_join(thread_3,&sum_3);

	result = *((uint16_t*)sum_1)+*((uint16_t*)sum_2)+*((uint16_t*)sum_3);

        clock_gettime(CLOCK_REALTIME, &current_time);

        syslog(LOG_CRIT, "The sum of numbers from 0 to 299 is %d @ current_time.tv_sec %d, current_time.tv_usec %d\n", result, current_time.tv_sec, current_time.tv_nsec);
}
