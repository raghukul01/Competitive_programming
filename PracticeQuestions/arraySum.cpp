// find if there exist a subarray with sum of elements equal to a given value(sum)
// given algorithm works in 2*O(n) => O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i = 0; i < n;i++)cin>>a[i];
    int sumarr = a[0];
    int j = 0;
    for(int i = 0;i < n;i++) {
        while((sum < sumarr)&&(j < n)) {
            sumarr -= a[j];
            j++;
        }
        if(sum == sumarr) {
            cout<<"YES";
            cout<<"\nstart: "<<j<<"\nend: "<<i-1;
            return 0;
        }
        else {
            sumarr += a[i];
        }
    }
    cout<<"NO";
    
	return 0;
}
