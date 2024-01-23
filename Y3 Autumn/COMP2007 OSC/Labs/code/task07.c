#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void* withdrawFunds(void* arg); 
void* addFunds(void* arg);
bool ifExit();

/* Variable initialization */
int balance = 100;
pthread_t pWithdrawFunds;
pthread_t pAddFunds;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() { 
    pthread_create((&pWithdrawFunds), NULL, withdrawFunds, NULL); 
    pthread_create((&pWithdrawFunds), NULL, withdrawFunds, NULL); 
    pthread_create((&pAddFunds), NULL, addFunds, NULL); 

    pthread_join(pWithdrawFunds, NULL);
    pthread_join(pWithdrawFunds, NULL);
    pthread_join(pAddFunds, NULL);
}

bool ifExit() {
    pthread_mutex_lock(&mutex);
    if (balance < 0) {
        printf("EXIT PROGRAM!\n", balance);
        pthread_mutex_unlock(&mutex);
        return true;
    }
    pthread_mutex_unlock(&mutex);
    return false;
}
void* withdrawFunds(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (balance >= 10) {
            balance -= 10;
            printf("Remove. Balence = %d\n", balance);
        }
        pthread_mutex_unlock(&mutex);
        if (ifExit())
            break;
    }
}
void* addFunds(void* arg) { 
    while (1){
        pthread_mutex_lock(&mutex);
        balance += 1;
        printf("Added. Balence = %d\n", balance);
        pthread_mutex_unlock(&mutex);
        if (ifExit())
            break;
    }
}

// gcc -std=gnu99 task06.c -pthread