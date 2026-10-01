#include  <iostream>
using namespace std;
int main() {
    int n=0;
    int x=6;
    for (int i=100;i<1000;i++) {
        string t=to_string(i);
        int suma=0;
        for (int j=0;j<3;j++) {
            suma+=t[j]-'0';
        }
        if (suma==x&&i%x==0) {
            cout<<i<<endl;
            n++;
        }
    }
    cout<<n;
}