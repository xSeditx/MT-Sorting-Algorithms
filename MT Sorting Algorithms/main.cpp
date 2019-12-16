#include"MTsort.h"

#include<algorithm>
int main()
{
	for (int i{ 0 }; i < 10; ++i)
	{
		std::vector<int> SmallArray = { 31,30,29,28,27,26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
		};// 32 Elements
		std::vector<int> LargeArray;
		for (int i{ 0 }; i < 100; ++i)
		{
			LargeArray.emplace_back(i);
		}
		LargeArray = Linear::Randomize(LargeArray);


		std::vector<int> RandomArray;
		for (int i{ 0 }; i < 1000; ++i)
		{// Place Random numbers into the array then mix them up afterwards
			RandomArray.emplace_back(rand() % 1000);
		}
		RandomArray = Linear::Randomize(RandomArray);

		//  LargeArray;SmallArray; //
		auto Array = RandomArray; //LargeArray;
		{// START THE TESTING
			std::cout << "==================== START =============================== \n";

			Array = Linear::Randomize(Array);
			uint64_t Time{ 0 };
			{
				Benchmark B(&Time);
				std::sort(Array.begin(), Array.end());
			}
			std::cout << "Control Group: \n";
			std::cout << "std::sort" << " finished in " << ((float)Time / 1000.0f) / 1000.0f << "ms  \n";
			Test_array(Array);

			std::cout << "========================================================= \n";
			Test_sort("     Heap Sort", Array, Linear::Heap_sort);
			//Test_sort("    Intro Sort", Array, Linear::Intro_sort);
			Test_sort("    Merge Sort", Array, Linear::Merge_sort);
			Test_sort("    Shell Sort", Array, Linear::Shell_sort);
			Test_sort("    Gnome Sort", Array, Linear::Gnome_sort);
			Test_sort("    Quick Sort", Array, Linear::Quick_sort);
			Test_sort("    Count Sort", Array, Linear::Count_sort);
			Test_sort("    Cycle Sort", Array, Linear::Cycle_sort);
			Test_sort("   Bubble Sort", Array, Linear::Bubble_sort);
			Test_sort("Insertion Sort", Array, Linear::Insertion_sort);
			Test_sort("Selection Sort", Array, Linear::Selection_sort);


			//Test_sort("Bucket Sort", Array, Linear::Bucket_sort);
			//Test_sort("Radix Sort", Array, Linear::Radix_sort);

			std::cout << "===================== END =============================== \n";
		}// END TESTING SCOPE
	}
}










/*
================================================================================
		  Incomplete and Improper implementations for later review
================================================================================
*/
/* A utility function to get maximum value in arr[]
template<typename _Ty>
int getMax(std::vector<_Ty> _input)
{// This however may still prove useful as it could be incorperated into Count sort or
	int mx = _input[0];// a modified count sort to gather the largest number
	for (int i = 1; i < _input.size(); i++)
		if (_input[i] > mx)
			mx = _input[i];
	return mx;
}
template<typename _Ty>
std::vector<_Ty> Radix_sort(std::vector<_Ty> _input)
{
	int m = getMax(_input);
	for (int exp = 1; m / exp > 0; exp *= 10)
		_input = Count_sort(_input); Count sort does not take in the highest number. Arrays would need broken 
		down in my implementation and currently this is just count sort sorting a sorted array multiple times
	return _input;
}*/
