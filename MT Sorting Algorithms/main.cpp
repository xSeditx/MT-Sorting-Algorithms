#include"MTsort.h"

int main()
{

	std::vector<int> Array = { 31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };// 32 Elements
	Test_sort("Merge Sort", Array, Linear::Merge_sort);
	Test_sort("Bubble Sort", Array, Linear::Bubble_sort);
	Test_sort("Quick Sort", Array, Linear::Quick_sort);
	Test_sort("Heap Sort", Array, Linear::Heap_sort);
	Test_sort("Insertion Sort", Array, Linear::Insertion_sort);
	Test_sort("Selection Sort", Array, Linear::Selection_sort);
}