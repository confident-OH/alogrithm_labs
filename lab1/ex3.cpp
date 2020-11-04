#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int dis;
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
    int lable, num_n;
    int i, j;
    long long int result;
    int root1, root2;
    int start, end, dist;
    vector<node> paths;
    int *array;
    node pnode;

    scanf("%d", &lable);
    getchar();
    while(lable!=0){
        paths.clear();
        result = 0;
        array = (int*)malloc((lable+1)*sizeof(int));
        memset(array, 0, (lable+1)*sizeof(int));
        num_n = lable*(lable-1)/2;
        for(i = 0;i<num_n;i++){
            scanf("%d %d %d", &start, &end, &dist);
            getchar();         //clear the '\n' in every line;
            pnode.dis = dist;
            pnode.start = start;
            pnode.end = end;
            paths.push_back(pnode);
        }
        sort(paths.begin(), paths.end(), cmp);    // sort the vector
        /*
        int size = paths.size();
        for(i = 0; i < size ;i++){
            cout << "dis: " << paths[i].dis << " start: " << (char)(paths[i].start+'A' - 1) << " end: " << (char)(paths[i].end+'A'-1) << endl;
        }
        */
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
        cout << result << endl;
        free(array);
        scanf("%d", &lable);
        getchar();
    } 
    paths.clear(); 
    return 0;
}
