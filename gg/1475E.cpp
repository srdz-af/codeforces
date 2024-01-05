#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

typedef unsigned long long ull;

ull modmul(ull a, ull b, ull M) {
    ull ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ull)M);
}

ull nCr(ull n, ull k) {
    ull c[k + 1] = {0};
    c[0] = 1;
    for (ull i = 1; i <= n; i++){
        for (ull j = min(i, k); j > 0; j--){
            c[j] = (c[j] + c[j - 1])%MOD;
        }
    }
    return c[k];
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ull t;
    cin >> t;

    while(t--){
        ull n, k, ans = 1;
        map<ull, ull,  std::greater<ull>> m;

        cin >> n >> k;
        
        for(int i = 0; i < n; i++){
            ull a;
            cin >> a;
            m[a]++;
        }

        n = 0;
        for(auto it: m){
            if(n < k){
                if(n + it.second > k) ans = modmul(ans, nCr(it.second, k-n), MOD);
                n+=it.second;
            }
            else break;
        }

        cout << ans << "\n";
    }

    return 0;
}

