#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll s[200005];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll n, b, a, ma, ans = 0;
    cin >> n >> b >> a;
    ma = a;

    for(int i = 0; i < n; i++) cin >> s[i];
    
    ll i = 0;

    while(i < n && (a > 0 || b > 0)){
        if(s[i]){
            if(b && a != ma) ans++, a = min(ma, a+1), b--;
            else ans++, a--;
        } else {
            if(a) ans++, a--;
            else ans++, b--;
        }

        i++;
    }
    cout << ans << "\n";
    return 0;
}