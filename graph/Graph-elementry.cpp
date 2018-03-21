// http://codeforces.com/problemset/problem/330/B
// codeforces 330/B

#include <bits/stdc++.h>
using namespace std;

int maxval = 99999;
vector< vector<int> > adjList;
int main() {
    //code
    int n,m,u,v;
    int index;
    cin>>n>>m;
    adjList.resize(n+2);
    for(int i = 1;i <= n;i++) {
        adjList[i].push_back(i);
    }
    while(m--) {
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) { // to find the node with minimum enemy: ie no direct connection
        if(adjList[i].size() < maxval){
            maxval = adjList[i].size();
            index = i;
        }
    }
    // we just connect all the neighbours of index(along with index) to the rest of the members
    cout<<((maxval)*(n-maxval))<<endl;
    for(int i = 1;i <= n;i++) {
        if(find(adjList[index].begin(), adjList[index].end(), i) != adjList[index].end())continue;
        else {
               for(int j = 0;j < adjList[index].size();j++) {
               cout<<i<<" "<<adjList[index][j]<<endl;
               }
        }
    }
    return 0;
}
