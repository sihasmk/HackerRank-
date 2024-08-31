#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m)
{
    map<int, string> intToStringMap;

    intToStringMap[1] = "one";
    intToStringMap[2] = "two";
    intToStringMap[3] = "three";
    intToStringMap[4] = "four";
    intToStringMap[5] = "five";
    intToStringMap[6] = "six";
    intToStringMap[7] = "seven";
    intToStringMap[8] = "eight";
    intToStringMap[9] = "nine";
    intToStringMap[10] = "ten";
    intToStringMap[11] = "eleven";
    intToStringMap[12] = "twelve";
    intToStringMap[13] = "thirteen";
    intToStringMap[14] = "fourteen";
    intToStringMap[16] = "sixteen";
    intToStringMap[17] = "seventeen";
    intToStringMap[18] = "eighteen";
    intToStringMap[19] = "nineteen";
    intToStringMap[20] = "twenty";
    intToStringMap[21] = "twenty one";
    intToStringMap[22] = "twenty two";
    intToStringMap[23] = "twenty three";
    intToStringMap[24] = "twenty four";
    intToStringMap[25] = "twenty five";
    intToStringMap[26] = "twenty six";
    intToStringMap[27] = "twenty seven";
    intToStringMap[28] = "twenty eight";
    intToStringMap[29] = "twenty nine";

    if (m == 0)
    {
        return intToStringMap[h] + " o' clock";
    }

    if (m >= 1 and m <= 30)
    {
        if (m == 15)
        {
            return "quarter past " + intToStringMap[h];
        }
        if (m == 30)
        {
            return "half past " + intToStringMap[h];
        }
        if (m == 1)
        {
            return "one minute past " + intToStringMap[h];
        }
        return intToStringMap[m] + " minutes past " + intToStringMap[h];
    }

    int nextHour = h + 1;
    int minutesToNextHour = 60 - m;

    if (minutesToNextHour == 15)
    {
        return "quarter to " + intToStringMap[nextHour];
    }

    return intToStringMap[minutesToNextHour] + " minutes to " + intToStringMap[nextHour];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

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
