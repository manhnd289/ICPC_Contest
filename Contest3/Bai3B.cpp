#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll; // Định nghĩa kiểu dữ liệu long long để xử lý số lớn

vector<ll> primes; // Vector để lưu trữ các số nguyên tố
map<ll, ll> memo;  // Map để lưu trữ kết quả đã tính toán của F(K) nhằm tối ưu hóa

// Hàm sieve để tìm các số nguyên tố nhỏ hơn hoặc bằng max_limit
void sieve(int max_limit) {
    // Khởi tạo một vector đánh dấu tất cả các số là nguyên tố (true)
    vector<bool> is_prime(max_limit + 1, true);
    
    // Bắt đầu từ 2, tìm các số nguyên tố và đánh dấu bội số của chúng là không phải nguyên tố
    for (int i = 2; i <= max_limit; ++i) {
        if (is_prime[i]) {  // Nếu i là số nguyên tố
            primes.push_back(i); // Thêm i vào danh sách số nguyên tố
            for (int j = i * i; j <= max_limit; j += i) {
                is_prime[j] = false; // Đánh dấu tất cả bội số của i là không phải nguyên tố
            }
        }
    }
}

// Hàm calculate_F để tính F(K) - số cách phân tích K thành tích các thừa số nguyên tố
ll calculate_F(ll K) {
    // Kiểm tra nếu kết quả của F(K) đã được tính trước đó và lưu trong memo
    if (memo.find(K) != memo.end()) return memo[K];
    
    ll result = 1; // Bắt đầu với kết quả là 1
    ll temp = K;   // Lưu giá trị K vào biến tạm temp
    
    // Phân tích K thành các thừa số nguyên tố
    for (ll i = 2; i * i <= temp; ++i) {
        int count = 0;
        while (temp % i == 0) {
            temp /= i; // Chia temp cho i nếu i là thừa số của temp
            ++count;   // Tăng đếm số lần chia cho i
        }
        result *= (count + 1); // Nhân kết quả với (count + 1)
    }
    
    // Nếu phần còn lại của temp là số nguyên tố lớn hơn sqrt(K)
    if (temp > 1) result *= 2;
    
    // Lưu kết quả vào memo để lần sau không cần tính lại
    memo[K] = result;
    return result;
}

// Hàm find_smallest_K để tìm số K nhỏ nhất sao cho F(K) = N
ll find_smallest_K(ll N) {
    ll K = 1; // Bắt đầu với K = 1
    while (true) {
        // Tính F(K) và kiểm tra nếu F(K) bằng N thì trả về K
        if (calculate_F(K) == N) return K;
        ++K; // Tăng K và thử lại
    }
}

int main() {
    sieve(100); // Sinh các số nguyên tố nhỏ hơn hoặc bằng 100
    
    int T;
    cin >> T; // Nhập số lượng test case
    
    while (T--) {
        ll N;
        cin >> N; // Nhập giá trị N
        cout << find_smallest_K(N) << endl; // In ra K nhỏ nhất sao cho F(K) = N
    }
    
    return 0;
}
