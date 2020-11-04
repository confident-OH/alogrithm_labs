#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int dis;
    char start;
    char end;
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
    int lable, num_n, num_p;
    int i, j;
    char c_p;
    long long int result;
    char root1, root2;
    int start, end;
    vector<node> paths;
    char array[28];
    node pnode;

    scanf("%d", &lable);
    getchar();
    while(lable!=0){
        paths.clear();
        result = 0;
        memset(array, 0, 28*sizeof(char));
        for(i = 1;i<lable;i++){
            start = i;
            getchar();
            getchar();
            scanf("%d", &num_n);
            for(j = 0;j<num_n;j++){
                getchar();
                c_p = getchar();     //the followed word
                getchar();
                scanf("%d", &num_p);  //the length of the path
                pnode.dis = num_p;
                pnode.start = (char)i;
                pnode.end = c_p - 'A' + 1;
                paths.push_back(pnode);
            }
            getchar();         //clear the '\n' in every line;
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
        scanf("%d", &lable);
        getchar();
    } 
    paths.clear(); 
    return 0;
}
