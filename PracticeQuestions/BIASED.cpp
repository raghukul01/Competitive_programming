// Pay attention to this code :P
// Author: RAGHUKUL RAMAN
// BAISED spoj

// simple greedy approach works. sort given ranks then assign best possible for i = 0 to n
// since assigning lower rank to higher preferred ranks won't make any difference 
// if it makes than it would be loss
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
int main() {
    int t;
    iin(t);
    while(t--) {
        int n;
        iin(n);
        int a[n];
        char x[1000];
        For(i,0,n){
            scanf("%s",x);
            iin(a[i]);
            x[0] = '\0'; // to clear the string for new input
        }
            
        sort(a,a+n);
        ll ans = 0;
        For(i,0,n) {
            ans += abs(a[i] -i - 1);
        }
        lliout(ans);
    }
    return 0;
}

