#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX	10
#define THREADS	2	// 1 producer and 1 consumer

// Initiate shared buffer
int buffer[MAX];
int fill = 0;
int use = 0;

sem_t empty;
sem_t full;
sem_t lock;

void put(int value);	// put data into buffer
int get();	// get data from buffer

void *producer(void *arg) {
	int i;
	int tid = (int) arg;
	for (i = 0; i < MAX; i++) {
//		sem_wait(&lock);	// line P0	(NEW LINE)
		sem_wait(&empty); 	// line P1
		sem_wait(&lock);	// line P1.1
		put(i); 			// line P2
		printf("Producer %d put data %d\n", tid, i);
		sleep(1);
		sem_post(&lock);	// line P3.1
		sem_post(&full); 	// line P3
//		sem_post(&lock); // line P4 (NEW LINE)
	}
	pthread_exit(NULL);
}

void *consumer(void *arg) {
	int i, tmp = 0;
	int tid = (int) arg;
	while (tmp != -1) {
//		sem_wait(&lock);	// line C0 (NEW LINE)
		sem_wait(&full);	// line C1
		sem_wait(&lock);	// line C1.1
		tmp = get(); 		// line C2
		printf("Consumer %d get data %d\n", tid, tmp);
		sleep(1);
		sem_post(&lock);	// line C3.1
		sem_post(&empty); 	// line C3
//		sem_post(&lock);	// line C4 (NEW LINE)
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
	sem_init(&lock, 0, 1);

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