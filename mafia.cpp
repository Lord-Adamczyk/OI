#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace  std;
int tab[1000000];
int licznik[1000000];
bool odw[1000000];
bool cykl[1000000];
vector<vector<int>> cykle;
void DFS(int p) {
    if (odw[p-1]==false) {
        odw[p-1]=true;
        DFS(tab[p-1]);
    }
    if (!cykl[p-1]) {
        vector<int> pusty;
        cykle.push_back(pusty);
        int start=p;
        int teraz=tab[p-1];

        cykle.back().push_back(start);
        cykl[start-1]=true;
        while (start!=teraz) {
            cykle.back().push_back(teraz);
            teraz=tab[teraz-1];
            cykl[teraz-1]=true;
        }
    }
}
int main() {
    for(int i=0;i<1000000;i++) {
        licznik[i]=0;
        odw[i]=false;
        cykl[i]=false;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>tab[i];
        licznik[i]=tab[i];
    }
    DFS(1);
    for(int i=1;i<n;i++) {
        if (!odw[i]) {
            DFS(i+1);
        }
    }
    for (int i = 0; i < cykle.size(); i++) {

    }
}