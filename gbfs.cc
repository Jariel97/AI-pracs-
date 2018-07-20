
#include <bits/stdc++.h>

using namespace std;

void gbfs(vector<pair<int, int>> adj[], int s, int t, map<int, int> h) {
    bool visited[27];
    int distance[27];
    memset(visited, false, sizeof visited);
    for(int i =0; i < 27; i++) distance[i] = 99999;
    priority_queue<pair<int, int>> que;
    distance[s] = 0;
    que.push({0, s});
    cout << "ORDER OF THE VERTICES: " << endl;
    int total = 0;
    while(!que.empty()) {
        int p = que.top().second;
        total += h[p];
        que.pop();
        cout << p << endl;
        if(p == t) break;
        for(auto u: adj[p]) {
            int v = u.first;
            if(visited[v]) continue;
            int heu = u.second;
            int priority = h[t];
            que.push({-priority, v});
            visited[v] = true;
        }
    }
    cout << "Total Cost: " << total << endl;
    cout << "Heuristic: " << endl;
    for(auto i : h) {
        cout << i.first << " heuristic: " << i.second << endl;
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
    gbfs(adj, start , end , h);
	fclose(stdin);
    return 0;
}
