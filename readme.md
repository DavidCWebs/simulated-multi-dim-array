Simulated 3D Array in C
=======================
Represent a 3d array as a single array by using offsets to compute the array index.

Learning exercise, work in progress.

## Example Array
`array[index]` simulates `array[Dim1][Dim2][Dim3]`

To calculate index:
`x * (DIMENSION_3 * DIMENSION_2)) + (y * DIMENSION_3) + z`

...where x, y and z are the values for DIMENSION_1, DIMENSION_2 and DIMENSION_3 respectively.
```
Index Dim1  Dim2  Dim3
----------------------
0     0     0     0
1     0     0     1
2     0     0     2
3     0     1     0
4     0     1     1
5     0     1     2
6     0     2     0
7     0     2     1
8     0     2     2
9     1     0     0
10    1     0     1
11    1     0     2
12    1     1     0
13    1     1     1
14    1     1     2
15    1     2     0
16    1     2     1
17    1     2     2
18    2     0     0
19    2     0     1
20    2     0     2
21    2     1     0
22    2     1     1
23    2     1     2
24    2     2     0
25    2     2     1
26    2     2     2
27    -     -     -
```
