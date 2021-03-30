#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top=-1;

char push(char elem);
char pop();
int priority(char symbol);

int main() {

    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;

    printf("Enter the Expression : ");
    scanf("%s",infix);
    push('#');

    while( (ch=infix[i++]) != '\0') {

        if( ch == '(') push(ch);
        else
        if(isalnum(ch)) postfix[k++]=ch;
        else
        if( ch == ')') {
            while( stack[top] != '(')
                postfix[k++]=pop();
            elem=pop();
        } else {
            while( priority(stack[top]) >= priority(ch) )
                postfix[k++]=pop();
            push(ch);
        }
    }
    while( stack[top] != '#')
        postfix[k++]=pop();
    postfix[k]='\0';

    printf("\nPostfix Expression =  %s\n",postfix);
}

char push(char elem) {
    stack[++top]=elem;
}

char pop() {
    return(stack[top--]);
}

int priority(char symbol) {
    if(symbol == '^') {
        return(3);
    } else if(symbol == '*' || symbol == '/') {
        return(2);
    } else if(symbol == '+' || symbol == '-') {
        return(1);
    } else {
        return(0);
    }
}