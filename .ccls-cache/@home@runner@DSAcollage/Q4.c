#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char infix[MAX];
char postfix[MAX];
char stack[MAX];
int top = -1;

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

int precedence(char symbol){
    switch(symbol){
        case '^':
            return 3;
        
        case '/':
        case '*':
            return 2;
        
        case '-':
        case '+':
            return 1;
        
        default :
            return 0;
    }
}

void push(char c){
    if(isFull()){
        printf("stack is overflow\n");
        exit(1);
    }
    top++;
    stack[top] = c;
}

char pop(){
    char val;
    if(isEmpty()){
        printf("stack is underflow\n");
        exit(1);
    }
    val = stack[top];
    top--;
    return val;
}

void in2post(){
    int i,j = 0;
    char symbol,next;
    for(i=0;i<strlen(infix);i++){
        symbol = infix[i];
        switch(symbol) {
            case '(':
                push(symbol);
                break;
            
            case ')':
                while((next=pop()) != '('){
                    postfix[j++] = next;
                }
                break;
            
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;
                
            default :
                postfix[j++] = symbol;
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();
    postfix[j++] = '\0';
}

void print(){
    int i = 0;
    printf("postfix : ");
    while(postfix[i]){
        printf("%c",postfix[i++]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the infix expression : ");
    gets(infix);
    in2post();
    print();
    return 0;
}
