#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int total(vector<vector<int>> s, vector<vector<int>> arr)
{
    vector<int> total;

    for (int row = 0; row < 3; row++)
    {
        vector<int> row_total;
        for (int col = 0; col < 3; col++)
        {
            row_total.push_back(abs(s[row][col] - arr[row][col]));
        }
        total.push_back(accumulate(row_total.begin(), row_total.end(), 0));
    }

    return accumulate(total.begin(), total.end(), 0);
}

vector<vector<int>> reflect(vector<vector<int>> mat)
{
    vector<vector<int>> reflectedMatrix(3, vector<int>(3));

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            reflectedMatrix[i][j] = mat[i][2 - j];
        }
    }

    return reflectedMatrix;
}

vector<vector<int>> rotate(vector<vector<int>> mat)
{
    vector<vector<int>> rotatedMatrix(3, vector<int>(3));

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            rotatedMatrix[j][2 - i] = mat[i][j];
        }
    }

    return rotatedMatrix;
}

int formingMagicSquare(vector<vector<int>> s)
{
    vector<vector<int>> ms = {
        {8, 3, 4},
        {1, 5, 9},
        {6, 7, 2}};

    vector<int> totals;
    for (int i = 0; i < 4; i++)
    {
        totals.push_back(total(s, ms));
        totals.push_back(total(s, reflect(ms)));

        ms = rotate(ms);
    }

    return *min_element(totals.begin(), totals.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++)
    {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++)
        {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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
