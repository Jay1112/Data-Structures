// Evaluation of Postfix Expression
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstring>

using namespace std;

int evaluation(string exp)
{
    string temp = "" ;
    stack<int> s;
    
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]>=48 && exp[i]<=57)
        {
            temp = temp + exp[i];
        }
        else if(exp[i] == ' ')
        {
            if(temp == "")
            {
                continue;
            }
            
            int num = std::stoi(temp);
            s.push(num);
            
            temp = "";
        }
        else
        {
            int num1 = s.top();
            s.pop();
                
            int num2 = s.top();
            s.pop();
            
            int ans;
            
            switch(exp[i])
            {
                case '+' : ans = num2 + num1 ; break;
                case '-' : ans = num2 - num1 ; break;
                case '*' : ans = num2 * num1 ; break;
                case '/' : ans = num2 / num1 ; break;
            }
            
            s.push(ans);
        }
    }
    return s.top();
}

int main()
{
    string exp ; 
    
    cout << "Enter the Expression : "; getline(cin,exp);
    
    int ans = evaluation(exp);
    
    cout << "Answer : " << ans << endl;

    return 0;
}