#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> xd(n+1);
        vector<bool> mucho_ojo(n+1, false);

        for (int i = 1; i <= n; i++) {
            int a;
            cin >> xd[i];
        }

        mucho_ojo[0] = true;
        
        for (int i = 1; i <= n; i++) {
            if(((xd[i] + i) <= n && mucho_ojo[i-1])) mucho_ojo[xd[i] + i] = true;
            if(i - xd[i] - 1 >= 0 && mucho_ojo[i - xd[i] - 1]) mucho_ojo[i] = true;
        }
        
        if(mucho_ojo[n]){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

