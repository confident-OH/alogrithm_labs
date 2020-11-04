#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void in_nums(char *ch, int &M, int &N);

int main ()
{
    char inputline[20];
    int M, N;
    int i;
    int *vectors;
    int a1, a2;
    int root1, root2;
    int result;
    fgets(inputline, 20, stdin);
    while(inputline[0] != '0' || inputline[1] != '\n'){
        result = 0;
        in_nums(inputline, N, M);
        //printf("read the M: %d, read the N: %d\n", M, N);
        vectors = (int*)malloc((N+1)*sizeof(int));
        memset(vectors, 0, (N+1)*sizeof(int));
        for(i=0;i<M;i++){
            scanf("%d %d", &a1, &a2);
            getchar();
            while(vectors[a1]!=0){
                a1 = vectors[a1];
            }
            while(vectors[a2]!=0){
                a2 = vectors[a2];
            }
            if(a1!=a2){
                vectors[a1] = a2;
            }
        }
        for(i = 1; i<=N; i++){
            if(vectors[i] == 0){
                result++;
            }
        }
        result--;
        printf("%d\n", result);
        free(vectors);
        fgets(inputline, 20, stdin);
    }
    return 0;
}

void in_nums(char *ch, int &M, int &N)
{
    char *c = ch;
    M = 0;
    N = 0;
    while(*c!='\n'){
        while(*c!=' '){
            M *= 10;
            M += (*c) - '0';
            c++;
        }
        c++;
        while(*c!='\n'){
            N *= 10;
            N += (*c) - '0';
            c++;
        }
    }
}