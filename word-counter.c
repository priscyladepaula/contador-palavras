#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *counter(char *file);

int main(int argc, char *argv[]) {
    pthread_t t[argc - 1];

    for (int i = 1; i < argc; i++) {
        pthread_create(&t[i - 1], NULL, (void *)counter, argv[i]);
    }

    for(int i = 0; i < argc; i++) {
        pthread_join(t[i], NULL);
    }

    return 0;
}

void *counter(char *file){
    char c;
    int countWords=0;
    FILE *f;
    f = fopen(file, "r");

    while((c = fgetc(f)) != EOF ){
        if(c == ' ' || c == '\n' )
            countWords++;
    }

    printf("%s: %d palavras \n", file, countWords);

    fclose(f);
}