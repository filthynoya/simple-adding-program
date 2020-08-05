#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string sum_of (std::string str1, std::string str2);

int main (void)
{
    std::string str1, str2, res;

    std::cout << "Enter First number: ";

    std::cin >> str1;

    std::cout << "Enter Second number: ";

    std::cin >> str2;

    res = sum_of (str1, str2);

    std::cout << "Result: " << res << std::endl;

    return 0;
}

std::string sum_of (std::string str1, std::string str2)
{
    int str1_size, str2_size, carry, sum;
    std::string res = "";

    if (str1.length () > str2.length ())
    {
        std::swap (str1, str2);
    }

    str1_size = str1.length ();
    str2_size = str2.length ();

    std::reverse (str1.begin (), str1.end ());
    std::reverse (str2.begin (), str2.end ());

    carry = 0;

    for (int i = 0; i < str1_size; i++)
    {
        sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        res.push_back ((sum % 10) + '0');

        carry = sum / 10;
    }

    for (int i = str2_size; i < str2_size; i++)
    {
        sum = ((str2[i] - '0') + carry);
        res.push_back ((sum % 10) + '0');

        carry = sum / 10;
    }

    if (carry)
    {
        res.push_back (carry + '0');
    }

    std::reverse (res.begin (), res.end ());

    return res;
}