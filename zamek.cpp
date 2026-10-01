#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;
struct chain {
    ll x1;
    ll y1;
    ll x2;
    ll y2;
};
struct wall {
    ll ax;
    ll p1;
    ll p2;
    int chain_number;
};
int main()
{
    vector<chain> chains;
    vector<pair<ll, ll>>dangerous;
    vector <wall> axY;
    vector <wall> axX;
    ll w, h, n, m, x1, x2, y1, y2;
    cin >> w >> h >> n >> m >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; i++)
    {
        chain chain_t;
        cin >> chain_t.x1;
        cin >> chain_t.y1;
        cin >> chain_t.x2;
        cin >> chain_t.y2;
        chains.push_back(chain_t);
        wall w;
        w.chain_number = i;
        w.ax = chain_t.x1;
        w.p1 = chain_t.y1;
        w.p2 = chain_t.y2;
        axY.push_back(w);
        w.ax = chain_t.x2;
        axY.push_back(w);
        w.ax = chain_t.y1;
        w.p1 = chain_t.x1;
        w.p2 = chain_t.x2;
        axX.push_back(w);
        w.ax = chain_t.y2;
        axX.push_back(w);

    }
    sort(chains.begin(), chains.end(),
        [](const chain& c1, const chain& c2) {
            if (c1.x1 != c2.x1)
                return c1.x1 < c2.x1;
            return c1.x2 < c2.x2;
        }
    );
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        dangerous.push_back({ x,y });
        int p = -1, k = n;
        while (k - p > 1) {
            int mid = p + (k - p) / 2;
            if (chains[mid].x1 < x)
                p = mid;
            else
                k = mid;
        }
        cout << p;
    }
}