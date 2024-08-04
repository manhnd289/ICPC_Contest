#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Cấu trúc ma trận 2x2
struct Matrix {
    ll mat[2][2];
};

// Nhân hai ma trận
Matrix matrixMultiply(const Matrix &a, const Matrix &b, ll mod) {
    Matrix result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.mat[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result.mat[i][j] = (result.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % mod;
            }
        }
    }
    return result;
}

// Tính lũy thừa ma trận
Matrix matrixPower(Matrix base, ll exp, ll mod) {
    Matrix result = {{{1, 0}, {0, 1}}};  // ma trận đơn vị
    while (exp > 0) {
        if (exp % 2 == 1) result = matrixMultiply(result, base, mod);
        base = matrixMultiply(base, base, mod);
        exp /= 2;
    }
    return result;
}

// Tính F(n) % mod
ll fibonacciMod(ll n, ll mod) {
    if (n == 0) return 0;
    Matrix fibMatrix = {{{1, 1}, {1, 0}}};
    Matrix result = matrixPower(fibMatrix, n - 1, mod);
    return result.mat[0][0];
}

// Tính GCD
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b, M;
        cin >> a >> b >> M;
        ll g = gcd(a, b);
        cout << fibonacciMod(g, M) << endl;
    }
    return 0;
}
