#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr)
{
    int len = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    long min_sum = 0;
    long max_sum = 0;
    vector<bool> min_bool(5, false);
    vector<bool> max_bool(5, false);

    bool all_equal = true;
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] != arr[i + 1])
            all_equal = false;
    }

    if (all_equal)
        cout << arr[0] * 4 << " " << arr[0] * 4;

    else
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i] != max && !min_bool[i])
            {
                min_sum += arr[i];
                min_bool[i] = true;
            }
            if (arr[i] != min && !max_bool[i])
            {
                max_sum += arr[i];
                max_bool[i] = true;
            }
        }

        cout << min_sum << " " << max_sum;
    }
}

int main()
{

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

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
