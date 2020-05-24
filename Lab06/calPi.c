#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Compile: g++ -pthread -o calPi calPi.c

long incircle = 0;
long points_per_thread;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *runner(void* arg) {
    long incircle_thread = 0;

    unsigned int rand_state = rand();
    long i;
    for (i = 0; i < points_per_thread; i++) {
        double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        double y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;

        if (x * x + y * y < 1) {
		// I change this code to update the global variable: incircle in each iteration
		// Approach: time is longer.`
		pthread_mutex_lock(&mutex);
		incircle += 1;
		pthread_mutex_unlock(&mutex);
        }
    }    
}

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: ./pi <total points>\n");
        exit(1);
    }

    long totalpoints = atol(argv[1]);
    int thread_count = 64;
    points_per_thread = totalpoints / thread_count;

    srand((unsigned)time(NULL));

    pthread_t *threads =(pthread_t*) malloc(thread_count * sizeof(pthread_t));

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    time_t start = time(NULL);
    int i;
    for (i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], &attr, runner, (void*)&i);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    free(threads);

    printf("Pi: %f\n", (4. * (double)incircle) / ((double)points_per_thread * thread_count));
    printf("Time: %d sec\n", (unsigned int)(time(NULL) - start));

    return 0;
}
