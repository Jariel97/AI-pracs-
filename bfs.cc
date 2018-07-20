#include <bits/stdc++.h>
#define pb push_back 
using namespace std;
 
vector<bool> v;
vector<vector<int> > g;
 
void edge(int a, int b)
{
    g[a].pb(b);
 }
 void bfs(int u)
{
    queue<int> q; 
    q.push(u);
    v[u] = true;
    while (!q.empty()) { 
        int f = q.front();
        q.pop();
        cout << f << " "; 
        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}
int main()
{
    freopen("data.txt", "r", stdin);
    int nodes, edges;
    int start, end,x,y,c;
    cin >> nodes >> edges;
	v.assign(nodes,false);   
	g.assign(nodes,vector<int>());
    cin >> start >> end;
 
    for(int i = 0; i < edges; i++) {
        cin >> x >> y >> c;
     edge(x,y);
    }cout<<"ORDER OF VERTICES ARE :";
	for (int i = 0; i < nodes; i++) {
        if (!v[i])
            bfs(i);
    }
    cout<<endl;
    fclose(stdin);
    return 0;
}
