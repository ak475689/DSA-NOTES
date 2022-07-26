// The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm). Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values of all the substrings of txt[] match with hash value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string txt = "AABAACBAA", pat = "BAA";
    int hpat = 0, htxt = 0;
    int d = 26;
    int p = 5381; // for avoiding overflow
    for (int i = 0; i < pat.size(); i++)
    {
        hpat = hpat * d;
        hpat += ((pat[i] - 'A' + 1) % p); // rolling hash
    }
    int l = 0, r = 0;
    while (r < txt.size())
    {
        htxt = htxt * d;
        htxt = htxt + (txt[r] - 'A' + 1);
        if (r - l + 1 == pat.size())
        {
            if (htxt == hpat)
            {
                cout << "MATCH AT " << l;
            }
            htxt = htxt - (txt[l] - 'A' + 1) * pow(d, r - l); // sliding window
            l++;
        }
        r++;
    }
    return 0;
}