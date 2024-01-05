#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        ll c0 = 0, r0 = 0, r1 = 0, p0 = 0, l0 = 0, c1, c2;
        bool f = false;
        string s;
        cin >> s;
        ll n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                c0++; p0+=1-f; l0++;
            } else {
                f = 1; l0 = 0;
            }
        }

        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                r0++;
            } else {
                r1++;
            }
            if(r1 == c0-r0) break;
        }
        c1 = r1-l0;
        r0 = r1 = 0;

        r0 = r1 = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                r0++;
            } else {
                r1++;
            }
            if(r1 == c0-r0) break;
        }
        c2 = r1-p0;


       if(!c0 || min(c1, c2) < 0) cout << "0\n";
       else cout << min(c1, c2) << "\n";
    }
    return 0;
}