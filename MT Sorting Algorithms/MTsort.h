#pragma once
#include<vector>
#include<iostream>
 
/*
============================================================================
 Sorting algorithms                                          
 https://www.geeksforgeeks.org/sorting-algorithms/
============================================================================
*/

/* Used for Printing out std::vector */
#define Print(x) std::cout << x << "\n\n"

template<typename _Ty>
std::ostream& operator <<(std::ostream& lhv, std::vector<_Ty> rhv)
{
	for (auto& V : rhv)
	{
		lhv << V << ":";
	}
	return lhv;
}


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
	std::vector<_Ty>  Bubble_sort(std::vector<_Ty> _input)
	{// Bubble sort Input array
		uint32_t Length = _input.size();
		bool Swapped{ true };
		while (Swapped)
		{// Loop as long as nothing is swapped
			Swapped = false;
			for (uint32_t i{ 1 }; i < (Length); ++i)
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
	size_t Partition(std::vector<_Ty>& _input, size_t _low, size_t _high)
	{
		_Ty pivot{ _input[_high] };
		size_t i{ _low - 1};
		for (uint32_t j{ _low }; j <= _high; ++j)
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

	template<typename _Ty>
	std::vector<_Ty> Quick_sort(std::vector<_Ty>& _input)
	{
		return  Quick_sort_impl(_input, 0, _input.size() - 1);
	}
}// End Linear Namespace


namespace MTsort
{
};// MTsort
