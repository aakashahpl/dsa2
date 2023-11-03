#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}



string preToPost(string pre_exp)
{
    stack<string> s;
    int length = pre_exp.size();

    for (int i = length - 1; i >= 0; i--)
    {
        if (isOperator(pre_exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + pre_exp[i];
            s.push(temp);
        }
        else
        {
            s.push(string(1, pre_exp[i]));
        }
    }

    return s.top();
}

int main()
{
    string pre_exp;
 

    while (true)
    {
        cout << "Enter a prefix expression: ";
        getline(cin, pre_exp);
        if(pre_exp=="-1"){
            break;
            cout<<"exiting"<<endl;
        } 
        
            cout << "Postfix : " << preToPost(pre_exp) << endl;
    }
    return 0;
}
