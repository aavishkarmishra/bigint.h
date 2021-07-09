#include "./bigint.hpp"

/* ---------------------------- Utils ------------------------------*/
string removeZero(string str);
string add(string str1, string str2);
string subtract(string str1, string str2);
string multiply(string str1, string str2);
string power(string str1, string str2);
string maxCompare(string str1, string str2);
string minCompare(string str1, string str2);
string factorial(int num);
bool isInputCorrect(string s)
{
    if (s[0] == '-')
        s.erase(0, 1);
    for (int i = 0; i < s.size(); ++i)
    {
        if ((int)s[i] < 48 || (int)s[i] > 57)
            return false;
    }
    return true;
}
string removeZero(string str)
{
    int i = 0, flag = 0;
    if (str[0] == '-')
    {
        flag = 1;
        i++;
    }
    while (str[i] == '0')
        i++;
    if (flag)
        str.erase(1, i);
    else
        str.erase(0, i);
    return str;
}
string subtract(string s1, string s2)
{
    string answer = "", ans, temp;
    int carry = 0, i, j, k, y = 0, flag = 0, flag1 = 0;
    int sum = 0;
    if (s1 == s2)
    {
        return "0";
    }
    else if (s1[0] == '-' and s2[0] == '-')
    {
        flag1 = 1;
        s1 = s1.substr(1);
        s2 = s2.substr(1);
    }
    else if (s1[0] == '-' and s2[0] != '-')
    {
        s1 = s1.substr(1);
        answer = add(s1, s2);
        answer = '-' + answer;
        return answer;
    }
    else if (s1[0] != '-' and s2[0] == '-')
    {
        s2 = s2.substr(1);
        answer = add(s1, s2);
        return answer;
    }
    ans = maxCompare(s1, s2);
    if (ans == s2)
    {
        temp = s1;
        s1 = s2;
        s2 = temp;
        flag = 1;
    }
    int m = s1.size();
    int n = s2.size();
    if (m > n)
        k = m;
    else
        k = n;
    int A[k + 1] = {0};
    for (i = m - 1, j = n - 1; i >= 0 || j >= 0; i--, j--)
    {
        sum = 0;
        if (i >= 0)
        {
            sum += s1[i] - '0';
        }
        if (j >= 0)
        {
            if (sum < s2[j] - '0' + carry)
            {
                sum += 10;
                sum -= s2[j] - '0' + carry;
                carry = 1;
            }
            else
            {
                sum -= s2[j] - '0' + carry;
                carry = 0;
            }
        }
        if (carry != 0 and j < 0)
        {
            if (sum < carry)
            {
                sum += 10;
                sum -= carry;
                carry = 1;
            }
            else
            {
                sum -= carry;
                carry = 0;
            }
        }
        A[y++] = sum;
        //carry=sum/10;
    }
    for (i = k - 1; i >= 0; i--)
    {
        answer += (char)(A[i] + 48);
    }
    answer = removeZero(answer);
    if (flag1 == 1 and flag == 0)
    {
        answer = '-' + answer;
    }
    else if (flag1 == 0 and flag == 1)
    {
        answer = '-' + answer;
    }
    return answer;
}
string add(string s, string s1)
{
    int carry = 0, i, j;
    int sum = 0;
    int m = s.size();
    int n = s1.size();
    string y = "";
    if (m == 0 && n == 0)
    {
        y = "0";
    }
    else if (s[0] == '-' && s1[0] == '-')
    {
        y = add(s.erase(0, 1), s1.erase(0, 1));
        y = '-' + y;
    }
    else if (s[0] == '-')
    {
        y = subtract(s1, s.erase(0, 1));
    }
    else if (s1[0] == '-')
    {
        y = subtract(s, s1.erase(0, 1));
    }
    else
    {
        vector<int> v;
        for (i = m - 1, j = n - 1; i >= 0 || j >= 0; i--, j--)
        {
            sum = carry;
            if (i >= 0)
            {
                sum += s[i] - '0';
            }
            if (j >= 0)
            {
                sum += s1[j] - '0';
            }
            v.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry != 0)
            v.push_back(carry);

        for (i = v.size() - 1; i >= 0; i--)
            y += (char)(v[i] + 48);
    }
    return y;
}
string multiply(string s, string s1)
{
    int flag = 0;
    int m = s.size();
    int n = s1.size();
    int A[m + n] = {0};
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int mul = (s[i] - '0') * (s1[j] - '0');
            int sum = A[i + j + 1] + mul;
            A[i + j] += sum / 10;
            A[i + j + 1] = sum % 10;
        }
    }

    string finalanswer = "";
    for (int i = 0; i < m + n; i++)
    {
        if (A[i] == 0 && flag == 0)
        {
        }
        else if (A[i] != 0)
            flag = 1;

        if (flag == 1)
            finalanswer += (char)(A[i] + 48);
    }
    if (finalanswer.size() == 0)
        finalanswer = "0";
    return finalanswer;
}
string division(string str, long long int num)
{
    string result;
    int index = 0;
    long long int temp = str[index] - '0';
    while (temp < num)
    {
        temp = temp * 10 + (str[++index] - '0');

        if (index >= str.size())
            break;
    }

    while (str.size() > index)
    {
        result += (temp / num) + '0';
        temp = (temp % num) * 10 + str[++index] - '0';
    }

    if (result.size() == 0)
        return "0";

    return result;
}
string division(string s1, int div)
{
    string result;
    int index = 0;
    int temp = s1[index] - '0';
    while (temp < div)
    {
        temp = temp * 10 + (s1[++index] - '0');

        if (index >= s1.size())
            break;
    }

    while (s1.size() > index)
    {
        result += (temp / div) + '0';
        temp = (temp % div) * 10 + s1[++index] - '0';
    }

    if (result.size() == 0)
        return "0";

    return result;
}
string power(string str1, string str2)
{
    if (str2 == "0")
    {
        return "1";
    }
    else if (str1 == "0")
    {
        if (str2[0] == '-')
            return to_string((long long int)std::pow(0, -5));
        return "0";
    }
    else if (str1[0] == '-' && str2[0] == '-')
    {
        if (str1 == "-1" && str2 == "-1")
        {
            return "-1";
        }
        else if (str1 == "-1")
        {
            if ((((int)str2[str2.size() - 1]) - 48) & 1)
            {
                return "-1";
            }
            else
            {
                return "1";
            }
        }
        else
        {
            return "0";
        }
    }
    else if (str1[0] == '-')
    {
        if ((((int)str2[str2.size() - 1]) - 48) & 1)
            return '-' + power(str1.erase(0, 1), str2);
        return power(str1.erase(0, 1), str2);
    }
    else if (str2[0] == '-')
    {
        if (str1 == "1")
        {
            return str1;
        }
        else
        {
            return "0";
        }
    }
    else
    {
        string init_str1 = str1;
        while (str2 != "1")
        {
            str1 = multiply(str1, init_str1);
            str2 = subtract(str2, "1");
        }
        return str1;
    }
}
string maxCompare(string s1, string s2)
{
    string answer = "";
    int i;
    if (s1[0] == '-' and s2[0] != '-')
    {
        return s2;
    }
    else if (s1[0] != '-' and s2[0] == '-')
    {
        return s1;
    }
    else if (s1[0] != '-' and s2[0] != '-' and s1.size() > s2.size())
    {
        return s1;
    }
    else if (s1[0] != '-' and s2[0] != '-' and s2.size() > s1.size())
    {
        return s2;
    }
    else if (s1[0] == '-' and s2[0] == '-' and s1.size() > s2.size())
    {
        return s2;
    }
    else if (s1[0] == '-' and s2[0] == '-' and s2.size() > s1.size())
    {
        return s1;
    }
    else if (s1[0] != '-' and s2[0] != '-' and s2.size() == s1.size())
    {
        for (i = 0; i < s1.size(); i++)
        {
            if (s1[i] - '0' < s2[i] - '0')
            {
                return s2;
            }
            else if (s1[i] == s2[i])
            {
                continue;
            }
            else if (s1[i] - '0' > s2[i] - '0')
            {
                return s1;
            }
        }
    }
    else if (s1[0] == '-' and s2[0] == '-' and s2.size() == s1.size())
    {
        for (i = 0; i < s1.size(); i++)
        {
            if (s1[i] - '0' < s2[i] - '0')
            {
                return s1;
            }
            else if (s1[i] == s2[i])
            {
                continue;
            }
            else if (s1[i] - '0' > s2[i] - '0')
            {
                return s2;
            }
        }
    }
    return s1;
}
string minCompare(string s1, string s2)
{
    string ans;
    ans = maxCompare(s1, s2);
    if (ans == s1)
    {
        return s2;
    }
    return s1;
}
string factorial(int n)
{
    int i = 2;
    int j = 0;
    int len = 1;
    int A[100000] = {0};
    A[0] = 1;
    int num = 0;
    while (i <= n)
    {
        j = 0;
        num = 0;
        while (j < len)
        {
            A[j] = A[j] * i;
            A[j] = A[j] + num;
            num = A[j] / 10;
            A[j] = A[j] % 10;
            j++;
        }
        while (num != 0)
        {
            A[len] = num % 10;
            num = num / 10;
            len++;
        }
        i++;
    }
    len--;
    string y = "";
    while (len >= 0)
    {
        y += (char)(A[len] + '0');
        len = len - 1;
    }
    return y;
}

/* ---------------------------- Contructors ------------------------------*/
bigint ::bigint()
{
    Bint = "0";
}
bigint ::bigint(string str)
{
    if (!isInputCorrect(str))
    {
        cerr << "Invalid Input.. Please Use Valid bigint" << endl;
        exit(0);
    }
    Bint = str;
}
bigint ::bigint(int num)
{
    ostringstream convertstr;
    convertstr << num;
    Bint = convertstr.str();
}
bigint ::bigint(long long int num)
{
    ostringstream convertstr;
    convertstr << num;
    Bint = convertstr.str();
}
bigint ::bigint(const bigint &N)
{
    if (!isInputCorrect(N.Bint))
    {
        cerr << "Invalid Input...." << endl;
        exit(0);
    }
    Bint = N.Bint;
}

/* ---------------------------- Operator Overloading------------------------------*/

bigint bigint ::operator++()
{
    string s = "1";
    Bint = add(this->Bint, s);
    return *this;
}
bigint bigint ::operator--()
{
    string s = "1";
    Bint = subtract(this->Bint, s);
    return *this;
}
bigint bigint ::operator++(int)
{
    bigint NewBint;
    NewBint.Bint = this->Bint;
    string s = "1";
    Bint = add(this->Bint, s);
    return NewBint;
}
bigint bigint ::operator--(int)
{
    bigint NewBint;
    NewBint.Bint = this->Bint;
    string s = "1";
    Bint = subtract(this->Bint, s);
    return NewBint;
}

bigint bigint ::operator+(bigint const &N)
{
    bigint NewBint;
    string s = Bint;
    string s1 = N.Bint;
    NewBint.Bint = add(s, s1);
    return NewBint;
}
bigint bigint ::operator-(bigint const &N)
{
    bigint NewBint;
    string str1 = Bint;
    string str2 = N.Bint;
    NewBint.Bint = subtract(str1, str2);
    return NewBint;
}
bigint bigint ::operator*(bigint const &N)
{
    bigint NewBint;
    string str1 = Bint;
    string str2 = N.Bint;
    NewBint.Bint = multiply(str1, str2);
    return NewBint;
}
bigint bigint ::operator/(bigint const &N)
{
    bigint NewBint;
    string str1 = Bint;
    string str2 = N.Bint;
    stringstream convertnum(str2);
    long long int div = 0;
    convertnum >> div;
    NewBint.Bint = division(str1, div);
    return NewBint;
}

bigint operator+(bigint &N, int num)
{
    bigint NewBint;
    ostringstream convertstr;
    convertstr << num;
    NewBint.Bint = convertstr.str();
    NewBint.Bint = add(N.Bint, NewBint.Bint);
    return NewBint;
}
bigint operator-(bigint &N, int num)
{
    bigint NewBint;
    ostringstream convertstr;
    convertstr << num;
    NewBint.Bint = convertstr.str();
    NewBint.Bint = subtract(N.Bint, NewBint.Bint);
    return NewBint;
}
bigint operator*(bigint &N, int num)
{
    bigint NewBint;
    ostringstream convertstr;
    convertstr << num;
    NewBint.Bint = convertstr.str();
    NewBint.Bint = multiply(N.Bint, NewBint.Bint);
    return NewBint;
}
bigint operator/(bigint &N, int num)
{
    bigint NewBint;
    NewBint.Bint = division(N.Bint, (long long int)num);
    return NewBint;
}

bigint operator+(int num, bigint &N)
{
    bigint NewBint;
    ostringstream convertstr;
    convertstr << num;
    NewBint.Bint = convertstr.str();
    NewBint.Bint = add(N.Bint, NewBint.Bint);
    return NewBint;
}
bigint operator-(int num, bigint &N)
{
    bigint NewBint;
    ostringstream convertstr;
    convertstr << num;
    NewBint.Bint = convertstr.str();
    NewBint.Bint = subtract(NewBint.Bint, N.Bint);
    return NewBint;
}
bigint operator*(int num, bigint &N)
{
    bigint NewBint;
    ostringstream convertstr;
    convertstr << num;
    NewBint.Bint = convertstr.str();
    NewBint.Bint = multiply(N.Bint, NewBint.Bint);
    return NewBint;
}
bigint operator/(int num, bigint &N)
{
    bigint NewBint;
    ostringstream convertstr;
    convertstr << num;
    NewBint.Bint = convertstr.str();
    string s2 = N.Bint;
    stringstream convertnum(s2);
    long long int div = 0;
    convertnum >> div;
    NewBint.Bint = division(NewBint.Bint, div);
    return NewBint;
}

bool bigint ::operator==(bigint const &N)
{
    return this->Bint == N.Bint;
}
bool bigint ::operator!=(bigint const &N)
{
    return this->Bint != N.Bint;
}

bigint &bigint ::operator+=(bigint N)
{
    this->Bint = add(this->Bint, N.Bint);
    return *this;
}
bigint &bigint ::operator-=(bigint N)
{
    this->Bint = subtract(this->Bint, N.Bint);
    return *this;
}
bigint &bigint ::operator*=(bigint N)
{
    this->Bint = multiply(this->Bint, N.Bint);
    return *this;
}
bigint &bigint ::operator/=(bigint N)
{
    string str = N.Bint;
    stringstream convertnum(str);
    long long int div = 0;
    convertnum >> div;
    this->Bint = division(this->Bint, div);
    return *this;
}

/*---------------------------- Member Funtions ------------------------*/

bigint bigint::to_bigint(string s)
{
    return bigint(s);
}
bigint bigint::to_bigint(int num)
{
    return bigint(num);
}
bigint bigint::to_bigint(long long int num)
{

    return bigint(num);
}

bigint bigint::pow(string str1, string str2)
{
    bigint temp;
    temp.Bint = power(str1, str2);
    return temp;
}
bigint bigint::pow(bigint &N, string str)
{
    bigint temp;
    temp.Bint = power(N.Bint, str);
    return temp;
}
bigint bigint::pow(string str, bigint &N)
{
    bigint temp;
    temp.Bint = power(str, N.Bint);
    return temp;
}
bigint bigint::pow(bigint &N1, bigint &N2)
{
    bigint temp;
    temp.Bint = power(N1.Bint, N2.Bint);
    return temp;
}
bigint bigint::pow(int num1, int num2)
{
    bigint temp;
    temp.Bint = power(to_string(num1), to_string(num2));
    return temp;
}
bigint bigint::pow(long int num1, long int num2)
{
    bigint temp;
    temp.Bint = power(to_string(num1), to_string(num2));
    return temp;
}
bigint bigint::pow(long long int num1, long long int num2)
{
    bigint temp;
    temp.Bint = power(to_string(num1), to_string(num2));
    return temp;
}

bigint bigint::fact(int num)
{
    bigint NewBint;
    NewBint.Bint = factorial(num);
    return NewBint;
}
bigint bigint::fact(bigint N)
{
    bigint NewBint;
    string s = N.Bint;
    stringstream convertnum(s);
    int n = 0;
    convertnum >> n;
    NewBint.Bint = factorial(n);
    return NewBint;
}
bigint bigint::fact(string str)
{
    bigint NewBint;
    stringstream convertnum(str);
    int n = 0;
    convertnum >> n;
    NewBint.Bint = factorial(n);
    return NewBint;
}

bigint bigint::max(bigint N1, bigint N2)
{
    string s1, s2, ans;
    s1 = N1.Bint;
    s2 = N2.Bint;

    ans = maxCompare(s1, s2);

    if (N1.Bint == ans)
        return N1;
    else
        return N2;
}
bigint bigint::min(bigint N1, bigint N2)
{
    string s1, s2, ans;
    s1 = N1.Bint;
    s2 = N2.Bint;

    ans = minCompare(s1, s2);

    if (N1.Bint == ans)
        return N1;
    else
        return N2;
}

bigint bigint::abs(bigint N)
{
    string s1 = N.Bint;

    if (s1[0] == '-')
        s1 = s1.substr(1);

    return bigint(s1);
}
bigint bigint::reverse(bigint N)
{
    string s2 = "", s1 = N.Bint;
    for (int i = s1.size() - 1; i >= 0; i--)
        s2 += s1[i];
    return bigint(s2);
}
int bigint::countDigits(bigint N, int nums)
{
    char ch = (char)(nums + '0');
    int counti = 0;
    for (int i = 0; i < N.Bint.size(); i++)
    {
        if (N.Bint[i] == ch)
            counti++;
    }
    return counti;
}
bool bigint::isPalindrome(bigint N)
{
    string str = N.Bint;
    int i = 0, j = str.size() - 1;
    if (str[0] == '-')
        i++;
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}