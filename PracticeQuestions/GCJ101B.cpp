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
/////////////////////////////////////////////////////
    int main() {
    int c;
    iin(c);
    while(c--) {
        int n,k,b,t,x;
        iin(n);iin(k);iin(b);iin(t);
        std::vector<pii> chick(n);
        For(i,0,n) {iin(x); chick[i].X = x;}
        For(i,0,n) {iin(x);chick[i].Y = x;}
        sortA(chick);
        int possible[n] = {0};
        For(i,0,n) {
            if((chick[i].X + (chick[i].Y)*t) >= b) possible[i] = 1;
        }



    }


    return 0;
}
