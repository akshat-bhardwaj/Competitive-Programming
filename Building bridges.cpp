#include <bits/stdc++.h>
using namespace std;
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] > key)
        r = m;
    else
        l = m;
    }
 
    return r;
}
int lms(std::vector<int> &v) {
    if (v.size() == 0)
        return 0;
    std::vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])  tail[0] = v[i];
        else if (v[i] >= tail[length-1])    tail[length++] = v[i];
        else    tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }
    return length;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		pair<int,int> a[n];
		for(int i=0;i<n;i++) cin>>a[i].first;
		for(int i=0;i<n;i++) cin>>a[i].second;
		sort(a,a+n);
		vector<int> second;
		for(int i=0;i<n;i++){ 
			second.push_back(a[i].second);
		//	cout<<a[i].second<<" ";
		}
		//cout<<endl;
		cout<<lms(second)<<endl;
	}
} 
