#include<iostream>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10];
 
int main()
{

   freopen("data.txt", "r", stdin);
    int nodes, edges;
    int start, end,x,y,c;
    cin >> nodes >> edges;
	
    cin >> start >> end;
 for(k=0;k<=edges;k++)
{
   cin >> i >> j >> c;
     cost[i][j]=1;
}
v=start; 
cout <<"ORDER OF VISITED VERTICES:   ";
cout << v <<" ";
visited[v]=1;
k=1;
while(k<nodes)
{
for(j=nodes;j>=1;j--)
if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
stk[top]=j;
top++;
}
v=stk[--top];
cout<< v << " ";
k++;
visit[v]=0; visited[v]=1;
}
   cout<<endl;
    fclose(stdin);
    return 0;
}

