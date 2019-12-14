#pragma once
#include<vector>
#include<iostream>
 
/*
============================================================================
 Sorting algorithms                                          
 https://www.geeksforgeeks.org/sorting-algorithms/
============================================================================
*/
namespace Linear
{
	/* Merge Two Arrays into a single output array */
	template<typename _Ty>
	std::vector<_Ty> Merge(std::vector<_Ty> _A, std::vector<_Ty> _B)
	{
		std::vector<_Ty> result;
		int a{ 0 }, b{ 0 };

		while (a < (int)_A.size() && b < (int)_B.size())
		{
			if (_A[a] <= _B[b])
			{
				result.push_back(_A[a++]);
			}
			else
			{
				result.push_back(_B[b++]);
			}
		}
		while (a++ < (int)_A.size())
		{
			result.push_back(_A[a - 1]);
		}
		while (b++ < (int)_B.size())
		{
			result.push_back(_B[b - 1]);
		}
		return result;
	}

	/*Single Threaded Merge sort */
	template<typename _Ty>
	std::vector<_Ty> Merge_sort(std::vector<_Ty> _input)
	{
		if (_input.size() <= 1)
		{
			return _input;
		}
		std::vector<_Ty> Left, Right;

		uint32_t Half = (uint32_t)(_input.size() * .5);

		std::move(_input.begin(), _input.begin() + Half, std::back_inserter(Left));
		std::move(_input.begin() + Half, _input.end(), std::back_inserter(Right));

		auto L = Merge_sort(Left);
		auto R = Merge_sort(Right);
		return Merge(L, R);
	}

	/* Randomize a Sorted array */
	template<typename _Ty>
	std::vector<_Ty> Randomize(std::vector<_Ty> _input)
	{// Return a vector of Randomized elements
		std::vector<_Ty> result;

		while (!_input.empty())
		{// Pick a random number add that element to output and erase from input
			size_t Element = rand() % _input.size();
			result.push_back(_input[Element]);
			_input.erase(_input.begin() + Element);
		}

		return result;
	}

	/* Single Threaded Bubble sort */
	template<typename _Ty>
	std::vector<_Ty> Bubble_sort(std::vector<_Ty> _input)
	{// Bubble sort Input array
		int Length = (int)_input.size();
		bool Swapped{ true };
		while (Swapped)
		{// Loop as long as nothing is swapped
			Swapped = false;
			for (int i{ 1 }; i < (Length); ++i)
			{// Loop over entire Array
				if (_input[i - 1] > _input[i])
				{// If elements are greater than swap elements
					std::swap(_input[i - 1], _input[i]);
					Swapped = true;
				}
			}
		}

		return _input;
	}

	template<typename _Ty>
	int Partition(std::vector<_Ty>& _input, int _low, int _high)
	{
		_Ty pivot{ _input[_high] };
		int i{ _low - 1};
		for (int j{ _low }; j <= _high; ++j)
		{
			if (_input[j] < pivot)
			{
				std::swap(_input[++i], _input[j]);
			}
		}
		std::swap(_input[i+1], _input[_high]);
		return i +1;
	}

	template<typename _Ty>
	std::vector<_Ty> Quick_sort_impl(std::vector<_Ty>& _input, int _low, int _high)
	{
		if (_low < _high)
		{
			int p = Partition(_input, _low, _high);
			Quick_sort_impl(_input, _low, p - 1);
			Quick_sort_impl(_input, p + 1, _high);
		}
		return _input;
	}

	/* Single Threaded Quick sort */
	template<typename _Ty>
	std::vector<_Ty> Quick_sort(std::vector<_Ty> _input)
	{
		return  Quick_sort_impl(_input, 0, (int)_input.size() - 1);
	}


	template<typename _Ty>
	void Heapify(std::vector<_Ty>& _input, int _n, int _index)
	{
		int Largest{ _index };
		int Left{ 2 * _index + 1 };
		int Right{ 2 * _index + 2 };

		if (Left < _n && _input[Left] > _input[Largest])
		{
			Largest = Left;
		}
		if (Right < _n && _input[Right] > _input[Largest])
		{
			Largest = Right;
		}
		if (Largest != _index)
		{
			std::swap(_input[_index], _input[Largest]);
			Heapify(_input, _n, Largest);
		}
	}
	template<typename _Ty>
	void Heap_sort_impl(std::vector<_Ty>& _input, int _n)
	{
		for (int i{ _n / 2 - 1 }; i >= 0; --i)
		{
			Heapify(_input, _n, i);
		}
		for (int i{ _n - 1 }; i >= 0; --i)
		{
			std::swap(_input[0], _input[i]);
			Heapify(_input, i, 0);
		}
	}
	template<typename _Ty>

	/* Single Threaded Heap sort */
	std::vector<_Ty> Heap_sort(std::vector<_Ty> _input)
	{
		Heap_sort_impl(_input, (int)_input.size());
		return _input;
	}



	/* Single Threaded Insertion Sort */
	template<typename _Ty>
	std::vector<_Ty> Insertion_sort(std::vector<_Ty> _input)
	{
		for (int Index{ 1 }; Index < _input.size(); ++Index)
		{
			int Key = _input[Index];
			int j = Index - 1;

			while (j >= 0 && _input[j] > Key)
			{
				_input[j + 1] = _input[j];
				--j;
			}
			_input[j + 1] = Key;
		}
		return _input;
	}

	/* Single Threaded Selection Sort */
	template<typename _Ty>
	std::vector<_Ty> Selection_sort(std::vector<_Ty> _input)
	{
		for (uint32_t Index{ 0 }; Index < _input.size() - 1; ++Index)
		{
			uint32_t MinElement = Index;
			for (uint32_t j{ Index + 1 }; j < _input.size(); ++j)
			{
				if (_input[j] < _input[MinElement])
				{
					MinElement = j;
				}
			}
			std::swap(_input[MinElement], _input[Index]);
		}
		return _input;
	}

}// End Linear Namespace


namespace MTsort
{
};// MTsort





/*
============================================================================
                        UTILITIES && TESTING                                           
============================================================================
*/
#include<chrono>
#include<assert.h>

#define Print(x) std::cout << x << "\n\n"
/* Used for Printing out std::vector */
template<typename _Ty>
std::ostream& operator <<(std::ostream& lhv, std::vector<_Ty> rhv)
{
	for (auto& V : rhv)
	{
		lhv << V << ":";
	}
	return lhv;
}


typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::time_point<std::chrono::steady_clock> SteadyClock;
using Nanoseconds = std::chrono::nanoseconds;
using Microseconds = std::chrono::microseconds;


/* Simple Benchmark to test speeds of the sorting algorithms */
template<typename _Res = Nanoseconds>
struct Benchmark
{
	using Resolution = _Res;
	uint64_t *Storage;
	Benchmark(uint64_t* _storage)
		:
		Storage(_storage)
	{
		Start_Time = Clock::now();
	}
	~Benchmark()
	{
		*Storage = (uint64_t)std::chrono::duration_cast <Resolution> (Clock::now() - Start_Time).count();
	}
	SteadyClock Start_Time;
	SteadyClock Duration;
};


/* Asserts the Input array is in order NOTE: Test can falsely pass in rare cases */
template<typename _Ty>
bool Test_array(std::vector<_Ty> _input)
{
	return
		(_input[0] == 0) &&                                     // Is first element 0? 
		(_input.back() == (_input.size() - 1)) &&               // Is the Last Element the Size?
		(_input[(size_t)(_input.size() * .5)] == (size_t)(_input.size() * .5)); // Is the Middle Element exactly half of the Size of the Array?
}

/* Accepts a Predicate and Vector. Prints out the Array the Test that it has been sorted properly */
template<typename _Ty>
void Test_sort(const char *_name, std::vector<_Ty> _input, std::vector<_Ty>(*_predicate)(std::vector<_Ty>))
{
	_input = Linear::Randomize(_input);
	uint64_t Time{ 0 };
	{
		Benchmark B(&Time);
		_input = _predicate(_input);
	}
	Print(_name << " : " << _input);
	Print("Finished in " << ((float)Time / 1000.0f) / 1000.0f << "ms");
	assert(Test_array(_input));
}
