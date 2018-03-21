//simple application of inclusion exclusion principle.
// NGM2 spoj

// Pay attention to this code :P
// Author: RAGHUKUL RAMAN
// GCJ101BB
#include <bits/stdc++.h>
using namespace std;
#define      pii               pair<int,int>
#define      vi                vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      For(i, m, n)      for(int i = m; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
#define      iin(n)            scanf("%d",&n)
#define      iout(n)           printf("%d\n",n)
#define      lliin(n)          scanf("%lld",&n)
#define      lliout(n)         printf("%lld\n",n)

typedef long long ll;
ll mod = 1000000007;
//////////////////////////////////////////////////////

int cnt = 0;
int n;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int lcm(int a[], int n) { // this returns LCM of an array of integres
  int res = 1, i;
  for (i = 0; i < n; i++) {
    res = res*a[i]/gcd(res, a[i]);
  }
  return res;
}

void combinationUtil(int arr[], int data[], int start, int end,
					int index, int r, int sign)
{
	if (index == r)
	{
		int lol = lcm(data,r); // lcm of current combination
		cnt += (sign)*(n / lol);
		
	}
	for (int i=start; i<=end && end-i+1 >= r-index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i+1, end, index+1, r, sign);
	}
}

int main() {
    int k;
    iin(n);iin(k);
    int a[k],data[k];

    For(i,0,k) 
        iin(a[i]);
    int factors = 0;
    For(i,1,k+1) { //this denotes the size of the subset on which we apply principle
        int sign = pow(-1,i-1); // as per the  theorem
        combinationUtil(a,data,0,k-1,0,i,sign); //all combinations of size i
    }
    iout(n - cnt);
    return 0;
}
