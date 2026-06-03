int graph[MAX_VEX][MAX_VEX];    //use adjacency matrix to store the graph
int nv, ne;                     //number of vertices and edges

//initialize
void init(int nv){
    for(int i = 1; i <= nv; i++){
        for(int j = 1; j <= nv; j++){
            if(i == j){
                graph[i][j] = 0;        //the distance from a vertex to itself is 0
            } else {
                graph[i][j] = INF;      //initialize the distance between different vertices to infinity
            }
        }
    }
}

//add an weighed edge to the graph
void add_edge(int u, int v, int w){
    //the graph is undirected, we need to update both graph[u][v] and graph[v][u]
    graph[u][v] = w;
    graph[v][u] = w;
}