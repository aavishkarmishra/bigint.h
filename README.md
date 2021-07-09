# Usage

Download the "bigint.h" header .Then #include it inside your code:

Command to compile cpp files `g++ bigint.hpp bigint.cpp SampleCode.cpp `

```c++
#include "bigint.h"   // the actual path may vary

```

# Declaring A Variable

```c++
    bigint n1;                                  //n1 defined with value 0
    bigint n2(123);                             //n2 defined with value int value
    bigint n3((long long int)1234567898765432); //n3 defined with value long long int value
    bigint n4("7832467326423873423435");        //n4 defined with string value
    bigint n5(n3);                              //n5 defined with values of n3
```

# Converting to Numbers

```c++
    bigint n6 = bigint::to_bigint(num1); //converting int to bigint
    bigint n7 = bigint::to_bigint(num2); //converting long long int to bigint
    bigint n8 = bigint::to_bigint(str1); //converting string to bigint

```

# Arithmatic Operations

```c++
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
```

# Other Operations

### unary operations

```c++
    cout<<"PreIncrement: "<<++n2<<endl;
    cout<<"PreDecrement: "<<--n2<<endl;
    cout<<"PostIncrement: "<<n2++<<endl;
    cout<<"PostDecrement: "<<n2--<<endl;
```

### equality check

```c++
    cout<<"Check n3 != n5: "<<(bool)(n3 != n5)<<endl;            //Checking if value of both are different
    cout<<"Check n3 == n5: "<<(bool)(n3 == n5)<<endl;            //Checking if value of both are same
```

### few other operators

```c++
    n3 += n2;
    cout<<"n3 += n2: "<<n3<<endl;

    n3 -= n2;
    cout<<"n3 -= n2: "<<n3<<endl;

    n3 *= n2;
    cout<<"n3 *= n2: "<<n3<<endl;

    n3 /= n2;
    cout<<"n3 /= n2: "<<n3<<endl;
```

# Functions

```c++
    cout << "Maximum: " << bigint::max(n1, n2) << endl;                           //Maximum of two Numbers
    cout << "Minimum: " << bigint::min(n1, n2) << endl;                           //Minimum of two Numbers
    cout << "absolute: " << bigint::abs(n1) << " " << bigint::abs(n2) << endl;    //Absolute value of a number
    cout << "Factorial: " << bigint::fact(n1) << " " << bigint::fact(n2) << endl; //Factorial of a number
    cout << "Reverse: " << bigint::reverse(n3) << endl;                           //Reverse a number
    cout << "isPalindrome: " << (bool)bigint::isPalindrome(n9) << endl;           //Checking if a number is palindrome
    cout << "Power: " << bigint::pow(n3, n2) << endl;                          //finds int(X) to the power int(Y)
```
