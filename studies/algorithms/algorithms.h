#ifndef STUDIES_ALGORITHMS_H
#define STUDIES_ALGORITHMS_H

#include <iostream>

namespace algorithms
{
    namespace sorting
    {
        // Merge sort: constant O(n log(n))
        void merge_sort(int A[], size_t array_size);
        void merge_sort(int A[], int begin, int end);
        void merge(int A[], int begin, int middle, int end);

        // Quick sort: average O(n log(n)), worst case O(n^2)
        void quick_sort(int A[], int asize);

        // Insertion sort: best O(n), worst O(n^2)
        void insertion_sort(int A[], int asize);

        // Selection sort: best O(n), worst O(n^2)
        void selection_sort(int A[], int asize);

        // Bubble sort: best O(n), worst O(n^2)
        void bubble_sort(int A[], int asize);
    }

    ///
    /// Prints a 2D-array in a spiral order
    ///
	template<size_t rows, size_t cols>
	void print_spiral(int A2D[rows][cols]);

	///
	/// Finds a element in a circularly sorted array
	///
	int circular_array_search(int A[], int asize, int element);

	///
	/// Finds the rotation count of a circulary rotated array
	///
	int find_rotation_count(int A[], int asize);

}

#endif // STUDIES_ALGORITHMS_H