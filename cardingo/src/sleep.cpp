#include <chrono>
#include <thread>
using namespace std;

void wait(int s) {
    this_thread::sleep_for(chrono::seconds(s));
}