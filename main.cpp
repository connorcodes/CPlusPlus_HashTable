//
// Created by Connor Sanders (eldoradocoder) on 12/8/18.
//

#include<iostream>
#include<string>
#include<fstream>

#include"hashTable.h"
#include"hashEntry.h"

using namespace std;


int main()
{
    ifstream infile;
    string location="bst_testFile.txt";
    infile.open(location.c_str());

    auto *node = new hashEntry<string, string>;
    auto *table = new hashTable<string, string>;

    string name, date;

    while (!infile.eof())
    {
        getline(infile, name);
        getline(infile, date);
        node->setKey(date);
        node->setValue(name);
        table->insert(date, name);
    }

    infile.close();
    table->display();

    cout << "Load factor: "<< table->mapSize() / table->capacityF() * 100 << endl;
    cout << "Collisions: " << table->getCollisions() << endl;

    string userDate;
    cout << "Enter a birthdate (Ex: 1974-08-24): ";
    getline(cin, userDate);

    string value = table->find(userDate);

    cout << "Name: " << value << endl;

    if (value == "invalid data") {
        char choice;

        cout << "Check again? (Y/N)" << endl;
        cin >> choice;

        string value2, inputDate;

        switch (choice) {
            case 'y':

                cout << "Enter a birthdate: ";
                getline(cin, inputDate);
                value2 = table->find(inputDate);
                cout << value2 << " has that birthday!" <<endl;

                break;

            case 'n':
                cout << " Good bye!" << endl;

                break;

            default:

                break;
        }
    }

    system("pause");
    return 0;
}