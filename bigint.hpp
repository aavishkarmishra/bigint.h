#ifndef bigint_H_INCLUDED
#define bigint_H_INCLUDED
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class bigint
{
private:
    string str;

protected:
    static string removeZero(string str);
    static string add(string str1, string str2);
    static string subtract(string str1, string str2);
    static string multiply(string str1, string str2);
    static string division(string str, long long int num);
    static string division(string str, int num);
    static string power(string str1, string str2);
    static string maxCompare(string str1, string str2);
    static string minCompare(string str1, string str2);
    static string factorial(int num);

public:
    /*---------------- Constructors ------------------*/
    bigint();
    bigint(string str);
    bigint(int num);
    bigint(long long int num);
    bigint(const bigint &N);

    /* ------------- Operator Overloading ------------*/
    friend ostream &operator<<(ostream &output, const bigint &N);
    friend istream &operator>>(istream &input, bigint &N);

    bigint operator++();
    bigint operator--();
    bigint operator++(int);
    bigint operator--(int);

    bigint operator+(bigint const &N);
    bigint operator-(bigint const &N);
    bigint operator*(bigint const &N);
    bigint operator/(bigint const &N);

    friend bigint operator+(bigint &N, int num);
    friend bigint operator-(bigint &N, int num);
    friend bigint operator*(bigint &N, int num);
    friend bigint operator/(bigint &N, int num);

    friend bigint operator+(int num, bigint &N);
    friend bigint operator-(int num, bigint &N);
    friend bigint operator*(int num, bigint &N);
    friend bigint operator/(int num, bigint &N);

    bool operator==(bigint const &N);
    bool operator!=(bigint const &N);

    bigint &operator+=(bigint N);
    bigint &operator-=(bigint N);
    bigint &operator*=(bigint N);
    bigint &operator/=(bigint N);

    /* ------------------ Member funtions -----------------*/
    static bigint to_bigint(string str);
    static bigint to_bigint(int num);
    static bigint to_bigint(long long int num);
    static bigint pow(string str1, string str2);
    static bigint pow(bigint &N, string str);
    static bigint pow(string str, bigint &N);
    static bigint pow(bigint &N1, bigint &N2);
    static bigint pow(int num1, int num2);
    static bigint pow(long int num1, long int num2);
    static bigint pow(long long int num1, long long int num2);
    static bigint fact(int num);
    static bigint fact(bigint N);
    static bigint fact(string str);
    static bigint max(bigint N1, bigint N2);
    static bigint min(bigint N1, bigint N2);
    static bigint abs(bigint N);
    static bigint reverse(bigint N);
    static int countDigits(bigint N, int num);
    static bool isPalindrome(bigint N);
};

#endif // bigint_H_INCLUDED
