#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define SIZE 20
struct stack{
int top;
float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,float item)
{
    s->data[++(s->top)]=item;
}
float pop(STACK *s)
{
    return s->data[(s->top)--];
}
float operate(float opr1,char symbol,float opr2)
{
    switch(symbol)
    {
        case '+': return opr1+opr2;
        case '-': return opr1-opr2;
        case '*': return opr1*opr2;
        case '/': return opr1/opr2;
        case '^': return pow(opr1,opr2);
    }
}
float evaluatepostfix(STACK *s,char postfix[SIZE])
{
    float opr1,opr2,res;
    int i;
    char symbol;
    for(i=0;postfix[i]!='\0';i++)
        {
            symbol=postfix[i];
            if(isdigit(symbol))
            push(s,symbol-'0');
        else
        {
            opr2=pop(s);
            opr1=pop(s);
            res=operate(opr1,symbol,opr2);
            push(s,res);
        }
    }
    return pop(s);
}
int main()
{
    float ans;
    char postfix[SIZE];
    STACK s;
    s.top=-1;
    printf("\n read postfix \n");
    scanf("%s",postfix);
    ans=evaluatepostfix(&s,postfix);
    printf("\n defined results is %f\n",ans);
    return 0;
}
