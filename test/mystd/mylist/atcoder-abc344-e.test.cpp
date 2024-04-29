#define PROBLEM "https://atcoder.jp/contests/abc344/tasks/abc344_e"

#include "../../../mystd/mylist.cpp"

int main() {
    ll N;
    cin >> N;

    List<ll> lst;
    map<ll, list<ll>::iterator> mp;

    rep(i, N) {
        ll a;
        cin >> a;
        mp[a] = lst.push_back(a);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll x, y;
            cin >> x >> y;

            auto it = mp[x];
            mp[y] = lst.insert_after(it, y);
        }
        else {
            ll x;
            cin >> x;

            auto it = mp[x];
            lst.erase(it);
            mp.erase(x);
        }
    }

    cout << lst << endl;

    return 0;
}