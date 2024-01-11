#include <iostream>
#include <vector>
#include <omp.h>

void Vectors(std::vector<int>& result, const std::vector<int>& a, const std::vector<int>& b) {
    #pragma omp parallel for
    for (size_t i = 0; i < result.size(); ++i)
        result[i] = a[i] + b[i];
}

int main() {
    const int size = 5;
    std::vector<int> a(size), b(size);

    std::cout << "Введите элементы вектора А: ";
    for (int& elem : a) {
        std::cin >> elem;
    }

    std::cout << "Введите элементы вектора B: ";
    for (int& elem : b) {
        std::cin >> elem;
    }

    std::vector<int> result(size);
    Vectors(result, a, b);

 
    std::cout << "Сумма векторов:";
    for (int elem : result) {
        std::cout << ' ' << elem;
    }
    std::cout << std::endl;

    return 0;
}
