#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;

int dist[MAXN];
int visited[MAXN];

vector<vector<int> > adj;//Adjacency lists

void bfs(int start)
{
    memset(dist,-1,sizeof(dist));//dist[i] stores minimum distance from start to i
    memset(visited,0,sizeof(visited));

    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];//Iterate over neighbours of u
            if(visited[v]==1)
                continue;
            visited[v]=1;
            dist[v]=dist[u]+1;
        }
    }
}


void dfs(int v)
{
    visited[v]=1;
    for(int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if(visited[u]==1)
        {
            continue;
        }
        dfs(u);
    }
}

int main()
{
    int V,E;
    //input the graph
    scanf("%d%d",&V,&E);
    adj.resize(V+5);
    for(int i=1;i<=E;i++)
    {
        int u,v;//An edge exists between u and v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //DFS from 1
    memset(visited,0,sizeof(visited));
    dfs(1);
    //BFS from 1
    bfs(1);
    return 0;
}
