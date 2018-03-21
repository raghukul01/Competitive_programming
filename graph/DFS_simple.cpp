// http://codeforces.com/problemset/problem/500/A
// codeforces 500/A
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjList;
int visited[30001] = {0}; // to maintain list of points that can be visited by 1

void dfs (int k) {
    visited[k] = 1;
    for(int i = 0;i < adjList[k].size();i++) {
        if(!visited[adjList[k][i]]){
            dfs(adjList[k][i]);
        }
    }
    return;
}
int main() {
    int  V,index;
    cin>>V>>index;
    int a;
    adjList.resize(V+5);
    for (int i = 1;i <= V-1;i++){
        cin>>a;
        adjList[i].push_back(a+i); // given condition
    }
    adjList[1].push_back(1);
    dfs(1);
    if(visited[index] == 1) cout<<"YES";
    else cout<<"NO";
    return 0;
}
