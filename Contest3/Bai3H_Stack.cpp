#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long solve(int N, vector<int>& P) {
    stack<int> s;
    long long result = 0;

    // Duyệt qua từng phần tử trong mảng P
    for (int i = 0; i < N; i++) {
        // Xử lý các phần tử trong stack mà nhỏ hơn hoặc bằng P[i]
        while (!s.empty() && P[s.top()] <= P[i]) {
            int mid = s.top();
            s.pop();
            int left = s.empty() ? -1 : s.top();

            // Tính đóng góp của P[mid] vào kết quả
            // (mid - left): số phần tử bên trái mà P[mid] là số lớn thứ hai
            // (i - mid): số phần tử bên phải mà P[mid] là số lớn thứ hai
            result += (long long)P[mid] * (mid - left) * (i - mid);
        }
        // Thêm chỉ số hiện tại vào stack
        s.push(i);
    }

    // Xử lý các phần tử còn lại trong stack
    while (!s.empty()) {
        int mid = s.top();
        s.pop();
        int left = s.empty() ? -1 : s.top();

        // Tính đóng góp của các phần tử còn lại
        // Ở đây, N đóng vai trò là biên phải
        result += (long long)P[mid] * (mid - left) * (N - mid);
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    cout << solve(N, P) << endl;
    return 0;
}