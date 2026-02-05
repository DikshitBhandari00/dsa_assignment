#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char z){
    stack[++top] = z;
}

char pop(){
    if(top == -1) return '\0';
    return stack[top--];
}

int match(char x,char y){
    if(x=='(' && y==')') return 1;
    if(x=='{' && y=='}') return 1;
    if(x=='[' && y==']') return 1;
    return 0;
} 

int balanced(char exp[]){
    top= -1;
    for(int i=0;exp[i];i++){
        char ch=exp[i];

        if(ch=='(' || ch=='{'|| ch=='[')
        push(ch);

        else if(ch==')' || ch=='}'|| ch==']'){
            char t=pop();
            if(!match(t,ch))
            return 0;
        }
    }
    return top==-1;
}

int main(){
    char*tests[]={
        "a+(b-c)*(d",
        "m+[a-b*(c+d*{m)]", 
        "a+(b-c)"
    };

    for(int i=0;i<3;i++){
        printf("%s -> %s\n",tests[i],balanced(tests[i])?"Balanced":"Not Balanced");
    }
}