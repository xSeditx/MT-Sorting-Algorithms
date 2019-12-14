#include"MTsort.h"


int main()
{

	std::vector<int> Array =	{ 31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0	};// 32 Elements

	Array = Linear::Merge_sort(Array);
	Print("\n Merge Sort: " << Array);

	Array = Linear::Randomize(Array);

	Array = Linear::Bubble_sort(Array);
	Print("\n Bubble Sort: " << Array);

	Array = Linear::Randomize(Array);

	Array = Linear::Quick_sort(Array);
	Print("\n Quick Sort: " << Array);
 }