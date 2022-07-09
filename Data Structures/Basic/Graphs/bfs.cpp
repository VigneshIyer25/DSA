#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 1e6;
vector<int> adj_mat[N];
int dist[N];

void add_edge(int x, int y){
    adj_mat[x].push_back(y);
    adj_mat[y].push_back(x);
}

void BFS(int source){
    dist[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();

        for(int next_node : adj_mat[curr]){
            if(dist[next_node] == -INF){
                dist[next_node] = dist[curr] + 1;
                q.push(next_node);
            }
        }
    }
}

int main(){
    int n = 4;
    for(int i = 0; i < n; i++)
        dist[i] = -INF; // initially all nodes are not connected.

    add_edge(0,1);
    add_edge(0,2);
    add_edge(1,2);
    add_edge(2,3);
    add_edge(3,1);

    BFS(0); // 0 1 2 3
    cout << "\nShortest Distance of node 3 from 0: " << dist[3];

    return 0;
}