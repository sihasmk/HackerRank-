#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    string input = s;
    istringstream iss(input);

    string tok;

    getline(iss, tok, ':');
    string hours = tok;
    bool is_AM = input.substr(8, 10) == "AM";

    if (is_AM)
    {
        if (hours == "12")
        {
            input[0] = '0';
            input[1] = '0';
        }
        cout << input.substr(0, 8);
        return input.substr(0, 8);
    }

    if (hours != "12")
    {
        int new_hours_int = stoi(hours) + 12;
        string new_hours_str = to_string(new_hours_int);
        input[0] = new_hours_str[0];
        input[1] = new_hours_str[1];
    }
    cout << input.substr(0, 8);
    return input.substr(0, 8);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
