#include <iostream>
#include <thread>

void ThreadProc()
{
    printf("Inside thread = %d", std::this_thread::get_id());
}

int main(){
std::thread t(ThreadProc);

t.join();

}