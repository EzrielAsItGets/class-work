#include <iostream>
#include <stack>
using namespace std;

class MinStack {
	public:
		stack<int> stack1;
		int min;
		void getMin();
		void top();
		void pop();
		void push(int x);
};

int main() {
	MinStack minStack;
	
	cout << endl << "******MinStack Functions******\n";
	minStack.push(-1);
	minStack.push(0);
	minStack.push(-2);
	minStack.getMin();
	minStack.pop();
	minStack.top();
	minStack.getMin();
	cout << endl;
	
	return 0;
}

void MinStack::getMin() {
	if (stack1.empty())
		cout << "Stack is empty!\n";
	else
		cout << "The minimum element is: " << min << endl;
}

void MinStack::top() {
	int t = stack1.top();
	if (stack1.empty()) {
		cout << "Stack is empty!\n";
		return;
	}
	cout << "Top Element is: ";
	(t < min)? cout << min: cout << t;
	cout << endl;
}

void MinStack::pop() {
	int t = stack1.top();
	if (stack1.empty()) {
		cout << "Stack is empty!\n";
		return;
	}
	cout << "Top Most Element Removed: ";
	stack1.pop();
	if(t < min) {
		cout << min << endl;
		min = 2 * min - t;
	}
	else
		cout << t << endl;
}

void MinStack::push(int x) {
	if (stack1.empty()) {
		min = x;
		stack1.push(x);
		cout << "Number Inserted: " << x << endl;
		return;
	}
	if (x < min) {
		stack1.push(2 * x - min);
		min = x;
	}
	else
		stack1.push(x);
	cout << "Number Inserted: " << x << endl;
}
