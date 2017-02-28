#include <iostream>
using namespace std;
void insert(int index,int val,int bit[],int size){
	index=index+1;
	while(index<size){
		bit[index]+=val;
		index=index + (index & -index);
	}
}
int find(int index,int bit[]){
	index++;
	int ans=0;
	while(index>0){
		ans+=bit[index];
		index=index - (index & -index);
	}
	return ans;
}
int main(){
	int n,q;
	cin>>n>>q;
	int values[n]={0};
	for(int i=0;i<n;i++) values[i]=0;
	int bit[n+1]={0};
	while(q--){
		string s;int t1,t2;
		cin>>s>>t1>>t2;
		if(s=="find"){
			t1--;t2--;cout<<find(t2,bit)-find(t1,bit)+values[t1]<<endl;
		//	cout<<t1<<" val "<<values[t1]<<endl;
		}
		else{
			t1--;
			values[t1]+=t2;
			insert(t1,t2,bit,n);
		}
	}
	
	return 0;
}
