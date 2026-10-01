#include <bits/stdc++.h>
using namespace  std;

vector<pair<int,int>>tab; //pozycja,wartosc
vector<int> zaleznosci[100000];
vector<int> pomiary[200000];


vector<long long> drzewo;
int n;

// void buduj(vector) {
//
// }
int main() {
    int n,s,m;
    cin>>n>>s>>m;

    int  p=1;
    int rozmiar=1;
    for (int i=0;i<s;i++) {
        int a,b;
        cin>>a>>b;
        tab.push_back({a,b});
    }
    while (rozmiar<n) {
        rozmiar*=2;
        p++;
    }
    for (int i=0;i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
    }
}