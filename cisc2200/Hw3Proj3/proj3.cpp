#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef int ValueType;

class IllegalExprException : public exception {}; 

class ZeroDivideException : public exception {}; 

ValueType processExpression(const string& expr) 
    throw (IllegalExprException, ZeroDivideException);

int precedence(char op);
void provideHelpIfNecessary(void);
void evaluate(vector<char> postfix, stack<int> &post);

ValueType doOperation(ValueType left, char operation, ValueType right)
    throw (IllegalExprException, ZeroDivideException);

int main(void) {
    provideHelpIfNecessary();
    while (true) {
		cout << "Expression? " ;
		string expr;
		getline(cin, expr);
		if (expr.length() == 0){
			break;
		}
		try {
			ValueType result = processExpression(expr);
			cout << "Answer : " << result << endl;
		} 
		catch (ZeroDivideException ex) {
			cerr << "Attempt to divide by zero!\n";
		} 
		catch (IllegalExprException ex) {
			cerr << "Illegal infix expression!\n";
		}
    }
    cout << endl;
}

void provideHelpIfNecessary(void) {
    cout << "Do you need help (Y/N)? ";
    string help;
    cin >> help;
    if (help == "Y" || help == "y") {
		cout << "Enter an infix expression at the prompt. " << endl
			 << "The program will tell you its value. " << endl
			 << "To stop the program, just hit \"return\" " 
			 << "at the prompt." << endl;
        cin.ignore();
    }
    else if (help == "N" || help == "n") {
        cin.ignore();
		return;   
    }
    else {
		cout << "Response must be either either \"Y\" or \"N\"." << endl;
		provideHelpIfNecessary();
    } 
}

ValueType processExpression(const string& expr) 
    throw (IllegalExprException, ZeroDivideException)
{
    vector<char> postfix;
    stack<char> aStack;
    char ch;
    int braceCount = 0;
    int operandCount = 0;
    int operatorCount = 0;
    for(unsigned int i = 0; i < expr.length(); i++) {
		ch = expr[i];
		switch(ch) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				operatorCount++;
				postfix.push_back(ch);
				break;
			case '(':
				braceCount++;
				aStack.push(ch);
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if (i == expr.length()-1)
					throw IllegalExprException();
				while((!aStack.empty()) && (aStack.top() != '(') && (precedence(ch) <= precedence(aStack.top()))) {
					postfix.push_back(aStack.top());
					aStack.pop();
				}
				operandCount++;
				aStack.push(ch);
				break;
			case ')':
				if (braceCount < 1)
					throw IllegalExprException();
				while(aStack.top() != '('){
					postfix.push_back(aStack.top());
					aStack.pop();
				}
				braceCount--;
				aStack.pop();
				break;
			default:
				throw IllegalExprException();
	    } 
    }
    if (braceCount != 0 || operandCount == 0)
		throw IllegalExprException();
    if (operatorCount <= operandCount)
		throw IllegalExprException();
    while(!aStack.empty()){
		postfix.push_back(aStack.top());
		aStack.pop();
    }
    stack<int> post;
    evaluate(postfix, post);
    return post.top();
}

int precedence(char op) {
    int prec = 0;
    switch (op) {
		case '+':
			prec = 1;
			break;
		case '-':
			prec = 1;
			break;
		case '*':
			prec = 2;
			break;
		case '/':
			prec = 2;
			break;
    }
    return prec;
}

void evaluate(vector<char> postfix, stack<int> &post) {    
    for(unsigned int i = 0; i < postfix.size(); i++) {
		if ('0' <= postfix[i] && postfix[i] <= '9')
			post.push(postfix[i] - '0');   
		else {
			int right = post.top();
			post.pop();
			int left = post.top();
			post.pop();
			post.push(doOperation(left, postfix[i], right));
		}
    }
}

ValueType doOperation(ValueType left, char operation, ValueType right)
    throw (IllegalExprException, ZeroDivideException)
{
    switch (operation) {
		case '+':
			return left + right;	
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			if(right == 0)
				throw ZeroDivideException();
			return left / right;
		default:
			throw IllegalExprException();
    }
    return 0;
}
