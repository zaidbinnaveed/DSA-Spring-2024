#include <iostream>
using namespace std;

class FruitShopInventory {
    int** inventory;
    int fruits, details;

public:
    FruitShopInventory(int f, int d, int initialQuantity, int initialPrice) : fruits(f), details(d) {
        inventory = new int*[fruits];
        for (int i = 0; i < fruits; i++) {
            inventory[i] = new int[details];
            inventory[i][0] = initialQuantity;
            inventory[i][1] = initialPrice;
        }
    }

    FruitShopInventory(const FruitShopInventory& other) : fruits(other.fruits), details(other.details) {
        inventory = new int*[fruits];
        for (int i = 0; i < fruits; i++) {
            inventory[i] = new int[details];
            for (int j = 0; j < details; j++) inventory[i][j] = other.inventory[i][j];
        }
    }

    FruitShopInventory& operator=(const FruitShopInventory& other) {
        if (this != &other) {
            for (int i = 0; i < fruits; i++) delete[] inventory[i];
            delete[] inventory;

            fruits = other.fruits;
            details = other.details;
            inventory = new int*[fruits];
            for (int i = 0; i < fruits; i++) {
                inventory[i] = new int[details];
                for (int j = 0; j < details; j++) inventory[i][j] = other.inventory[i][j];
            }
        }
        return *this;
    }

    ~FruitShopInventory() {
        for (int i = 0; i < fruits; i++) delete[] inventory[i];
        delete[] inventory;
    }

    void setFruitDetails(int index, int quantity, int price) {
        if (index >= 0 && index < fruits) {
            inventory[index][0] = quantity;
            inventory[index][1] = price;
        }
    }

    void displayInventory() {
        for (int i = 0; i < fruits; i++) {
            cout << "Fruit " << i + 1 << ": Quantity = " << inventory[i][0] << ", Price = " << inventory[i][1] << endl;
        }
    }
};

int main() {
    FruitShopInventory f1(3, 2, 100, 50);
    f1.displayInventory();
    FruitShopInventory f2 = f1;
    f1.setFruitDetails(0, 200, 75);
    f1.displayInventory();
    f2.displayInventory();
    return 0;
}
