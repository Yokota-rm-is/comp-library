#define PROBLEM "https://atcoder.jp/contests/abc345/tasks/abc345_d"

#include "../../../search/trit-zentansaku.cpp"

struct Coordinate {
    long long y, x;

    Coordinate(long long y_ = 0, long long x_ = 0) : y(y_), x(x_) {};

    double euclid() {
        return sqrt(pow(y, 2) + pow(x, 2));
    }

    double euclid_from(const Coordinate &other) {
        return Coordinate(y - other.y, x - other.x).euclid();
    }

    long long manhattan() {
        return abs(y) + abs(x);
    }

    long long manhattan_from(const Coordinate &other) {
        return Coordinate(y - other.y, x - other.x).manhattan();
    }

    Coordinate char2dir(char c) {
        assert(c == 'R' or c == 'L' or c == 'U' or c == 'D');
        Coordinate ret(y, x);

        if (c == 'D') ++ret.y;
        if (c == 'U') --ret.y;
        if (c == 'R') ++ret.x;
        if (c == 'L') --ret.x;

        return ret;
    }

    char dir2char() {
        assert(manhattan() == 1);

        char ret;
        if (x > 0) ret = 'R';
        if (x < 0) ret = 'L';
        if (y > 0) ret = 'D';
        if (y < 0) ret = 'U';

        return ret;
    }

    char dir2char(Coordinate next) {
        Coordinate dir = next - *this;
        return dir.dir2char();
    }

    Coordinate operator- () {
        return Coordinate(y, x) *= -1;
    }

    Coordinate operator+ (const Coordinate &other) {
        return Coordinate(y, x) += other;
    }

    Coordinate operator- (const Coordinate &other) {
        return Coordinate(y, x) -= other;
    }

    Coordinate operator+ (const long long &a) {
        return Coordinate(y, x) += a;
    }

    Coordinate operator- (const long long &a) {
        return Coordinate(y, x) -= a;
    }

    Coordinate operator* (const long long &a) {
        return Coordinate(y, x) *= a;
    }

    Coordinate operator/ (const long long &a) {
        return Coordinate(y, x) /= a;
    }

    Coordinate operator% (const long long &a) {
        return Coordinate(y, x) %= a;
    }

    Coordinate& operator+= (Coordinate other) {
        this->y += other.y;
        this->x += other.x;
        return *this;
    }

    Coordinate& operator-= (Coordinate other) {
        this->y -= other.y;
        this->x -= other.x;
        return *this;
    }

    Coordinate& operator+= (long long a) {
        this->y += a;
        this->x += a;
        return *this;
    }

    Coordinate& operator-= (long long a) {
        this->y -= a;
        this->x -= a;
        return *this;
    }

    Coordinate& operator*= (long long a) {
        this->y *= a;
        this->x *= a;
        return *this;
    }

    Coordinate& operator/= (long long a) {
        this->y /= a;
        this->x /= a;
        return *this;
    }

    Coordinate& operator%= (long long a) {
        this->y %= a;
        this->x %= a;
        return *this;
    }

    bool operator== (const Coordinate &other) {
        return y == other.y and x == other.x;
    }

    bool operator!= (const Coordinate &other) {
        return y != other.y or x != other.x;
    }

    bool operator< (const Coordinate &other) {
        if (y == other.y) {
            return x < other.x;
        }
        else return y < other.y;
    }

    friend ostream& operator << (ostream &os, const Coordinate& p) {
        return os << "(" << p.y << ", " << p.x << ")";
    }
};

template<typename T>
struct Grid {
    long long H;
    long long W;
    vector<vector<T>> vv;

    Grid(long long h = 0, long long w = 0, T a = T()) : H(h), W(w), vv(h, vector<T>(w, a)) {}
    Grid(vector<vector<T>> A) : H(A.size()), W(A[0].size()), vv(A) {}

    T& operator() (size_t i, size_t j) {
        return vv[i][j];
    }

    T& operator() (const Coordinate& p) {
        return vv[p.y][p.x];
    }

    void assign(long long h, long long w, T a) {
        H = h;
        W = w;
        vv.assign(h, vector<T>(w, a));
    }

    vector<T>& operator[] (size_t i) {
        return vv[i];
    } 

    friend ostream& operator << (ostream &os, Grid<T>& grid) {
        rep(i, grid.H) {
            os << grid[i] << endl;
        }
        return os;
    }
};

template<>
struct Grid<bool> {
    long long H;
    long long W;
    vector<vector<bool>> vv;

    Grid(long long h = 0, long long w = 0, bool a = false) : H(h), W(w), vv(h, vector<bool>(w, a)) {}
    Grid(vector<vector<bool>> A) : H(A.size()), W(A[0].size()), vv(A) {}

    vector<bool>::reference operator() (size_t i, size_t j) {
        return vv[i][j];
    }

    vector<bool>::reference operator() (const Coordinate& p) {
        return vv[p.y][p.x];
    }

    void assign(long long h, long long w, bool a) {
        H = h;
        W = w;
        vv.assign(h, vector<bool>(w, a));
    }

    vector<bool>& operator[] (size_t i) {
        return vv[i];
    } 

    friend ostream& operator << (ostream &os, Grid<bool>& grid) {
        rep(i, grid.H) {
            os << grid[i] << endl;
        }
        return os;
    }
};

struct Field {
    long long H;
    long long W;
    vector<string> vs;
    char obj = '#';

    Field(long long h, long long w) :H(h), W(w), vs(h, string(w, '.')) {}
    Field(vector<string>& A) : H(A.size()), W(A.front().size()), vs(A) {}

    char& operator() (size_t y, size_t x) {
        return vs[y][x];
    }

    char& operator() (const Coordinate& p) {
        return vs[p.y][p.x];
    }

    bool is_obj(size_t y, size_t x) {
        return vs[y][x] == obj;
    }

    bool is_obj(const Coordinate& p) {
        return vs[p.y][p.x] == obj;
    }

    bool is_out(long long y, long long x) {
        return y < 0 or y >= H or x < 0 or x >= W;
    }

    bool is_out(const Coordinate& p) {
        return p.y < 0 or p.y >= H or p.x < 0 or p.x >= W;
    }

    string& operator[] (size_t i) {
        return vs[i];
    }

    friend ostream& operator << (ostream &os, Field& field) {
        rep(i, field.H) {
            os << field[i] << endl;
        }
        return os;
    }
};


int main() {
    ll N, H, W;
    cin >> N >> H >> W;

    vll A(N), B(N);

    rep(i, N) {
        cin >> A[i] >> B[i];
    }

    vector<pll> v(N);

    bool ans = false;

    for (long long bit = 0; bit < binpow(3ll, N); ++bit) {
        ll x = bit;
        rep(i, N) {
            v[i] = {i, x % 3};
            x /= 3;
        }

        vector<pll> C;

        rep(i, N) {
            ll a = A[i], b = B[i];
            if (v[i].second == 0) {
                // i番目が0の処理を書く
                continue;
            }
            else if (v[i].second == 1) {
                // i番目が1の処理を書く
                C.emplace_back(a, b);
            }
            else {
                // i番目が2の処理を書く
                swap(a, b);
                C.emplace_back(a, b);
            }
        }

        do {
            Field field(H, W);

            bool flg = true;

            ll idx = 0;
            rep(t, H) {
                rep(l, W) {
                    if (field.is_obj({t, l})) continue;

                    if (idx == C.size()) {
                        flg = false;
                        break;
                    }
                    
                    auto [a, b] = C[idx];
                    if (field.is_out({t + a - 1, l + b - 1})) {
                        flg = false;
                        break;
                    }

                    rep(i, b) {
                        if (field.is_obj({t, l + i})) {
                            flg = false;
                        }
                    }
                    if (!flg) break;

                    rep(y, t, t + a) rep(x, l, l + b) field({y, x}) = '#';
                    ++idx;
                }
                if (!flg) break;
            }

            if (flg) {
                ans = true;
                break;
            }

        } while (next_permutation(C.begin(), C.end()));
        
        if (ans) break;
    }

    cout << YesNo(ans) << endl;


    return 0;
}