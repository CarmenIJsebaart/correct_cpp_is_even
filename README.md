# correct_cpp_is_even

Branch|[Travis CI](https://travis-ci.org)|[Codecov](https://www.codecov.io)
---|---|---
master|[![Build Status](https://travis-ci.org/CarmenIJsebaart/correct_cpp_is_even.svg?branch=master)](https://travis-ci.org/CarmenIJsebaart/correct_cpp_is_even)|[![codecov.io](https://codecov.io/github/CarmenIJsebaart/correct_cpp_is_even/coverage.svg?branch=master)](https://codecov.io/github/CarmenIJsebaart/correct_cpp_is_even/branch/master)

[Correct C++](https://github.com/richelbilderbeek/correct_cpp) chapter 'is even'.

## Goals

 * First use of std::regex

## Prerequisites

 * Understand [how this course works](https://github.com/richelbilderbeek/correct_cpp/blob/master/doc/how_this_course_works.md)
 * Have written [a correct 'is_odd' program](https://github.com/richelbilderbeek/correct_cpp_is_odd)

## Exercise

Write a command-line interface (CLI) program that determines if its argument is an even number.

If there are more arguments supplied, exit the program.

Call to `is_even`|Output|Exit status
---|---|---
`./is_even`|Any|1
`./is_even 12345678901234567890`|`true` (with newline)|0
`./is_even 12345678901234567891`|`false` (with newline)|0
`./is_even nonsense`|Any|1
`./is_even 2 1`|Any|1

This is the code you start with:

```c++
main(argc, argv)
{
  //Your code here
}
```

 * You cannot use [std::stoi](https://github.com/richelbilderbeek/cpp/blob/master/content/CppStdStoi.md), as it will not convert `12345678901234567890`
   to integer
 * Instead, you should use [std::regex](https://github.com/richelbilderbeek/cpp/blob/master/content/CppStdRegex.md)
 * An even number is a regular expression of one or more digits, that may or may not start with a minus

## External links

 * [Download the Qt Creator file `main.pro`](https://raw.githubusercontent.com/richelbilderbeek/correct_cpp/master/shared/main.pro)
