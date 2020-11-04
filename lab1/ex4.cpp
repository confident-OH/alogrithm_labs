#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    double dis;
    int start;
    int end;
    node(){
        dis = 0;
        start = 0;
        end = 0;
    }
};

bool cmp(node a1, node a2){
    return a1.dis > a2.dis;
}

int main()
{
    int turn, num_n;
    int i, j, k;
    double result;
    int root1, root2;
    double dist;
    vector<node> paths;
    int *x, *y;
    int *array;
    node pnode;

    scanf("%d", &turn);
    getchar();
    for(i = 0; i < turn; i++){
        result = 0;
        scanf("%d", &num_n);
        getchar();
        x = (int*)malloc((num_n+1)*sizeof(int));
        y = (int*)malloc((num_n+1)*sizeof(int));
        array = (int*)malloc((num_n+1)*sizeof(int));
        memset(x, 0, (num_n+1)*sizeof(int));
        memset(y, 0, (num_n+1)*sizeof(int));
        memset(array, 0, (num_n+1)*sizeof(int));
        paths.clear();
        for(j = 1; j<=num_n; j++){
            scanf("%d %d", x+j, y+j);
            getchar();
        }  //以二维数组的形式将坐标存入
        for(j = 1; j<num_n;j++){
            //calculate the distance between islands;
            for(k = j+1; k<=num_n;k++){
                dist = sqrt(pow((x[j] - x[k]), 2) + pow((y[j] - y[k]), 2));
                if(dist>=10.0&&dist<=1000){
                    pnode.dis = dist*100;
                    pnode.start = j;
                    pnode.end = k;
                    paths.push_back(pnode);
                }
            }
        }
        sort(paths.begin(), paths.end(), cmp);    // sort the vector
        while(!paths.empty()){   //using kruscral algorithm
            pnode = paths.back();
            paths.pop_back();
            root1 = pnode.start;
            root2 = pnode.end;
            while(array[root1]!=0){
                root1 = array[root1];
            }
            while(array[root2]!=0){
                root2 = array[root2];
            }
            if(root1!=root2){    
                //Only when the root1!=root2, there is no circle in the graph, and we add the edge.
                array[root1] = root2;
                result+=pnode.dis;
            }
        }
        int item = 0;
        for(j = 1; j<=num_n; j++){
            if(array[j] == 0){
                item++;
            }
        }
        if(item>1){
            // It shows that the graph is not connected!
            cout << "oh!" << endl;
        }
        else{
            printf("%.1f\n", result);
        }
        free(array);
        free(x);
        free(y);
    }
    paths.clear(); 
    return 0;
}
