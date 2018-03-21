//topological sort:- print a sequence such that all the parents of a node lie to the left of that node

#include<bits/stdc++.h>
using namespace std;
#define present(container, element) (container.find(element) != container.end())
///////////////////////////////////////

int MaxNode = 101;
vector<int> v[101];
set<int> s; // to store all the visited nodes
stack<int> stk; // to store the sequence in correct order

void topological_sort(int n);
void visit(int i);


int main() {
  int nodes;
  cin>>nodes;//total nuber of nodes
  int vert,x,y; // number of vertices in directed graph
  cin>>vert;// number of edges
  for(int i = 0;i < vert;i++) {
    cin>>x>>y; // vertex exist from x to y
    v[x].push_back(y);
  }
  topological_sort(nodes);
  for(int i = 0;i < nodes;i++) {
    cout<<stk.top()<<", ";
    stk.pop();
  }
  return 0;
}

void topological_sort(int n) {
  for(int i = 1;i < n+1; i++) {
    if(present(s,i))continue; // visited
    else {
      visit(i); // visit and visit its children
    }
  }
}

void visit(int i) {
  for(int k = 0;k < v[i].size();k++) {
    if(present(s,v[i][k]))continue;
    else visit(v[i][k]);
  }
  s.insert(i); // as all the child are visited now we can push that in the vector
  stk.push(i);
  return;
}
