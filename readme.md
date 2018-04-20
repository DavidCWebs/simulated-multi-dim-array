Simulated 3D Array in C
=======================
Represent a 3d array as a single array by using offsets to compute the array index.

This repo is just a learning exercise.

## Example Array
For a conceptual "3D" array `array3d[xmax][ymax][zmax]`, the total number of elements required to represent this as a flat array is `xmax * ymax * znax`: `array3d[xmax * ymax * zmax]`.

Array indexes are then calculated with an offset to provide the multi-dimensional behaviour: `array[f(x, y, z)]` simulates `array[x][y][z]`, where `f(x, y, z)` returns an integer index.

To calculate index `i` for `array3d[x][y][z]`:

` i = x * (ymax * zmax)) + (y * zmax) + z`

## Array Visualisation
```
i     x     y     z
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
```

## Resources
* [SO Question][1] (quite a few wrong/confusing answers here)

[1]: https://stackoverflow.com/questions/7367770/how-to-flatten-or-index-3d-array-in-1d-array
