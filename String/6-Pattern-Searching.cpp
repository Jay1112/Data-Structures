// Pattern Searching 
#include<iostream>
#include<cstdlib>

using namespace std;

void PatternSearching(string s,string t)
{
    for(int i=0;i<s.length()-t.length()+1;i++)
    {
        int j = 0 ;

        for(;j<t.length();j++)
        {
            if(s[i+j]!=t[j])
            {
                break;
            }
        }

        if(j == t.length())
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main()
{
    string s="ABABABAB"; 
    string t="ABAB"; 

    PatternSearching(s,t);

    return 0;
}