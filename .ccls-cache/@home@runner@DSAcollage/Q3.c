#include <stdio.h>
#define MAX 6

int stack_arr[MAX];
int top = -1;

void push(int data);
int pop();
int peep();
void display();
void change();
int isfull();
int isempty();

int main()
{
    int ch,data;
    while(1){
        printf("\n1.push\n2.pop\n3.peep\n4.change\n5.display\n6.exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("enter data for push : ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            printf("topmost value going to pop : ");
            data = pop();
            printf("%d",data);
            break;
        case 3:
            printf("top of stack : ");
             data = peep();
            printf("%d",data);
            break;
        case 4:
            change();
            break;
        case 5:
            printf("order of stacks : ");
            display();
            break;
        case 6:
            exit(1);
        default:
            printf("invalid Choice\n");
            break;
        }
    }
    
}

int isfull(){
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

int isempty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int data){
    if(isfull()){
        printf("stack is overflow\n");
        exit(1);
    }
    top++;
    stack_arr[top] = data;
}

int pop(){
    int val;
    if(isempty()){
        printf("stack is underflow\n");
        exit(1);
    }
    val = stack_arr[top];
    top--;
    return val;
}

int peep(){
    int val;
    if(isempty()){
        printf("stack is underflow\n");
        exit(1);
    }
    val = stack_arr[top];
    return val;
}

void display(){
    int i;
    if(isempty()){
        printf("stack is underflow\n");
        exit(1);
    }
    for(i=0;i<=top;i++){
        printf("%d ",stack_arr[i]);
    }
}

void change(){
    int pos,val;
    printf("Enter position you want to change : ");
    scanf("%d",&pos);
    
    if(pos >= MAX){
        printf("stack overflow\n");
        exit(1);
    }else{
        printf("Enter new value for position choosed : ");
        scanf("%d",&val);
        stack_arr[pos] = val;
    }
}