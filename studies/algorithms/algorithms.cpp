#include <iostream>

///
/// Finds a element in a circularly sorted array
///
int circularArraySearch(int A[], int asize, int element)
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
int findRotationCount(int A[], int asize) {

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

int main()
{
    int A[] = {10, 11, 12, 13, 14, 15, 16, 17, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int asize = sizeof(A)/sizeof(A[0]);
    int index = 0;
    int find_me = 3;

    index = findRotationCount(A, asize);
    printf("findRotationCount returned %d\n", index);

    index = circularArraySearch(A, asize, find_me);
    printf("circularArraySearch: %d is at A[%d] = %d\n", find_me, index, A[index]);

	return 0;
}
