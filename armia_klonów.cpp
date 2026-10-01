#include <bits/stdc++.h>
using namespace  std;
#define ll long long
int main() {
    ll n,a,b;
    cin>>n>>a>>b;
    int p =1;
    ll licznik=1;
    while(licznik<n) {
        p+=1;
        licznik*=2;

    }
    ll odp=INFINITY;
    //maksyjmalna liczba ktora do potegi i nie prtzekracza n
    for(int i=1;i<=p;i++) {
        if (i==1) {
            ll odpt=a+n*b;
            odp=min(odp,odpt);
        }
        else  {
            ll x=1;
            ll y=n;
            while (x+1<y) {
                ll srodek=(x+y)/2;
                ll potega=srodek;
                for (ll j=0;j<i;j++) {
                    potega*=srodek;
                }
                if (potega==n) {
                    ll odpt=i*a+(srodek-1)*b;
                    odp=min(odp,odpt);
                    break;
                }
                else if (potega<n) {
                    x=srodek;
                }
                else {
                    y=srodek;
                }
            }
            for (int j=0;j<=i;j++) {
                ll wynik=1;
                for (int k=0;k<j;k++) {
                    wynik*=x;
                }
                for (int k=0;k<(i-j);k++) {
                    wynik*=y;
                }
                if (wynik>n) {
                    ll odpt=i*a+b*(x-1)*j+b*(y-1)*(i-j);
                    odp=min(odp,odpt);
                    cout<<i<<" ";
                }
            }
        }
    }
    cout<<odp;

}