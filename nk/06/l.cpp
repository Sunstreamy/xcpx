#include <bits/stdc++.h>
using namespace std;

bool flag = false;
bool check(const string &s)
{
    unordered_map<char, int> tfreq = {
        {'C', 2}, {'H', 1}, {'I', 1}, {'K', 1}, {'E', 1}, {'N', 1}};
    unordered_map<char, int> freq;

    for (char c : s)
    {
        freq[c]++;
    }

    for (auto &p : tfreq)
    {
        if (freq[p.first] < p.second)
        {
            return false;
        }
    }

    int targetIndex = 0;
    string target = "CHICKEN";
    flag = false;

    for (char c : s)
    {
        if (c == target[targetIndex])
        {
            targetIndex++;
            if (targetIndex == target.length())
            {
                flag = true;
            }
        }
    }

    int extra_cnt = 0;
    unordered_map<char, int> extra_freq;
    for (auto &p : freq)
    {
        if (tfreq.find(p.first) != tfreq.end())
        {
            extra_freq[p.first] = max(0, p.second - tfreq[p.first]);
            extra_cnt += extra_freq[p.first];
        }
        else
        {
            extra_freq[p.first] = p.second;
            extra_cnt += p.second;
        }
    }

    if (extra_cnt % 2 != 0)
    {
        return false;
    }

    int mx = extra_cnt / 2;
    for (auto &p : extra_freq)
    {
        if (p.second > mx)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (check(s) && flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}