// Find the Left most repeated character in the given string.
#include<iostream>
#include<cstdlib>
#include<climits>
#include<algorithm>

using namespace std;

int LeftMostRepeat(string s)
{
    int length = s.length();
    int res = INT_MAX ;

    int count[256];

    for(int i=0;i<256;i++)
    {
        count[i] = -1;
    }

    for(int i=0;i<length;i++)
    {
        if(count[s[i]]==-1)
        {
            count[s[i]] = i;
        }
        else
        {
            res = min(res,count[s[i]]);
        }
    }

    if(res == INT_MAX)
    {
        return -1;
    }
    return -1;
}

int main()
{
    string s = "abcd";

    int index = LeftMostRepeat(s);

    cout << index << endl;
    
    return 0;
}