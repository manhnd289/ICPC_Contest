#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int max1, max2;  // Lưu trữ hai giá trị lớn nhất và lớn thứ hai trong đoạn
};

// Hàm xây dựng Segment Tree
void buildSegmentTree(vector<Node>& st, const vector<int>& arr, int si, int ss, int se) {
    if (ss == se) {
        st[si] = {arr[ss], -1}; // Nếu chỉ có một phần tử, max2 không tồn tại, gán bằng -1
        return;
    }
    int mid = (ss + se) / 2;
    // Xây dựng cây cho nửa trái và nửa phải
    buildSegmentTree(st, arr, 2 * si + 1, ss, mid);
    buildSegmentTree(st, arr, 2 * si + 2, mid + 1, se);
    // Kết hợp kết quả từ hai nửa để tạo nút cha
    vector<int> temp = {st[2 * si + 1].max1, st[2 * si + 1].max2, st[2 * si + 2].max1, st[2 * si + 2].max2};
    sort(temp.begin(), temp.end(), greater<int>()); // Sắp xếp để tìm hai giá trị lớn nhất
    st[si].max1 = temp[0]; // Giá trị lớn nhất
    st[si].max2 = temp[1]; // Giá trị lớn thứ hai
}

// Hàm truy vấn Segment Tree để tìm max1 và max2 trong khoảng [qs, qe]
Node query(const vector<Node>& st, int si, int ss, int se, int qs, int qe) {
    if (qs <= ss && qe >= se) {
        // Trả về nút hiện tại nếu đoạn [ss, se] nằm hoàn toàn trong đoạn truy vấn [qs, qe]
        return st[si];
    }
    if (se < qs || ss > qe) {
        return {-1, -1}; // Trả về {-1, -1} nếu đoạn không giao nhau
    }
    int mid = (ss + se) / 2;
    // Truy vấn đệ quy nửa trái và nửa phải
    Node left = query(st, 2 * si + 1, ss, mid, qs, qe);
    Node right = query(st, 2 * si + 2, mid + 1, se, qs, qe);
    // Kết hợp kết quả từ hai nửa
    vector<int> temp = {left.max1, left.max2, right.max1, right.max2};
    sort(temp.begin(), temp.end(), greater<int>());
    return {temp[0], temp[1]};
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];  // Nhập mảng
    }
    
    vector<Node> st(4 * N);  // Khởi tạo vector để lưu Segment Tree
    buildSegmentTree(st, P, 0, 0, N - 1);  // Xây dựng Segment Tree
    
    long long totalSum = 0;
    for (int L = 0; L < N - 1; L++) {
        for (int R = L + 1; R < N; R++) {
            Node result = query(st, 0, 0, N - 1, L, R);
            if (result.max2 != -1) { // Kiểm tra xem có giá trị lớn thứ hai hợp lệ
                totalSum += result.max2;  // Tính tổng các số lớn thứ hai
            }
        }
    }
    
    cout << totalSum << endl;  // In ra tổng
    return 0;
}
