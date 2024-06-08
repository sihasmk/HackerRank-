#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'acmTeam' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */

string getOrString(string str1, string str2)
{
    int m = (int)str1.size();
    string result = "";

    for (int i = 0; i < m; i++)
    {
        string add_bit;
        if (str1[i] == '1' or str2[i] == '1')
            add_bit = "1";
        else
            add_bit = "0";

        result += add_bit;
    }

    return result;
}

int getOnesCount(string binary_string)
{
    int count = 0;
    for (char c : binary_string)
    {
        if (c == '1')
            count++;
    }

    return count;
}

vector<int> acmTeam(vector<string> topic)
{
    int count = 0;
    int max = -1;

    for (int i = 0; i < (int)topic.size() - 1; i++)
    {
        for (int j = i + 1; j < (int)topic.size(); j++)
        {
            string or_string = getOrString(topic[i], topic[j]);
            int no_of_ones = getOnesCount(or_string);
            if (no_of_ones == max)
                count++;

            else if (no_of_ones > max)
            {
                max = no_of_ones;
                count = 1;
            }
        }
    }

    return vector<int>{max, count};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++)
    {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

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
