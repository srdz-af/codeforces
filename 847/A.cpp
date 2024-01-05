#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    string pi = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    ll t;
    cin >> t;

    while(t--){
        bool f = false;
        string s;
        cin >> s;

        for(int i = 0; i < s.size(); i++){
            if(s[i] != pi[i]){
                f = true;
                cout << i << "\n";
                break;
            }
        }

        if(!f) cout << s.size() << "\n";

    }

    return 0;
}