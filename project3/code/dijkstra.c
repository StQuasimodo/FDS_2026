//check if the given sequence is a valid Dijkstra's algorithm order
int is_dijkstra(int seq[]){
    int dist[MAX_VEX];          //the shortest distance from the source vertex to vertex i
    int visited[MAX_VEX];       //visited sign of vertex i

    //initialize dist and visited arrays
    for(int i = 1; i <= nv; i++){
        dist[i] = INF;          //initialize the shortest distance to all vertices to infinity
        visited[i] = 0;         //initialize all vertices as unvisited
    }
    dist[seq[1]] = 0;           //set the first vertex in the sequence as the source vertex

    for(int i = 1; i <= nv; i++){
        if(i){
            for (int v = 1; v <= nv; v++) {
                if (!visited[v] && dist[v] < dist[seq[i]]) {        //check if the current vertex has a shorter distance than the one in the sequence
                    return 0;
                }
            }
        }

        visited[seq[i]] = 1;                //mark the current vertex as visited

        for(int v = 1; v <= nv; v++){
            if(!visited[v] && graph[seq[i]][v] != INF){             //check if there is an edge between the current vertex and vertex v
                if(dist[seq[i]] + graph[seq[i]][v] < dist[v]){
                    dist[v] = dist[seq[i]] + graph[seq[i]][v];      //update the shortest distance to vertex v
                }
            }
        }
    }
    return 1;
}