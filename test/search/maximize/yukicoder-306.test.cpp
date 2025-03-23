#define IGNORE
#define PROBLEM "https://yukicoder.me/problems/no/306"

#include "../../../search/maximize.cpp"

int main() {
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    long double xa2 = xa * xa;
    long double xb2 = xb * xb;

    auto f = [&](double y) {
        return -sqrt(xa2 + (ya - y) * (ya - y)) + sqrt(xb2 + (yb - y) * (yb - y));
    };

    double y = maximize(f, 0., 1000.);
    cout << fixed << setprecision(10);
    cout << y << endl;

    return 0;
} 
