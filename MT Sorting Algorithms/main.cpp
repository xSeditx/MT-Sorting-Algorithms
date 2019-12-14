#include"MTsort.h"



int main()
{
	std::vector<int> Array =
	{
		54,23,54,3,6,
		45,62,34,56,456,
		76,55,36,56,65,
		46,52,34,6,54,
		68,57,8,9,63,
		23,54,23,65,12,
		54,85
	};// 32 Elements

	std::vector<int> Reverse =
	{
		31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
	};// 32 Elements

	Array = MTsort::Merge_sort(Array);
	Reverse = MTsort::Bubble_sort(Reverse);

	//Reverse = MTsort::Merge_sort(Reverse);
	Reverse = MTsort::Randomize(Reverse);
	//Reverse = MTsort::Merge_sort(Reverse);

	Reverse = MTsort::Bubble_sort(Reverse);
}