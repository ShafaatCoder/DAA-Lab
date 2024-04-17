#include<bits/stdc++.h>
using namespace std;

# define MAX 1000

int cost[MAX][MAX];

int freqsum(int freq[],int i,int j){
  int sum=0;
  for(int k=i;k<=j;++k){
    sum+=freq[k];
  }
  return sum;
}

int opt_memorized(int freq[],int i,int j){
  
  if(cost[i][j]) return cost[i][j];
  
  int fsum=freqsum(freq,i,j);
  int min = INT_MAX;
  for(int k=i;k<=j;++k){
    int c = opt_memorized(freq,i,k-1)+opt_memorized(freq,k+1,j)+fsum;
    if(c<min){
      min=c;
      
      cost[i][j]=c;
    }
  }
  return cost[i][j];
}
int OBST(int keys[],int freq[],int n){
  return opt_memorized(freq,0,n-1);
}
int main(){
  int keys[]={10,12,20};
  int freq[]={34,8,50};
  int n = sizeof(keys)/sizeof(keys[0]);
  
  memset(cost,0,sizeof(cost));
  
  for(int i=0;i<n;++i){
    cost[i][i]=freq[i];
  }
  cout<<"The cost of  the OBST is ->  "<<OBST(keys,freq,n);
}
