#ifndef STUDIES_ALGORITHMS_H
#define STUDIES_ALGORITHMS_H

#include <math.h>
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
        // I could act like crazy and handle Grid as a one-dimension array
        // such as Grid[0 <= row < rows] points to a int[5] (column[0 to cols - 1])
        // Leave it for a future implementation.
        int count_rb = 0;
        int count_br = 0;
        int l_path = 0;
        int d_path = 0;

        for (int r = startX; r < rows; r++)
        {
            for (int c = startY; c < cols; c++) // You can use other languages too.
            {
                // Q. Why don't you use 'auto' instead of std::pair<int, int> ?
                // R. Good question.
                auto current_cell = std::make_pair(r, c);
                if (Grid[r][c] == 0)
                {
                    // Here is the trick.
                    // Try and figure out what I am doing.
                    if ((r + 1 < rows && Grid[r + 1][c] == 0) ||
                        (r - 1 > 0 && Grid[r - 1][c] == 0) ||
                        (c + 1 < cols && Grid[r][c + 1] == 0) ||
                        (c - 1 > 0 && Grid[r][c - 1] == 0))
                    {
                        count++;
                    }
                    else
                    {
                        count--;
                    }
                    
                }
                else if (Grid[r][c] == whatToFind)
                {
                    printf("[find_shortest_path] Found target '%d' at (%d, %d).\n",
                        whatToFind, r, c);

                    if (count > 0 && 
                        ((r - 1 > 0 && Grid[r - 1][c] == 0) ||
                        ((c - 1 > 0 && Grid[r][c - 1]) == 0)))
                    {
                        // We came from a valid path
                        l_path = (r - startX) + (c - startY);
                        printf("a^2 = (%d)^2 + (%d)^2\n", r - startX, c - startY);
                        double diagonal = sqrt(pow(r - startX, 2) + pow(c - startY, 2));
                        d_path = ceil(diagonal);
                    }
                    else
                    {
                        // No suitable path.
                        count = -1;
                    }

                    // Found target. Update paths and exit loop
                    r = rows, c = cols; // Just to make sure we exit all loops
                    break;
                }
            }
        }

        /// Dump values here
        printf("[I] l_path is %d, d_path is %d (%d), count is %d\n", 
            l_path, d_path, (d_path - 1) * 2,
            count);

        /// Now proceed with the investigation:
        /// I. If 'count' < 'l_path', then there is no path to the target
        /// because the minimum would be l_path
        /// II. If 'count' > 'l_path', then the path to the target
        /// is the diagonal.
        if (count < l_path)
        {
            return -1;
        }
        else if (count == l_path)
        {
            return l_path;
        }
        
        /// Note: we don't draw a straight diagonal in the grid.
        /// So bear in mind that it must be considered as a 'line'
        /// of right -> bottom combinations.
        /// In other words, a 'diagonal' for each cell is calculated
        /// as a 1 right, 1 bottom (2 steps).
        /// Since we are not counting the last diagonal (target cell)
        /// the value for d_path is (actual diagonal - 1 * 2)
        /// Diagonal, our 2o shortest path.
        return (d_path - 1) * 2;
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