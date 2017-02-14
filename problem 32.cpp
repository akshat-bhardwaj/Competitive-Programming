#include <iostream>
#include <map>
using namespace std;
int main(){
	int ans=0;
	int n;
	map <int,int> mm;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			for(int k=1;k<=9;k++){
				for(int l=1;l<=9;l++){
					if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l && l!=5 && l!=9){
						n=1000*i+100*j+10*k+l;
						for(int m=1;m<99;m++){
							int a[10]={0};
							a[i]++;a[j]++;a[k]++;a[l]++;
								
							if(n%m==0 && m>10){
								int x=n/m;
								a[m%10]++;a[m/10]++;
								a[(x%100)%10]++;a[(x%100)/10]++;a[x/100]++;
								int count=0;
								for(int o=1;o<=9;o++){
									if(a[o]==1)
										count++;
									else
										break;
								}
								if(count==9 && mm[n]==0){
									mm[n]++;
									ans+=n;
									cout<<m<<"*"<<x<<"="<<n<<endl;
								}
							}
							else if(n%m==0){
								int x=n/m;
								a[m%10]++;
								a[(x/1000)]++;a[(x/100)%10]++;a[(x/10)%10]++;a[x%10]++;
								int coun=0;
								for(int o=1;o<=9;o++){
									if(a[o]==1)
										coun++;
									else
										break;
								}
								if(coun==9 && mm[n]==0){
									mm[n]++;
									ans+=n;
									cout<<m<<"*"<<x<<"="<<n<<endl;
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
}