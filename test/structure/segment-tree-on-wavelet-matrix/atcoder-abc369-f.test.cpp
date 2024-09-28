#define PROBLEM "https://atcoder.jp/contests/abc369/tasks/abc369_f"

#include "../../../structure/segment-tree-on-wavelet-matrix.cpp"

template<typename T>
struct ABC369F : Operation<T> {
    using S = Node<T>;

    ABC369F(): _e(numeric_limits<T>::min()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = max(x.value, y.value);
        long long r = (y.value > x.value ? y.y : x.y);
        long long c = (y.value > x.value ? y.x : x.x);
        if (y.value == x.value) {
            if (y.y > x.y or (y.y == x.y and y.x > x.x)) {
                r = y.y;
                c = y.x;
            }
            else {
                r = x.y;
                c = x.x;
            }
        }
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, r, c, size, coeff);

        return ret;
    }

private:
    T _e;
};

int main() {
    ll H, W, N;
    cin >> H >> W >> N;

    vll R(N), C(N);
    rep(i, N) cin >> R[i] >> C[i];
    --R, --C;

    SegmentTreeonWaveletMatrix<ll, ll, Set, ABC369F> seg;

    vector<pll> coin(N);
    rep(i, N) {
        coin[i] = {R[i], C[i]};
        seg.add_point(R[i], C[i]);
    }

    sort(coin);
    seg.build(0);

    rep(i, N) {
        ll r, c;
        tie(r, c) = coin[i];

        auto x1 = seg.prod(r, c + 1);
        auto x2 = seg.prod(r + 1, c);

        if (x1 > x2) seg.apply(r, c, x1 + 1);
        else seg.apply(r, c, x2 + 1);
    }

    vector<Node<ll>> used;
    auto s = seg.prod(H, W);
    while (s.value != 0) {
        used.push_back(s);
        auto x1 = seg.prod(s.y, s.x + 1);
        auto x2 = seg.prod(s.y + 1, s.x);
        
        if (x1 > x2) s = x1;
        else s = x2;
    }

    reverse(used);
    cout << used.size() << endl;
    
    string ans;

    ll y = 0, x = 0;
    fore(node, used) {
        while (y < node.y) {
            ans += 'D';
            ++y;
        } 
        while (x < node.x) {
            ans += 'R';
            ++x;
        }
    }
    while (y < H - 1) {
        ans += 'D';
        ++y;
    }
    while (x < W - 1) {
        ans += 'R';
        ++x;
    }

    cout << ans << endl;

    return 0;
} 