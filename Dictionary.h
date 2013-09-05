#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>

class Dictionary {

    public:
            virtual void Insert(int val) = 0;
            virtual bool Delete(int val) = 0;
            virtual bool Search(int val) = 0;
	    virtual void ClearADT() = 0;
            virtual void Display() = 0;

            void PopulateDictionary(std::string input, std::string timeinput);
            void LocateInDictionary(std::string locate, std::string timelocate);
};

#endif
