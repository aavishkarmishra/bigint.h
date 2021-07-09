#include <iostream>
//initialisation of library
#include "bigint.hpp"
using namespace std;

int main()
{
    /********declaration of variables*********/
    bigint n1;                                  //n1 defined with value 0
    bigint n2(123);                             //n2 defined with value int value
    bigint n3((long long int)1234567898765432); //n3 defined with value long long int value
    bigint n4("7832467326423873423435");        //n4 defined with string value
    bigint n5(n3);                              //n5 defined with values of n3

    /********Converting to Bigint*********/
    int num1 = -321;
    long long int num2 = -9876543219876543;
    string str1 = "-2112321321321312421534365777";
    bigint n6 = bigint::to_bigint(num1); //converting int to bigint
    bigint n7 = bigint::to_bigint(num2); //converting long long int to bigint
    bigint n8 = bigint::to_bigint(str1); //converting string to bigint

    /********user Input*********/
    bigint n9;
    cout << "Enter the value for n9: ";
    cin >> n9; //Taking input from user

    cout << "n1: " << n1 << endl; //Printing Values
    cout << "n2: " << n2 << endl; //Printing Values
    cout << "n3: " << n3 << endl; //Printing Values
    cout << "n4: " << n4 << endl; //Printing Values
    cout << "n5: " << n5 << endl; //Printing Values
    cout << "n6: " << n6 << endl; //Printing Values
    cout << "n7: " << n7 << endl; //Printing Values
    cout << "n8: " << n8 << endl; //Printing Values

    /********Arithmatic Operations*********/
    cout << "Addition: " << n1 + n2 << endl;       //Addition
    cout << "Subtraction: " << n2 - n1 << endl;    //subtraction
    cout << "Multiplication: " << n1 * n2 << endl; //Multiplication
    cout << "Division: " << n4 / n2 << endl;       //Division

    cout << "n2 + 5: " << n2 + 5 << endl;
    cout << "n2 - 5: " << n2 - 5 << endl;
    cout << "n2 * 5: " << n2 * 5 << endl;
    cout << "n2 / 5: " << n2 / 5 << endl;

    cout << "5 + n2: " << 5 + n2 << endl;
    cout << "5 - n2: " << 5 - n2 << endl;
    cout << "5 * n2: " << 5 * n2 << endl;
    cout << "5 / n2: " << 5 / n2 << endl;

    //unary operations
    cout << "PreIncrement: " << ++n2 << endl;
    cout << "PreDecrement: " << --n2 << endl;
    cout << "PostIncrement: " << n2++ << endl;
    cout << "PostDecrement: " << n2-- << endl;

    //equality check
    cout << "Check n3 != n5: " << (bool)(n3 != n5) << endl; //Checking if value of both are different
    cout << "Check n3 == n5: " << (bool)(n3 == n5) << endl; //Checking if value of both are same

    n3 += n2;
    cout << "n3 += n2: " << n3 << endl;

    n3 -= n2;
    cout << "n3 -= n2: " << n3 << endl;

    n3 *= n2;
    cout << "n3 *= n2: " << n3 << endl;

    n3 /= n2;
    cout << "n3 /= n2: " << n3 << endl;

    /********Functions*********/

    cout << "Maximum: " << bigint::max(n1, n2) << endl;                           //Maximum of two Numbers
    cout << "Minimum: " << bigint::min(n1, n2) << endl;                           //Minimum of two Numbers
    cout << "absolute: " << bigint::abs(n1) << " " << bigint::abs(n2) << endl;    //Absolute value of a number
    cout << "Factorial: " << bigint::fact(n1) << " " << bigint::fact(n2) << endl; //Factorial of a number
    cout << "Reverse: " << bigint::reverse(n3) << endl;                           //Reverse a number
    cout << "isPalindrome: " << (bool)bigint::isPalindrome(n9) << endl;           //Checking if a number is palindrome
    cout << "Power: " << bigint::pow(n3, n2) << endl;                             //finds x to the power y.

    return 0;
}