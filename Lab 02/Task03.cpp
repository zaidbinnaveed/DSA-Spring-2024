#include <iostream>
using namespace std;

class ProductStockManager {
    int* stock;
    int size;
public:
    ProductStockManager(int n, int initialStock) : size(n) {
        stock = new int[n];
        for (int i = 0; i < n; i++) stock[i] = initialStock;
    }
    ProductStockManager(const ProductStockManager& other) : size(other.size) {
        stock = new int[size];
        for (int i = 0; i < size; i++) stock[i] = other.stock[i];
    }
    ProductStockManager& operator=(const ProductStockManager& other) {
        if (this != &other) {
            delete[] stock;
            size = other.size;
            stock = new int[size];
            for (int i = 0; i < size; i++) stock[i] = other.stock[i];
        }
        return *this;
    }
    ~ProductStockManager() { delete[] stock; }
    void setStock(int index, int quantity) { if (index >= 0 && index < size) stock[index] = quantity; }
    int getStock(int index) const { return (index >= 0 && index < size) ? stock[index] : -1; }
};

int main() {
    ProductStockManager p1(3, 50);
    ProductStockManager p2 = p1;
    p1.setStock(0, 100);
    cout << "Original: " << p1.getStock(0) << ", Copy: " << p2.getStock(0) << endl;
    return 0;
}
