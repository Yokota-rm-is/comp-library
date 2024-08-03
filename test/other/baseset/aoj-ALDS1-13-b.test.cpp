#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_B"

#include "../../../other/baseset.cpp"

ll N = 3;

long long f(Baseset now, Baseset target) {
    long long ret = 0;

    vector<bool> seen(binpow(9, 9), false);
    queue<array<long long, 4>> que;

    ll x, y;
    rep(i, N) rep(j, N) {
        if (now.get(i * N + j) == 0) {
            y = i;
            x = j;
            break;
        }
    }
    que.push({now, 0, y, x});
    seen[now] = true;

    while (!que.empty()) {
        auto [nb, cost, y, x] = que.front(); que.pop();
        Baseset now(9, nb);
        if (now == target) {
            ret = cost;
            break;
        }

        rep(i, 4) {
            auto [ny, nx] = DRUL(y, x, "DRUL"[i]);
            if (ny < 0 or ny >= N or nx < 0 or nx >= N) continue;

            Baseset next = now;
            next.set(y * N + x, now.get(ny * N + nx));
            next.set(ny * N + nx, 0);
            if (seen[next]) continue;
            seen[next] = true;
            que.push({next, cost + 1, ny, nx});
        }
    }

    return ret;
}

int main() {
    vvll A(N, vll(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    Baseset now(9), target(9);
    rep(i, N) rep(j, N) {
        now.set(i * N + j, A[i][j]);
        if (i * N + j < 8) target.set(i * N + j, i * N + j + 1);
        else target.set(i * N + j, 0);
    }

    ll ans = f(now, target);

    cout << ans << endl;

    return 0;
} 
