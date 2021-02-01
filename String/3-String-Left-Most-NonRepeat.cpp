// Find the Left most non-repeated character in the given string.
#include<iostream>
#include<cstdlib>
#include<climits>

using namespace std;

int NonLeftMostRepeat(string s)
{
    int length = s.length();
    int res = INT_MAX;

    int count[256] = {0};

    for(int i=0;i<length;i++)
    {
        count[s[i]]++;
    }

    for(int i=0;i<length;i++)
    {
        if(count[s[i]]==1)
        {
            return i;
        }
    }

    if(res == INT_MAX)
    {
        res = -1;
    }

    return res;
}

int main()
{
    string s = "aabbcc";

    int index = NonLeftMostRepeat(s);

    cout << index << endl;
    
    return 0;
}