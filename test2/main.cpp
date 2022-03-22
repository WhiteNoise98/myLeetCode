#include "bits/stdc++.h"

using namespace std;

mutex data_mutex;
condition_variable data_var;
bool flag = true;

void aPrint() {
    int i = 1;
    while (i <= 100) {
        unique_lock<mutex> lck(data_mutex);
        data_var.wait(lck,[]{return flag;}); // flag = true;
        cout << "a is printing :" << i << endl;
        i += 2;
        flag = false;
        data_var.notify_one();
    }
}
void bPrint() {
    int i = 2;
    while (i <= 100) {
        unique_lock<mutex> lck(data_mutex);
        data_var.wait(lck,[]{return !flag;}); // flag = true;
        cout << "b is printing :" << i << endl;
        i += 2;
        flag = true;
        data_var.notify_one();
    }
}

int main() {
    thread t_a(aPrint);
    thread t_b(bPrint);
    t_a.join();
    t_b.join();
    return 0;
}


