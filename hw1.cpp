/* 
 Name: Orion Gregory
 Email: oagregory@crimson.ua.edu
 Course Section: Fall 2023 CS 201
 Homework #: 1
 Instructions to compile the program: g++ perftest.cpp (really fast with -O2 or -Ofast, Ofast is untested for accuracy though)
 Instructions to execute the program: ./a.exe
*/

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>
using namespace std;
template<class RandomIt>
constexpr void heapify(RandomIt first, int size, int i)
{
    auto largestIndex = i;
    auto l = 2 * i + 1; //left
    auto r = 2 * i + 2; //right

    if (l < size && *(first + l) > *(first + largestIndex))
    {
        largestIndex = l; // i will not "update", so we must update a different index with the correct largest index
    }

    if (r < size && *(first + r) > *(first + largestIndex))
    {
        largestIndex = r; 
    }

    if (largestIndex != i)
    {
        iter_swap(first + i, first + largestIndex); 
        heapify(first, size, largestIndex); // if we use i instead of largestIndex then the heapify index is broken
    }
}

template<class RandomIt>
constexpr void buildheap(RandomIt first, RandomIt last)
{
    auto dis = distance(first, last);
    for(auto i = dis / 2; i>= 0; i--) //auto i = static_cast<int>(floor(dis / 2) - 1) also works
    {
        heapify(first, dis, i);
    }
};

/*
* almost the exact same function from the powerpoint slides
*/
template<class RandomIt>
constexpr void heapsort(RandomIt first, RandomIt last)
{
    buildheap(first, last); // establishes working heap for heapsort
    auto dis = distance(first, last) - 1;
    for(auto i = dis; i > 0; i--)
    {
        auto itI = first+ i;
        iter_swap(first, itI);
        heapify(first, i, 0); 
    }
};

template<class RandomIt>
constexpr auto partition(RandomIt first, RandomIt last)
{
    last = last - 1; //must do this or last will be out of bounds
    auto x = last;
    auto mid = (first + distance(first,last)/2); // we must use middle pivot, operations past 10k break if last pivot.
    auto a = mid - 1; 
    auto b = mid + 1;
    iter_swap(x, mid); // puts pivot point at end
    auto i = first - 1;
    for(auto j = first; j <= (last-1); j++)
    {
        if(*j <= *x)
        {  
            /*
            *I always try and trace out the swaps, makes it easier to debug for me.
            */
            i = i+1;
            // auto temp = *i;
            // *i = *j;
            // *j = temp;
            iter_swap(i, j);
        }
    }
    // auto temp = *(i+1);
    // *(i+1) = *last;
    // *last = temp;
    iter_swap(i+1, last);
    return (i+1);
};

/*
* Straight from the powerpoint slides.
*/
template<class RandomIt>
constexpr void quicksort(RandomIt first, RandomIt last)
{
    RandomIt q;
    if (first < last)
    {
        q = partition(first, last); // determines partition split
        quicksort(first, q);
        quicksort((q + 1), last);
    }
}
/*
* Code given from perftest.cpp, I did not write this, it was given to allow us to test our sorting functions.
*/
int main(int argc, char *argv[]) {
	std::chrono::duration<double> timetaken[3][3];
	std::cout << "Problem Size\tTime Taken (seconds)" << std::endl;
	std::cout << "\t\tCase 1\tCase 2\tCase 3" << std::endl;
	for (int size = 10; size <= 100000000; size *= 10) {
	
		int *a = new int[size];

		// repeat each case for three times 
		for (int i = 0; i < 3; i++) {
			std::generate(a, a+size, std::rand);

			/* Case 1: sorting random values */
			auto starttime = std::chrono::steady_clock::now();
			quicksort(a, a+size); //change for what sort you want
			auto endtime = std::chrono::steady_clock::now();
			timetaken[i][0] = endtime - starttime;

			/* Case 2: sorting data that is already sorted */
			starttime = std::chrono::steady_clock::now();
			quicksort(a, a+size); //change for what sort you want
			endtime = std::chrono::steady_clock::now();
			timetaken[i][1] = endtime - starttime;

			/* Case 3: sorting data that is in reverse sorted order */
			std::reverse(a, a+size);
			starttime = std::chrono::steady_clock::now();
			quicksort(a, a+size); //change for what sort you want
			endtime = std::chrono::steady_clock::now();
			timetaken[i][2] = endtime - starttime;
		}

		// print the average time of three runs
		std::cout << size << "\t\t";
		std::cout << (timetaken[0][0].count() + timetaken[1][0].count() + timetaken[2][0].count())/3.0 << "\t";
		std::cout << (timetaken[0][1].count() + timetaken[1][1].count() + timetaken[2][1].count())/3.0 << "\t";
		std::cout << (timetaken[0][2].count() + timetaken[1][2].count() + timetaken[2][2].count())/3.0 << std::endl;
		delete[] a;
	}
	return 0;
}
