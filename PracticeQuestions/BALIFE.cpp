// Pay attention to this code :P
// Author: RAGHUKUL RAMAN
// BALIFE spoj 
// we just calculate how much each element wants or how much more it has.
// then we calculate cumulative sum which indicate the maximum number of rounds
// needed for that part. note that elements of a particular sum can redistribute
// among themselves. if one item gets 1 then it can also pass that to the needed on at the same time
// so max denotes the correct answer for that answer

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
    int n;
    iin(n);
    while(n != -1) {
        int a[n];
        ll sum = 0;
        int avg;
        For(i,0,n){
            iin(a[i]);
            sum += a[i];
        }
        if(sum % n != 0) {
            iout(-1);
            iin(n);
            continue;
        }
        else {
            int ans[n];
            int max = -1;
            avg = sum / n;
            For(i,0,n)
                ans[i] = a[i] - avg;
            
            For(i,1,n)
                ans[i] = ans[i-1] +ans[i];
            For(i,0,n) {
                ans[i] = abs(ans[i]);
                if(ans[i] > max) max = ans[i];
		// this max denotes maximum rounds for that substring
            }
            iout(max);
        }
        iin(n);
    }
    return 0;
}
