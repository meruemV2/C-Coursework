#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef map<string, int> StrNumMap;
typedef map<string, int> StrCharMap;
typedef map<string, int> StrWordMap;
vector<pair<string, int>> valueVec;

void countWords(istream& in, StrNumMap& nums, StrCharMap& chars, StrWordMap& words) {

    char cur ;
    string num;
    string word;
    string lnum = "";
    string lword = "";

    while (in.get(cur)) {

        string ichar;
        ichar = cur;
         if (cur == '\n')
        {
            ichar = "\n";
            ++chars[ichar];
        }
        else if (cur == '\t')
        {
            ichar = "\t";
            ++chars[ichar];
        }
        else
        ++chars[ichar];


        if (isdigit(cur))
        {
            num = cur;
            char n = in.peek();
            if (isdigit(n))
            {
                lnum = lnum + num;
            }
            else
            {

                if (lnum == "")
                {
                    ++nums[num];

                }
                else
                {
                    lnum = lnum + num;
                    ++nums[lnum];
                    lnum = "";
                }
            }

        }
        else if (isalpha(cur))
        {
            word = cur;
            char n = in.peek();
            if (isalpha(n))
            {
                lword = lword + word;
            }
            else
            {
                if (lword == "")
                {
                    ++words[word];
                }
                else
                {
                    lword = lword + word;
                    ++words[lword];
                    lword = "";
                }

            }
        }
    }
}
bool sortValues(const pair<string, int> &a,
                const pair<string, int> &b)
{
    return (a.second > b.second);
}

int main() {


string input;
while (getline(cin, input)){

    StrNumMap n;
    StrCharMap c;
    StrWordMap w;
    countWords(cin, n, c, w);

    cout << "Top 10 Numbers: " << endl;

    for (StrNumMap::iterator p = n.begin();p != n.end(); ++p) {
        valueVec.push_back(make_pair(p->first, p->second));
    }
    sort(valueVec.begin(), valueVec.end(), sortValues);
    for (int i = 0; i < 10; i++)
    {
        cout << valueVec[i].first << ": " << valueVec[i].second << endl;
    }

    valueVec.clear();


    cout << "Top 10 Characters: " <<endl;

    for (StrCharMap::iterator p = c.begin();p != c.end(); ++p) {
        valueVec.push_back(make_pair(p->first, p->second));

    }
    sort(valueVec.begin(), valueVec.end(), sortValues);
    for (int i = 0; i < 10; i++)
    {
        cout << valueVec[i].first << ": " << valueVec[i].second << endl;
    }

    valueVec.clear();

    cout << "Top 10 words: " <<endl;
    for (StrWordMap::iterator p = w.begin();p != w.end(); ++p) {
        valueVec.push_back(make_pair(p->first, p->second));
    }

    sort(valueVec.begin(), valueVec.end(), sortValues);
    for (int i = 0; i < 10; i++)
    {
        cout << valueVec[i].first << ": " << valueVec[i].second << endl;
    }

}


}
