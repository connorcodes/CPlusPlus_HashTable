//
// Created by eldoradocoder on 12/8/18.
// Lab #6 - Hash Table with Quadratic Probing
// External files: Dataset provided by bst_testfile.txt
//

#include <iostream>
#include <string>
#include <stdlib.h>


#include "hashTable.h"

using namespace std;

void displayMenu();
char getCommand();
void executeCmd(char command, hashTable& aTable);

void getName(data & stock); //TODO: change to bday and name
int getInt(char * prompt);
float getFloat(char * prompt);
void getString(char * prompt, char * input);

void display(const hashTable & aTable);

int main(){
    //TODO: Allow program to read file from anywhere on host machine CHAR ERROR
    //TODO: Read bst_testfile.txt DONE
    //TODO: Convert yyyy-mm-dd to a single hash key number (string->int) MAYBE DO IN HASHTABLE.H?

    int command = 1;
    string filename;

    cout << "Enter the file name: " << endl;
    cin >> filename;

    char fileName[] = "bst_testfile.txt"; //TODO: Add filename input question
    hashTable birthdays(fileName);

    displayMenu();
    command = getCommand();
    while(command != '5')
    {
        executeCmd(command, birthdays);
        displayMenu();
        command = getCommand();
    }

    birthdays.writeOut (fileName);
    cout << "\nThank you for using The Birthdate Hashing System!" << endl << endl;
    return 0;
}

void displayMenu()
{
    cout << "\nWelcome to The Birthdate Hashing System! "<< endl;
    cout << "\t1) add a birthdate" << endl
         << "\t2) remove a birthdate" << endl

         << "\t3) search for a birthdate" << endl
         << "\t4) list all the birthdates" << endl
         << "\t5) quit the application" << endl << endl;
}

char getCommand()
{
    int cmd;
    cout << "Please enter your choice: ";
    cin >> cmd;
    cin.ignore(100, '\n');
    return tolower(cmd);
}

void executeCmd(int command, hashTable& aTable)
{
    data stock; //TODO: change to bday and name
    char key[MAX_LEN]; //TODO: What is MAX_LEN for?

    switch(command)
    {
        case '1': getStock(stock);
            aTable.insert (stock);
            cout << endl << "The birthdate has been saved to the textfile. " << endl;
            break;
        case '2': getString("\nPlease enter the birthdate of the entry you want to remove: ", key);
            aTable.remove(key);
            cout << endl << key << " has been removed from the textfile. " << endl;
            break;
        case '3': getString("\nPlease enter the birthdate of the entry you want to search: ", key);
            aTable.search (key, stock);
            cout << endl << "Information about " << key << ": " << endl << '\t' << stock << endl;
            break;
        case '4': display(aTable);
            break;
        default: cout << "Wrong command! enter 1-4 for options or 5 to quit. " << endl;
            break;
    }
}
void display(const hashTable & aTable)
{
    aTable.display();
}

void getName(data & stock) //TODO: change to bday and name
{
    string bday[MAX_LEN]; //TODO: What is MAX_LEN for?
    string name[MAX_LEN]; //TODO: What is MAX_LEN for?

    cout << "\nPlease enter information about the stock: " << endl;
    getString("\tBirthdate: ", bday);
    getString("\tName: ", name);

    stock.setBday (bday);
    stock.setName (name);
}
int getInt(char * prompt)
{
    int temp;
    cout << prompt;
    cin >> temp;
    while(!cin)
    {
        cin.clear ();
        cin.ignore(100, '\n');
        cout << "Illegal input -- try again: ";
        cin >> temp;
    }
    cin.ignore(100, '\n');
    return temp;
}
float getFloat(char * prompt)
{
    float temp;
    cout << prompt;
    cin >> temp;
    while(!cin)
    {
        cin.clear ();
        cin.ignore(100, '\n');
        cout << "Illegal input -- try again: ";
        cin >> temp;
    }
    cin.ignore(100, '\n');
    return temp;
}
void getString(char * prompt, char * input)
{
    cout << prompt;
    cin.get(input, MAX_LEN, '\n'); //TODO: What is MAX_LEN for?
    cin.ignore (100, '\n');
}


/*
 * Hashing usage reference:

    hashTable table1;

    // storing elements in table
    table1.insert(12);
    table1.insert(26);
    table1.insert(31);
    table1.insert(17);
    table1.insert(90);
    table1.insert(28);
    table1.insert(88);
    table1.insert(40);
    table1.insert(77);		// element that causes collision at position 0

    // displaying the Table
    table1.display();
    cout<<"\n";

    // printing position of elements
    cout<<"\nThe position of element 31 is : " <<table1.search(31);
    cout<<"\nThe position of element 28 is : " <<table1.search(28);
    cout<<"\nThe position of element 90 is : " <<table1.search(90);
    cout<<"\nThe position of element 77 is : " <<table1.search(77);
    cout<<"\nThe position of element 1 is : " <<table1.search(1);

    cout<<"\n";

    table1.remove(90);
    table1.remove(12);

    table1.display();
*/
