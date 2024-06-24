#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
square(const T& value) {
    return value * value;
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, std::vector<T>>::type
square(const std::vector<T>& vec) 
{
    std::vector<T> result;
    result.reserve(vec.size());

    for (const auto& elem : vec) {
        result.push_back(square(elem));
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int num = 4;
    std::cout << "Квадрат " << num << " равен " << square(num) << std::endl;

    std::vector<int> vec = { -1, 4, 8 };

 
    std::cout << "Квадрат вектора: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }

    std::vector<int> squared_vec = square(vec);
    std::cout << " равен ";
    for (const auto& elem : squared_vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
