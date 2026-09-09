#include "Array.hpp"

int main() {
    Array<int> empty;
    Array<int> arr(5);

    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = i;
    }

    Array<int> copy(arr);
    copy[0] = 999;

    Array<int> assigned;
    assigned = arr;
    assigned[1] = 888;

    std::cout << empty.size() << "\n";
    std::cout << arr[0] << " " << copy[0] << "\n";
    std::cout << arr[1] << " " << assigned[1] << "\n";

    try {
        arr[5] = 42;
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    try {
        empty[0] = 1;
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}
