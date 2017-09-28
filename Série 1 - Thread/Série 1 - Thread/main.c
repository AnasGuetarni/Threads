//
//  main.c
//  Série 1 - Thread
//
//  Created by Anas Guetarni on 28/09/2017.
//  Copyright © 2017 Anas Guetarni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 25 // On définit le nombre de threads

void *thread(void *thread_id) { // On crée une procédure qui pointe sur l'id d'un thread
    int id = *((int *) thread_id); // On initialise l'id du thread
    // printf("Value of thread_id %d\n", &thread_id);
    printf("Hello from thread %d\n", id); // Affiche
    return NULL; // Retourne la valeur nulle
}

int main(int argc, const char * argv[]) {
    pthread_t threads[NUM_THREADS]; // Crée 16 threads
    for (int i = 0; i < NUM_THREADS; i++) { // Boucle sur tous les threads
        //printf("Boucle: %i\n", i);
        int code = pthread_create(&threads[i], NULL, thread, &i); // Initialise un int "code" qui initialise un thread sur la procédure thread et avec comme argument la boucle
        if(pthread_join(threads[i], NULL) != 0) {
            printf("pthread_join\n");
            return EXIT_FAILURE;
        }
        // printf("Code: %i\n", code);
        if (code != 0) { // Si le code retourne 0
            fprintf(stderr, "pthread_create failed!\n"); // Le thread n'est pas créée
            return EXIT_FAILURE; // Retourne error
        }
    }
    return EXIT_SUCCESS; // Retourne succès
}
