#include <iostream>
#include <set>

using namespace std;

int main()
{
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

    set<pair<int, int>> flats;
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
                flats.insert(make_pair(r, c));
            }
            else if (lot[r][c] == 9)
            {
                flats.insert(make_pair(r, c));
                row_o = r;
                col_o = c;

                found = true;
                break;
            }
        }
        printf("<\n");
    }

    // Dump the set here
    printf("Paths to obstacle: \n");
    for (auto it = flats.begin(); it != flats.end(); it++)
    {
        printf("(%d, %d)", it->first, it->second);
        if (it->first == row_o && it->second == col_o)
        {
            printf(" *");
        }
        printf("\n");
    }

    return 0;
}