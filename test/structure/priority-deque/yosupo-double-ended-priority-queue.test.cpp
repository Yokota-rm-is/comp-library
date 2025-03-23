#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../../structure/priority-deque.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll S(N);
    rep(i, N) cin >> S[i];

    PriorityDeque<ll> que(S);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x;
            cin >> x;

            que.push(x);
        }
        else if (t == 1) {
            cout << que.get_min() << endl;
            que.pop_min();
        }
        else {
            cout << que.get_max() << endl;
            que.pop_max();
        }
    }
}

