#include<stdio.h>
#include<stdlib.h>  
#include<string.h>
#include<ctype.h>


#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }
char peek(){ return stack[top]; }

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

void infixToPostfix(char *in, char *post){
    int k=0;
    for(int i=0; in[i]; i++){
        if(isdigit(in[i]))
            post[k++]=in[i];
        else if(in[i]=='(')
            push(in[i]);
        else if(in[i]==')'){
            while(peek()!='(')
                post[k++]=pop();
            pop();
        }
        else{
            while(top!=-1 && prec(peek())>=prec(in[i]))
                post[k++]=pop();
            push(in[i]);
        }
    }
    while(top!=-1)
        post[k++]=pop();
    post[k]='\0';
}

int evalPostfix(char *post){
    int s[MAX], t=-1;

    for(int i=0; post[i]; i++){
        if(isdigit(post[i]))
            s[++t]=post[i]-'0';
        else{
            int b=s[t--];
            int a=s[t--];

            switch(post[i]){
                case '+': s[++t]=a+b; break;
                case '-': s[++t]=a-b; break;
                case '*': s[++t]=a*b; break;
                case '/': s[++t]=a/b; break;
            }
        }
    }
    return s[t];
}

int main(){
    char infix[100], postfix[100];

    printf("Enter expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evalPostfix(postfix));
}
