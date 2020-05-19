#include <stdio.h>
#include <pthread.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void * hello (void * tid ) {
	pthread_mutex_lock(&mutex);
	printf ("Hello from thread %d\n" , (int) tid ) ;
	pthread_mutex_unlock(&mutex);
}
int main ( ) {
	pthread_t tid [10] ;
	int i;
	for ( i = 0; i < 10; i++) {
		pthread_create(&tid [i] , NULL, hello , (void*)i) ;
	}
	pthread_exit (NULL);
}
