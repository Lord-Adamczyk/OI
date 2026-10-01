#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int miasta[500001];
vector <int> miasta_a[500001];//jacy agenci maja dostaep do tego miasta
vector <int> poloczenia[500000];
int main() {
  int n,k;
  cin>>n>>k;
  for (int i = 0; i < n; i++) miasta[i]=0;
  for (int i = 0; i < k; i++){
    int x;cin>>x;
    miasta[x]=i+1;
  }
  for (int i = 0; i < n-1; i++)
  {
    /* code */
  }
  
  return 0;
}