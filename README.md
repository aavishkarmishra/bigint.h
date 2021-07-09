<p align="center">
  <a href="https://github.com/aavishkarmishra/bigint.h">
    <img src="https://image.flaticon.com/icons/png/512/1159/1159283.png" alt="Logo" width="150">
  </a>

  <h2 align="center"><strong>bigint.h</strong></h2>
  <p align="center">
    <a href="https://github.com/aavishkarmishra/bigint.h/wiki"><strong>Enhanced big integer library for C++</strong></a>
    <br />
    <br />
    <a href="https://github.com/aavishkarmishra/bigint.h/issues">Report Bug</a>
    ·
    <a href="https://github.com/aavishkarmishra/bigint.h/issues">Request Feature</a>
  </p>
</p>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

### Enhanced big integer library for C++

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

## Author 👨‍💻

### [Aavishkar Mishra](https://github.com/aavishkarmishra)

[<img src="https://image.flaticon.com/icons/svg/185/185964.svg" width="35" padding="10">](https://www.linkedin.com/in/aavishkarmishra/)
[<img src="https://www.flaticon.com/svg/static/icons/svg/1312/1312142.svg" width="35" padding="10">](https://www.twitter.com/aavishkarmishra)
[<img src="https://image.flaticon.com/icons/svg/185/185985.svg" width="35" padding="10">](https://www.instagram.com/aavishkar_mishra/)

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/aavishkarmishra/bigint.h.svg?style=flat-square
[contributors-url]: https://github.com/aavishkarmishra/bigint.h/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/aavishkarmishra/bigint.h.svg?style=flat-square
[forks-url]: https://github.com/aavishkarmishra/bigint.h/network/members
[stars-shield]: https://img.shields.io/github/stars/aavishkarmishra/bigint.h.svg?style=flat-square
[stars-url]: https://github.com/aavishkarmishra/bigint.h/stargazers
[issues-shield]: https://img.shields.io/github/issues/aavishkarmishra/bigint.h.svg?style=flat-square
[issues-url]: https://github.com/aavishkarmishra/bigint.h/issues
[license-shield]: https://img.shields.io/github/license/aavishkarmishra/bigint.h.svg?style=flat-square
[license-url]: https://github.com/aavishkarmishra/bigint.h/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/aavishkarmishra
