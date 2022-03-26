#include <iostream>
#include <array>
#include <numeric>

constexpr int constexprPow(int base, int pow) {
    int result = 1;
    while (pow) {
        result *= base;
        --pow;
    }
    return result;
}

constexpr int BASE = 13;
constexpr int LEN = 6;

constexpr int MAX_SUM = (BASE - 1) * LEN;
constexpr int MAX_NUMBER = constexprPow(BASE, LEN);

int digitSum(int n) {
    int result = 0;
    while (n > 0) {
        result += n % BASE;
        n /= BASE;
    }
    return result;
}

using Sums = std::array<int, MAX_SUM + 1>;

// Prepare map where key is digit sum for 6-digit number
// and value is count of such sums
auto getSums() {
    Sums result{};
    for (int current = 0; current < MAX_NUMBER; ++current) {
        ++result[digitSum(current)];
    }
    return result;
}

// For every 6-digit sum there is sum*sum*13 beauty numbers
auto  beautyCount(const Sums& sums) {
    int64_t count = 0;
    for (const int64_t c : sums) {
        count += c * c * BASE;
    }
    return count;
}

int main() {
    const auto sums = getSums();

    std::cout << "all sum = " << std::accumulate(sums.begin(), sums.end(), 0ll)
        << " must be " << MAX_NUMBER << '\n';

    const auto count = beautyCount(sums);

    std::cout << count << '\n';
}
