# NasaSafeRPNCalculator
Reverse Polish Notation calculator written in C following THE POWER OF TEN
https://en.wikipedia.org/wiki/The_Power_of_10:_Rules_for_Developing_Safety-Critical_Code

![Reverse_Polish_Notation_Stack_Example](https://github.com/Leek727/NasaSafeRPNCalculator/assets/91506829/2aadc98b-6cdd-48c4-9c23-08dd80c6c136)

# To Compile
`gcc NasaSafeRPNCalc.c -lm -Wall -Wextra -Wshadow`

# Test Cases
Expressions
```
7 8 3 2 ^ * 4 + +
5 6 7 * +
2 3 + 4 *
8 2 / 3 4 * +
9 5 + 2 3 + *
6 3 / 4 2 * +
2 3 ^ 4 *
4 2 5 * + 1 3 2 * + /
7 2 ^ 3 * 4 5 + +
5.5 7.2 *
```

Outputs
```
83
47
20
16
70
10
32
2
156
39.6
```
