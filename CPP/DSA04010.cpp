#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;cin >> t;
	while(t--){
		int n; cin >> n;
		long a[n];
		for(int i = 0; i< n; i++) cin >> a[i];
		long long max = -1, max1 = 0;
		for(int i = 0; i< n; i++){
			max1 += a[i];
			if(max < max1) max = max1;
			else if(max1<0) max1 = 0;
		}
		cout << max << endl;
	}
	return 0;
}

