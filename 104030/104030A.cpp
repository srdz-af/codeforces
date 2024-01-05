#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll n, sum, x, y, a = 0, b = 0, err = 0;
	cin >> n;
	char ch;

	for(int i = 0; i < n; i++){
		cin >> x >> ch >> y;
		sum = x + y;

		if((( x > 11 || y > 11 ) || (x == 11 && y == 11)) && err==0){
			err = i + 1;
		} else if ( sum % 4 == 0 || (sum + 1) % 4 == 0){
			if(((x < a || y < b) || ((a != x || b != y) && (a == 11 || b == 11))) && err == 0) err = i + 1;
			a = x; b = y;
		} else{
			if(((x < b || y < a) || ((a != y || b != x) && (a == 11 || b == 11))) && err == 0) err = i + 1;
			a = y; b = x;
		}
	}

	if(!err) cout << "ok";
	else cout << "error " << err;
	cout << "\n";

	return 0;
}