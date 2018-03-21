#include <bits/stdc++.h>
using namespace std;

struct data {
    int sum;
    int pref;
    int suf;
    int ans;
};

typedef struct data data;

data combine(data l, data r);
void build_tree(int a[],data t[],int v,int tl,int tr);
data make_data(int a);
void update(data t[],int v, int tl, int tr,int index, int val);
data query(data t[], int v,int tl, int tr, int l,int r);

int main() {
	int i,n,x,y,z;
	cin>>n;
	int a[n];
	data t[4*n];
	for(i = 0; i < n; i++) {
	    cin>>a[i];
	}
	build_tree(a, t, 1, 0, n-1);

	int m;
	cin>>m;
	while(m--) {
	    cin>>x>>y>>z;
	    for(i = 0;i < 4*n;i++)cout<<t[i].ans<<": ";
	    if(x == 0)update(t,1,0,n-1,y-1,z);
	    if(x == 1)cout<<query(t,1,0,n-1,y-1,z-1).ans<<"\n";

	}
	return 0;
}

data combine(data l, data r) {
    data res;
    res.sum = l.sum+r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suf = std::max(l.suf + r.sum,r.suf);
    res.ans = std::max(max(l.ans,r.ans),l.suf + r.pref);
    return res;
}

data make_data(int a) {
    data res;
    res.sum = res.pref = res.suf = res.ans = a;
    return res;
}

void build_tree(int a[],data t[],int v,int tl,int tr) {
    if(tl == tr) t[v] = make_data(a[tl]);
    else {
        int tm = (tl + tr)/2;
        build_tree(a,t,2*v,tl,tm);
        build_tree(a,t,2*v+1,tm+1,tr);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}

void update(data t[],int v, int tl, int tr,int index, int val) {
    if(tl == tr) t[v] = make_data(val);
    else {
        int tm = (tl + tr)/2;
        if(index > tm) update(t,2*v+1,tm+1,tr,index,val);
        else update(t,2*v,tl,tm,index,val);
        t[v] = combine(t[2*v],t[2*v+1]);
    }
}

data query(data t[], int v,int tl, int tr, int l,int r) {
    if((tr == r)&&(tl == l)) return t[v];
    int tm = (tl + tr)/2;
    if(r <= tm) return query(t,2*v,tl,tm,l,r);
    if(l > tm) return query(t,2*v+1,tm+1,tr,l,r);
    else combine(query(t,2*v,tl,tm,l,tm), query(t,2*v+1,tm+1,tr,tm+1,r));
}
