#include <iostream>
#include <utility>
#include <queue>

using namespace std;


int odlP[1000][1000];
int odlK[1000][1000];
char tab[1000][1000];
char histP[1000][1000];
char histK[1000][1000];


pair<int,int> p;
pair<int,int> k;
int INTMAX=INT_MAX-1000;

void BFS(int &n,pair<int,int> punkt,int odl[1000][1000],char hist[1000][1000]) {
  queue <pair<int,int>> punkty;
  punkty.push(punkt);
  odl[punkty.front().first][punkty.front().second]=0;
  while(!punkty.empty()) {
    pair<int,int> p=punkty.front();
    punkty.pop();
    pair<int,int> ruchy[4]={{-1,0},{1,0},{0,-1},{0,1}};
    char ruchyc[4]={'L','P','G','D'};
    for(int i=0;i<4;i++) {
      int x=p.first;
      int y=p.second;
      int dx=ruchy[i].first;
      int dy=ruchy[i].second;
      if (x+dx>=0 && x+dx<n && y+dy>=0 && y+dy<n) {
         if (tab[x+dx][y+dy]!='X'&&tab[x+dx][y+dy]!='#' && odl[x+dx][y+dy]==INTMAX) {
          punkty.push({x+dx,y+dy});
          odl[x+dx][y+dy]=odl[x][y]+1;
          hist[x+dx][y+dy]=ruchyc[i];
        }
      }
    }
  }

}

int main() {
  int n;
  cin>>n;

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin>>tab[i][j];
      if(tab[i][j]=='P') {
        p.first=i;
        p.second=j;
      }
      if(tab[i][j]=='K') {
        k.first=i;
        k.second=j;
      }
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      odlP[i][j]=INTMAX;
      odlK[i][j]=INTMAX;
      histP[i][j]=0;
      histK[i][j]=0;
    }
  }
  BFS(n,p,odlP,histP);
  BFS(n,k,odlK,histK);
  for (int i = 0; i< n; i++) {
    for (int j=0;j<n;j++) {
      if (tab[i][j]=='X') {
        continue;
      }
      long long part_one=INTMAX;
      long long part_two=INTMAX;
      long long value=INTMAX;
      // wylom gora
      for (int k=i-1;k>=0;k--) {
        if (tab[k][j]=='X') {
          break;
        }
        if (j==0) {
          part_one=odlP[k][j+1]+(i-k);
          part_two=odlK[k][j+1]+(i-k);
          value=min(value,part_one+part_two);
        }
        else if (j==n) {
          part_one=odlP[k][j-1]+(i-k);
          part_two=odlK[k][j-1]+(i-k);
          value=min(value,part_one+part_two);
        }
        else {
          part_one=odlP[k][j+1]+(i-k);
          part_two=odlK[k][j+1]+(i-k);
          value=min(value,part_one+part_two);

          part_one=odlP[k][j-1]+(i-k);
          part_two=odlK[k][j-1]+(i-k);
          value=min(value,part_one+part_two);
        }
      }
      //wylom dol
      for (int k=i+1;k<n;k++) {
        if (tab[k][j]=='X') {
          break;
        }
        if (j==0) {
          part_one=odlP[k][j+1]+(i-k);
          part_two=odlK[k][j+1]+(i-k);
          value=min(value,part_one+part_two);
        }
        else if (j==n) {
          part_one=odlP[k][j-1]+(i-k);
          part_two=odlK[k][j-1]+(i-k);
          value=min(value,part_one+part_two);
        }
        else {
          part_one=odlP[k][j+1]+(i-k);
          part_two=odlK[k][j+1]+(i-k);
          value=min(value,part_one+part_two);

          part_one=odlP[k][j-1]+(i-k);
          part_two=odlK[k][j-1]+(i-k);
          value=min(value,part_one+part_two);
        }
      }
      //wylom prawo
      for (int k=j+1;k<n;k++) {
        if (tab[k][j]=='X') {
          break;
        }
        if (j==0) {
          part_one=odlP[i+1][k]+(i-k);
          part_two=odlK[i-1][k]+(i-k);
          value=min(value,part_one+part_two);
        }
        else if (j==n) {
          part_one=odlP[i+1][k]+(i-k);
          part_two=odlK[i-1][k]+(i-k);
          value=min(value,part_one+part_two);
        }
        else {
          part_one=odlP[i+1][k]+(i-k);
          part_two=odlK[i-1][k]+(i-k);
          value=min(value,part_one+part_two);

          part_one=odlP[i+1][k]+(i-k);
          part_two=odlK[i-1][k]+(i-k);
          value=min(value,part_one+part_two);
        }
      }
      //wylom lewo
      for (int k=j-1;k>=0;k--) {
        if (tab[k][j]=='X') {
          break;
        }
        if (j==0) {
          part_one=odlP[i+1][k]+(i-k);
          part_two=odlK[i-1][k]+(i-k);
          value=min(value,part_one+part_two);
        }
        else if (j==n) {
          part_one=odlP[i+1][k]+(i-k);
          part_two=odlK[i-1][k]+(i-k);
          value=min(value,part_one+part_two);
        }
        else {
          part_one=odlP[i+1][k]+(i-k);
          part_two=odlK[i-1][k]+(i-k);
          value=min(value,part_one+part_two);

          part_one=odlP[i+1][k]+(i-k);
          part_two=odlK[i-1][k]+(i-k);
          value=min(value,part_one+part_two);
        }
      }
    }
  }
}