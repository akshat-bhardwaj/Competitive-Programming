#include <bits/stdc++.h>
using namespace std;

vector<int> a[7];
map<int, vector<int> > b[7];
long long int n = 1,val,dig,ans=0;
int ind[6]={1,2,3,4,5,6};
vector<int> final;

int perm(vector<int> final){
	if(final.size() == 6){
		return 1;
	}
	int done,next_index,first_index;
	done = final.size();
	next_index = ind[done];
	first_index = ind[0];
	int last_two = final[done-1] % 100;
	if( done == 5){
		if(b[next_index][last_two].size() == 0 ){
			final.pop_back();
			return 0;
		}
		for(int i=0;i<b[next_index][last_two].size();i++){
			if(b[next_index][last_two][i]%100==final[0]/100){
				final.push_back(b[next_index][last_two][i]);
				for(int k=0;k<final.size();k++){
					cout<<final[k]<<" ";
					ans+=final[k];
				}
				cout<<endl;
				cout<<ans<<endl;
				return 1;
			}
		}
		return 0;
	}
	//return 0 condition
	if(b[next_index][last_two].size() == 0 ){
		final.pop_back();
		return 0;
	}
	for(int i=0;i<b[next_index][last_two].size();i++){
		final.push_back(b[next_index][last_two][i]);
		return(perm(final));
	}
}
  
int main(){
	/*Triangle    P3,n=n(n+1)/2   1, 3, 6, 10, 15, ...
Square    P4,n=n2   1, 4, 9, 16, 25, ...
Pentagonal    P5,n=n(3n−1)/2    1, 5, 12, 22, 35, ...
Hexagonal   P6,n=n(2n−1)    1, 6, 15, 28, 45, ...
Heptagonal    P7,n=n(5n−3)/2    1, 7, 18, 34, 55, ...
Octagonal   P8,n=n(3n−2)    1, 8, 21, 40, 65, ...
*/
  while(true){
    val = (n * (n+1)) / 2;
    if ( val >=1000 && val < 10000) {
      a[1].push_back(val);
      dig=val/100;
      b[1][dig].push_back(val);
    }
    if(val>=10000) break;
    n++;
  }
  n = 1;
  while(true){
    val = (n * n);
    if ( val >=1000 && val < 10000) {
      a[2].push_back(val);
      dig=val/100;
      b[2][dig].push_back(val);
    }
    if(val>=10000) break;
    n++;
  }
  n = 1;
  while(true){
    val = (n * (3LL*n-1LL)) / 2LL;
    if ( val >=1000 && val < 10000) {
      a[3].push_back(val);
      dig=val/100;
      b[3][dig].push_back(val);
    }
    if(val>=10000) break;
    n++;
  }
  n = 1;
  while(true){
    val = (n * (2LL*n-1LL));
    if ( val >=1000 && val < 10000) {
      a[4].push_back(val);
      dig=val/100;
      b[4][dig].push_back(val);
    }
    if(val>=10000) break;
    n++;
  }
  n = 1;
  while(true){
    val = (n * (5LL*n-3LL)) / 2LL;
    if ( val >=1000 && val < 10000) {
      a[5].push_back(val);
      dig=val/100;
      b[5][dig].push_back(val);
    }
    if(val>=10000) break;
    n++;
  }
  n = 1;
  while(true){
    val = (n * (3LL*n-2LL)) ;
    if ( val >=1000 && val < 10000) {
      a[6].push_back(val);
      dig=val/100;
      b[6][dig].push_back(val);
    }
    if(val>=10000) break;
    n++;
  }
  for(int i=0;i<=719;i++){
  	for(int j=0;j<a[ind[0]].size();j++){
  		final.clear();
      final.push_back(a[ind[0]][j]);
      if(perm(final) == 1){
      	cout<<final.size()<<endl;
        return 0;
      }
  	}
  	next_permutation(ind,ind+6);
  }
  return 0;
}
