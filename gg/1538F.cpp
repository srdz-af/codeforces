    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
     
    int main(){
        ios::sync_with_stdio(false);
    	cin.tie(0),cout.tie(0);
     
        ll t;
        cin >> t;
        while(t--){
            ll l, r, ans = 0;
            cin >> l >> r;
            while(l > 0 || r > 0){
                ans += r-l;
                r /= 10; l/=10;
            }
            cout << ans << "\n";
        }
        
        return 0;
    }