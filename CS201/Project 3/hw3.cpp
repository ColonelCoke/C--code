/*
* Name: Orion Gregory
* Email: oagregory@crimson.ua.edu
* Course Section: Fall 2023 CS 201
* Homework #: 3
* Instructions to Compile: g++ hw3.cpp
* Instructions to Run: ./a.exe <input.txt>
*/
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>
#include <chrono>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	auto starttime2 = chrono::steady_clock::now();
	unordered_map<string, vector<string>> map1;
	int i = 0;
	// check for correct command-line arguments
	if (argc != 3) {
	   cout << "Usage: " << argv[0] << " <db file> <query file>" << endl;
	   exit(-1);
	}
    
	string line, name;
	regex delim("/");
	ifstream dbfile(argv[1]);
	if (!dbfile.is_open()) {
	   cout << "Unable to open file: " << argv[1] << endl;
	   exit(-1);
	}

	cout << "***Reading db file " << argv[1] << "***" << endl;
	auto starttime = chrono::steady_clock::now();
	while (getline(dbfile, line)) {
	   // parse each line for tokens delimited by "/"
	   auto begin = sregex_token_iterator(line.begin(), line.end(), delim, -1);
	   auto end = sregex_token_iterator();
	   string movieName = *begin; // needed to retain name of each movie. 
	   ++begin;
	   vector<string> actors;
	   for (sregex_token_iterator word = begin; word != end; ++word) {
		string actor = *word;
		actors.push_back(actor); // creates a list of actors and stores them in a vector. 
		map1[actor].push_back(movieName); // creates a element in the hash table and stores the movies each actor was in.
	   }
	   map1[movieName] = actors; // creates an element in the hash table and stores each actor in the movie. 
	}
	dbfile.close();
	cout << "***Done reading db file " << argv[1] << "***" << endl;

	auto endtime = chrono::steady_clock::now();
	ifstream queryfile(argv[2]);
	if (!queryfile.is_open()) {
	   cout << "Unable to open file: " << argv[2] << endl;
	   exit(-1);
	}
	auto starttime1 = chrono::steady_clock::now();
	cout << "***Reading query file " << argv[2] << "***" << endl;
	   while (getline(queryfile, name)) {
	   cout << "\t\t*SEARCH: " << name << endl;
	   auto output = map1[name]; // This access the index of the hash of the search string
	   	if(output.empty() == 1) // If search query is not within the hash keys, it returns No Result:
		{
			cout << "No Result " << endl;
		}
		else
		{
            for (int i = 0; i < output.size(); i++) // walks through the vector that is linked to the searched movie or actor
            {
                cout << "Result: " << output[i] << " ";
                cout << endl;
            }
		}
        }
	queryfile.close();
	cout << "***Done reading query file " << argv[2] << "***" << endl;

	auto endtime1 = chrono::steady_clock::now();
	auto totaltime1 = endtime1 - starttime1;
	auto seconds1 = chrono::duration_cast<chrono::duration<double>>(totaltime1);
	auto totaltime = endtime - starttime;
	auto seconds = chrono::duration_cast<chrono::duration<double>>(totaltime);
	auto endtime2 = chrono::steady_clock::now();
	auto totaltime2 = endtime2 - starttime2;
	auto seconds2 = chrono::duration_cast<chrono::duration<double>>(totaltime2);

	cout << "total time to read DB file: " << seconds.count() << endl;
	cout << "Total time to search: " << seconds1.count() << endl;
	cout << "Total Time of everything: " << seconds2.count(); 
	
	return 0;
}
