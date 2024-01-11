#include <iostream>
#include <vector>
#include <omp.h>

int scalarVectors(const std::vector<int>& a, const std::vector<int>& b) {
    int result = 0;

    #pragma omp parallel for reduction(+:result)
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }

    return result;
}

int main() {
    const int size = 5;
    std::vector<int> a(size), b(size);
    std::cout << "Введите элементы вектора А: ";
    for (int& elem : a) {
        std::cin >> elem;
    }

    std::cout << "Введите элементы вектора Б: ";
    for (int& elem : b) {
        std::cin >> elem;
    }
    int result = scalarVectors(a, b);
    std::cout << "Произведение векторов: " << result << std::endl;

    return 0;
}
