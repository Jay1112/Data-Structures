// Find the Permutation of a String in the Main String.
#include<iostream>
#include<cstdlib>

using namespace std;

bool compare(int count1[],int count2[])
{
    for(int i=0;i<256;i++)
    {
        if(count1[i] != count2[i])
        {
            return false;
        }
    }

    return true;
}

bool AnagramPermutation(string s,string t)
{
    int count1[256] = {0};
    int count2[256] = {0};

    for(int i=0;i<t.length();i++)
    {
        count1[s[i]]++;
        count2[t[i]]++;
    }

    if(compare(count1,count2))
    {
        return true;
    }

    for(int i=t.length();i<s.length()-t.length()+1;i++)
    {
        count1[s[i]]++;
        count1[s[i-t.length()]]--;

        if(compare(count1,count2))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string s = "geeksforgeeks"; 
    string t = "eeesk";

    bool check = AnagramPermutation(s,t);

    cout << check << endl;

    return 0;
}