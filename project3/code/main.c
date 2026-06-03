#include<stdio.h>
#include <limits.h>

#define MAX_VEX 1001
#define INF INT_MAX

#include "graph.c"
#include "dijkstra.c"

int main(){
    int k;

    freopen("input.txt", "r", stdin); 

    //input until EOF, convenient for multiple test cases
    while(scanf("%d %d",&nv,&ne) == 2){                 //input the number of vertices and edges
        init(nv);                               //initialize the graph

        //input the edges and their weights
        for(int i = 0; i < ne; i++){
            int u, v, w;
            scanf("%d %d %d",&u,&v,&w);
            if(w < graph[u][v]){
                add_edge(u, v, w);              //if there are multiple edges between the same vertices, we only keep the one with the smallest weight
            }
        }

        scanf("%d",&k);             //the number of sequences to check
        int seq[MAX_VEX];           //the array to store the sequence of vertices to check
        for(int i = 0; i < k; i++){
            for(int j = 1; j <= nv; j++){
                scanf("%d",&seq[j]);            //input the sequence of vertices, starting from index 1
            }

            //check if the sequence is a valid Dijkstra's algorithm order and print the result
            if(is_dijkstra(seq)){
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}