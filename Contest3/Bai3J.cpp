#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005; // Giới hạn số lượng đỉnh tối đa theo đề bài.
const int LOG = 20; // Độ sâu tối đa dùng cho Sparse Table, ước lượng dựa trên log2 của MAXN.
const int MOD = 1e9 + 7; // Giá trị modulo để tránh overflow khi tính toán kết quả.
vector<int> adj[MAXN]; // Danh sách kề: lưu danh sách các đỉnh kề với mỗi đỉnh.
int depth[MAXN], parent[LOG][MAXN]; // 'depth' lưu độ sâu của mỗi đỉnh, 'parent' lưu Sparse Table cho LCA.
int w[MAXN], gcdTable[MAXN]; // 'w' lưu trọng số mỗi đỉnh, 'gcdTable' lưu GCD của đường đi đến mỗi đỉnh.
int n; // Số lượng đỉnh của cây.

// Hàm tính GCD (ước chung lớn nhất) của hai số nguyên.
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Duyệt cây bằng DFS để tính độ sâu và thông tin LCA cho mỗi đỉnh.
void dfs(int node, int par, int dep) {
    parent[0][node] = par; // Lưu đỉnh cha trực tiếp của 'node'.
    depth[node] = dep; // Lưu độ sâu của 'node'.
    gcdTable[node] = w[node]; // Khởi tạo GCD của đỉnh là trọng số của chính nó.
    if (par != -1) {
        gcdTable[node] = gcd(gcdTable[node], gcdTable[par]); // Cập nhật GCD của đường đi.
    }
    for (int child : adj[node]) {
        if (child != par) { // Tránh đi ngược trở lại đỉnh cha
            dfs(child, node, dep + 1);
        }
    }
}

// Chuẩn bị dữ liệu cho truy vấn LCA bằng cách sử dụng Sparse Table.
void preprocessLCA() {
    dfs(1, -1, 0); // Bắt đầu DFS từ đỉnh 1 với đỉnh cha là -1 và độ sâu là 0.
    for (int i = 1; i < LOG; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (parent[i-1][j] != -1) {
                parent[i][j] = parent[i-1][parent[i-1][j]]; // Xây dựng Sparse Table cho LCA.
            } else {
                parent[i][j] = -1;
            }
        }
    }
}

// Trả về LCA (tổ tiên chung thấp nhất) của hai đỉnh u và v sử dụng Sparse Table.
int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v); // Đảm bảo rằng 'u' luôn có độ sâu lớn hơn hoặc bằng 'v'.
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i) { // Nâng 'u' lên để có cùng độ sâu với 'v'.
        if (diff & (1 << i)) {
            u = parent[i][u];
        }
    }
    if (u == v) return u; // Nếu 'u' là 'v', đã tìm thấy LCA.
    for (int i = LOG - 1; i >= 0; --i) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v]; // Di chuyển 'u' và 'v' lên cho đến khi chúng cùng ở ngay dưới LCA.
        }
    }
    return parent[0][u]; // Trả về cha của 'u' hoặc 'v' (cùng một đỉnh vì chúng giờ ở ngay dưới LCA).
}

int main() {
    ios_base::sync_with_stdio(false); // Tắt đồng bộ hóa giữa C++ và C I/O streams để tăng tốc độ nhập xuất.
    cin.tie(NULL); // Tắt cơ chế flush 'cout' trước mỗi lần 'cin'.

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i]; // Đọc trọng số của mỗi đỉnh.
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v; // Đọc cạnh của cây.
        adj[u].push_back(v); // Thêm 'v' vào danh sách kề của 'u'.
        adj[v].push_back(u); // Thêm 'u' vào danh sách kề của 'v'.
    }

    preprocessLCA(); // Chuẩn bị dữ liệu cho các truy vấn LCA.

    long long result = 0; // Biến lưu trữ kết quả cuối cùng.
    // Vòng lặp để tính tổng f(x, y, z) * g(x, y, z) cho mọi bộ ba đỉnh.
    for (int x = 1; x <= n; ++x) {
        for (int y = x + 1; y <= n; ++y) {
            for (int z = y + 1; z <= n; ++z) {
                int lca_xy = LCA(x, y);
                int lca_yz = LCA(y, z);
                int lca_xz = LCA(x, z);
                int lca_xyz = LCA(lca_xy, z); // Giả sử đây là LCA chính xác cho ba đỉnh.
                int dist_xyz = depth[x] + depth[y] + depth[z] - 2 * depth[lca_xyz]; // Tính tổng khoảng cách.
                int gcd_xyz = gcd(gcdTable[x], gcd(gcdTable[y], gcdTable[z])); // Tính GCD của ba đỉnh.
                result = (result + (long long)dist_xyz * gcd_xyz) % MOD; // Cập nhật kết quả.
            }
        }
    }
    cout << result / 6 % MOD << endl; // In ra kết quả cuối cùng, chia cho 6 để chỉ tính mỗi bộ ba một lần.
    return 0;
}
