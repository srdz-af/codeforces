#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll n, s, r;
        cin >> n >> s >> r;
        cout << s-r;
        ll rat = (n-2)/(r/(s-r));

        if(!rat){
            for(int i = 0; i < n-1; i++){
                cout << " " << s-r;
            }
        } else {
            if(r-rat*(n-2) > 6){
                rat += (r-rat)/(n-2);
                for(int i = 0; i < n-2; i++){
                    cout << " " << rat;
                }
                cout << " " << r-rat*(n-2);
            } else {
                for(int i = 0; i < n-2; i++){
                    cout << " " << rat;
                }
                cout << " " << r-rat*(n-2);
            }
        }

        cout << "\n";
    }

    return 0;
}