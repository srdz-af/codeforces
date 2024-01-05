#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        char ans;
        for(int i = 0; i < 3; i++){
            set<char> lol;
            string s;
            cin >> s;
            for(int j = 0; j < 3; j++){
                if(s[j] == '?'){
                    for(int k = 0; k < 3; k++){
                        lol.insert(s[k]);
                    }
                    if(lol.count('A') && lol.count('B')) ans = 'C';
                    else if(lol.count('A') && lol.count('C')) ans = 'B';
                    else if(lol.count('B') && lol.count('C')) ans = 'A';
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}