#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sieve_of_eratosthenes(const std::vector<int>& numbers) {
    if (numbers.size() < 2) {
        return {};
    }

    int max_number = *std::max_element(numbers.begin(), numbers.end());
    std::vector<bool> is_prime(max_number + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int num = 2; num * num <= max_number; ++num) {
        if (is_prime[num]) {
            for (int multiple = num * num; multiple <= max_number; multiple += num) {
                is_prime[multiple] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int num : numbers) {
        if (is_prime[num]) {
            primes.push_back(num);
        }
    }

    return primes;
}

int main() {
    std::vector<int> integer_list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::vector<int> result = sieve_of_eratosthenes(integer_list);

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
