#include <bits/stdc++.h>
using namespace std;
int Knapsack(int wt[],int profit[],int W,int n){
  vector<vector<int>> dp(n+1,vector<int>(W+1, -1));
  if(n==0 || W==0){
    return 0;
  }
  if(dp[n][W] != -1) return dp[n][W];
  else if(wt[n-1]<=W){
    return dp[n][W]=max(profit[n-1] + Knapsack(wt,profit,W-wt[n-1],n-1), Knapsack(wt,profit,W,n-1));
  }
  else{
    return dp[n][W]=Knapsack(wt,profit,W,n-1);  
  }
}
int main(){
  int profit[] = {10,20,50,60};
    int wt[] = {5,4,3,2};
    int W = 10;
    int n = sizeof(profit) / sizeof(profit[0]);
  int mp = Knapsack(wt,profit,W,n);
  cout<<mp;
}
