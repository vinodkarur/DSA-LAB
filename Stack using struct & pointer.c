#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack{
    int top;
    int data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,int item){
    if(s->top==SIZE-1){
        printf("Stack overflow");
    }
    else{
        s->top++;
        s->data[s->top]=item;
    }
}
    void pop(STACK *s){
        if(s->top==-1){
            printf("Stack underflow");
        }
        else{
            printf("Popped item is %d",s->data[s->top]);
            s->top--;
        }
    }
    void display(STACK s){
        int i;
        if(s.top==-1){
            printf("Stack is empty");
        }
        else{
            printf("Stack contents are\n");
            for(i=s.top;i>=0;i--){
                printf("%d\n",s.data[i]);
            }
        }
    }
int main(){
    int ch,item;
    STACK s;
    s.top=-1;
    for(;;){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("\n Read element to be pushed: ");
                scanf("%d",&item);
                push(&s,item);
                break;
            }
            case 2:{
                pop(&s);
                break;
            }
            case 3:{
                display(s);
                break;
            }
            default:{
                exit(0);
            }
        }
    }
    return 0;
}
