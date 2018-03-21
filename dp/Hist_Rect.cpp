// given an array, a[i] represents the height of rectange, find the maximum sized rectangle possible

#include<bits/stdc++.h>

using namespace std;
typedef long long ll; // dont use semicolon in DebugArr and Debug
#define Debug(x) cout << #x << ": " << x << endl; // prints value of x
#define DebugArr(a,n) For(i,0,n)cout<<i<<": "<<a[i]<<endl; //prints whole array given size of array
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define ForD(i,a,b) for(int i=(a);i>(b);i--)
#define Imax INT_MAX
#define Imin INT_MIN
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define sz(a) int((a).size())
#define pb push_back
#define it iterator
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007
#define PI 3.14159265359
#define EULER 2.7182818284

/////////////////////////////////////////////////////////////////////
int area;
int max_area = Imin;
std::stack<int> myStack;
void checkStack(int i) {
  if(myStack.empty())  {
    area =
  }
}
int Max_rect(int hist[],int n) {

  int i = 0, top;
  myStack.push(i);
  while(!myStack.empty()) {
    if(i < n) {

    }
  }
}

int main() {
  int n;
  cin>> n;
  int hist[n];
  For(i,0,n)cin>>hist[i];
  cout<<Max_rect(hist,n);

  return 0;
}
