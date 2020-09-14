#include <iostream>
#include <iomanip>

using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

int main() {
    double totalPrice = 0;

    menuItemType item1; item1.menuItem = "Plain Egg"; item1.menuPrice = 1.45;
    menuItemType item2; item2.menuItem = "Bacon and Egg"; item2.menuPrice = 2.45;
    menuItemType item3; item3.menuItem = "Muffin"; item3.menuPrice = 0.99;
    menuItemType item4; item4.menuItem = "French Toast"; item4.menuPrice = 1.99;
    menuItemType item5; item5.menuItem = "Fruit Basket"; item5.menuPrice = 2.49;
    menuItemType item6; item6.menuItem = "Cereal"; item6.menuPrice = 0.69;
    menuItemType item7; item7.menuItem = "Coffee"; item7.menuPrice = 0.50;
    menuItemType item8; item8.menuItem = "Tea"; item8.menuPrice = 0.75;

    cout << "Breakfast Items\n\n";
    cout << item1.menuItem << "\t$" << item1.menuPrice << endl;
    cout << item2.menuItem << "\t$" << item2.menuPrice << endl;
    cout << item3.menuItem << "\t\t$" << item3.menuPrice << endl;
    cout << item4.menuItem << "\t$" << item4.menuPrice << endl;
    cout << item5.menuItem << "\t$" << item5.menuPrice << endl;
    cout << item6.menuItem << "\t\t$" << item6.menuPrice << endl;
    cout << item7.menuItem << "\t\t$" << item7.menuPrice << endl;
    cout << item8.menuItem << "\t\t$" << item8.menuPrice << endl;



    return 0;
}
