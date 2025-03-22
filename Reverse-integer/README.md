# Reverse Integer

This program reverses the digits of a given 32-bit signed integer. If the reversed integer exceeds the 32-bit range, it returns `0`.

## Example Usage

```cpp
Solution solution;
int result = solution.reverse(123);  // Output: 321
int result2 = solution.reverse(-123); // Output: -321
int result3 = solution.reverse(120);  // Output: 21
