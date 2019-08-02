#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define IS_WANTED_CELL(__cell) (__cell == 1 || __cell == 9)

int main()
{
    clock_t start = clock();
    clock_t end = 0L;
    double cpu_time = 0.0;

    const int numRows = 6;
    const int numCols = 8;

    const int lot[numRows][numCols] =
    {
        1, 1, 1, 1, 0, 0, 0, 1,
        0, 0, 1, 0, 1, 0, 1, 1,
        1, 1, 1, 0, 1, 1, 0, 0,
        0, 0, 1, 1, 0, 1, 0, 1,
        1, 1, 0, 9, 1, 0, 1, 0,
        1, 1, 0, 0, 1, 0, 1, 0
    };

    map<pair<int, int>, pair<int, int>> backwardPath;

    int row_o = 0, col_o = 0;
    bool found = false;

    for (int r = 0; r < numRows && !found; r++)
    {
        printf("> ");
        for (int c = 0; c < numCols && !found; c++)
        {
            printf("%d ", lot[r][c]);

            if (lot[r][c] == 1)
            {
                // Add cells backwardly
                pair<int, int> currentCell = make_pair(r, c);
                pair<int, int> newCell = make_pair(-1, -1);

                backwardPath.insert(make_pair(currentCell, newCell));
                if (r + 1 < numRows && IS_WANTED_CELL(lot[r + 1][c]))
                {
                    backwardPath[make_pair(r + 1, c)] = currentCell;
                }
                
                if (c + 1 < numCols && IS_WANTED_CELL(lot[r][c + 1]))
                {
                    backwardPath[make_pair(r, c + 1)] = currentCell;
                }
            }
            else if (lot[r][c] == 9)
            {
                row_o = r, col_o = c;
                found = true;
                break;
            }
        }
        printf("<\n");
    }

    printf("\n");
    printf("[backward path]\n");
    for (auto bit = backwardPath.begin(); bit != backwardPath.end(); bit++)
    {
        printf("[%d, %d] <= [%d, %d]\n", 
            bit->first.first, bit->first.second, 
            bit->second.first, bit->second.second);
    }

    // Now use 'backward' search to look for our path
    // Starting at coord(obstacle)
    int length = 0;
    auto obstacle = make_pair(row_o, col_o);

    printf("[main] start by finding our obstacle in the map.\n");
    auto it = backwardPath.find(obstacle);
    if (it == backwardPath.end())
    {
        printf("[main] no valid path to obstacle.\n");
        return 0;
    }

    while (it != backwardPath.end())
    {
        printf("[main] found valid cell at (%d, %d).. move on to (%d, %d).\n", 
            it->first.first, it->first.second,
            it->second.first, it->second.second);
        it = backwardPath.find(it->second);

        length++;
    }

    printf("[main] length of path: %d\n", length);

    // Just some extra data to calculate execution time
    end = clock();
    cpu_time = (double)((end - start) / CLOCKS_PER_SEC);

    printf("\n");
    printf("[main] cpu time used: %.5f s\n", cpu_time);

    return 0;
}