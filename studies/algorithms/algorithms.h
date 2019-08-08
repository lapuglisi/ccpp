#ifndef STUDIES_ALGORITHMS_H
#define STUDIES_ALGORITHMS_H

#include <iostream>
#include <map>

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
    typedef std::map<std::pair<int, int>, std::pair<int, int>> two_paired_map_t;
    template<size_t rows, size_t cols>
    void find_shortest_path(int Grid[rows][cols], int startX, int startY, int whatToFind)
    {
        // UPDATE: Use of map is wrong because the key may override
        // previous mappings.
        // Think of another solution.
        two_paired_map_t paths;

        DUMP_2D_ARRAY(Grid, rows, cols);

        // If whoever is calling this function is confused, 
        // we must help them
        startX = (startX < 0 || startX >= rows ? 0 : startX);
        startY = (startY < 0 || startY >= cols ? 0 : startY);

        // Now I'm trying to think of a way to avoid some O(rows * cols) here
        // Processing...
        // I don't know
        for (int r = startX; r < rows; r++)
        {
            for (int c = startY; c < cols; c++) // You can use other languages too.
            {
                auto current_cell = std::make_pair(r, c);
                if (Grid[r][c] == whatToFind)
                {
                    printf("[find_shortest_path] Found target '%d' at (%d, %d).\n",
                        whatToFind, r, c);

                    // Found target. Update paths and exit loop
                    paths.insert(std::make_pair(current_cell, current_cell));
                    r = rows, c = cols; // Just to make sure we exit all loops
                    break;
                }
                else if (r + 1 < rows && Grid[r + 1][c] == 0)
                {
                    // Cell on the right is free
                    paths.insert(std::make_pair(current_cell, std::make_pair(r + 1, c)));
                }
                else if (c + 1 < cols && Grid[r][c + 1] == 0)
                {
                    // Cell at the bottom of current is free
                    paths.insert(std::make_pair(current_cell, std::make_pair(r, c + 1)));
                }
            }
        }

        // Dump 'paths' here        
        for (two_paired_map_t::iterator it = paths.begin(); it != paths.end(); it++)
        {
            printf("[%d, %d] -> [%d, %d]\n", 
                it->first.first, it->first.second,
                it->second.first, it->second.second);
        }

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