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

int main() { 
    pthread_create((&pWithdrawFunds), NULL, withdrawFunds, NULL); 
    pthread_create((&pWithdrawFunds), NULL, withdrawFunds, NULL); 
    pthread_create((&pAddFunds), NULL, addFunds, NULL); 

    pthread_join(pWithdrawFunds, NULL);
    pthread_join(pWithdrawFunds, NULL);
    pthread_join(pAddFunds, NULL);

}

bool ifExit() {
    if (balance < 0) {
        printf("EXIT PROGRAM!\n", balance);
        return true;
    }
    return false;
}
void* withdrawFunds(void* arg) {
    while (1) {
        if (balance >= 10) {
            balance -= 10;
            printf("Remove. Balence = %d\n", balance);
        }
        if (ifExit())
            break;
    }
}
void* addFunds(void* arg) { 
    while (1){
        balance += 1;
        printf("Added. Balence = %d\n", balance);
        if (balance < 0) {
            printf("Balence < 0, exit while loop.");
            break;
        }
    }
}

// gcc -std=gnu99 task06.c -pthread