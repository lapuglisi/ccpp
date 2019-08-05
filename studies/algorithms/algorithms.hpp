#pragma once

#include <iostream>

namespace algorithms
{
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