#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Để sử dụng gcd

using namespace std;

struct Segment {
    long long A, B;
};

bool compare(Segment s1, Segment s2) {
    return s1.B * s2.A < s2.B * s1.A;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;

    vector<Segment> segments(N);
    for (int i = 0; i < N; ++i) {
        cin >> segments[i].A >> segments[i].B;
    }

    sort(segments.begin(), segments.end(), compare);

    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        sumA += segments[i].A;
        sumB += segments[i].B;

        if (sumA <= sumB) {
            // Thỏ đã bắt kịp Rùa tại đoạn i
            cout << "1 1" << endl;
            return 0;
        }
    }

    // Nếu không bắt kịp ở bất kỳ đoạn nào, tính xác suất dưới dạng phân số tối giản
    long long P = sumA, Q = sumB;
    if (P < Q) swap(P, Q); // Đảm bảo P luôn lớn hơn hoặc bằng Q

    long long g = gcd(P, Q);
    P /= g;
    Q /= g;

    cout << P << " " << Q << endl;

    return 0;
}
