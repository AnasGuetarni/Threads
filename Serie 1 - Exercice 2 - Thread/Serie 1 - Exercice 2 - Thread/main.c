//
//  main.c
//  Serie 1 - Exercice 2 - Thread
//
//  Created by Anas Guetarni on 28/09/2017.
//  Copyright © 2017 Anas Guetarni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 1 // On définit le nombre de threads

int RES = 0;

void *thread() { // On crée une procédure qui pointe sur l'id d'un thread
    printf("Saisir les valeurs du tableau: ");
    int TAB [] = {2,3,4,5};
    printf("Hello from thread\n");
    for (int i=0; i < sizeof(*TAB);i++){
        printf("Valeurs: %i\n",TAB[i]);
        RES += TAB[i];
    }
    return NULL; // Retourne la valeur nulle
}

int main(int argc, const char * argv[]) {
    pthread_t threads; // Crée un certain nombre de threads
    
    int code = pthread_create(&threads, NULL, thread, NULL);
    
    if(pthread_join(threads, NULL) != 0) {
        printf("pthread_join\n");
        return EXIT_FAILURE;
    }
    
    printf("Résulat: %i\n",RES);
    
    if (code != 0) { // Si le code retourne 0
        fprintf(stderr, "pthread_create failed!\n"); // Le thread n'est pas créée
        return EXIT_FAILURE; // Retourne error
    }
    
    return EXIT_SUCCESS; // Retourne succès
}






