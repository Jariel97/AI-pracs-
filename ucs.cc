#include <bits/stdc++.h>

using namespace std;
 
void ucs(vector<pair<int, int>> adj[], int s) {
   bool visited[27];
    int distance[27];
    memset(visited, false, sizeof visited);
    for(int i =0; i < 27; i++) distance[i] = INT_MAX;
    priority_queue<pair<int, int>> que;
    distance[s] = 0;
    que.push({0, s});
    cout << "ORDER OF THE PATH : " << endl;
    while(!que.empty()) {
        int p = que.top().second;
        que.pop();
        if(visited[p]) continue;
        
        cout << p<< " ";
        visited[p] = true;
        for(auto u: adj[p]) {
            int v = u.first;
            int cost = u.second;
            if(distance[p] + cost < distance[v]) {
                distance[v] = distance[p] + cost;
                que.push({-distance[v], v});
            }
        }
    }
    cout << endl << "Cost: " << endl;
    for(int i = 0; i < 26; i++) {
        if(distance[i] != INT_MAX) {
           
            cout << i << " : " << distance[i] << endl;
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
    for(int i = 0; i < nodes; i++) {
        cin >> x >> y >> u;
    }
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
    }
    ucs(adj, start);
fclose(stdin);    
return 0;
}
