# Multi-Threaded-Sort-Algorithms
Simple test bed for Sorting Algorithms both Linear and Multithreaded. 

 Return Value                       |        Function Name                  |      Description
------------------------------------|---------------------------------------|-----------------------------------
template<typename _Ty> std::ostream& |    operator <<(std::ostream& lhv, std::vector<_Ty> rhv) |  Returns the whole array in sequence to the Console
template<typename _Ty> bool |   Test_array(std::vector<_Ty> _input) | Test the Array and Asserts to Entire every element is higher than the last as proof a sort has worked
template<typename _Ty> void |   Test_sort(const char *_name, std::vector<_Ty> _input, std::vector<_Ty>(*_predicate)(std::vector<_Ty>)) |  Runs a Benchmark on a Sort algorithm, User supplies the Name of the sort, The Array in question and a Function pointer to the sort algorithm which accepts a vector as parameter and returns a vector




Sorting Algorithm            | Linear  | Multi-Threaded
-----------------------------|---------|-------------
Merge Sort                   |  [x]    |  [ ]
Bubble Sort                  |  [x]    |  [ ]
Quick Sort				     |  [x]    |  [ ]                  
Heap Sort				     |  [x]    |  [ ]                  
Insertion Sort			     |  [x]    |  [ ]                  
Selection Sort               |  [x]    |  [ ]                                       
Counting Sort			     |  [x]    |  [ ]                  
Cycle Sort				     |  [x]    |  [ ]                  
BogoSort/Permutation Sort	 |  [x]    |  [ ]
Gnome Sort					 |  [x]    |  [ ]
ShellSort				     |  [x]    |  [ ]    
Intro Sort				     |  [O]    |  [ ]                  
Bucket Sort				     |  [!]    |  [ ]                  
Radix Sort				     |  [ ]    |  [ ]                  
TimSort					     |  [ ]    |  [ ]                  
Comb Sort				     |  [ ]    |  [ ]                  
Pigeonhole Sort			     |  [ ]    |  [ ]                  
Cocktail Sort			     |  [ ]    |  [ ]                  
Strand Sort				     |  [ ]    |  [ ]                  
Bitonic Sort			     |  [ ]    |  [ ]                  
Pancake sorting			     |  [ ]    |  [ ]                  
Binary Insertion Sort	     |  [ ]    |  [ ]                  
Recursive Bubble Sort	     |  [ ]    |  [ ]                  
Recursive Insertion Sort     |  [ ]    |  [ ]                  
Iterative Merge Sort	     |  [ ]    |  [ ]                  
Iterative Quick Sort	     |  [ ]    |  [ ]                  
Sleep Sort  				 |  [ ]    |  [ ]
Structure Sorting  			 |  [ ]    |  [ ]
Stooge Sort					 |  [ ]    |  [ ]
Tag Sort  					 |  [ ]    |  [ ]
Tree Sort					 |  [ ]    |  [ ]
Cartesian Tree 				 |  [ ]    |  [ ]
Odd-Even / Brick 			 |  [ ]    |  [ ]
QuickSort S Linked List		 |  [ ]    |  [ ]
QuickSort D Linked List		 |  [ ]    |  [ ]
3-Way QuickSort 			 |  [ ]    |  [ ]
Merge Sort Linked 			 |  [ ]    |  [ ]
Merge Sort Doubly  			 |  [ ]    |  [ ]
3-way Merge Sort			 |  [ ]    |  [ ]