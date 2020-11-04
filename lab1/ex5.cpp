#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct  node
{
    int start;
    int end;
    int dis;
};

bool cmp (node a1, node a2)
{
    return a1.dis > a2.dis;
}

int distances (char* ch1, char* ch2)
{
    int result = 0;
    while(*ch1!='\0'){
        if(*ch1 != *ch2){
            result++;
        }
        ch1++;
        ch2++;
    }
    return result;
}

int find(int* array, int num){
    if(array[num] == 0){
        return num;
    }
    int a = find(array, array[num]);
    array[num] = a;
    return a;
}

int main()
{
    node pnode;
    vector<node> paths;
    int i, j, k;
    int num_n;
    int result;
    int dist;
    char **albs;
    int *array;
    int root1, root2;
    scanf("%d", &num_n);
    getchar();
    while(num_n!=0){
        //init some
        result = 0;
        paths.clear();
        array = (int*)malloc((num_n+1)*sizeof(int));
        memset(array, 0, (num_n+1)*sizeof(int));
        albs = (char**)malloc(num_n*sizeof(char*));
        // save the char[8]s;
        for(i=0;i<num_n;i++){
            albs[i] = (char*)malloc(9*sizeof(char));
            memset(albs[i], 0, 9);
            fgets(albs[i], 9, stdin);
        } // init end
        //calculate the distances
        for(i=0;i<num_n - 1;i++){
            for(j = i+1; j < num_n; j++){
                pnode.dis = distances(albs[i], albs[j]);
                pnode.start = i+1;
                pnode.end = j+1;
                paths.push_back(pnode);
            }
        }
        sort(paths.begin(), paths.end(), cmp);
        while(!paths.empty()){   //using kruscral algorithm
            pnode = paths.back();
            paths.pop_back();
            root1 = pnode.start;
            root2 = pnode.end;
            root1 = find(array, root1);
            root2 = find(array, root2);
            if(root1!=root2){    
                //Only when the root1!=root2, there is no circle in the graph, and we add the edge.
                array[root1] = root2;
                result+=pnode.dis;
            }
        }
        printf("The highest possible quality is 1/%d.\n", result);
        free(array);
        for(i = 0;i<num_n; i++){
            free(albs[i]);
        }
        free(albs);
        scanf("%d", &num_n);
        getchar();
    }
    paths.clear();
    return 0;
}