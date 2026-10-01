#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string t;
    cin>>t;
    int tab[1000000][3];
    for (int i = 0; i < n; i++) {
        tab[i][0] = 0;
        tab[i][1] = 0;
        tab[i][2] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (t[i]=='B')tab[i][0]++;
        else if (t[i]=='C')tab[i][1]++;
        else tab[i][2]++;
    }

}