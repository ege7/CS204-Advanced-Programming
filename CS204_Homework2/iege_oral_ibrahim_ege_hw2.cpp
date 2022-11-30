#include <sstream>
#include "iege_oral_ibrahim_ege_hw2_myfuncs.cpp"



int main() {



    scanLinkedLists();
    string input;
    do {

        cout << "Enter a command and its corresponding argument(s), if any: ";
        
        getline(cin >> ws, input); //ws = whitespace
        int index = 0;
        stringstream command;
        while(input[index] != ' ' && input[index] != '\0'){
            command << input[index];
            index++;
        }

        if(command.str() == "insert1"){

           

            char character = input[index + 1];
            char occurrence = input[index + 3];
            if((' ' != character != occurrence) &&
               (character >= lowerCaseA && character <= lowerCaseZ) &&
                    (occurrence >= lowerCaseA && occurrence <= lowerCaseZ))
            {
                insert1(character, occurrence);
            } else {
                cout << "Invalid arguments." << endl;
                cout << endl;
            }
        } else if(command.str() == "insert2"){

            char character = input[index + 1];
            char occurrence = input[index + 3];
            if((' ' != character != occurrence) &&
               (character >= lowerCaseA && character <= lowerCaseZ) &&
               (occurrence >= lowerCaseA && occurrence <= lowerCaseZ))
            {
                insert2(character, occurrence);
            } else {
                cout << "Invalid arguments." << endl;
                cout << endl;
            }

        } else if(command.str() == "del1"){

            char character = input[index + 1];
            if(character != ' ' && (character >= lowerCaseA && character <= lowerCaseZ)){
                del1(character);
            } else {
                cout << "Invalid arguments." << endl;
                cout << endl;
            }


        } else if(command.str() == "del2"){

            char character = input[index + 1];
            if(character != ' ' && (character >= lowerCaseA && character <= lowerCaseZ)){
                del2(character);
            } else {
                cout << "Invalid arguments." << endl;
                cout << endl;
            }

        } else if(command.str() == "sim"){
            sim();
        } else if(command.str() == "exit"){
            cout << "Clearing the two lists and saying Goodbye!";
            DeleteList(firstListHead);
            DeleteList(secondListHead);
            cout << endl;
        } else {
            cout << "Invalid command." << endl;
            cout << endl;
        }

    } while(input != "exit");

    return 0;
}
