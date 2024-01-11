#include <iostream>
#include <thread>
#include <mutex>

std::mutex resultMutex;

void scalarProductThread(const double* vec1, const double* vec2, size_t start, size_t end, double& partialResult) {
    double localResult = 0;

    for (size_t i = start; i < end; ++i) {
        localResult += vec1[i] * vec2[i];
    }

    resultMutex.lock(); // Явный вызов lock
    partialResult += localResult;
    resultMutex.unlock(); // Явный вызов unlock
}

int main() {
    double a[5];
    double b[5];
    double res = 0;

    std::cout << "a = ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> a[i];
    }

    std::cout << "b = ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> b[i];
    }

    const int numThreads = 3;
    const int chunkSize = 5 / numThreads;

    std::thread threads[numThreads];

    double localResults[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? 5 : start + chunkSize;
        threads[i] = std::thread([&, start, end, i]() {
            scalarProductThread(a, b, start, end, localResults[i]);
        });
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    for (int i = 0; i < numThreads; ++i) {
        res += localResults[i];
    }

    std::cout << "a.b = " << res << std::endl;

    return 0;
}
