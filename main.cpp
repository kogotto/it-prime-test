#include <iostream>
#include <array>

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

void print(const Sums& sums) {
    for (int i = 0; i < sums.size(); ++i) {
        std::cout << "sum = " << i << " count = " << sums[i] << '\n';
    }
}

auto getSums() {
    Sums result{};
    for (int current = 0; current < MAX_NUMBER; ++current) {
        ++result[digitSum(current)];
    }
    print(result);
    return result;
}

#define pr(s) {std::cout << #s << " = " << (s) << '\n';}

auto  beautyCount(const Sums& sums) {
    int64_t count = 0;
    for (const int64_t c : sums) {
        count += c * c * BASE;
    }
    return count;
}

int main() {
    const auto sums = getSums();

    pr(digitSum(0));
    pr(digitSum(1));
    pr(digitSum(13));
    pr(digitSum(13+1));
    pr(digitSum(2*13 + 5));

    const auto count = beautyCount(sums);

    std::cout << count << '\n';
}
