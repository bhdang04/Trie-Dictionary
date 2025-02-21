#include "dictionary.h"

int main () {
    int choices = 0;
    int entries = 0;
    Dictionary dict;
    string entry;

    do { 
        cout << "<-------- Choose Options (1-5) -------->" << endl;
        cout << "1. Add to Dictionary\n" 
            << "2. Remove to Dictionary\n"
            << "3. Search Up Word\n"
            << "4. View List\n"
            << "5. Quit Application\n";
        cout << "Pick a number to select that option: ";
        cin >> choices;

        system("clear");
        switch (choices) {
            case 1:
                cout << "Enter a word into the Dictionary: ";
                cin.ignore();
                cin >> entry;
                if (dict.insert(entry.c_str())) {
                    cout << "Added Successfully\n";
                } else {
                    cout << "Word already existed\n";
                }
                break;
            case 2:
                cout << "Enter a word to remove from Dictionary: ";
                cin.ignore();
                cin >> entry;
                if (dict.remove(entry.c_str())) {
                    cout << "Removed Successfully\n";
                } else {
                    cout << "Word did not exist\n";
                }
                break;
            case 3:
                cout << "Enter a word to search up from Dictionary: ";
                cin.ignore();
                cin >> entry;
                if (dict.search(entry.c_str())) {
                    cout << "WORD: " << entry << endl 
                        << "DEFINITION: ";  
                } else {
                    cout << "Word does not exist\n";
                }
                break;
            case 4:
                dict.print();
                break;
            case 5:
                cout << "Successfully Closed\n";
                break;
            default: 
                cerr << "\nInvalid Option";
                break;               
        }
        system("clear");
    } while (choices != 5);
}