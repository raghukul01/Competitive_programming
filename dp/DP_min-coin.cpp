// Given a list of N coins, their values (V1, V2, … , VN), and the total sum S.
// Find the minimum number of coins the sum of which is S (we can use as many
// coins of one type as we want), or report that it’s not possible to select
// coins in such a way that they sum up to S.

#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int sum,i,j;
  int arr[n];
  for(i = 0;i < n;i++) {
    cin>>arr[i];
  }
  cin>>sum;
  int min[sum+1]; // this min array stores(at index i) the min coins required to make a sum of i
  std::fill_n(min,sum+1,999999); // function to set all the values of arra to 999999
  min[0] = 0;// for making sum 0, 0 coins required - base case
  sort(arr,arr+n);
  for(i = 1;i < sum+1;i++) {
    for(j = 0;j < n;j++) { //
      if((arr[j] <= i) && (min[i-arr[j]]+1 < min[i])) {
        min[i] = min[i-arr[j]] + 1;
        // min[i-arr[j]]+1 < min[i] to check if the new min is possible or not
      }
    }
  }
  // if min[i] has not changed means that it is not possible to make that sum, with given coins
  if(min[sum] == 999999) cout<<"Not Possible to make that sum";
  else
  cout<<min[sum];
}
