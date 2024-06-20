#include <iostream>
#include <vector>

// TODO: Implement the functions in q.cc
// Answer all non-programming questions in you README.md file.

//-----------------------------------------------------------------------------
// Concatenate two dynamic arrays.
// In your implementation you cannot use any STL function or class.
// Example:
// array_1 = {1, 2}, size_1 = 2
// array_2 = {2, 3, 4}, size_12 = 3
// Output: {1, 2, 2, 3, 4}.
//
// Answer these questions in the README file.
// Question 1: Why did we have to provide size_1, size_2 as an input?
// Question 2: How can we know the size of the output?
int *Concatenate(int *array_1, int size_1, int *array_2, int size_2);

//-----------------------------------------------------------------------------
// Concatenate two vectors.
// In your implementation you cannot use any STL function or class other then
// vector.

// Example:
// vector_1 = {1, 2}
// vector_2 = {2, 3, 4}
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why didn't we provide the sizes?
// Question 2: We have two functions with the name of Concatenate. Is this ok?
std::vector<int> Concatenate(std::vector<int> &vector_1,
                             std::vector<int> &vector_2);
