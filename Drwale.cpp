#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
bitset<5000001> can;
int tab[5000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long suma = 0;
    int maks = 0;
    can[0] = 1;
    for (int i = 0; i < 5000001; i++) {
        tab[i]=0;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tab[x]++;
        if (x>maks) {
            suma += maks;
            maks = x;
        }
        else {
            suma += x;
        }
    }
    for (int i = 0; i < 5000001; i++) {
        if (tab[i]!=0&&i!=maks) {
            int pow=1;
            while (tab[i]>=pow) {
                can |= (can << i*pow);
                tab[i]-=pow;
                pow*=2;
            }
            can |= (can << i*tab[i]);
        }
        else if (i==maks&&tab[i]>1) {
            int pow=1;
            int ile=tab[i]-1;
            while (ile>=pow) {
                can |= (can << i*pow);
                ile-=pow;
                pow*=2;
            }
            can |= (can << i*ile);
        }
    }
    for (int i = (suma / 2); i >= 0; i--) {
            if (can[i]) {
                cout<<maks+i;
                return 0;
            }
    }
    return 0;
}