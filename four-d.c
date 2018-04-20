#include "stdio.h"
#define DIMENSION_1 3
#define DIMENSION_2 3
#define DIMENSION_3 3
#define DIMENSION_4 3

int getIndex(int i, int j, int k, int a);
void output(const int *array, int size);

int main(void)
{
    printf("\nOne dimensional array mimicking 3d array:\n");
    const int num_elements = DIMENSION_1 * DIMENSION_2 * DIMENSION_3 * DIMENSION_4;
    int single4d[num_elements];
    int val = 0;
    int index = 0;

    for (int x = 0; x < DIMENSION_1; x++) {
        for (int y = 0; y < DIMENSION_2; y++) {
            for (int z = 0; z < DIMENSION_3; z++) {
                for (int a = 0; a < DIMENSION_4; a++) {
                    index = getIndex(x, y, z, a);
                    val = index * (a + 1);
                    single4d[index] = val;
                    printf(z < DIMENSION_4 - 1 ? "%d: %d, " : "%d: %d", index, val);
                }
            }
            printf(" | ");
        }
        printf("\n");
    }

    output(single4d, num_elements);
    printf("\nGet single4d[1][1][2][1]:");
    printf(" %d\n", single4d[getIndex(1, 1, 2, 1)]);

    return 0;
}

int getIndex(int x, int y, int z, int a)
{
    if (x >= DIMENSION_1 || y >= DIMENSION_2 || z >= DIMENSION_3 || a >= DIMENSION_4) {
        return 1;
    }
    return (x * (DIMENSION_4 * DIMENSION_3 * DIMENSION_2)) + (y * (DIMENSION_4 * DIMENSION_3)) + (z * DIMENSION_4) + a;
}

void output(const int *array, int size)
{
    int index = 0;
    printf("Size: %d\n", size);
    for (int x = 0; x < DIMENSION_1; x++) {
        for (int y = 0; y < DIMENSION_2; y++) {
            for (int z = 0; z < DIMENSION_3; z++) {
                for (int a = 0; a < DIMENSION_4; a++) {
                    index = getIndex(x, y, z, a);
                    printf("array[%d][%d][%d][%d] = %d\t", x, y, z, a, array[index]);
                    printf("Index: %d, Value: %d\n", index, (index * (a + 1)));
                }
            }
        }
    }

}
