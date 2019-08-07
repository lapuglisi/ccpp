#include <iostream>
#include "algorithms.h"

#define DUMP_ARRAY(__A, __begin, __end) \
  printf("%s (%d -> %d): [", #__A, __begin, __end); \
  for (int __i = __begin; __i < __end; __i++) \
  {\
    printf("%d%s", __A[__i], (__i + 1 < __end ? ", " : "")); \
  }\
  printf("]\n");

namespace algorithms
{

//
// Algorithms for sorting
//
namespace sorting
{
    ///
    /// Merge Sort: constant O(n log(n))
    ///
    void merge_sort(int A[], size_t array_size)
    {
      merge_sort(A, 0, array_size - 1);
    }

    void merge_sort(int A[], int begin, int end)
    {
      if (begin >= end)
      {
        return;
      }

      int middle = ((begin + end) / 2);

      merge_sort(A, begin, middle);
      merge_sort(A, middle + 1, end);

      merge(A, begin, middle, end);
    }

    void merge(int A[], int begin, int middle, int end)
    {
      int li = 0; // index for operations on the left
      int ri = 0; // index for operations on the right
      int mi = 0; // Index of the merged array
      int left_size = (middle - begin) + 1;
      int right_size = (end - middle);

      // Use temporary arrays to sort
      int LA[left_size], RA[right_size];

      // Copy left half
      for (li = 0; li < left_size; li++)
      {
        LA[li] = A[begin + li];
      }

      // Copy right half
      for (ri = 0; ri < right_size; ri++)
      {
        RA[ri] = A[middle + ri + 1];
      }

      // Merge the two arrays back into A[begin ... end]
      li = 0;     // Reset left index
      ri = 0;     // Reset right index
      mi = begin; // Reset merged index
      while (li < left_size && ri < right_size)
      {
        // Left element is <= right element?
        if (LA[li] <= RA[ri])
        {
          A[mi] = LA[li];
          li++;
        }
        else
        {
          // Right element is lower than left element.
          // Copy it to A
          A[mi] = RA[ri];
          ri++;
        }

        mi++;
      }

      // Now we must copy any remaining elements in LA to A...
      while (li < left_size)
      {
        A[mi] = LA[li];
        mi++;
        li++;
      }

      // ... and do the same for the remaining elements in RA
      while (ri < right_size)
      {
        A[mi] = RA[ri];
        ri++;
        mi++;
      }
    }

    ///
    /// Quick sort: average θ(n log(n)), worst O(n^2)
    ///
    void quick_sort(int A[], int asize)
    {

    }

    ///
    /// Insertion sort: best O(n), worst O(n^2)
    ///
    void insertion_sort(int A[], int asize)
    {

    }

    ///
    /// Selection sort: best O(n), worst O(n^2)
    ///
    void selection_sort(int A[], int asize)
    {

    }

    ///
    /// Bubble sort: best O(n), worst O(n^2)
    ///
    void bubble_sort(int A[], int asize)
    {

    }
}

template<size_t rows, size_t cols>
void find_shortest_path(int Grid[rows][cols], int startX, int starY, int findX, int findY)
{
	
}

template<size_t rows, size_t cols>
void print_spiral(int A2D[rows][cols])
{
	int top = 0, right = cols - 1, bottom = rows - 1, left = 0;
	int direction = 0; // 0 - top, 1 - right, 2 - bottom, 3 - left
	int index = 0;

	for (; top <= bottom && left <= right; )
	{
		switch (direction)
		{
		case 0: //top
		{
			for (index = left; index <= right; index++)
			{
				printf("%d ", A2D[top][index]);
			}

			top++;
			break;
		}

		case 1: // right
		{
			for (index = top; index <= bottom; index++)
			{
				printf("%d ", A2D[index][right]);
			}

			right--;
			break;
		}

		case 2: // bottom
		{
			for (index = right; index >= left; index--)
			{
				printf("%d ", A2D[bottom][index]);
			}

			bottom--;
			break;
		}

		case 3: // left
		{
			for (index = bottom; index >= top; index--)
			{
				printf("%d ", A2D[index][left]);
			}

			left++;
			break;
		}

		default:
			printf("What the hell?\n");
			break;
		}

		// Little trick to master direction
		direction = (direction + 1) % 4;
	}
}

///
/// Finds a element in a circularly sorted array
///
int circular_array_search(int A[], int asize, int element)
{
	// Note: asize, in this case, can be calculated as sizeof(A)/sizeof(A[0])
	// Just to make sure this function does not receive an invalid asize

	int start = 0, end = asize - 1;
	int middle = -1;
	int found = -1;

	for (; start <= end; )
	{
		middle = (start + end) / 2;

		if (A[middle] == element)
		{
			found = middle;
			break;
		}

		// Divide and conquer;
		// Is the right half sorted?
		if (A[middle] <= A[end])
		{
			// Is the last element our match?
			if (element == A[end])
			{
				found = end;
				break;
			}

			// Do whatever
			if (element > A[middle] && element < A[end])
			{
				start = middle + 1;
			}
			else // Our element is in the left half
			{
				end = middle - 1;
			}
		}
		else // Left half is surely sorted
		{

			if (element > A[start] && element <= A[middle])
			{
				end = middle - 1;
			}
			else
			{
				start = middle + 1;
			}
		}
	}

	return found;
}

///
/// Finds the rotation count of a circulary rotated array
///
int find_rotation_count(int A[], int asize) {

	int low = 0;
	int high = asize - 1;
	int index = 0;

	while (high > 0 && low < asize && A[high] <= A[low])
	{
		index = high;
		low++, high--;
	}

	// By now, we should have A[high] > A[low]
	// So A[high] is now the element right before
	// the minimum element. 
	// Update index to high + 1
	index = (index > 0 ? index : -1);

	return index;
}

}