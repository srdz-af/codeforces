#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll t;
    cin >> t;
    while(t--){
        ll n , k, c0 = 0, c1 = 0, cq = 0; // la cq ya va a empezar
        string s;
        bool p = false, f = false;
        cin >> n >> k >> s;
        for(int i = 0; i < k; i++){
            if(s[i] == '0') c0++;
            else if(s[i] == '1') c1++;
            else cq++;
        }

        if(abs(c0-c1) > cq){
            cout << "NO\n";
            continue;
        }

        p = cq % 2;

        for(int i = 1; i <= n-k; i++){

            if(s[i-1] == '0') c0--;
            else if(s[i-1] == '1') c1--;
            else cq--;

            if(s[i+k-1] == '0') c0++;
            else if(s[i+k-1] == '1') c1++;
            else cq++;

            if((abs(c0-c1) > cq) || ((cq % 2) && p && s[i-1] != s[i+k-1])){
                f = true;
                cout << "NO\n";
                break;
            }
        }

        if(!f) cout << "YES\n";
    }
    return 0;
}