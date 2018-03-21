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

int mod1 = 1610612741;
const int p = 53; // this code is for lower case english alphabets
// for uppercase replace 'a' by 'A'
// if both upper and lower case, replace by 'A', and p = 53

int add_mod(int a,int b) {
   return (a % b + b) % b;
}

// return the number of matching found.
int Rabin_karp(string text, int n, int k) {

   set<int> match1;
   int m = k;
   if(n < m) return 0;
   int ans = 0;

   int M1 = 1; // M = p^(m-1) mod mod1, mod2

   for(int i = 0; i < m-1;i++) {
       M1 = (M1 * p) % mod1;

   }
   int ht1 = 0; //hash of text
   for(int i = 0; i < m; i++) {
       ht1 = add_mod(ht1 * p + text[i],mod1);
   }
   ans++;
   match1.insert(ht1);
   for(int i = m; i < n;i++) {

       ht1 = add_mod(ht1 - add_mod((text[i-m])*M1,mod1),mod1);
       ht1 = add_mod(ht1 * p, mod1);
       ht1 = add_mod(ht1 + text[i],mod1);

       match1.insert(ht1);
   }
   return match1.size();
}

int main() {
    int t,n,k;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> s;
        cout << Rabin_karp(s,n,k) << endl;
    }
    return 0;
}
