#include <bits/stdc++.h>
using namespace std;
#define ll long long

double p[5005];
double dp[5005][5005];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i < n+1; i++) cin >> p[i];

    sort(p+1, p+n+1, greater<double>());

    for(int q = 1; q < n+1; q++){
        for(int pt = 0; pt < n+1; pt++){
            if(pt > q) dp[q][pt] = 0;
            else if(q == 1) dp[q][pt] = p[q];
            else dp[q][pt] = p[q]*dp[q-1][pt-1]+(1-p[q])*dp[q-1][pt+1];
        }
    }

/*     ll maxp = 0;
    for(int i = k; i < n+1; i++){
        ll prob = 0;
        for(int j = k; j < n+1; j++){
            prob += dp[i][j]; 
        }
        maxp = max(maxp, prob);
    } */

    for(int i = 1; i <  n+1; i++){
        for(int j = 1; j < n+1; j++){
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";
    return 0;
}