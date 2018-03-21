// Pay attention to this code :P
// Author: RAGHUKUL RAMAN
// GAMES
#include <bits/stdc++.h>
using namespace std;
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
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

int gcd(int a,int b) {
	while(a){//reverses a and b automatically if a >= b
		int r = b % a; b = a; a = r;
	}
	return b;//when a becomes 0
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int flag = 0,i,denom,num = 0,hcf;
        char a[20];
        cin>>a;
        for(i = 0;i < strlen(a);i++) {
            if(a[i] == '.') {flag = 1;break;}
        }   i++;
        if(flag == 0) {iout(1);continue;}
        denom = pow(10,strlen(a) - i);
        for(;i < strlen(a);i++) {
            num *= 10;
            num += (a[i] - '0');
        }
        hcf = gcd(denom,num);
        iout(denom / hcf);
    }

    return 0;
}
