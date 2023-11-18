/*
* Name: Orion Gregory
* Email: oagregory@crimson.ua.edu
* Course Section: Fall 2023 CS 201
* Homework #: 2
* To Compile: g++ homework2.cpp
* To Run: ./a.exe <inputfile.txt> <outputfile.txt>
*/
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <map>
#include <chrono>

using namespace std;

bool Compare(const pair<string, int>& a, const pair<string, int>& b) 
{
    return a.second > b.second;
}

int main(int argc, char* argv[]) {
   auto starttime = chrono::steady_clock::now();
   string text;
   vector<string> tokens;
   const regex delim("\\s+"); 

   fstream inFile(argv[1]);
   fstream outFile(argv[2]);
   map<string, int> dictionary;
   /*
   * sample program used to parse text, O(n)
   */
   while (inFile >> text) {
      auto begin = sregex_token_iterator(text.begin(), text.end(), delim, -1);
      auto end = sregex_token_iterator();
      for (sregex_token_iterator word = begin; word != end; word++) {
         tokens.push_back(*word);
         dictionary[*word]++; //adds the word to the map
      }
   }
    vector<pair<string, int>> temp(dictionary.begin(), dictionary.end()); // done to allow sort to work correctly. O(n)
    sort(temp.begin(), temp.end(), Compare); // O(nlogn)
    for (const auto &mapOut : temp) 
    {
        outFile << mapOut.first << ": " << mapOut.second << " occurrences" << endl;
    }
   auto endtime = chrono::steady_clock::now();
   auto timeTaken = std::chrono::duration_cast<std::chrono::duration<double>>(endtime - starttime);
   cout << timeTaken.count();
   return 0;
}