#include <iostream>
#include <string.h>
using namespace std;

char stack[1000],out[1000],str[1000];
int r=0,top=0,n=0;
void ans();


int pi(char y){
    if(y == '+' || y == '-')
        return 1;
    else if(y == '*' || y == '/')
        return 3;
    else if(y == '^')
        return 6;
    else if((y >= 'a' && y <= 'z') || (y >= 'A' && y <= 'Z'))
        return 7;
    else if(y == '(')
        return 9;
    else if(y == ')')
        return 0;
}


int ps(char y){
    if(y == '+' || y == '-')
        return 2;
    else if(y == '*' || y == '/')
        return 4;
    else if(y == '^')
        return 5;
    else if((y >= 'a' && y <= 'z') || (y >= 'A' && y <= 'Z'))
        return 8;
    else if(y == '(')
        return 0;
}


void ranks(char y){
    if((y >= 'a' && y <= 'z') || (y >= 'A' && y <= 'Z'))
        r++;
    else if(y != '(' && y != ')')
        r--;
}


void push(char y){
    if(top<0)
        cout << "Invalid";
    else{
        top++;
    stack[top]=y;
 }
    ans();
}


void pop(){
    top--;
    ans();
}


void ans(){
    printf("%c\t\t",stack[top]);
    for(int i=0;i<=top;i++ ){
        cout << stack[i];
 }
    cout << "\t " << out;
    cout <<"\t\t " << r;
    cout << "\n";
}


int main(){
    cout << "Enter Infix Expression : ";
    cin.getline(str, 1000);
    strcat(str,")");
    stack[top]='(';
    cout << "\nCharacter\tStack\t Output\t\t Rank\n";
    for(int i=0;i<strlen(str);){
        if(pi(str[i])<ps(stack[top])){
            out[n]=stack[top];
            ranks(stack[top]);
            n++;
            pop();
        }
        else if(pi(str[i])==ps(stack[top])){
            pop();
            i++;
        }
        else {
        push(str[i]);
            i++;
        }
    }
    cout << "\nPostfix Expression out " << out;
}
