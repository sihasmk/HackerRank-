#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'howManyGames' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER d
 *  3. INTEGER m
 *  4. INTEGER s
 */

int firstArithmeticSeriesValueLessThanNAffordablebyS(int start, int difference, int N, int s)
{
    int n = 1;
    int carrying_sum = start;
    while (start + difference > N)
    {
        start += difference;
        carrying_sum += start;

        if (s >= carrying_sum)
            n++;
        else
            break;
    }

    return n;
}

int getArithmeticSum(int a0, int n, int d)
{
    int right_left = 2.0 * a0;
    int right_right = (n - 1.0) * d;
    int right = right_left + right_right;

    int doubletotal = n * right;

    int total = doubletotal / 2;

    return total;
}

int getNthValueOfArithmeticSequence(int a, int n, int d)
{
    return a + ((n - 1) * d);
}

int howManyGames(int p, int d, int m, int s)
{
    int games_bought = 0;
    int current_price = p;

    while (current_price >= m)
    {
        if (s - current_price < 0)
            return games_bought;

        else
            s -= current_price;
        games_bought++;

        if (current_price - d <= m)
            current_price = m;
        else
            current_price -= d;
    }

    return games_bought;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int p = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    int m = stoi(first_multiple_input[2]);

    int s = stoi(first_multiple_input[3]);

    int answer = howManyGames(p, d, m, s);

    fout << answer << "\n";

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
