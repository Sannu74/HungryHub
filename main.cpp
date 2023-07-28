// HungryHub Online Food Delivery System

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void SetColor(int ForgC)
{
    WORD wColor;
    // This handle is needed to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    // csbi is used for wAttributes word

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // To mask out all but the background attribute, and to add the color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    // 15 -> white
    // 14 -> yellow
    // 4 -> red
    // 10 -> green
    // 7 -> grey
    // 9 -> blue
    // 11 -> sea
    // 12 -> pink
    // 13 -> purple
}

class Restaurant
{
public:
    Restaurant(const string &name) : name(name) {}
    void addItems(string itemName, double price)
    {
        if (menuSize < MAX_menu)
        {
            menuItem[menuSize] = itemName;
            menuPrice[menuSize] = price;
            menuSize++;
        }
        else
        {
            cout << "\n\n\t-------------------------------------------------------------------------------\t" << endl;
            cout << "\t-------------------------------------------------------------------------------\t" << endl;
            cout << "\tMenu is full. Cannot add more items.\n";
        }
    }

    void displayMenu()
    {
        system("cls");
        SetColor(14);
        cout << "\n\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\tMenu:" << endl;
        for (int i = 0; i < menuSize; i++)
        {
            cout << "\t" << i + 1 << " " << menuItem[i] << " - Rs." << menuPrice[i] << endl;
        }
    }

    string getName() const
    {
        return name;
    }

    void writeVectorToFile(const vector<string> &vec, const vector<double> &vec1, const string &filename)
    {
        ofstream outputFile(filename);

        outputFile << "Total Bill : Rs. " << totalBill << endl;
        if (outputFile.is_open())
        {

            for (size_t i = 0; i < vec1.size(); ++i)
            {
                outputFile << vec[i] << "   Rs." << vec1[1] << endl;
                ;
            }
        }
        outputFile.close();
    }

    string billname(string name)
    {
        return name;
    }

    void processOrder(string bilname)
    {
        int itemChoice = 1;
        SetColor(14);
        cout << "\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\tTo finish your order press 0" << endl;
        while (itemChoice > 0)
        {
            SetColor(7);
            cout << "\n\t-------------------------------------------------------------------------------\t" << endl;
            cout << "\t-------------------------------------------------------------------------------\t" << endl;
            cout << "\tEnter your choice: ";
            cin >> itemChoice;
            if (itemChoice == 1)
            {
                totalBill += menuPrice[0];
                bill.push_back(menuItem[0]);
                billPrice.push_back(menuPrice[0]);
            }
            else if (itemChoice == 2)
            {
                totalBill += menuPrice[1];
                bill.push_back(menuItem[1]);
                billPrice.push_back(menuPrice[1]);
            }
            else if (itemChoice == 3)
            {
                totalBill += menuPrice[2];
                bill.push_back(menuItem[2]);
                billPrice.push_back(menuPrice[2]);
            }
            else if (itemChoice == 4)
            {
                totalBill += menuPrice[3];
                bill.push_back(menuItem[3]);
                billPrice.push_back(menuPrice[3]);
            }
            else if (itemChoice == 5)
            {
                totalBill += menuPrice[4];
                bill.push_back(menuItem[4]);
                billPrice.push_back(menuPrice[4]);
            }

            else if (itemChoice == 6)
            {
                totalBill += menuPrice[5];
                bill.push_back(menuItem[5]);
                billPrice.push_back(menuPrice[5]);
            }
        }
        SetColor(11);
        cout << "\n\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\t-------------------------------------------------------------------------------\t" << endl;
        bilname[0] = toupper(bilname[0]);
        cout << "\t" << bilname << " Your Total Bill: " << totalBill;
        cout << "\n\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\tItems:" << endl;
        for (int i = 0; i < bill.size(); i++)
        {
            cout << "\t" << i + 1 << " " << bill[i] << endl;
        }
        cout << "\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\tThank You for choosing our services.Your Order will be delivered shortly \n\tEnjoy Your Meal!!" << endl;
        SetColor(15);

        writeVectorToFile(bill, billPrice, filename);
    }

private:
    string name;
    double totalBill = 0.0;
    static const int MAX_menu = 6;
    string menuItem[MAX_menu];
    double menuPrice[MAX_menu];
    int menuSize = 0;
    vector<string> bill;
    vector<double> billPrice;
    string filename = "My_Bill.txt";
};

class deliverySystem
{
public:
    void addRestaurant(const Restaurant &res)
    {
        Res.push_back(res);
    }

    void displayRestaurants() const
    {
        cout << "\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\tChoose between the Restaurant Options: " << endl;
        for (size_t i = 0; i < Res.size(); ++i)
        {
            cout << "\t" << i + 1 << ". " << Res[i].getName() << endl;
        }
    }

private:
    vector<Restaurant> Res;
};

void mainScreen()
{
    system("cls");
    // Main Menu
    SetColor(14);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t\t       HUNGRY HUB\n"
         << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t Feeding Your Soul, One Bite at a Time!\n"
         << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t       Can we take your order..?" << endl;
    cout << "\n\t\t\t\t    Choose from our wide assortment of restaurants\n"
         << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    SetColor(15);
    cout << "\n\t\t\t\t\t->Press P to Place Order" << endl;
    SetColor(12);
    cout << "\t\t\t\t\t->For Vendors press I to add items to menu" << endl;
    cout << "\n\n\t\t\t\t\t";
    // Main Menu
}

int main()
{
   //Environment variable declaration
    const char *key = "Food";
    const char *value = getenv(key);

    //Object Creation
    Restaurant r1("Nest Restaurant");
    Restaurant r2("Punjabi Dhaba");
    Restaurant r3("Rasta Cafe");

    r1.addItems("Honey Chilli Potato", 70);
    r1.addItems("Jhol Momos(Veg)", 70);
    r1.addItems("Jhol Momos(Non-Veg)", 80);
    r1.addItems("Honey Seseame Chicken", 120);

    r2.addItems("Paneer Butter Masala", 180);
    r2.addItems("Butter Chicken", 220);
    r2.addItems("Butter Naan (2Pcs)", 18);
    r2.addItems("Butter Milk", 20);

    r3.addItems("Loaded House Fries", 225);
    r3.addItems("Ceaser Salad(Veg/Non-Veg)", 275);
    r3.addItems("Iced Mochaccino", 150);
    r3.addItems("Fresh Ice Tea", 170);

    deliverySystem ds1;
    ds1.addRestaurant(r1);
    ds1.addRestaurant(r2);
    ds1.addRestaurant(r3);
start:
    mainScreen();
    char choice;
    string customName;
    choice = toupper(getch());
    if (choice == 'P')
    {
        system("cls");
        cout << "\n\n\n\n\n\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\n\tEnter your name: " << endl;
        cout << "\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\n\n\t\t\t\t\t";
        getline(cin, customName);
        ds1.displayRestaurants();
        int choice;
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            r1.displayMenu();
            r1.processOrder(customName);
        }
        if (choice == 2)
        {
            r2.displayMenu();
            r2.processOrder(customName);
        }
        if (choice == 3)
        {
            r3.displayMenu();
            r3.processOrder(customName);
        }
    }
    else if (choice == 'I')
    {

        system("cls");
        string item;
        string priceStr;
        double price;
        bool validInput = false;
        cout << "\n\n\n\n\n\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\t-------------------------------------------------------------------------------\t" << endl;
        do
        {
            cout << "\tName the item you want to add to your menu: ";
            cin.ignore(); // To consume the newline character left in the buffer
            getline(cin, item);

            // Check if the input contains any numeric characters
            bool containsNumeric = false;
            for (char c : item)
            {
                if (isdigit(c))
                {
                    containsNumeric = true;
                    break;
                }
            }

            if (!item.empty() && !containsNumeric)
            {
                break; // Valid non-empty string entered
            }
            else
            {
                cout << "\tInvalid input. Please enter a non-empty string for the item without any numeric characters." << endl;
            }
        } while (true);
        cout << "\n\n\n\t-------------------------------------------------------------------------------\t" << endl;
        cout << "\t-------------------------------------------------------------------------------\t" << endl;
        while (!validInput)
        {
            cout << "\tEnter the price of this item: ";
            getline(cin, priceStr);

            // Check if the input is numeric
            stringstream ss(priceStr);
            double price;
            if (ss >> price)
            {
                validInput = true; // Valid numeric value entered
            }
            else
            {
                cout << "\tInvalid input. Please enter a numeric value for the price." << endl;
            }
        }
        ds1.displayRestaurants();
        int choice;
        cout << "\t";
        cin >> choice;
        if (choice == 1)
        {
            r1.addItems(item, price);
        }
        if (choice == 2)
        {
            r2.addItems(item, price);
        }
        if (choice == 3)
        {
            r3.addItems(item, price);
        }
        cout << "Press any key to go to main menu:   ";
        getch();
        goto start;
    }

    return 0;
}