#include <iostream>
#include <thread>

void ThreadProcI(int intValue) {
    printf("Inside thread: %d, Int Value: %d\n", std::this_thread::get_id(), intValue);
}

void ThreadProcF(float floatValue) {
    printf("Inside thread: %d, Float Value: %f\n", std::this_thread::get_id(), floatValue);
}

void ThreadProcD(double* doublePtr) {
    printf("Inside thread: %d, Double Value: %f\n", std::this_thread::get_id(), *doublePtr);
}

int main() {
    int intValue = 15;
    float floatValue = 3.14f;
    double doubleValue = 2.71828;

    std::thread threadInt(ThreadProcI, intValue);
    std::thread threadFloat(ThreadProcF, floatValue);
    std::thread threadDouble(ThreadProcD, &doubleValue);

    threadInt.join();
    threadFloat.join();
    threadDouble.join();

    return 0;
}
