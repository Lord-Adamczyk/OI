#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("Ofast,unroll-loops")
struct sklep {
    ll x;
    ll y;
    int t;
};
vector<sklep> sklepy;
vector<sklep> sklepy_manhatan;
ll odl(ll x,ll y, int n) {
    ll o=0;
    for (int i=0;i<n;i++) {
        o+=max(abs(x-sklepy[i].x),abs(y-sklepy[i].y))*sklepy[i].t;
    }
    return o;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        sklep s;
        cin>>s.x;
        cin>>s.y;
        cin>>s.t;
        sklepy.push_back(s);
    }
    ll sumaT=0;
    for(int i=0;i<n;i++) {
        sklep s;
        s.x=sklepy[i].x+sklepy[i].y;
        s.y=sklepy[i].x-sklepy[i].y;
        s.t=sklepy[i].t;
        sumaT+=s.t;
        sklepy_manhatan.push_back(s);
    }
    sort(sklepy_manhatan.begin(),sklepy_manhatan.end(),[](const sklep& a,const sklep& b) {
        return a.x<b.x;
    });
    ll st=0;
    ll kordXM;
    ll kordYM;
    for (int i=0;i<n;i++) {
        st+=sklepy_manhatan[i].t;
        if (st>sumaT/2) {
            kordXM=sklepy_manhatan[i].x;
            break;
        }
    }
    sort(sklepy_manhatan.begin(),sklepy_manhatan.end(),[](const sklep& a,const sklep& b) {
        return a.y<b.y;
    });
    st=0;
    for (int i=0;i<n;i++) {
        st+=sklepy_manhatan[i].t;
        if (st>sumaT/2) {
            kordYM=sklepy_manhatan[i].y;
            break;
        }
    }
    ll x =(kordXM+1)/2+kordYM/2;
    ll y= (kordXM+1)/2-kordYM/2;
    ll xo=x;
    ll yo=y;
    ll min_wynik=INFINITY;
    vector<pair<int,int>> moves={{0,0},{1,0},{1,1},{0,1},{-1,-1},{-1,1},{-1,0},{0,-1},{1,-1}};
    for(int i=0;i<moves.size();i++) {
        ll odle=odl(x+moves[i].first,y+moves[i].second,n);
        if(odle<min_wynik) {
            min_wynik=odle;
            xo=x+moves[i].first;
            yo=y+moves[i].second;
        }
    }
    cout<<xo<<" "<<yo;
}