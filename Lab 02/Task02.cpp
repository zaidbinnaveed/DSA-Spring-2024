#include <iostream>
using namespace std;

class StudentFeeManager {
    int* fees;
    int size;
public:
    StudentFeeManager(int n, int fee) : size(n) {
        fees = new int[n];
        for (int i = 0; i < n; i++) fees[i] = fee;
    }
    StudentFeeManager(const StudentFeeManager& other) : size(other.size) {
        fees = new int[size];
        for (int i = 0; i < size; i++) fees[i] = other.fees[i];
    }
    StudentFeeManager& operator=(const StudentFeeManager& other) {
        if (this != &other) {
            delete[] fees;
            size = other.size;
            fees = new int[size];
            for (int i = 0; i < size; i++) fees[i] = other.fees[i];
        }
        return *this;
    }
    ~StudentFeeManager() { delete[] fees; }
    void setFee(int index, int fee) { if (index >= 0 && index < size) fees[index] = fee; }
    int getFee(int index) const { return (index >= 0 && index < size) ? fees[index] : -1; }
};

int main() {
    StudentFeeManager s1(3, 1000);
    StudentFeeManager s2 = s1;
    s1.setFee(1, 2000);
    cout << "Original: " << s1.getFee(1) << ", Copy: " << s2.getFee(1) << endl;
    return 0;
}
