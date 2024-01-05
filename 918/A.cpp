#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
    ll a, b, c;
    cin >> a >> b >> c;

    if(a == b) cout << c << "\n";
    else if(b == c) cout << a << "\n";
    else if(a == c) cout << b << "\n";
    }
    return 0;
}