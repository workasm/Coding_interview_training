
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <map>

// #include <math.h>
#include <stdio.h>

pthread_mutex_t mtx1;
pthread_mutex_t mtx2;
pthread_mutex_t mtx3;

void *thread1_proc(void*) {
 
    while(1) {
        pthread_mutex_lock(&mtx1);
        printf("1\n");
        pthread_mutex_unlock(&mtx2);
        usleep(200000);
    }
}

void *thread2_proc(void*) {
 
    while(1) {
        pthread_mutex_lock(&mtx2);
        printf("2\n");
        pthread_mutex_unlock(&mtx3);
        usleep(200000);
    }
}

void *thread3_proc(void*) {
 
    while(1) {
        pthread_mutex_lock(&mtx3);
        printf("3\n");
        pthread_mutex_unlock(&mtx1);
        usleep(200000);
    }
}

int main(){
    
    pthread_mutex_init(&mtx1, NULL);
    
    pthread_mutex_init(&mtx2, NULL);
    
    pthread_mutex_init(&mtx3, NULL);
    
    pthread_mutex_lock(&mtx2);
    pthread_mutex_lock(&mtx3);
    
    pthread_t tid;
    pthread_create(&tid, NULL, thread1_proc, NULL);
    pthread_create(&tid, NULL, thread2_proc, NULL);
    pthread_create(&tid, NULL, thread3_proc, NULL);
    
    while(1);
    return 1;
}

