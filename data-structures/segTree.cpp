#include <iostream>
using namespace std;
// finding maximum in a given range, with update

void build_tree(int a[],int t[],int v,int tl,int tr) {
    if(tl == tr) t[v] = a[tl];
    else {
        int tm = (tl + tr)/2;
        build_tree(a,t,2*v,tl,tm);
        build_tree(a,t,2*v+1,tm+1,tr);
        t[v] = (t[2*v]>t[2*v+1])?t[2*v]:t[2*v+1];
    }
    return;
}
void update(int t[],int v,int tl,int tr,int index,int val) {
    if(tl == tr) t[v] = val;
    else {
        int tm = (tl + tr)/2;
        if(index <= tm) update(t,2*v,tl,tm,index,val);
        else update(t,2*v+1,tm+1,tr,index,val);
        t[v] = (t[2*v]>t[2*v+1])?t[2*v]:t[2*v+1]; 
    }
    return;
    
}

int print(int t[],int v,int tl, int tr,int l,int r) {
    if(l > r)return -100000;
    if((tl == l)&&(tr == r)) return t[v];
    else {
        int tm = (tl + tr)/2;
        int a = print(t,2*v,tl,tm,l,(r>tm)?tm:r);
        int b = print(t,2*v+1,tm+1,tr,(l>tm+1)?l:tm+1,r);
        
        return (a > b)?a:b;
               
    }
}

int main() {
	int i,n,m,x,y,z;
    cin>>n;
    int a[n];
    int t[2*n];
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    build_tree(a,t,1,0,n-1);
    cin>>m;
    while(m--) {
        cin>>x>>y>>z;
        if(x == 0)update(t,1,0,n-1,y-1,z);
        if(x == 1)cout<<print(t,1,0,n-1,y-1,z-1)<<"\n";
        // cout<<m<<", ";
    }
    
	return 0;
}
