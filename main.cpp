#include "dictionary.h"

int main () {
    int choices = 0;
    int entries = 0;

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
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
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