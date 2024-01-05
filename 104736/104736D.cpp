#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll n, g;
    vector<string> dic;
    set<char> sec;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(!i) for(auto it: s) sec.insert(it);
        dic.push_back(s);
    }

    cin >> g;

    for(int i = 0; i < g; i++){
        string s;
        cin >> s;
        set<string> pos;
        for(auto it: dic){
            for(int i = 0; i < 5; i++){

                if(s[i] == '*'){
                    if(it[i] == dic[0][i]) pos.insert(it);
                    else{ pos.erase(it); break;}
                } else if(s[i] == '!'){
                    if(it[i] != dic[0][i] && sec.count(it[i])) pos.insert(it);
                    else{ pos.erase(it); break;}
                } else {
                    if(it[i] != dic[0][i] && !sec.count(it[i])) pos.insert(it);
                    else{ pos.erase(it); break;}
                }
            }
        }
        cout << pos.size() << "\n";
    }

    return 0;
}