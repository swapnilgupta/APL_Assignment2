#include "Dictionary.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void Dictionary::PopulateDictionary(std::string input, std::string timeinput) 
{
   fstream insertfile(input.c_str(), std::fstream::in);
   fstream timefile;
   int elem;
   int tflag = 0;

   if (!timeinput.empty())
   {
       tflag = 1;
       timefile.open(timeinput.c_str(), std::fstream::app| std::fstream::out); 
       timefile << "I'm here \n" ; 
   } 
   
   while(insertfile >> elem)
   {
         Insert(elem);
   }

   if(!insertfile.eof())
   {
     cout << "Invalid Input. Input file should only contain integers separated by space\n" ;
   }
  
   insertfile.close(); 
   timefile.close(); 

}

void Dictionary::LocateInDictionary(std::string locate, std::string timelocate)
{
   fstream locatefile(locate.c_str(), std::fstream::in);
   fstream timesearch;
   int elem;
   int tflag = 0;

   if (!timelocate.empty())
   {
       tflag = 1;
       timesearch.open(timelocate.c_str(), std::fstream::app| std::fstream::out);  
       timesearch << "I'm here\n";
   } 
   
   while(locatefile >> elem)
   {
         Search(elem);
   }

   if(!locatefile.eof())
   {
     cout << "Invalid Input. Input file should only contain integers separated by space\n" ;
   }
  
   locatefile.close(); 
   timesearch.close(); 
 }


