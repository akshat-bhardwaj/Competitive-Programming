#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 80;
	int val[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>val[i][j];
		}
	}
	int ans=10000000;
	int dp[n], dptemp[n];
	for(int i=0;i<n;i++){
		dp[i] = val[i][0];
	}
	int iter1[n]={0},iter2[n]={0};
	for(int j=1;j<n;j++){
		for(int i=0;i<n;i++){
			dptemp[i] = dp[i] + val[i][j];
		}
		int sum;
		for(int i=0;i<n;i++){
			sum=0;
			for(int k=i;k>=0;k--){
				sum+=val[k][j];
				dptemp[i] = min(dptemp[i],sum+dp[k]);
			}
			sum=0;
			for(int k=i;k<n;k++){
				sum+=val[k][j];
				dptemp[i] = min(dptemp[i],sum+dp[k]);
			}
		}
		for(int i=0;i<n;i++){
			dp[i] = dptemp[i];
			//cout<<dp[i]<<" ";
			if(j==n-1){
				ans = min(ans,dp[i]);
			}
		}
		//cout<<endl;
	}
	cout<<ans<<endl;
	
	return 0;
}
