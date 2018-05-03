Simulated 3D Array in C
=======================
Represent a 3d array as a single array by using offsets to compute the array index.

This repo is just a learning exercise.

## Example Array
For a conceptual "3D" array `array3d[xmax][ymax][zmax]`, the total number of elements required to represent this as a flat array is `xmax * ymax * zmax` - so theh array should be initialized with `array3d[xmax * ymax * zmax]`.

Array indexes are then calculated with an offset to provide the multi-dimensional behaviour.
`array[f(x, y, z)]` simulates `array[x][y][z]`, where `f(x, y, z)` returns an integer index.

To calculate index `i` for `array3d[x][y][z]`:

` i = (x * (ymax * zmax)) + (y * zmax) + z`

## Array Visualisation
```
i     x     y     z     val
---------------------------
0     0     0     0     A00
1     0     0     1     A01
2     0     0     2     A02
3     0     1     0     A10
4     0     1     1     A11
5     0     1     2     A12
6     0     2     0     A20
7     0     2     1     A21
8     0     2     2     A22
9     1     0     0     B00
10    1     0     1     B01
11    1     0     2     B02
12    1     1     0     B10
13    1     1     1     B11
14    1     1     2     B12
15    1     2     0     B20
16    1     2     1     B21
17    1     2     2     B22
18    2     0     0     C00
19    2     0     1     C01
20    2     0     2     C02
21    2     1     0     C10
22    2     1     1     C11
23    2     1     2     C12
24    2     2     0     C20
25    2     2     1     C21
26    2     2     2     C22
```
To access `array[2][1][1]`, `flatArray[f(2, 1, 1)]` is used. This is computed to retrieve `flatArray[22]` - in this case the value C11 is retrieved.

## Demo

To build, run `make c3d`. The run `./bin/c3d`.

## Resources
* [SO Question][1] (quite a few wrong/confusing answers here)

[1]: https://stackoverflow.com/questions/7367770/how-to-flatten-or-index-3d-array-in-1d-array
