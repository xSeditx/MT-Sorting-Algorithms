#include"MTsort.h"

#include<algorithm>

// Prevents the console from Syncing in MT environment sync_with_stdio(false)
void TestShitSorts();

int main()
{
	for (int i{ 0 }; i < 10; ++i)
	{
		std::vector<int> SmallArray = { 31,30,29,28,27,26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
		};// 32 Elements

		std::vector<int> LargeArray;
		for (int i{ 0 }; i < 1000; ++i)
		{
			LargeArray.emplace_back(i);
		}	LargeArray = Impl::Randomize(LargeArray);


		std::vector<int> RandomArray;
		for (int i{ 0 }; i < 100; ++i)
		{// Place Random numbers into the array then mix them up afterwards
			RandomArray.emplace_back(rand() % 1000);
		}	RandomArray = Impl::Randomize(RandomArray);

		/*
		auto Array = RandomArray;  
		auto Array = SmallArray ;  
	*/
			auto Array = LargeArray ;  

		{// START THE TESTING
			std::cout << "________________________________________________________________________________ \n";
			std::cout << "===================================== START ==================================== \n";
			std::cout << "================================================================================ \n";

			Array = Impl::Randomize(Array);
			uint64_t Time{ 0 };
			{
				Benchmark B(&Time);
				std::sort(Array.begin(), Array.end());
			}

			std::cout << "Control Group: " << Array.size() << " elements \n";
			std::cout << "std::sort" << " finished in " << ((float)Time / 1000.0f) / 1000.0f << "ms  \n";
			Test_array(Array);

			std::cout << "================================================================================ \n";
			
			Test_sort("     Tree Sort", Array, Linear::Tree_sort);

			Test_sort("     Heap Sort", Array, Linear::Heap_sort);
			Test_sort("    Merge Sort", Array, Linear::Merge_sort);
			Test_sort("    Shell Sort", Array, Linear::Shell_sort);
			Test_sort("    Gnome Sort", Array, Linear::Gnome_sort);
			Test_sort("    Quick Sort", Array, Linear::Quick_sort);
			Test_sort("    Count Sort", Array, Linear::Count_sort);
			Test_sort("    Cycle Sort", Array, Linear::Cycle_sort);
			Test_sort("   Bubble Sort", Array, Linear::Bubble_sort);
			Test_sort("Insertion Sort", Array, Linear::Insertion_sort);
			Test_sort("Selection Sort", Array, Linear::Selection_sort);
			std::cout << "________________________________________________________________________________ \n";
			std::cout << "==================================== END ======================================= \n\n\n";


		}// END TESTING SCOPE
	}

	TestShitSorts();
}


void TestShitSorts()
{
	std::vector<int> MediumArray = { 31,30,29,28,27,26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	std::vector<int> TinyArray = { 7, 6, 5, 4, 3, 2, 1, 0 };

	auto Array = TinyArray;
	std::cout << " \n";
	std::cout << "=============== Running Shitty Sorts =========================================== \n";
 	std::cout << Array.size() << " Elements in sequential Arrays \n\n";
	std::cout << "================================================================================ \n";

	std::thread BogoThread = run_Sort_Thread("Bogo Sort", Array, Shitsorts::Bogo_sort);
	std::thread IntroThread = run_Sort_Thread("Intro Sort", Array, Shitsorts::Intro_sort);
	std::thread StoogeThread = run_Sort_Thread("Stooge Sort", Array, Shitsorts::Stooge_sort);

	StoogeThread.join();
	IntroThread.join();
	BogoThread.join();
	std::cout << "================================================================================ \n";
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
