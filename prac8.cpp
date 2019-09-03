#include<bits/stdc++.h>
using namespace std;

int PostEvaluteStack[100];
int top = -1;
void push(int exp)
{
	if(top > 100)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		PostEvaluteStack[++top] = exp;
	}
}

int pop()
{
	int exp;
	if(top < 0)
	{
		cout<<"stack under flow: invalid infix expression";
		//getchar();
		exit(0);
	}
	else
	{
		exp = PostEvaluteStack[top--];
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

int PostfixEvaluation(char postfix[]){
  push('(');
  strcat(postfix,")");
  int i = 0;
  int res = 0;
  char expAtIndex = postfix[i];
  while(expAtIndex != '\0'){
    if(expAtIndex=='('){
      push(expAtIndex-'0');
    }else if(isdigit(expAtIndex)){
      push(expAtIndex-'0');
    }else if(is_operator(expAtIndex) == 1){
        int temp2 = pop();
        int temp1 = pop();
				// cout<<"temp1 is "<<temp1<<" and temp2 is"<<temp2<<endl;
        if(expAtIndex=='+'){
          res=temp1+temp2;
        }else if(expAtIndex=='-'){
          res=temp1-temp2;
        }else if(expAtIndex=='*'){
          res=temp1*temp2;
        }else if(expAtIndex=='/'){
          res=temp1/temp2;
        }else if(expAtIndex=='^'){
          res=pow(temp1,temp2);
        }
      push(res);
			// push(expAtIndex);
    }else if(expAtIndex==')'){
      return pop();
    }else{
      cout<<"\nInvalid Expression!!!\n";
      //getchar();
      exit(0);
    }
    expAtIndex = postfix[++i];
  }

  if(top > 0){
    cout<<"Invalid Expression!!!"<<endl;
    //getchar();
    exit(0);
  }


}

int main(){
  char postfix[100];
  cin>>postfix;
  cout<<"Answer of Postfix Expression is: "<<PostfixEvaluation(postfix)<<endl;
  return 0;
}
