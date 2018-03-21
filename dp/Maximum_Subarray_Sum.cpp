#include <bits/stdc++.h>
using namespace std;
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      For(i, m, n)      for(int i = m; i < (n); ++i)
#define      fill(a,k)         For(i,0,sizeof(a)/sizeof(a[0])) a[i] = k;
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
#define      in(n)             scanf("%d",&n)
#define      out(n)            printf("%d\n",n)
#define      llin(n)           scanf("%lld",&n)
#define      llout(n)          printf("%lld\n",n)
#define      Debug(x)          cout<<"> "<<#x<<" : "<<x<<endl
#define      DebugArr(a,n)     For(i,0,n) cout<<i<<" : "<<a[i]<<endl

typedef long long ll;
ll mod = 1000000007;

int n;
int a[100005];

void Find_max_subarr() {
    vi b(n+1,0); // this vector stores the max subarray sum ending at index i
    b[0] = a[0];
    For(i,1,n) {
        b[i] = max(a[i]+b[i-1],a[i]);
    }
    int mx = -1e9;
    For(i,0,n) mx = max(mx,b[i]);
    cout << mx << endl;
    return;
}

int main() {
    cin >> n;
    Debug(n);
    For(i,0,n) in(a[i]);
    Find_max_subarr();
    return 0;
}
