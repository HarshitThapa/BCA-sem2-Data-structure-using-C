#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i = 0, j = 0;
    char x;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        if((infix[i] >= 'a' && infix[i] <= 'z') ||
           (infix[i] >= 'A' && infix[i] <= 'Z') ||
           (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }

        i++;
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix Expression: %s", postfix);

    return 0;
}
