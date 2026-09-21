#include <iostream>

int main()
{
    // int * row0 = new int [4];
    // int * row1 = new int [4];
    // int * row2 = new int [4];
    // row1[2] = 5;
    int ** twod = new int * [3];
    for (int i = 0; i < 3; ++i)
    {
        twod[i] = new int [4];
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            twod[i][j] = -1;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        delete [] twod[i];
    }
    delete [] twod;
    return 0;
}
