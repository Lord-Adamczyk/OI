#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

bitset<5000001> can;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long suma = 0;
    int maks = 0;

    can[0] = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x > maks) {
            if (maks) {
                can |= (can << maks);
                suma += maks;
            }
            maks = x;
        } else {
            can |= (can << x);
            suma += x;
        }
    }

    for (int i = suma / 2; i >= 0; i--) {
        if (can[i]) {
            cout << maks + i;
            return 0;
        }
    }
}