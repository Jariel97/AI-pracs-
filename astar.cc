#include <bits/stdc++.h>

using namespace std;

void astar(vector<pair<int, int>> adj[], int s, int t, map<int, int> h) {
    bool visited[27];
    int distance[27];
    memset(visited, false, sizeof visited);
    for(int i =0; i < 27; i++) distance[i] = INT_MAX;
    priority_queue<pair<int, int>> pq;
    distance[s] = 0;
    pq.push({0, s});
    cout << "Order of the vertices are : " << endl;
    int total = 0;
    while(!pq.empty()) {
        int p = pq.top().second;
        pq.pop();
        if(visited[p]) continue;
        visited[p] = true;
        
        total += (distance[p] + h[p]);
        cout << p << " : " << distance[p] + h[p] << endl;
        if(p == t) break;
        for(auto u: adj[p]) {
            int v = u.first;
            int cost = u.second;
            if(distance[p] + cost < distance[v]) {
                int priority = distance[p] + cost + h[t];
                distance[v] = distance[p] + cost;
                pq.push({-priority, v});
            }
        }
    }
    cout << "Total Cost: " << total << endl;
    cout << "Heuristics: " << endl;
    for(int i = 0; i < 27; i++) {
        if(distance[i] != INT_MAX) {
           
            cout << i << " - distance: " << distance[i] << ", heuristic: " << distance[i] + h[i] << endl;
        }
    }
}
int main(int argc, char *argv[])
{
    freopen("data.txt", "r", stdin);
    int nodes, edges, c;
    int u, v;
    int start, end;
    cin >> nodes >> edges;
    cin >> start >> end;
    int x, y;
    vector<pair<int, int>> adj[27];

    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
    }
    map<int, int> h;
    for(int i = 0; i < nodes; i++) {
        cin >> u >> c;
        h[u] = c;
    }
    astar(adj, start , end , h);
	fclose(stdin); 
   return 0;
}
