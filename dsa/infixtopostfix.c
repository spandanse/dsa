#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char infix[MAX],postfix[MAX],stack[MAX];
int TOP=-1;
void push(char a)
{
    if(TOP==MAX-1)
        exit(1);
    stack[++TOP]=a;
}
char pop()
{
    if(TOP==-1)
        exit(1);
    return stack[TOP--];
}
int precedence(char a)
{
    switch(a)
    {
        case '^':
        return 3;
        case '*':case '/':case '%':
        return 2;
        case '+':case '-':
        return 1;
        default:
        return 0;
    }
}
void intopost()
{
    char symbol,x;int j=0;
    for(int i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(symbol!=' '&&symbol!='\t')
        {
            switch(symbol)
            {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while((x=pop())!='(')
                        postfix[j++]=x;
                    break;
                case '+':case '-':case '*':case '/':case '%':case '^':
                    while(TOP!=-1&&(precedence(stack[TOP])>=precedence(symbol)))
                    {
                        if(stack[TOP]=='^'&&symbol=='^')
                            break;
                        postfix[j++]=pop();
                    }
                    push(symbol);
                    break;
                default:
                    postfix[j++]=symbol;
            }
        }
    }
    while(TOP!=-1)
        postfix[j++]=pop();
    postfix[j]='\0';
}
void main()
{
    printf("ENTER THE INFIX EXPRESSION\n");gets(infix);
    strrev(infix);
    intopost();
    printf("THE EQUIVALENT POSTFIX EXPRESSION IS\n");
    strrev(postfix);
    puts(postfix);
}