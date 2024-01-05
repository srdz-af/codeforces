#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];
ll b[200005];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        ll ac = 0, mb = 0, mp = 0;
        for(int i = 0; i < min(n, k); i++){
            ac+=a[i];
            mb = max(mb, b[i]);
            mp = max(mp, ac+(mb*(k-(i+1))));
        }

        cout << mp << "\n";
    }
    return 0;
}