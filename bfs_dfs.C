


void bfs(vertex v) {
    q : queue;

    q.push(v);
    visited[v] = 1;
    
    while(!q.empty()) {
        x = q.pop();
        visited[x] = 1;
        forall (x,w) in G {
            if visited[w] == 0
                q.push(w)
        }
    }
}


void dfs(vertex v) {
    s : stack;
    s.push(v);

    while(!s.empty()) {
        x = s.pop();
        mark x;
        forall (x,w) in G {
            if unvisited w
                s.push(w)
        }
    }
}