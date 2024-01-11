#include <iostream>
#include <thread>

int main() {
    // Индексная переменная
    int i;

    // Первый массив
    double a[5];

    // Второй массив
    double b[5];

    // Переменная для записи результата
    double res = 0;

    // Ввод элементов первого массива
    std::cout << "a = ";
    for (i = 0; i < 5; i++) {
        std::cin >> a[i];
    }

    // Ввод элементов второго массива
    std::cout << "b = ";
    for (i = 0; i < 5; i++) {
        std::cin >> b[i];
    }

    // Вычисление скалярного произведения
    for (i = 0; i < 5; i++) {
        res += a[i] * b[i];
    }

    // Отображение результата
    std::cout << "a.b = " << res << std::endl;

    return 0;
}
