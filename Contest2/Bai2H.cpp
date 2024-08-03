#include <bits/stdc++.h>
using namespace std;

// Tìm tất cả các tập con có thể
void findSubsets(vector<int>& A, unordered_map<int, vector<int>>& subsetSums) {

    // Tính số tập con có thể có (các phần tử không cần liên tục) bằng cách dịch bit nhị phân
    int totalSubsets = 1 << A.size();
    
    // Duyệt qua các tập con có thể có (không tính tập mà không có phần tử nào)
    for (int i = 1; i < totalSubsets; ++i) {
        int sum = 0;
        // Duyệt qua các phần tử của mảng
        for (int j = 0; j < A.size(); ++j) {
            // Nếu bit thứ j của số nhị phân i là 1 -> Phần tử tại vị trí j có trong tập đang xét
            if (i & (1 << j)) {
                // Cộng dồn vào tổng của tập đang xét
                sum += A[j];
            }
        }
        //  Lưu lại tổng và key là stt của tập con đó để chuyển đổi sang nhị phân
        subsetSums[sum].push_back(i);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Map lưu tổng của tập con theo stt trong hệ nhị phân, 1 tổng có thể có nhiều tập con của tổng đó
    unordered_map<int, vector<int>> subsetSums;
    findSubsets(A, subsetSums);

    set<int> result;
    // Duyệt qua mỗi tổng và các stt tập con của nó
    for (const auto& pair : subsetSums) {
        const vector<int>& subsets = pair.second;   // Lấy stt của các tập con
        int len = subsets.size();
        // Duyệt qua các tập con được lưu theo tổng
        for (int i = 0; i < len; ++i) {
            // Xét các tập con đằng sau đó
            for (int j = i + 1; j < len; ++j) {
                /*
                Nếu 2 stt của 2 tập con có cùng tổng trong hệ nhị phân mà and với nhau = 0 nghĩa là các phần tử đều khác nhau -> Lưu tổng lại và thoát 
                Không tìm nữa do chỉ cần biết có tồn tại 2 tập con cùng tổng này là được, còn không thì vẫn phải tìm tiếp các tập con khác đằng sau đó.
                */
                if ((subsets[i] & subsets[j]) == 0) {
                    result.insert(pair.first);
                    break;
                }
            }
            // Trong khi đang tìm 2 tập con nào có cùng tổng mà không giao nhau hay không, nếu trong set đã có tổng đang xét -> Chuyển sang tổng tiếp theo để tìm tiếp
            if (result.find(pair.first) != result.end()) {
                break;
            }
        }
    }

    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
