#pragma once

#include <iostream>

namespace algorithms
{
    namespace sorting
    {
        // Merge sort: O(N logN)
        void merge_sort(int A[], int asize);

        // Quick sort: O(N logN), worst case O(N)
        void quick_sort(int A[], int asize);

        // Insertion sort: O(N) (? O(N²))
        void insertion_sort(int A[], int asize);

        // Selection sort: O(N) (? O(N²))
        void selection_sort(int A[], int asize);
    }
	template<size_t rows, size_t cols>
	void printSpiral2D(int A2D[rows][cols]);

	///
	/// Finds a element in a circularly sorted array
	///
	int circularArraySearch(int A[], int asize, int element);

	///
	/// Finds the rotation count of a circulary rotated array
	///
	int findRotationCount(int A[], int asize);

}