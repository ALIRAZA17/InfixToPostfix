#include <iostream>

using namespace std;

class Stack
{

public:
    char mystack[100]; // Stack of max 100 elements
    int top;

    Stack() // Default constructor with value of top = -1
    {
        top = -1;
    }

    void push(char c) // Pushes a character in to the stack
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

    void pop() // Pops the value present at the top
    {
        char expression = mystack[top];
        mystack[top--] = '0';
        cout << expression;
    }

    char Peak() // returns the element present at the top
    {
        char d;
        d = mystack[top];
        return d;
    }

    int priority(char expression)
    {
        if (expression == '(' || expression == ')' || expression == '{' || expression == '}' || expression == '[' || expression == ']')
        {
            return 1;
        }

        else if (expression == '+' || expression == '-')
        {
            return 2;
        }

        else if (expression == '*' || expression == '/')
        {
            return 3;
        }

        else if (expression == '^')
        {
            return 4;
        }
    }

    char operators(char MyOperator)
    {
        char my_array[5] = {'+', '-', '*', '/', '^'};
        for (int i = 0; i < 5; i++)
        {
            if (my_array[i] == MyOperator)
            {
                cout << MyOperator;
            }
        }
    }

    bool Validation(string userinput, Stack obj)
    {
        for (int i = 0; i < userinput.length(); i++)
        {
            if (userinput[i] == '(' || userinput[i] == '{' || userinput[i] == '[')
            {
                obj.push(userinput[i]);
            }

            else if ((userinput[i] == ')' && obj.Peak() == '(') || (userinput[i] == '}' && obj.Peak() == '{') || (userinput[i] == ']' && obj.Peak() == '['))
            {
                obj.pop();
            }
            else if ((userinput[i] == ')' && obj.Peak() != '(') || (userinput[i] == '}' && obj.Peak() != '{') || (userinput[i] == ']' && obj.Peak() != '['))
            {
                obj.push(userinput[i]);
            }
            else
                continue;
        }

        if (obj.isEmpty())
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void InfixToPostfix(string input, Stack Myobj)
    {
        if (Validation(input, Myobj))
        {
            for (int i = 0; i < input.length(); i++)
            {
                if (isdigit(input[i]))
                {
                    cout << input[i];
                }

                else if (input[i] == '(' || input[i] == '{' || input[i] == '[')
                {
                    Myobj.push(input[i]);
                }

                else if ((input[i] == ')' && Myobj.Peak() == '(') || (input[i] == '}' && Myobj.Peak() == '{') || (input[i] == ']' && Myobj.Peak() == '['))
                {
                    Myobj.pop();
                }
                else if ((input[i] == ')' && Myobj.Peak() != '(') || (input[i] == '}' && Myobj.Peak() != '{') || (input[i] == ']' && Myobj.Peak() != '['))
                {
                    Myobj.push(input[i]);
                }

                else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '^')
                {

                    if (top == -1)
                    {
                        Myobj.push(input[i]);
                    }

                    else if (priority(input[i] > priority(input[mystack[top]])))
                    {
                        Myobj.push(input[i]);
                    }

                    else if (priority(input[i] <= priority(input[mystack[top]])))
                    {
                        Myobj.pop();
                        Myobj.push(input[i]);
                    }
                }

                //     else if (input[i] == '+' && (Myobj.pop() == '-' || Myobj.pop() == '*' || Myobj.pop() == '/' || Myobj.pop() == '+') || input[i] == '-' && (Myobj.pop() == '-' || Myobj.pop() == '*' || Myobj.pop() == '/' || Myobj.pop() == '+') || input[i] == '*' && (Myobj.pop() == '-' || Myobj.pop() == '*' || Myobj.pop() == '/' || Myobj.pop() == '+') || input[i] == '/' && (Myobj.pop() == '-' || Myobj.pop() == '*' || Myobj.pop() == '/' || Myobj.pop() == '+'))
                //     {

                //     }
                // }
            }
        }
    }
};

int main()
{

    int choice;
    string userinput;
    Stack obj;
    while (choice != -1)
    {
        cout << endl;
        cout << "---> Press 1 to enter an expression." << endl;
        cout << "---> Press -1 to exit the program." << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter The equation: ";
            cin >> userinput;
            if (obj.Validation(userinput, obj))
            {
                obj.InfixToPostfix(userinput, obj);
            }

        case 2:
            break;
        }
    }
    return 0;
}