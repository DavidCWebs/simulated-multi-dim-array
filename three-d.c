#include "stdio.h"
#define DIMENSION_1 3
#define DIMENSION_2 3
#define DIMENSION_3 5

int getIndex(int i, int j, int k);
void output(const int *array, int size);

int main(void)
{
    printf("\nOne dimensional array mimicking 3d array:\n");
    const int num_elements = DIMENSION_1 * DIMENSION_2 * DIMENSION_3;
    int single3d[num_elements];
    int val = 0;
    int index = 0;

    for (int x = 0; x < DIMENSION_1; x++) {
        for (int y = 0; y < DIMENSION_2; y++) {
            for (int z = 0; z < DIMENSION_3; z++) {
                val = (x + 1) * (y + 1) * (z + 1);
                index = getIndex(x, y, z);
                single3d[index] = val;
                printf(z < DIMENSION_3 - 1 ? "%d: %d, " : "%d: %d", index, val);
            }
            printf(" | ");
        }
        printf("\n");
    }

    output(single3d, num_elements);
    printf("\nGet single3d[1][1][2]:");
    printf(" %d\n", single3d[getIndex(1, 1, 2)]);

    return 0;
}

int getIndex(int x, int y, int z)
{
    if (x >= DIMENSION_1 || y >= DIMENSION_2 || z >= DIMENSION_3) {
        return 1;
    }
    return (x * (DIMENSION_3 * DIMENSION_2)) + (y * DIMENSION_3) + z;
}

void output(const int *array, int size)
{
    int index = 0;
    printf("Size: %d\n", size);
    for (int x = 0; x < DIMENSION_1; x++) {
        for (int y = 0; y < DIMENSION_2; y++) {
            for (int z = 0; z < DIMENSION_3; z++) {
                index = getIndex(x, y, z);
                printf("array[%d][%d][%d] = %d\t", x, y, z, array[index]);
                printf("Index: %d, Value: %d\t%p\n", index, ((x + 1) * (y + 1) * (z + 1)), (void*)&array[index]);
            }
        }
    }

}
