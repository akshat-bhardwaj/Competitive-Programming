#include <bits/stdc++.h>

using namespace std;

int prime[1000001]={0},n;vector <int> p;
map<int,bool> mm; 
void sieve(){
	for(int i=2;i*i<=1000000;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=1000000;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
	n = p.size();
	for(int i=0;i<n;i++)
		mm[p[i]]=1;
}
int convert(vector <int> v){
	int n=v.size(),j=1;
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=j*v[i];
		j*=10;
	}
	return ans;
}
bool check(int m){
	vector<int> v;
	while(m>0){
		v.push_back(m%10);
		m/=10;
	}
	//for(int z=n-1;z>=0;z--) cout<<v[i];
	int n=v.size(),count=0,temp;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			if( v[i]==v[j] && v[i]<=2 ){
				count=0;temp=v[i];
				for(int k=temp;k<=9;k++){
					v[i]=k;
					v[j]=k;
					//cout<<convert(v)<<"_"<<mm[convert(v)]<<" ";
					if(mm[convert(v)] == 1){
						count++;
					} 
				}
				//cout<<endl;
				v[i]=temp;v[j]=temp;
				if(count>=8){
					return 1;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int z=j+1;j<n;j++){
				if( v[i]==v[j] && v[z]==v[i] && v[i]<=2 ){
					count=0;temp=v[i];
					for(int k=temp;k<=9;k++){
						v[i]=k;
						v[j]=k;
						v[z]=k;
						//cout<<convert(v)<<"_"<<mm[convert(v)]<<" ";
						if(mm[convert(v)] == 1){
							count++;
						} 
					}
					//cout<<endl;
					v[i]=temp;v[j]=temp;v[z]=temp;
					if(count>=8){
						return 1;
					}
				}
			}
		}
	}
}
int main(){
	sieve();
	for(int i=0;i<n;i++){
		if(p[i]<56004) continue;
		if(check(p[i])){
			cout<<p[i];
			return 0;
		}
	}
}
