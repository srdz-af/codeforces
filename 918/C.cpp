#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll n, ac = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            ll a;
            cin >> a;
            ac += a;
        }
        ll sq = sqrt(ac);
        if(sq*sq == ac) cout << "YES\n";
        else cout << "NO\n"; 
    }
    
    return 0;
}