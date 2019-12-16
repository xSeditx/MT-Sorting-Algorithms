#pragma once
#include<vector>
#include<iostream>
 
/*
============================================================================
     Sorting algorithms                                          
 https://www.geeksforgeeks.org/sorting-algorithms/
============================================================================
*/

/*
============================================================================
                            FUNCTIONALITY                                        
============================================================================

template<typename _Ty> 

std::vector<_Ty> Merge_sort(std::vector<_Ty> _input);

std::vector<_Ty> Randomize(std::vector<_Ty> _input);
std::vector<_Ty> Bubble_sort(std::vector<_Ty> _input);

std::vector<_Ty> Quick_sort(std::vector<_Ty> _input)

std::vector<_Ty> Cycle_sort(std::vector<_Ty> _input);
std::vector<_Ty> Gnome_sort(std::vector<_Ty> _input);
std::vector<_Ty> Shell_sort(std::vector<_Ty> _input);

std::vector<_Ty> Insertion_sort(std::vector<_Ty> _input)
std::vector<_Ty> Selection_sort(std::vector<_Ty> _input)

std::vector<_Ty> Heap_sort(std::vector<_Ty> _input);


std::vector<_Ty> Quick_sort_impl(std::vector<_Ty>& _input, int _low, int _high)
std::vector<_Ty> Merge(std::vector<_Ty> _A, std::vector<_Ty> _B);
void Heap_sort_impl(std::vector<_Ty>& _input, int _n);
int Partition(std::vector<_Ty>& _input, int _low, int _high);

void Heapify(std::vector<_Ty>& _input, int _n, int _index);
============================================================================
*/


#define DISPLAY_ARRAY 0

namespace Impl
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

	template<typename _Ty>
	int Partition(std::vector<_Ty>& _input, int _low, int _high)
	{
		_Ty pivot{ _input[_high] };
		int i{ _low - 1 };
		for (int j{ _low }; j <= _high; ++j)
		{
			if (_input[j] < pivot)
			{
				std::swap(_input[++i], _input[j]);
			}
		}
		std::swap(_input[i + 1], _input[_high]);
		return i + 1;
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
	struct Node
	{
		Node(_Ty item)
		{
			Value = item;
			Left = nullptr;
			Right = nullptr;
		}

		void Insert(_Ty _inputkey)
		{
			if (Value <= _inputkey)
			{
				if (Left == nullptr)
				{
					Left = new Node(_inputkey);
					return;
				}
				Left->Insert(_inputkey);
			}
			else if (Value > _inputkey)
			{
				if (Right == nullptr)
				{
					Right = new Node(_inputkey);
					return;
				}
				Right->Insert(_inputkey);
			}
		}

		void SortValue(std::vector<_Ty>& _input, int &i)
		{
			if (this != NULL)
			{
				if (Right != nullptr)
				{
					Right->SortValue(_input, i);
				}
				_input[i++] = Value;
				if (Left != nullptr)
				{
					Left->SortValue(_input, i);
				}
			}
		}

		_Ty Value{};
		Node *Left, *Right;
	};


}

 
namespace Linear
{

	/*
	 * Single Threaded Count Sort
	 * Note: Inorder for this to work I need to properly know the highest value contained in the array else it will fail
	 */
	template<typename _Ty>
	std::vector<_Ty> Count_sort(std::vector<_Ty> _input)
	{
		size_t RANGE = _input.size();
		std::vector<_Ty> result(RANGE);
		std::vector<int> Count(RANGE + 1);

		for (int i{ 0 }; i < RANGE; ++i)
		{
			++Count[_input[i]];
		}
		for (int i{ 1 }; i <= RANGE; ++i)
		{
			Count[i] += Count[i - 1];
		}
		for (int i{ 0 }; i < _input.size(); ++i)
		{
			result[Count[_input[i]] - 1] = _input[i];
			--Count[_input[i]];
		}
		for (int i{ 0 }; i < _input.size(); ++i)
		{
			_input[i] = result[i];
		}
		return _input;
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
		return Impl::Merge(L, R);
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

	/* Single Threaded Quick sort */
	template<typename _Ty>
	std::vector<_Ty> Quick_sort(std::vector<_Ty> _input)
	{
		return  Impl::Quick_sort_impl(_input, 0, (int)_input.size() - 1);
	}

	/* Single Threaded Heap sort */
	template<typename _Ty>
	std::vector<_Ty> Heap_sort(std::vector<_Ty> _input)
	{
		Impl::Heap_sort_impl(_input, (int)_input.size());
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

	/* Single Threaded Cycle sort */
	template<typename _Ty>
	std::vector<_Ty> Cycle_sort(std::vector<_Ty> _input)
	{
		int WriteCount = 0;
		size_t Length = _input.size();

		for (int Start{ 0 }; Start <= Length - 2; ++Start)
		{
			int Item = _input[Start];
			int ReadPosition = Start;
			for (int i{ Start + 1 }; i < Length; ++i)
			{
				if (_input[i] < Item)
				{
					++ReadPosition;
				}
			}
			if (ReadPosition == Start)
			{
				continue;
			}
			while (Item == _input[ReadPosition])
			{
				++ReadPosition;
			}

			if (ReadPosition != Start)
			{
				std::swap(Item, _input[ReadPosition]);
				++WriteCount;
			}

			while (ReadPosition != Start)
			{
				ReadPosition = Start;

				for (int i{ Start + 1 }; i < Length; ++i)
				{
					if (_input[i] < Item)
					{
						++ReadPosition;
					}
				}

				while (Item == _input[ReadPosition])
				{// Increment Read++ here /\ freeze even though it should happen after expressin
					++ReadPosition;// < Do it here instead
				}

				if (Item != _input[ReadPosition])
				{
					std::swap(Item, _input[ReadPosition]);
					++WriteCount;
				}
			}
		}
		return _input;
	}

	/* Single Threaded Gnome / Stupid Sort */
	template<typename _Ty>
	std::vector<_Ty> Gnome_sort(std::vector<_Ty> _input)
	{
		int Index = 0;

		while (Index < _input.size()) 
		{
			if (Index == 0)
			{ 
				++Index;
			}
			if (_input[Index] >= _input[Index - 1])
			{
				++Index;
			}
			else
			{
				std::swap(_input[Index], _input[Index - 1]);
				--Index;
			}
		}
		return _input;
	}

	/* Single Threaded Shell Sort */
	template<typename _Ty>
	std::vector<_Ty> Shell_sort(std::vector<_Ty> _input)
	{
		size_t Size = _input.size();
 		for (size_t Gap = Size / 2; Gap > 0; Gap /= 2)
		{
			for (size_t Index = Gap,  j{ 0 }; Index < Size; ++Index)
			{
				int TempValue = _input[Index];
				for (j = Index; (j >= Gap) && (_input[j - Gap] > TempValue); j -= Gap)
				{
					_input[j] = _input[j - Gap];
				}
				_input[j] = TempValue;
			}
		}
		return _input;
	}

	template<typename _Ty>
	std::vector<_Ty> Tree_sort(std::vector<_Ty> _input)
	{
		Impl::Node<_Ty> *Rootnode = new Impl::Node<_Ty>(_input[0]);

		for (int i{ 1 }; i < _input.size(); ++i)
		{
			Rootnode->Insert(_input[i]);
		}

		int i = 0;
		Rootnode->SortValue(_input, i);
		return _input;
	}



}// End Linear Namespace



#include<string>
#include<thread>
#include<mutex>
#include<Windows.h>
#include<atomic>
namespace MTsort
{
	std::mutex Mtx;
	std::mutex Mtx2;
	std::atomic<int> F = 0;
	template<typename _Ty>
	std::vector<_Ty> Sleep_sort(std::vector<_Ty> _input)
	{
		std::vector<_Ty> results;
		std::vector<std::thread> Sthreads;
		for (int i{ 0 }; i < _input.size() - 1; ++i)
		{
		    Mtx2.lock();
			Sthreads.push_back(std::thread(
				[&]()
			{
				Mtx.lock();
				int V = i; 
				Mtx.unlock();

				std::this_thread::sleep_for(std::chrono::milliseconds((_input[V] + 1) * 12));
				while (F.compare_exchange_weak(F, _input[V]) {}
				Mtx.lock();
				F.store(_input[V]);
				results.push_back(_input[V]);
				std::cout << _input[V] << ":";
				Mtx.unlock();
				//}
			}));
			Mtx2.unlock();
		}
		for (auto &Thr : Sthreads)
		{
			Thr.join();
		}
		return results;
	}
};// MTsort


/*
============================================================================
						UTILITIES && TESTING
============================================================================
*/
#include<chrono>
#include<assert.h>

#if DISPLAY_ARRAY
#    define Print(x) std::cout << x << "\n\n"
#else
#    define Print(x) 
#endif

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
typedef std::chrono::time_point<std::chrono::steady_clock> Timepoint;
using Nanoseconds  = std::chrono::nanoseconds;
using Microseconds = std::chrono::microseconds;


/* Simple Benchmark to test speeds of the sorting algorithms */
//template<typename _Res = Nanoseconds>
struct Benchmark
{
	using Resolution = Nanoseconds;
	uint64_t *Storage;
	Benchmark(uint64_t* _storage)
		:
		Storage(_storage)
	{
		Start_Time = Clock::now();
	}
	void Sample()
	{
		Start_Time = Clock::now();
	}
	~Benchmark()
	{
		*Storage = (uint64_t)std::chrono::duration_cast <Resolution> (Clock::now() - Start_Time).count();
	}
	Timepoint Start_Time;
	Timepoint Duration;
};


/* Asserts the Input array is in order NOTE: Test can falsely pass in rare cases */
template<typename _Ty>
bool Test_array(std::vector<_Ty> _input)
{
	for (int i{ 1 }; i < _input.size(); ++i)
	{
		if (_input[i] < _input[i - 1])
		{
			return false;
		}
	}
	return true;
}

/* Accepts a Predicate and Vector. Prints out the Array the Test that it has been sorted properly */
template<typename _Ty>
void Test_sort(const char *_name, std::vector<_Ty> _input, std::vector<_Ty>(*_predicate)(std::vector<_Ty>))
{
	_input = Impl::Randomize(_input);
	uint64_t Time{ 0 };
	{
		Benchmark B(&Time);
		_input = _predicate(_input);
	}
	std::cout << _name   << " finished in " << ((float)Time / 1000.0f) / 1000.0f << "ms" << "\n";
	Print(_input);
	assert(Test_array(_input));
}

std::mutex Mtx;
template<typename _Ty>
std::thread run_Sort_Thread(const char* _name, std::vector<_Ty> _array, std::vector<_Ty>(*_predicate)(std::vector<_Ty>))
{
	return std::move(std::thread(
		[&]()
	{
		std::string N{};
		{
			std::unique_lock<std::mutex> Lock{ Mtx };
			N = std::string(_name);
		}
		Test_sort(N.c_str(), _array, _predicate);
		std::cout << N.c_str() << " thread ended \n\n";
	}));
}


/*
 *    The Devil of Sort Algorithms...
 *  Enter at your Own risk! You have been warned.
 */
namespace Shitsorts
{
	size_t BogoCount{ 0 };
	template<typename _Ty>
	std::vector<_Ty> Bogo_sort(std::vector<_Ty> _input)
	{
		Timepoint Start_Time;

		while (!Test_array(_input))
		{
			_input = Impl::Randomize(_input);
			++BogoCount;
		}
		std::cout << "Bogo Sort completed in " << BogoCount << " tries \n" ;
		return _input;
	}


	// Function to implement stooge sort 
	template<typename _Ty>
	std::vector<_Ty> Stooge_sort_impl(std::vector<_Ty>& _input, int _low, int _high)
	{
		if (_low >= _high)
		{
			return _input;
		}
		if (_input[_low] > _input[_high])
		{
			std::swap(_input[_low], _input[_high]);
		}
		if (_high - _low + 1 > 2)
		{
			int t = (_high - _low + 1) / 3;
			_input = Stooge_sort_impl(_input, _low, _high - t);
			_input = Stooge_sort_impl(_input, _low + t, _high);
			_input = Stooge_sort_impl(_input, _low, _high - t);
		}
		return _input;
	}


	template<typename _Ty>
	std::vector<_Ty> Stooge_sort(std::vector<_Ty> _input)
	{
		return Stooge_sort_impl(_input, 0, (int)_input.size() - 1);
	}


	template<typename _Ty>
	void Swap(_Ty *a, _Ty *b)
	{
		_Ty *Temp = a;
		a = b;
		b = Temp;
		return;
	}

	template<typename _Ty>
	_Ty* MiddleValue(_Ty* _a, _Ty* _b, _Ty* _c)
	{
		if (*_a < *_b && *_b < *_c)    return  _b;
		if (*_a < *_c && *_c <= *_b)    return  _c;
		if (*_b <= *_a && *_a < *_c)    return  _a;
		if (*_b < *_c && *_c <= *_a)    return  _c;
		if (*_c <= *_a && *_a < *_b)    return  _a;
		if (*_c <= *_b && *_b <= *_c)    return  _b;
		__debugbreak();// Somethings wrong;
		return NULL;
	}


	/* Single Threaded Introsort */
	template<typename _Ty>
	void Intro_sort_impl(std::vector<_Ty>& _input, int _begin, int _end, int _depth)
	{
		int size = (_end - _begin);
		if (size < 16)
		{
			_input = Linear::Insertion_sort(_input);
			return;
		}
		if (_depth == 0)
		{
			_input = Linear::Heap_sort(_input);
			return;
		}

		_Ty* M{};
		M = MiddleValue(&_input[_begin], &_input[_begin + size / 2], &_input[_end]);
		Swap(M, &_input.at(_end));

		int partitionPoint = Impl::Partition(_input, _begin, _end);
		Intro_sort_impl(_input, _begin, partitionPoint - 1, _depth - 1);
		Intro_sort_impl(_input, partitionPoint + 1, _end, _depth - 1);
	}

	template<typename _Ty>
	std::vector<_Ty> Intro_sort(std::vector<_Ty> _input)
	{
		Intro_sort_impl(_input, 0, (int)_input.size() - 1, (int)(2 * log(_input.size())));
		return _input;
	}




	/* Single Threaded Bucket Sort */
	template<typename _Ty>
	std::vector<_Ty> Bucket_sort(std::vector<_Ty> _input)
	{
		int n = _input.size();
		std::vector<std::vector<_Ty>> Bucket(n);

		for (int i{ 0 }; i < n; ++i)
		{
			int bi = n * _input[i];
			Bucket[bi].push_back(_input[i]);
		}
		for (int i = 0; i < n; i++)
		{
			std::sort(Bucket[i].begin(), Bucket[i].end());
		}
		int index = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < Bucket[i].size(); j++)
			{
				_input[index++] = Bucket[i][j];
			}
		}
		return _input;
	}

}// End NS Shitsorts
