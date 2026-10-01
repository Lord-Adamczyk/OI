#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<long long> rozklad(long long n){
    long long i=2;
    vector<long long> czynniki;
    while(i*i<=n){
        if(n%i==0){
            czynniki.push_back(i);
            vector<ll> dodatkowe_dzielniki=rozklad(n/i);
             for (int i = 0; i < dodatkowe_dzielniki.size(); i++)
             {
                cout<<czynniki[i]<<" ";
            }
            while(n%i==0){
                n/=i;
            }
        }
        else{
            i++;
        }
    }
    return czynniki;
}
int main() {
  long long n;
  cin>>n;
  vector <ll> czynniki=rozklad(n);
  for (int i = 0; i < czynniki.size(); i++)
  {
    cout<<czynniki[i]<<" ";
  }
  
  return 0;
}