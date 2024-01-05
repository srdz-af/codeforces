#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll t;
    cin >> t;

    while(t--){
        ll l = 0, r = 1, ans = 0;
        string s;
        cin >> s;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == 'B'){
                while(l >= 0 && s[l] != 'B') l--;
                while(r < s.size() && s[r] != 'B') r++;
            }
            l++; r++;
        }

        cout << ans << "\n";
    }
    return 0;
}