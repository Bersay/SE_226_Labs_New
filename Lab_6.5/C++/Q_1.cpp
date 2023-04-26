#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<int> common_elements(const std::vector<int>& list1, const std::vector<int>& list2) {
    std::unordered_set<int> set1(list1.begin(), list1.end());
    std::unordered_set<int> set2(list2.begin(), list2.end());
    std::vector<int> result;

    for (int num : set1) {
        if (set2.count(num)) {
            result.push_back(num);
        }
    }

    return result;
}

int main() {
    std::vector<int> list1 = {1, 2, 3, 4, 5};
    std::vector<int> list2 = {5, 6, 7, 8, 9, 10};
    std::vector<int> result = common_elements(list1, list2);

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
