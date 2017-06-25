// spoj NDIV
// http://www.spoj.com/problems/NDIV/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,b,n;
	std::vector<int> prime;
    int numPrime = 0;
	int a[31624] = {0};
	for(int i = 2;i < 31624;i++) {
	    if(a[i] == 1)continue;
	    else {
	        for(int j = i;j<31624;j+=i)a[j] = 1;
	        a[i] = 1;
	        prime.push_back(i);
	        numPrime++;
	    }
	}
	cin>>x>>b>>n;
	int ans = 0;
	for(int i = x;i <= b;i++) {
	    int primes = 1;
	    int num = i;
	    int j = 0;
	    while((num > 1)&&(j < numPrime)) {
	        int thisPrime = 0;
	        if(num%prime[j] != 0) {
	            j++;
	        }
	        else {
	            while(num%prime[j] == 0) {
	                thisPrime++;
	                num /= prime[j];
	            }
	        }
	        primes *= (thisPrime+1);
	    }
	    if(num != 1) primes*=2;
	    if(primes == n)ans++;
	}
	cout<<ans;
	return 0;
}

