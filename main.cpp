#include "main.hpp"

/**
* Stack allocated multi-dimensional arrays - sub-arrays won't necessarily be
* stored in contigous memory, which mat degrade performance. A multi diumensional
* array can be mimicked by use of a single array with offsets.
*/
int main(void)
{
    // 2d array
    // -------------------------------------------------------------------------
    int** a2d = new int*[5];
    a2d[0] = nullptr; // assign an integer pointer as first element of a2d

    // Allocate 5 arrays, each one of which has space for 5 integers.
    // a2d array stores locations for the 2nd order arrays
    for (int i = 0; i < 5; i++)
    a2d[i] = new int[5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            a2d[i][j] = (1 + i) * (1 + j);
        }
    }
    std::cout << "\nTwo dimensional array:" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << std::setw(4) << a2d[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 5; i++)
    delete[] a2d[i];
    delete[] a2d;

    // Single dimensional array
    // -------------------------------------------------------------------------
    std::cout << "\nOne dimensional array mimicking 2d array:" << std::endl;
    int* single = new int[25];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            single[i * 5 + j] = (1 + i) * (1 + j);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << std::setw(4) << single[i * 5 + j];
        }
        std::cout << std::endl;
    }
    delete[] single;

    // 3d Array
    // -------------------------------------------------------------------------
    int*** a3d = new int**[5];
    for (int i = 0; i < 5; i++) {
        a3d[i] = new int*[5];
        for (int k = 0; k < 5; k++)
            a3d[i][k] = new int[5];
    }

    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 5; y++)
            for (int z = 0; z < 5; z++)
                a3d[x][y][z] = (x + 1) * (y + 1) * (z + 1);

    // 3d Array
    std::cout << "\n3d array:" << std::endl;
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < 5; z++) {
                std::cout << a3d[x][y][z] << (z != 4 ? ", " : "");
            }
            std::cout << " | ";
        }
        std::cout << std::endl;
    }

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            delete[] a3d[x][y];
        }
        delete[] a3d[x];
    }
    delete[] a3d;

    std::cout << "\nOne dimensional array mimicking 3d array:" << std::endl;
    int* single3d = new int[125];
    std::cout << std::left << std::setw(5) << "Pos"
    << std::left << std::setw(5) << "Val"
    << std::left << std::setw(15) << "Coords" << std::endl;
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < 5; z++) {
                single3d[(25 * x) + (5 * y) + z] = (x + 1) * (y + 1) * (z + 1);
                std::cout << std::left << std::setw(5) << ((25 * x) + (5 * y) + z)
                << std::left << std::setw(5) << (x + 1) * (y + 1) * (z + 1)
                << std::left << "(" << x << ", " << y << ", " << z << ")" << std::endl;
            }
        }
    }

    std::cout << "Get single3d[2][2][3]: answer should be 36" << std::endl;
    std::cout << "single3d[(25 * 2) + (5 * 2) + 3]: " << single3d[(25 * 2) + (5 * 2) + 3] << std::endl;

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < 5; z++) {
                std::cout << single3d[(5 * x) + (5 * y) + z] << (z != 4 ? ", " : "");
            }
            std::cout << " | ";
        }
        std::cout << std::endl;
    }
    delete[] single3d;

    return 0;
}
