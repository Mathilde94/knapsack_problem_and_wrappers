#include <iostream>
#include <vector>
#include "example.h"

using namespace std;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ITE(v) typeof(b.begin())
#define FORIT(it,v) for(ITE(v) it=v.begin();it!=v.end();it++)

Sack::Sack(int n,int w,vi val,vi wei){
  N=n+1;
  W=w+1;  
  values = (int *)malloc(sizeof(int)*val.size());
  weight = (int *)malloc(sizeof(int)*val.size());
  FOR(i,0,val.size()){values[i]=val[i];}
  FOR(i,0,val.size()){weight[i]=wei[i];}
  table = (int **)malloc(sizeof(int *)*N);
  FOR(i,0,N){ 
    table[i] = (int *)malloc(sizeof(int)*W); 
    FOR(k,0,W){table[i][k]=0;}
  }
}

Sack::~Sack(){
  free(values);
  free(weight);
  free(table);
}


void Sack::display_Sack() const {
  FOR(i,0,N){
    FOR(j,0,W){
      cout << table[i][j]<<' ';
    }
    cout <<endl;
  }
  cout <<endl;
}  
void Sack::construct_table() {
  FOR(i,1,N){
    FOR(w,1,W){
      if (weight[i-1]<=w){
        table[i][w] = (values[i-1]+ table[i-1][w-weight[i-1]]) > table[i-1][w] ? (values[i-1] + table[i-1][w-weight[i-1]]) :table[i-1][w] ;
      }
      else {
        table[i][w] = table[i-1][w] ;
      }
    }
  }
}


void Sack::pick_items(){
  int i(N-1);
  int k(W-1);
  int verification(0);
  int max_value(0);
  while (k>0 && i>0){
    if (table[i][k]!=table[i-1][k]) {
      cout << "The item "<< i << " has to be taken."<<endl;
      verification+=weight[i-1];
      max_value+=values[i-1];
      i--; k-=weight[i];
    }
    else{
      i--;
    }
  }
  cout <<endl;
  cout << "Max value: \t"<< max_value << "    ==> \t"<< ((max_value==table[N-1][W-1])? "AS EXPECTED ": "NOT EXPECTED...") <<endl;
  cout << "Weight : \t"<< verification <<"    ==> \t"<< ((verification<=W-1)? "LESS OR EQUAL ": "NOT EXPECTED...") <<endl;
}
