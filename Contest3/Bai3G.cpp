#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;  // Số đoạn đường
    cin >> N;

    vector<pair<long long, long long>> speeds(N);  // Vector lưu tốc độ Thỏ và Rùa cho mỗi đoạn
    for (int i = 0; i < N; ++i) {
        cin >> speeds[i].first >> speeds[i].second;  // Nhập tốc độ của Thỏ và Rùa trên mỗi đoạn
    }

    // Sắp xếp các đoạn đường để tối đa hóa khả năng Rùa giữ khoảng cách
    sort(speeds.begin(), speeds.end(), [](const pair<long long, long long>& x, const pair<long long, long long>& y) {
        // So sánh tỷ lệ tốc độ Rùa / Thỏ để đảm bảo Rùa duy trì khoảng cách xa nhất có thể
        return x.second * y.first > y.second * x.first;
    });

    double maxTimeRabbitCanCatchUp = 0.0;  // Thời gian tối đa mà Thỏ có thể bắt kịp Rùa

    // Tính toán thời điểm tối đa mà Thỏ có thể bắt kịp Rùa
    double timeRabbit = 0, timeTurtle = 0;  // Tổng thời gian Thỏ và Rùa mất để hoàn thành cuộc đua
    for (int i = 0; i < N; ++i) {
        timeRabbit += speeds[i].first;  // Cộng dồn thời gian Thỏ chạy qua mỗi đoạn
        timeTurtle += speeds[i].second;  // Cộng dồn thời gian Rùa chạy qua mỗi đoạn
        double catchUpTime = timeTurtle - timeRabbit;  // Tính thời gian Rùa còn dẫn trước Thỏ
        if (catchUpTime > maxTimeRabbitCanCatchUp) {
            maxTimeRabbitCanCatchUp = catchUpTime;  // Cập nhật thời gian lớn nhất Thỏ có thể bắt kịp
        }
    }

    // Xác suất Thỏ thắng
    double probabilityRabbitWins = maxTimeRabbitCanCatchUp / timeTurtle;

    // Định dạng kết quả dưới dạng phân số
    long long numerator = static_cast<long long>(probabilityRabbitWins * N + 0.5);  // Tử số của xác suất
    long long denominator = N;  // Mẫu số của xác suất
    long long g = __gcd(numerator, denominator);  // Tính GCD để rút gọn phân số
    numerator /= g;  // Rút gọn tử số
    denominator /= g;  // Rút gọn mẫu số

    cout << numerator << " " << denominator << endl;  // Xuất kết quả dưới dạng phân số tối giản

    return 0;
}
