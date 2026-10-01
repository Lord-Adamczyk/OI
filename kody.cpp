#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

bitset<5000001> can;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t="";
    int n;
    cin >> n;
    t+=to_string(n);
    long long suma = 0;
    int maks = 0;

    can[0] = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t+=to_string(x);
    }
    cout << t;

}