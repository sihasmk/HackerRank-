#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getTotalX(vector<int> a, vector<int> b)
{
    int min_in_b = *min_element(b.begin(), b.end());
    int max_in_a = *max_element(a.begin(), a.end());

    vector<int> common_multiples = {};

    for (int i = max_in_a; i <= min_in_b; i += max_in_a)
    {
        for (int el_a : a)
        {
            if (i % el_a == 0 and find(common_multiples.begin(), common_multiples.end(), i) == common_multiples.end())
                common_multiples.push_back(i);
        }
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < common_multiples.size(); j++)
        {
            if (common_multiples[j] % a[i] != 0)
            {
                common_multiples[j] = 1;
            }
        }
    }

    for (size_t j = 0; j < common_multiples.size(); j++)
    {
        for (size_t k = 0; k < b.size(); k++)
        {
            if (b[k] % common_multiples[j] != 0)
            {
                common_multiples[j] = 1;
            }
        }
    }

    int count = (find(a.begin(), a.end(), 1) == a.end()) ? 0 : 1;

    for (int multiple : common_multiples)
        if (multiple != 1)
            count++;

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++)
    {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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
