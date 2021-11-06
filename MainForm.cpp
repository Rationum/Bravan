#include "SimpleSaveAndLoad.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int MAX_SIZE = 100;

std::ostream& operator << (std::ostream& os, const SimpleSaveAndLoad& s)
{
    os << s.get_SLLabel() << ' '
        << s.get_SLID() << ' '
        << s.get_SLRate();
    return os;
}

class mainMethods
{
public:
    void createItemToSave()
    {
        // Pre-variables
        std::string newLabel;
        int newID;
        int newRating;

        // Prompt and Get input
        std::cout << "Please enter a label name:\t" << "\n";
        std::cin >> newLabel;
        std::cout << "Please enter a record ID:\t" << "\n";
        std::cin >> newID;
        std::cout << "Please enter a record rating:\t" << "\n";
        std::cin >> newRating;

        // Save Process
        SimpleSaveAndLoad newMenu;
        newMenu.set_SLLabel(newLabel);
        newMenu.set_SLID(newID);
        newMenu.set_SLRate(newRating);
        newMenu.saveRecord(newMenu);
    }

    void createDynamicArrayOfObjects()
    {
        std::ifstream myFile("Menu.dat"); // Declare file to use for storage .dat or .txt

        // new lines will be skipped unless we stop it from happening:    
        myFile.unsetf(std::ios_base::skipws);

        // count the newlines with an algorithm specialized for counting:
        unsigned lineCount = std::count(
            std::istream_iterator<char>(myFile),
            std::istream_iterator<char>(),
            '\n');

        // display the final count
        std::cout << "Lines: " << lineCount << "\n";

        // go a step further and build a dynamic object array using the row count (Q: Why would you do this? A: Allows you to declare an Array of the size you need without hard coding it, no wasted resources)
        std::vector<SimpleSaveAndLoad> menuArray;
        menuArray.resize(lineCount);

        // demonstrate it works
        int total = 0;
        for (int i = 0; i < menuArray.size(); i++)
        {
            total++;
        }

        std::cout << "Array Size: " << total << "Elements" << "\n";
    }

    void loadFileItems()
    {
        // check file
        std::ifstream fileToUse("Menu.dat");
        if (fileToUse.fail())
        {
            std::cout << "File was not found\n";
            system("PAUSE");
            exit(1);
        }

        //fileToUse.ignore(100, '\n'); //Skips the first 120chars or until a \n is reached

        // Create array
        SimpleSaveAndLoad objectArray[MAX_SIZE];

        // loop through file and process the data
        int loopCounter = 0;
        while (loopCounter < MAX_SIZE && fileToUse >> objectArray[loopCounter])
        {
            loopCounter++;
        }
        fileToUse.close();

        // print data to console
        for (int i = 0; i < loopCounter; ++i) 
        { 
            std::cout << objectArray[i] << '\n'; 
        }

        system("PAUSE");
        //// http://www.cplusplus.com/forum/beginner/221144/
    }
};

int main()
{
    mainMethods MM;
    MM.createItemToSave(); // and save it.
        
    //MM.createDynamicArrayOfObjects(); // Dynamic array list.

    MM.loadFileItems(); // Load objects from file.
    
    return 0;
}