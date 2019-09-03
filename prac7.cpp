#include<bits/stdc++.h>
using namespace std;

char InToPostStack[100];
int top = -1;
void push(char exp)
{
	if(top > 100)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		InToPostStack[++top] = exp;
	}
}

char pop()
{
	char exp;
	if(top < 0)
	{
		cout<<"stack under flow: invalid infix expression";
		//getchar();
		exit(0);
	}
	else
	{
		exp = InToPostStack[top--];
		return(exp);
	}
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedence(char symbol)
{
	if(symbol == '^')  //highest precedence
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-') // lowest precedence
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void infixToPostfix(char infix[],char postfix[]){
  push('(');
  strcat(infix,")");
  int i = 0, j = 0;
  char expAtIndex = infix[i];
  while(expAtIndex != '\0'){
    if(expAtIndex=='('){
      push(expAtIndex);
    }else if(isdigit(expAtIndex) || isalpha(expAtIndex)){
      postfix[j++]=expAtIndex;
    }else if(is_operator(expAtIndex) == 1){
        char temp = pop();
      while(is_operator(temp) == 1 && precedence(temp)>= precedence(expAtIndex))
			{
				postfix[j++] = temp;  //pop all higher precendence operator and
				temp = pop();    // add them to postfix expresion
			}
      push(temp);
			push(expAtIndex);
    }else if(expAtIndex==')'){
      char temp = pop();
      while(temp != '('){
        postfix[j++]=temp;
        temp = pop();
      }
    }else{
      cout<<"\nInvalid Expression!!!\n";
      //getchar();
      exit(0);
    }
    expAtIndex = infix[++i];
  }

  if(top > 0){
    cout<<"Invalid Expression!!!"<<endl;
    //getchar();
    exit(0);
  }
  postfix[j]='\0';

}

int main(){
  char infix[100],postfix[100];
  cin>>infix;
  infixToPostfix(infix,postfix);
  cout<<"Postfix Expression is: "<<postfix<<endl;
  return 0;
}
