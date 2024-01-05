#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll n, cc = 0, ans = 0;
    string s;
    cin >> n >> s;

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            ans++;
            cc = 2;
        } else {
            if(cc) ans++;
            cc = max((ll)0, cc-1);
        }
    }

    cout << ans << "\n";
    return 0;
}