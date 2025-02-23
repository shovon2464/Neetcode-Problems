#include<iostream>
#include<vector>
using namespace std;

int main() {
    int count = -1;
    vector<int> tracker{ 2,3,4,5 };
    vector<int> result;
    cout << tracker.size();
    if (count > tracker.size()) {
        cout << "Hi";
    }
    return 0;
}