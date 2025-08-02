#include "PrintHelper.h"

/* *************************************
 * * Fundamental types and expressions *
 * *************************************
 *
 * Tasks:
 * ------
 * - Compile the program and analyse the output of the different expressions
 * - Discuss with other students or your tutor in case the result of an expression is a surprise
 * - Fix the marked expressions by changing types such that they produce meaningful results
 * - Answer the questions in the code
 */

int main()
{
    std::cout << "Using literals of different number types:\n";
    print(5);
    print(5 / 2.);
    print(100 / 2ull);
    print(2 + 4ull);
    print(2.f + 4ull);
    print(0 - 1);
    print(1.0000000001);
    print(1.l + 1.E-18);

    std::cout << "\nUsing increment and decrement operators:\n";
    int a = 1;
    int b;
    int c;
    print(b = a++);
    print(c = ++a);
    print(a);
    print(b);
    print(c);

    std::cout << "\nCompound assignment operators:\n";
    double n = 1;
    print(n *= 2);
    print(n *= 2.9);
    print(n -= 1.1f);
    print(n /= 4); // Q: Based on the results of these expressions, is there a better type to be used for n?

    std::cout << "\nLogic expressions:\n";
    const bool alwaysTrue = true;
    bool condition1 = false;
    bool condition2 = true;
    print(alwaysTrue && condition1 && condition2);
    print(alwaysTrue || condition1 && condition2);
    print(alwaysTrue && condition1 || condition2);
    print(condition1 != condition1);
    print(condition2 = !condition2);
    print(alwaysTrue && condition1 && condition2);
    print(alwaysTrue || condition1 && condition2);
    print(alwaysTrue && condition1 || condition2);

    std::cout << '\n';
    print(false || 0b10);
    print(false | 0b10);
    printBinary(0b1 & 0b10);
    printBinary(0b1 | 0b10);
    printBinary(0b1 && 0b10);
    printBinary(0b1 || 0b10);

    std::cout << "\nPlay with characters and strings:\n";
    print("a");
    print('a');

    char charArray[20];
    std::fill(std::begin(charArray), std::end(charArray), '\0');
    char* charPtr = charArray;
    charArray[19] = 0;

    print(charArray);
    print(charArray[0] = 'a');
    print(charArray);
    print(charArray[1] = 98);
    print(charArray);
    print(charPtr);
}
