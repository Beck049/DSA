# Matrix (2D array)

## 2D array implementation
Sequential memory

|A:mxn|||
|---|---|---|
|Row-Major|$a_{ij}=a[i*n+j]$|ex.`C/C++`|
|Column-Major|$a_{ij}=a[i+j*m]$||

## Matrix

### `add`
### `mul`
### `scalar_mul`
### `transpose(int type)`

### special matrix

||儲存方式|
|---|---|
|**upper matrix**    |$a_{ij} = a[\frac{i(i-1)}{2}+j] = k$|
|**lower matrix**    |$a_{ij} = a[\frac{n(i-1)-i(i-1)}{2}+j] = k$|
|**symmetric matrix**|可同用 lower/upper matrix 的儲存方式|

|upper matrix|lower matrix|
|:---:|:---:|
|$\begin{vmatrix}a_{11} & a_{12} & a_{13} & a_{14} \\ & a_{22} & a_{23} & a_{24} \\ &  & a_{33} & a_{34} \\ &  &  & a_{44} \\\end{vmatrix}$|$\begin{vmatrix}a_{11} &  &  & \\a_{21} & a_{22} &  & \\a_{31} & a_{32} & a_{33} & \\a_{41} & a_{42} & a_{43} & a_{44} \\ \end{vmatrix}$|

**Band Matrix**

p.81 ex.2-16

[Sparse Matrix]()