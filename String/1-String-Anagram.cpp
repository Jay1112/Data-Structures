// Check Two strings are anagram of each other or not.
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

bool Anagram(string s1,string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    if(l1 != l2)
    {
        return false;
    }

    int count[256] = {0};

    for(int i=0;i<l1;i++)
    {
        count[s1[i]]++;
    }

    for(int i=0;i<l2;i++)
    {
        if(count[s2[i]]==0)
        {
            return false;
        }
        else
        {
            count[s2[i]]--;
        }
    }

    return true;
}

int main()
{
    string s1 = "aabcd";
    string s2 = "abbcd";

    bool check = Anagram(s1,s2);

    cout << check << endl;

    return 0;
}