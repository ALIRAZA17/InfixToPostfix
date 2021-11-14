#include <iostream>
#include <cmath>

using namespace std;

class Stack
{

public:
    string mystack[100]; // Stack of max 100 elements
    int top;

    Stack() // Default constructor with value of top = -1
    {
        top = -1;
    }

    void push(string c) // Pushes a character in to the stack
    {
        if (top >= 100 - 1)
        {
            cout << "Your Stack is Overflowing!!!" << endl;
        }
        else
        {
            mystack[++top] = c;
        }
    }

    bool isEmpty() // returns whether a stack is empty or not
    {
        if (top < 0)
        {
            return true;
        }

        else
            return false;
    }

    string pop() // Pops the value present at the top
    {
        string expression = mystack[top];
        mystack[top--] = '0';
        return expression;
    }

    string Peak() // returns the element present at the top
    {
        string d;
        d = mystack[top];
        return d;
    }
};

int main()
{

    return 0;
}