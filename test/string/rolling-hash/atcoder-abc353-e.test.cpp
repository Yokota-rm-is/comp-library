#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"

#include "../../../string/rolling-hash.cpp"
#include "../../../mystd/mymultiset.cpp"

int main() {
    long long N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0 ; i < N ; ++i){
        cin >> S[i];
    }

    MultiSet<ull> ms;
    ll ans = 0;

    rep(i, N) {
        RollingHash rh(S[i]);
        rep(j, S[i].size()) {
            ull hash = rh.get(0, j + 1);
            ans += ms.count(hash);
            ms.insert(hash);
        }
    }

    cout << ans << endl;

    return 0;
} 
