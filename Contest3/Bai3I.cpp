#include <iostream>
#include <vector>

std::vector<bool> sieve(int n) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    return isPrime;
}

int countPrimePairs(int n) {
    std::vector<bool> isPrime = sieve(n);
    int count = 0;
    for (int a = 2; a <= n / 2; ++a) {
        if (isPrime[a] && isPrime[n - a]) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    int result = countPrimePairs(n);
    std::cout << result << std::endl;
    return 0;
}
