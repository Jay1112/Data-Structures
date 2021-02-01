// Rotation of strings
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

bool isRotate(string s,string t)
{
    if(s.length() != t.length())
    {
        return false;
    }

    s = s + s;

    return (s.find(t) != string::npos);
}

int main()
{
    string s = "ABCD";
    string t = "DCAB";

    bool check = isRotate(s,t);

    cout << check << endl;

    return 0;
}