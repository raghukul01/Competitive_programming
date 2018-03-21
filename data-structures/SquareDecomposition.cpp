// kquery spoj

#include <bits/stdc++.h>
using namespace std;
int b;
int flag = 0;

    int binSearch(vector<int>& ar, int min,int f,int l){
        if((f == l) && (ar[f] == min)){
            {flag = 1;return f;}
        }else if(f > l){
            if(f == b) return -10;//all smaller than min
            if(l < 0) {
                if(ar[f] == min)return f+1;
                return -5;//all bigger
            }

            else return f;
        }else{
            int mid = (f + l)/2;
            if(ar[mid] > min){
                return binSearch(ar,min,f,mid-1);
            }else{
                return binSearch(ar,min,mid+1,l);
            }
        }
    }

int main() {
    int n;
    cin>>n;
    int a[n];
    b = sqrt(n);
    int size = n/b+1;
    vector<int> v[size];
    int start = 0;
    for(int i = 0;i < n;i++) {
        cin>>a[i];
        if(v[start].size() < b) {
            v[start].push_back(a[i]);
        }
        else {
            start++;
            v[start].push_back(a[i]);
        }
    }

    for(int i = 0;i < start + 1;i++) {
        sort(v[i].begin(),v[i].end());
    }
    int q,i,j,k;
    cin>>q;
    while(q--) {
        cin>>i>>j>>k;
        int s = (i-1)/b;
        int e = (j-1)/b;
        flag = 0;
        int ans = 0;

        if(s == e) {
            for(int g = i-1;g < j;g++) {
            if(k < a[g]){
                ans++;
                break;
            }
        }
            cout<<ans<<endl;
            continue;
        }
        else
        {
            for(int g = i-1;g < s*b+v[s].size();g++) {
            if(k < a[g]){
                ans++;
            }

        }
            for(int g = e*b;g < j;g++) {
                if(k < a[g]){
                    ans++;
                }
            }
        }
        for(int i = s+1;i < e;i++) {
            int t = binSearch(v[i],k,0,b-1);
            if((flag == 1)&&(t == v[i].size())) t = 0;
            if(flag == 1)t++;
            if(t == -10)t = b;
            if(t == -5) t = 0;
            ans += (b - t);
        }
        cout<<ans<<endl;

    }

    return 0;
}
