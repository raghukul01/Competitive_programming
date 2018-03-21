//spoj PTIME

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
    int n;
    iin(n);
    bool prime[n+1];
    vi primes;
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    For(i,2,n+1)
        if(prime[i])primes.pb(i);
    
    For(i,0,primes.size()) {
        if(primes[i] > n)break;
        int a = n;
        int power = 0;
        while(a != 0) {
            power += (a / primes[i]);
            a /= primes[i];
        }
        if(power == 0)continue;
        else {
            if(i < primes.size() -1)
                cout<<primes[i]<<"^"<<power<<" * ";
            else
                cout<<primes[i]<<"^"<<power;
        }
        
    }
    
    
    return 0;   
}
