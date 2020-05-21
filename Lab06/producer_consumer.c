#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX	1
#define THREADS	2

// Initiate shared buffer
int buffer[MAX];
int fill = 0;
int use = 0;

sem_t empty;
sem_t full;

void put(int value);	// put data into buffer
int get();	// put data into buffer

void *producer(void *arg) {
	int i;
	int tid = (int) arg;
	for (i = 0; i < MAX; i++) {
		sem_wait(&empty); 	// line P1
		put(i); 			// line P2
		printf("Producer put data %d to buffer\n", i);
		sleep(2);
		sem_post(&full); 	// line P3
	}
	pthread_exit(NULL);
}

void *consumer(void *arg) {
	int i, tmp = 0;
	int tid = (int) arg;
	while (tmp != -1) {
		sem_wait(&full);	// line C1
		tmp = get(); 		// line C2
		printf("Consumer get data %d from buffer\n", tmp);
		sleep(2);
		sem_post(&empty); 	// line C3
	}
	pthread_exit(NULL);
}

int main(int argc, char **argv){
	int i, j;
	int tid[THREADS];
	pthread_t producers[THREADS];
	pthread_t consumers[THREADS];

	sem_init(&empty, 0, MAX);
	sem_init(&full, 0, 0);

	for(i = 0; i < THREADS; i++){
		tid[i] = i;
		// Create producer thread
		pthread_create(&producers[i], NULL, producer, (void *) tid[i]);

		// Create consumer thread
		pthread_create(&consumers[i], NULL, consumer, (void *) tid[i]);
	}

	for(i = 0; i < THREADS; i++){
		pthread_join(producers[i], NULL);
		pthread_join(consumers[i], NULL);
	}

	sem_destroy(&full);
	sem_destroy(&empty);

	return 0;
}

void put(int value) {
	buffer[fill] = value; // line f1
	fill = (fill + 1) % MAX; // line f2
}

int get(){
	int tmp = buffer[use]; // line g1
	use = (use + 1) % MAX; // line g2
	return tmp;
}
