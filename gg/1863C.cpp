#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005

ll a[MAXN];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        priority_queue<ll> pq;
        cin >> n >> k;

        ll b[n+1] = {};
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] <= n) b[a[i]] = 1;
        }

        a[n] = LLONG_MAX;
        for(int i = 0; i < n+1; i++) if(!b[i]) pq.push(-i);

        for(int i = 0; i < n+1; i++){
            ll aux = a[i];
            a[i] = -pq.top();
            pq.pop();
            pq.push(-aux);
        }

        ll st = n-((k-2)%(n+1));
        for(int i = 0; i < n; i++){
            cout << a[(st+i)%(n+1)] << " ";
        }
        cout << "\n";

    }
    
    return 0;
}