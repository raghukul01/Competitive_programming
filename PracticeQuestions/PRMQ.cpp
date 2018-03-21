#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x,int flag)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
    if (arr[m] == x)
        return m;
    if (arr[m] < x)
        l = m + 1;
    else
         r = m - 1;
  }
  if(flag == 0) {
      return (l>r)?l:r;

  }
  else {return (l>r)?r:l;}

}

int main() {
	int n,i,p;

	int prime[1000001];
    std::fill_n(prime,1000001,1);

    for (int p=2; p*p<=1000001; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == 1)
        {
            // Update all multiples of p
            for (int i=p*2; i<=1000001; i += p)
                prime[i] = 0;
        }
    }
    int primes = 0;
    for(i = 2;i<1000001;i++) {
        if(prime[i] == 1){prime[primes] = i;primes++;}
    }
    for(i=0;i<primes;i++)if(prime[i] > 1000)cout<<i<<", ";

    int q;

    cin>>n>>q;
    int a[n];
	int l,r,x,y
	for(i=0;i<n;i++) {
	    cin>>a[i];
	}
	int b[169][n];

	for(i = 0;i<169;i++)
	{
	    for(j =0 ;j<n;j++)b[i][j] = 0;
	}

	for(i = 0;i<n;i++) {
	    for(j=0;j<168;j++) {
	        while(a[i]%prime[j] == 0) {
	            b[j][i]++;
	            b[168][i] = 1;
	            a[i]/=prime[j];
	        }
	    }
	    if(i > 0) {
	        for(j = 0;j<168;j++) {
	            b[j][i]+=b[j][i-1];
	        }
	    }
	}
	int primeval
	for(i=0;i<n;i++) {
	    if(a[i]<1000)a[i]=0;
	}

	long long int sum =0;
	int start = 0, end = primes - 1;
	while(q--) {
	    start = 0; end = primes - 1;
	    cin>>l>>r>>x>>y;

	    start = binarySearch(prime,0,primes-1,x,0);
	    end = binarySearch(prime,0,primes-1,y,1);

	    for(i = start;i<= end;i++) {
	        if(i<168) {
	            sum+=b[i][r]-b[i][l-1];
	        }
	        else for()
	    }

	}
	return 0;
}
