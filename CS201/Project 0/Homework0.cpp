/*
    Name: Orion Gregory
    Email oagregory@crimson.ua.edu 
    Course Section: Fall 2023 CS 201
    Homework #: 0
    Instructions to Compile: g++ Homework0.cpp
    Instructions to Execute: ./a.exe "filename"
*/
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>

using namespace std;

class Movie
{
    public:
        int year;
        string movieName;
        vector<string> actors;
    int getYear()
    {
        return year;
    }
    void setYear(int newYear)
    {
        year = newYear;
    }
    string getName()
    {
        return movieName;
    }
    void setName(string newMovieName)
    {
        movieName = newMovieName;
    }
    vector<string> getActors()
    {
        return actors;
    }
    void addActors(string actor)
    {
        actors.push_back(actor);
    }
    //Unused Function / old function
    /*
    *void Print()
    *{
    *    cout << movieName << " / ";
    *    cout << year << " / ";
    *    for(int i = 0; i<actors.size(); i++)
    *    {
    *        cout << actors.at(i) << " . ";
    *    }
    *    cout << endl;
    *}
    */
};
void MovieSortName(vector<Movie> movies, string fileName)
{
    string fileName1 = fileName + "ByName.txt";
    //Thank god for Lambda, allows us to sort by attribute of object in vector
	sort(movies.begin(), movies.end(), [](Movie& temp, Movie& temp1) {
            if(temp.getName() == temp1.getName())
            {
                return temp.getYear() < temp1.getYear();
            }
            else
            {
			    return  temp.getName() < temp1.getName();
            }
		});
        //Prints out each movie sorted into an output file, nameSortOut is the file
        ofstream nameSortOut(fileName1);
        for(int i = 0; i<movies.size(); i++)
        {
            Movie temp;
            temp = movies.at(i);
            nameSortOut << temp.movieName << "";
            nameSortOut << "(" <<temp.year << ")/";
            // This nested loop is to output each actor inside of the actors vector
            for(int i = 0; i<temp.actors.size(); i++)
            {
                nameSortOut << temp.actors.at(i) << "/";
            }
            nameSortOut << endl;
        }
    
}
void MovieSortYear(vector<Movie> movies, string fileName)
{
    //Thank god for Lambda, again.
    string fileName1 = fileName + "ByYear.txt";
	sort(movies.begin(), movies.end(), [](Movie& temp, Movie& temp1) {
            if(temp.getYear() == temp1.getYear())
            {
                return temp.getName() < temp1.getName();
            }
            else
            {
			    return  temp.getYear() < temp1.getYear();
            }
		});
        //Prints out each movie sorted into an output file
        ofstream yearSortOut(fileName1);
        for(int i = 0; i < movies.size(); i++)
        {
            Movie temp;
            temp = movies.at(i);
            yearSortOut << temp.movieName << "";
            yearSortOut << "(" <<temp.year << ")/";
            //required to output each actor in actors vector
            for(int i = 0; i<temp.actors.size(); i++)
            {
                yearSortOut << temp.actors.at(i) << "/";
            }
            yearSortOut << endl;
        }
}
int main(int argc, char* argv[])
{   
    auto totalStartTime = chrono::steady_clock::now();
    auto createColStart = chrono::steady_clock::now();
    
    string fileName = argv[1];
    string fileName1 = fileName.substr(0, 7);
    ifstream file(argv[1]);
    vector<Movie> movies;
    string readLine;
    //Reads the file line by line, Movie by movie.
    while(getline(file, readLine))
    {
        Movie movie;
        //Allows us to break down each getline a bit more
        istringstream sstream(readLine);
        string movieStr;
        string yearStr;
        string actorsTemp;
        string actorName;

        //Reads the first element of the line, parses all the data before the next '(' and stores it as the movie name
        getline(sstream, movieStr, '(');
        movie.setName(movieStr);

        //Reads the element after '(' and before ')' and then stores that data as a int for the year of the movie 
        getline(sstream, yearStr, ')');
        movie.setYear(stoi(yearStr));

        /*
        * Reads the rest of the string stream, which is parsed out to be all actors.
        * Each actor is seperated and stored in a vector within the Movie Object.
        * */
        getline(sstream, actorsTemp);
        istringstream aStream(actorsTemp);
        getline(aStream, actorName, '/');
        while(getline(aStream, actorName, '/'))
        {
            movie.addActors(actorName);
        }
        movies.push_back(movie);
    }
    auto createColEnd = chrono::steady_clock::now();
    chrono::duration<double> createColTime = createColEnd - createColStart;
    cout << "\n Creating Collection Time: " << createColTime.count() << endl;

    auto sortNameStart = chrono::steady_clock::now();

    MovieSortName(movies, fileName1);

    auto sortNameEnd = chrono::steady_clock::now();
    auto sortYearStart = chrono::steady_clock::now();

    MovieSortYear(movies, fileName1);

    auto sortYearEnd = chrono::steady_clock::now();
    chrono::duration<double> sortNameTimeTaken = sortNameEnd - sortNameStart;
    chrono::duration<double> sortYearTimeTaken = sortNameEnd - sortNameStart;
    cout << "\n Sort Name Time: " << sortNameTimeTaken.count() << endl;
    cout << "\n Sort Year Time: " << sortYearTimeTaken.count() << endl;   
    auto totalEndTime = chrono::steady_clock::now();
    chrono::duration<double> totalTimeTaken = totalEndTime - totalStartTime;
    cout << "\n Total Time: " << totalTimeTaken.count() << endl;

    return 0;
}