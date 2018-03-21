// Question:Again we have a staircase with N steps.Again we have to reach the top of the staircase.
// This time we can jump from the i th stair to the i+1 th stair or the i+3 th stair.There is an
// additional condition that some stairs are blocked and can’t be used.Now we are
//  interested in finding the minimum number of jumps to reach the N th stair.


#include <iostream>
using namespace std;


int main () {
  int n,t;
  cin>>n;
  int a[n];
  int D[n],i; // array to store the minimum steps needed to reach index i
  for(i = 0; i < n; i++) {
    cin>>a[i]; // number of staircase that are blocked given in sorted array
              // zero means stair is broken
  }
  D[0] = 0;
  D[1] = 1;  // base cases
  D[2] = 2;

  for(i = 3;i < n;i++) {
    if(a[i] != 0) { // stair not broken
      D[i] = min(D[i-1],D[i-3])+1; // one step needed
    }
    else D[i] = 99999999; // large penalty as this value of i cannot be reaced
  }
  cout<<D[n-1];

  return 0;

}
