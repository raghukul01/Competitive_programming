//spoj AFS

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
#define      fill(a)           memset(a, 1, sizeof (a))
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
    long long int sum_fac[1000000];
    int num[1000000];
    fill_n(num,1000000,1);
    For(i,0,1000000)num[i] = i;
    fill_n(sum_fac,1000000,1);
    int prime[1000] = {0},count = 0;
    For(i,0,1000000)num[i] = i;
    For(i,2,1000) {
        if(prime[i] == 0) {
            prime[count] = i;
            for(int j = i*2;j < 1000;j+=i) prime[j] = 1;
            count++;
        }
    }
    // For(i,0,count)iout(prime[i]);
    sum_fac[0] = 0;
    sum_fac[1] = 0;
    For(i,0,count) {
        for(int j = prime[i]*2;j < 1000000;j+=prime[i]) {
            int ans = 0;
            while(num[j] % prime[i] == 0) {
                num[j] /= prime[i];
                ans++;
            }
            sum_fac[j] *= ((long long int)(pow(prime[i],ans+1) -1) / (prime[i] - 1));
        }
    }
    For(i,2,1000000) {
      if((num[i] != 1)&&(num[i] != i)) {
        sum_fac[i] *= (num[i]+1);
      }
    }
    For(i,2,1000000) sum_fac[i] -= i;
    For(i,2,1000000) lliout(sum_fac[i]);
    // For(i,2,1000000) if(sum_fac[i] > 1)sum_fac[i] -= i;
    // For(i,1,1000000) sum_fac[i] += sum_fac[i-1];
    // For(i,0,5010)lliout(sum_fac[i]);
    int t,k;
    iin(t);
    while(t--) {
    	iin(k);
    	lliout(sum_fac[k]);
    }

    return 0;
}
