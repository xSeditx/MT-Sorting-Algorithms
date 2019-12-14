#pragma once
#include<vector>
#include<iostream>

#define Print(x) std::cout << x << "\n"


namespace MTsort
{
	/* Merge Two Arrays into a single output array */
	template<typename _Ty>
	std::vector<_Ty> Merge(std::vector<_Ty> _A, std::vector<_Ty> _B)
	{
		std::vector<_Ty> result;
		int a{ 0 }, b{ 0 };

		while (a < _A.size() && b < _B.size())
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
		while (a++ < _A.size())
		{
			result.push_back(_A[a - 1]);
		}
		while (b++ < _B.size())
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
	{
		std::vector<_Ty> result;

		while (!_input.empty())
		{
			size_t Element = rand() % _input.size();
			result.push_back(_input[Element]);
			_input.erase(_input.begin() + Element);
		}

		return result;
	}
	/* Single Threaded Bubble sort */
	template<typename _Ty>
	std::vector<_Ty>  Bubble_sort(std::vector<_Ty> _input)
	{
		int Length = _input.size();
		bool Swapped{ true };
		while (Swapped)
		{
			Swapped = false;
			for (uint32_t i{ 1 }; i < (Length); ++i)
			{
				if (_input[i - 1] > _input[i])
				{
					std::swap(_input[i - 1], _input[i]);
					Swapped = true;
				}
			}
		}

		return _input;
	}
}// End MTsort Namespace