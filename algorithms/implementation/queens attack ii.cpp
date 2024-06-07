#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

bool inQueenDiagonal(vector<int> obstacle, int r_q, int c_q)
{
    if (abs(obstacle[0] - r_q) == abs(obstacle[1] - c_q))
        return true;

    return false;
}

int getDifference(vector<int> obstacle, int r_q, int c_q)
{
    return abs(obstacle[0] - r_q);
}

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    vector<int> min_top_right_diag = {INT_MAX, INT_MAX};
    vector<int> min_top_left_diag = {INT_MAX, INT_MAX};
    vector<int> min_bottom_right_diag = {INT_MAX, INT_MAX};
    vector<int> min_bottom_left_diag = {INT_MAX, INT_MAX};
    vector<int> min_bottom = {INT_MAX, INT_MAX};
    vector<int> min_top = {INT_MAX, INT_MAX};
    vector<int> min_left = {INT_MAX, INT_MAX};
    vector<int> min_right = {INT_MAX, INT_MAX};

    for (int i = 0; i < obstacles.size(); i++)
    {
        assert(i > -1 && i < (int)obstacles.size());
        vector<int> obstacle = obstacles[i];
        if (inQueenDiagonal(obstacle, r_q, c_q))
        {
            if (obstacle[0] > r_q and obstacle[1] > c_q) // Top right
            {
                if (getDifference(obstacle, r_q, c_q) < getDifference(min_top_right_diag, r_q, c_q))
                {
                    min_top_right_diag = obstacle;
                }
            }
            else if (obstacle[0] > r_q and obstacle[1] < c_q) // Top left
            {
                if (getDifference(obstacle, r_q, c_q) < getDifference(min_top_left_diag, r_q, c_q))
                {
                    min_top_left_diag = obstacle;
                }
            }
            else if (obstacle[0] < r_q and obstacle[1] > c_q) // Bottom right
            {
                if (getDifference(obstacle, r_q, c_q) < getDifference(min_bottom_right_diag, r_q, c_q))
                {
                    min_bottom_right_diag = obstacle;
                }
            }
            else if (obstacle[0] < r_q and obstacle[1] < c_q) // Bottom left
            {
                if (getDifference(obstacle, r_q, c_q) < getDifference(min_bottom_left_diag, r_q, c_q))
                {
                    min_bottom_left_diag = obstacle;
                }
            }
        }
        else if (obstacle[0] == r_q)
        {
            if (obstacle[1] > c_q)
            {
                if (abs(obstacle[1] - c_q) < abs(min_right[1] - c_q))
                    min_right = obstacle;
            }
            else
            {
                if (abs(c_q - obstacle[1]) < abs(c_q - min_left[1]))
                    min_left = obstacle;
            }
        }
        else if (obstacle[1] == c_q)
        {
            if (obstacle[0] > r_q)
            {
                if (abs(obstacle[0] - r_q) < abs(min_top[0] - r_q))
                    min_top = obstacle;
            }
            else
            {
                if (abs(r_q - obstacle[0]) < abs(r_q - min_bottom[0]))
                    min_bottom = obstacle;
            }
        }
    }

    int top_right_diag;
    int top_left_diag;
    int bottom_right_diag;
    int bottom_left_diag;
    int left;
    int right;
    int top;
    int bottom;

    top_right_diag = (min_top_right_diag[0] != INT_MAX) ? abs(min_top_right_diag[0] - r_q) - 1 : min(n - r_q, n - c_q);
    top_left_diag = (min_top_left_diag[0] != INT_MAX) ? abs(min_top_left_diag[0] - r_q) - 1 : min(n - r_q, c_q - 1);
    bottom_right_diag = (min_bottom_right_diag[0] != INT_MAX) ? abs(min_bottom_right_diag[0] - r_q) - 1 : min(n - c_q, r_q - 1);
    bottom_left_diag = (min_bottom_left_diag[0] != INT_MAX) ? abs(min_bottom_left_diag[0] - r_q) - 1 : min(r_q - 1, c_q - 1);
    left = (min_left[0] != INT_MAX) ? abs(c_q - min_left[1]) - 1 : c_q - 1;
    right = (min_right[0] != INT_MAX) ? abs(min_right[1] - c_q) - 1 : n - c_q;
    top = (min_top[0] != INT_MAX) ? abs(min_top[0] - r_q) - 1 : n - r_q;
    bottom = (min_bottom[0] != INT_MAX) ? abs(r_q - min_bottom[0]) - 1 : r_q - 1;

    int result = top_right_diag + top_left_diag + bottom_left_diag + bottom_right_diag + left + right + top + bottom;

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++)
    {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
