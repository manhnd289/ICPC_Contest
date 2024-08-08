#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();
    // Lưu 1 mảng check reverse tại mỗi vị trí
    vector<int> rev(n + 1, 0);

    int m;
    cin >> m;
    // Nhập số phép biến đổi
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        // Lấy chỉ số của phép biến đổi
        int l = a - 1;   // Vị trí bắt đầu đảo
        int r = n - a;   // Vị trí kết thúc n-1 - (a-1)
        rev[l] += 1;    // Tăng số lần đảo cho phép đảo từ l-r
        if (r + 1 <= n) rev[r + 1] -= 1;    // Giảm 1 cho phép khi tổng tích lũy duyệt đến cuối đoạn thì sẽ kết thúc đoạn cần đảo
    }

    int curr_rev = 0;
    for (int i = 0; i < n; i++) {
        // Duyệt qua mảng đánh dấu và cộng dồn giá trị vào 
        curr_rev += rev[i];
        // Nếu tổng tích lũy lẻ -> cần phải đảo đaoọn từ đây, nếu ngay sau đó vẫn cần đảo thì tổng tích lũy sẽ chẵn và việc đảo  này là không cần thiết
        if (curr_rev % 2 == 1) {
            // Nếu phần tử hiện tại có chỉ số nhỏ hơn phần tử cuối đoạn đảo mới cho đảo còn không sẽ bị thừa và gây lỗi đảo 2 lần
            int j = n - i - 1;
            if (i < j) {
                swap(s[i], s[j]);
            }
        }
    }

    cout << s << endl;
    return 0;
}
