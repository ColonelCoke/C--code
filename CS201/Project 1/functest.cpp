/* 
   Sample program to test quicksort with different containers.
   To Compile: g++ -std=c++17 functest.cpp
   To Run: ./a.out
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
    auto l = 2 * i + 1;
    auto r = 2 * i + 2;

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
    buildheap(first, last);
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
    iter_swap(x, mid);
    auto i = first - 1;
    for(auto j = first; j <= (last-1); j++)
    {
        if(*j <= *x)
        {  
            /*
            *I always try and trace out the swaps, makes it easier to debug for me.
            */
            i = i+1;
            iter_swap(i, j);
            // auto temp = *i;
            // *i = *j;
            // *j = temp;
        }
    }
    iter_swap(i+1, last);
    // auto temp = *(i+1);
    // *(i+1) = *last;
    // *last = temp;
    return (i+1);
};

/*
* Straight from the text book.
*/
template<class RandomIt>
constexpr void quicksort(RandomIt first, RandomIt last)
{
    RandomIt q;
    if (first < last)
    {
        q = partition(first, last);
        quicksort(first, q);
        quicksort((q + 1), last);
        // first = q + 1;
    }
}

template< class RandomIt >
void print(RandomIt start, RandomIt end) {
	while (start != end) {
		std::cout << *start << " ";
		++start;
	}
	std::cout << std::endl;
}


int main(int argc, char *argv[]) {
	int a0[] = {56, 23, 11, 64, 43};
	std::array<int, 5> a1 = {5, 4, 3, 2, 1};
	std::array<std::string, 5> a2 = {"lion", "dog", "cat", "fox", "pig"};
	std::vector<double> v = {4.2, 3.1, 5.6, 2.8, 1.9};

	quicksort(a0, a0+5);
	print(a0, a0+5);

	quicksort(&a0[0], &a0[5]);
	print(&a0[0], &a0[5]);

	quicksort(a1.begin(), a1.end());
	print(a1.begin(), a1.end());

	quicksort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	std::reverse(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	quicksort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	quicksort(v.begin(), v.end());
	print(v.begin(), v.end());

	return 0;
}