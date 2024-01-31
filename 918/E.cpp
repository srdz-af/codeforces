#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        bool ojito = false;
        set<ll> mucho_ojo;
        ll n, ac = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            ll a;
            cin >> a;
            if(i%2) a = -a;
            ac += a;
            if(mucho_ojo.count(ac) || ac == 0) ojito = true;
            mucho_ojo.insert(ac);
        }

        if(ojito) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
