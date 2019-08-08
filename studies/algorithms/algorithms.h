#ifndef STUDIES_ALGORITHMS_H
#define STUDIES_ALGORITHMS_H

#include <math.h>
#include <memory.h>
#include <iostream>
#include <set>

#define DUMP_2D_ARRAY(__GRID, __rows, __cols) \
    printf("Dumping %s:\n", #__GRID); \
    for (int __r = 0; __r < __rows; __r++) \
    {\
        for (int __c = 0; __c < cols; __c++) \
        { \
            printf("%d%s", __GRID[__r][__c], (__c + 1 < __cols ? ", " : "")); \
        } \
        printf("\n"); \
    }

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

    } // namespace sorting

    ///
    /// Given a grid rows x cols, 
    /// find the shortest path from (startX, startY) to whatToFind (x, y)
    ///
    /// Proposition:
    /// 1. whatToFind defines the value of the cell to be found
    /// 2. Grid must be filled with 0's and 1's
    /// a. Cells with 0's are free cells and can be traversed
    /// b. Cells with 1 are blocked cells and can not
    ///
    /// I may add the following proposition:
    /// There are three ways to get to one point from another in a grid:
    /// 1. A 'L' (bottom then right)
    /// 2. A 180 rotated 'L' (right then bottom)
    /// 3. A diagonal from start to target
    ///
    /// To calculate the L's (1 and 2), just calculate targetX - startX, targetY - startY
    /// Now here is the trick: if there IS a path to target and neither 1 nor 2 satisfy
    /// THEN a diagonal exists.
    /// Since we can't traverse diagonally in a grid, we can calculate the diagonal
    /// length for the rectangle (startX, startY) (targetX, targetY)
    /// using a^2 = b^2 + c^2
    template<size_t rows, size_t cols>
    int find_shortest_path(int Grid[rows][cols], int startX, int startY, int whatToFind)
    {
        DUMP_2D_ARRAY(Grid, rows, cols);

        std::set<std::pair<int, int>> paths;

        // If whoever is calling this function is confused, 
        // we must help them
        startX = (startX < 0 || startX >= rows ? 0 : startX);
        startY = (startY < 0 || startY >= cols ? 0 : startY);

        // Now I'm trying to think of a way to avoid some O(rows * cols) here
        // Processing...
        // I don't know
        int count_br = 0;
        int count_rb = 0;
        int diagonal = 0;

        // Take the following propositions under consideration:
        //   I. There are 3 possible shortest paths from A to B
        //      in a grid:
        //   a. The diagonal (shortest of all)
        //   b. The L from A to B (bottom then right)
        //   c. The 180 rotated L from A to B (right then bottom)
        //
        //  II. The L's can be calculate with: (endX - startX) + (endY - startY).
        // III. Since we cannot traverse a diagonal in the array,
        //      we calculate it by calculating the original diagonal
        //      and multiplying by two (to traverse a single diagonal
        //      we must go 1 bottom <-> 1 right)
        for (int r = startX; r < rows; r++)
        {
            for (int c = startY; c < cols; c++) // You can use other languages too.
            {
                if (Grid[r][c] == 0)
                {
                    if (r - 1 > 0 && Grid[r - 1][c] == 0)
                    {
                        // We're doing right :)
                        count_rb++;
                    }
                    else if (c - 1 > 0 && Grid[r][c - 1] == 0)
                    {
                        // We're going down :|
                        count_br++;
                    }
                }
                else if (Grid[r][c] == whatToFind)
                {
                    if ((r - 1 > 0 && Grid[r - 1][c] != 0) ||
                        (c - 1 > 0 && Grid[r][c - 1] != 0))
                    {
                        // The target is blocked.
                        count_br = 0;
                        count_rb = 0;
                        diagonal = 0;
                    }

                    diagonal = sqrt(pow(r - startX, 2) + pow(c - startY, 2));

                    // Update diagonal to reflect the exact number of steps
                    diagonal = (diagonal - 1) * 2;
                    
                    // Reset r and c so that we exit all loops.
                    r = rows, c = cols;
                    break;
                }
            }
        }

        printf("count_br = %d, count_rb = %d\n", count_br, count_rb);

        return (diagonal > 0 ? diagonal : -1);
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