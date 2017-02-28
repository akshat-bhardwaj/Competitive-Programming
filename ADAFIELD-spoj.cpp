#include <iostream>
#include <set>
using namespace std; 
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y,n;
		cin>>x>>y>>n;
		multiset <long long int> set1,set2;
		multiset <long long int> mset1,mset2;
		set1.insert(0);
		set1.insert(x);
		set2.insert(0);
		set2.insert(y);
		mset1.insert(x);
		mset2.insert(y);
		long long int flag,val;
		for(int i=0;i<n;i++){
			multiset<long long int> :: iterator iter1,iter2;
			cin>>flag>>val;
			if(flag==0 && set1.find(val)==set1.end()){
				set1.insert(val);
				iter1=set1.upper_bound(val);
				iter2=--(set1.lower_bound(val));
				mset1.insert(val-*iter2);
			//	cout<<val-*iter2<<" "<<*iter1-val<<" "<<*iter1-*iter2<<endl;
				mset1.insert(*iter1-val);
				multiset<long long int>::iterator hit(mset1.find((*iter1-*iter2)));
				if (hit!= mset1.end()) mset1.erase(hit);
			}
			else if(flag==1 && set2.find(val)==set2.end()){
				set2.insert(val);
				iter1=set2.upper_bound(val);
				iter2=--(set2.lower_bound(val));
				mset2.insert(val-*iter2);
				mset2.insert(*iter1-val);
				multiset<long long int>::iterator hit(mset2.find((*iter1-*iter2)));
				if (hit!= mset2.end()) mset2.erase(hit);
			//	cout<<val-*iter2<<" "<<*iter1-val<<" "<<*iter1-*iter2<<endl;
			}
			cout<<(*(--mset1.end()))*(*(--mset2.end()))<<endl;
		}
	}
}  