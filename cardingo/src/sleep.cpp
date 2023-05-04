#include <chrono>
#include <thread>
using namespace std;

void wait(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}