#include <iostream>
#include <future>

int sum(int a, int b) {
    return a + b;
}

int main() {
    std::cout << "Введите два числа для сложения: ";
    int input_a, input_b;
    std::cin >> input_a >> input_b;
    std::future<int> future_sum = std::async(std::launch::async, sum, input_a, input_b);
    int result = future_sum.get();
    std::cout << "Сумма: " << result << std::endl;

    return 0;
}
