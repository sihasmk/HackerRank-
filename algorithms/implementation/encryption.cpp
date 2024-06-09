#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s)
{
    string spaceless_s = "";

    for (char c : s)
    {
        if (c != ' ')
            spaceless_s += c;
    }

    int length = spaceless_s.size();
    int lower_bound = (int)floor(sqrt(length));
    int upper_bound = (int)ceil(sqrt(length));

    while (lower_bound * upper_bound < length)
    {
        if (lower_bound < upper_bound)
            lower_bound++;
        else
            upper_bound++;
    }

    string result = "";

    for (int k = 0; k < upper_bound; k++)
    {
        for (int i = k; i < length; i += upper_bound)
        {
            result += spaceless_s[i];
        }
        result += " ";
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
