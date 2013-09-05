#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " [-bst|-rbt] <Input file name> <Search file name> [[-t]]"
              << "\nOptions:\n"
              << "\t-bst,\t\tSpecify the ADT as binary search tree\n"
              << "\t\targuments: <Input file name> <Search file name>\n"
              << "\t-rbt,\t\tSpecify the ADT as red black tree\n"
              << "\t\targuments: <Input file name> <Search file name>\n"
              << "\t-t,\t\tSpecify whether the execution time should be noted or not\n"
              << "\t\targuments: <Time file for insert> <Time file for locate>\n" 
              << std::endl;
}

int main(int argc, char* argv[])
{
    Dictionary *dict;
    BinarySearchTree bst;
    RedBlackTree rbt;
    std::string inputfile, timeInsert;
    std::string locatefile, timeSearch;

    if (argc < 4) {
        show_usage(argv[0]);
        return 1;
    }

    if (argc > 7) {
         std::cout << "********Too many Arguments !!!********* \n";
         show_usage(argv[0]);
         return 1;
    } 

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-bst") {
            if (i + 2 < argc) { // Make sure we aren't at the end of argv!
                inputfile = argv[++i]; // Increment 'i' so we don't get the argument as the next argv[i].
                locatefile = argv[++i];
                dict = &bst;
            } else { // Uh-oh, there was no argument to the destination option.
                show_usage(argv[0]);
                return 1;
            }  
 	} else if (std::string(argv[i]) == "-rbt") {
            if (i + 2 < argc) { // Make sure we aren't at the end of argv!
                inputfile = argv[++i]; // Increment 'i' so we don't get the argument as the next argv[i].
                locatefile = argv[++i];
                dict = &rbt;
            } else { // Uh-oh, there was no argument to the destination option.
                show_usage(argv[0]);
                return 1;
            }  
        } 
        if (std::string(argv[i]) == "-t") {
            if (i + 2 < argc) { // Make sure we aren't at the end of argv!
                timeInsert = argv[++i]; // Increment 'i' so we don't get the argument as the next argv[i].
                timeSearch = argv[++i];
            } else {
                  show_usage(argv[0]);
                  return 1;
            }
        }
    }

    dict->PopulateDictionary(inputfile, timeInsert);
    dict->LocateInDictionary(locatefile, timeSearch);

}
