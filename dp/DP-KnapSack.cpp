// the problem is to maximize the values using terms adding up to maximum of a weight
// we are given a pair including the weight and value
// we have to make a set of these, so as to maximize the sum of values
// the only constrain is that the sum of wight of all the pairs selected must be less than or equal
// to a specific number :-weight

#include <bits/stdc++.h>
int maxSize = 100;
std::pair<int,int> value[100];
  int weight,n;

int knapsack() {
  int a[n][weight + 1];
  for(int i = 0;i < n;i++) {
    a[i][0] = 0;
  }

  for(int i = 0;i < n;i++) {
    for(int j = 0;j < weight;j++) {
      if(i == 0) {
        if(value[i].first <= weight)a[i][j] = value[i].second;
        else a[i][j] = 0;
      }

      else {
        if(value[i].first > weight)a[i][j] = a[i-1][j];
        else a[i][j] = std::max(a[i-1][j],value[i].second + a[i-1][j-value[i].first]);
      }
    }
  }

  return a[n-1][weight];
}
using namespace std;
int main() {
  cin>>n>>weight;
  for(int i = 0;i < n;i++) { // first stores the weight amd second stores the value it will provide
    cin>>value[i].first>>value[i].second;
  }
  cout<<knapsack();

  return 0;
}
