#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    int value;
    value = stack[top];
    top--;
    return value;
}

int evaluatePostfix(char exp[])
{
    int i = 0;
    int a, b, result;

    while(exp[i] != '\0')
    {
        if(exp[i] >= '0' && exp[i] <= '9')
        {
            push(exp[i] - '0');   // convert character to integer
        }
        else
        {
            b = pop();
            a = pop();

            switch(exp[i])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main()
{
    char exp[100];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}
