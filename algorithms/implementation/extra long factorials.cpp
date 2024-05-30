#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

int multiply(int size, int array[], int num)
{
    int carry = 0;

    for (int i = 0; i < size; i++)
    {
        int product = (array[i] * num) + carry;
        array[i] = product % 10;
        carry = product / 10;
    }

    while (carry)
    {
        array[size] = carry % 10;
        carry /= 10;
        size++;
    }

    return size;
}

void extraLongFactorials(int n)
{
    int value[1000], size = 1;
    value[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        size = multiply(size, value, i);
    }

    for (int j = size - 1; j >= 0; j--)
    {
        cout << value[j];
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
