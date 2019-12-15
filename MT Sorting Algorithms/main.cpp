#include"MTsort.h"

#include<algorithm>
int main()
{
	for (int i{ 0 }; i < 10; ++i)
	{
		std::vector<int> SmallArray = { 31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };// 32 Elements
		std::vector<int> LargeArray;
		for (int i{ 0 }; i < 1000; ++i)
		{
			LargeArray.emplace_back(i);
		}
		LargeArray = Linear::Randomize(LargeArray);


		std::vector<int> RandomArray;
		for (int i{ 0 }; i < 1000; ++i)
		{
			RandomArray.emplace_back(rand() % 1000);
		}
		RandomArray = Linear::Randomize(RandomArray);

		auto Array = RandomArray;


		std::cout << "==================== START ===============================" << "\n";

		Array = Linear::Randomize(Array);
		uint64_t Time{ 0 };
		{
			Benchmark B(&Time);
			std::sort(Array.begin(), Array.end());
		}
		std::cout << "std::sort" << " finished in " << ((float)Time / 1000.0f) / 1000.0f << "ms" << "\n";
		Test_array(Array);

		std::cout << "=========================================================" << "\n";
		Test_sort("Merge Sort", Array, Linear::Merge_sort);
		Test_sort("Bubble Sort", Array, Linear::Bubble_sort);
		Test_sort("Quick Sort", Array, Linear::Quick_sort);
		Test_sort("Heap Sort", Array, Linear::Heap_sort);
		Test_sort("Insertion Sort", Array, Linear::Insertion_sort);
		Test_sort("Selection Sort", Array, Linear::Selection_sort);
		Test_sort("Count Sort", Array, Linear::Count_sort);

		std::cout << "===================== END ===============================" << "\n";
	}
}


 