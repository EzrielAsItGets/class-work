#include <iostream>
#include <cstring>
#include <map>
#include <stack>
using namespace std;

bool isValid(string str);
bool inputStream(string inputA, string inputB);
string simplifyDir(string dir);
string expandString(string expr);

int main() {
	string mystring, inputA, inputB, dir, expr;

	cout << endl << "******Valid String Function******\n";
	mystring = "(){}[]";
	cout << "String: " << mystring << endl;
	cout << "Is the string valid? : ";
	if (isValid(mystring))
		cout << "YES\n";
	else
		cout << "NO\n";
	cout << endl;
	
	cout << "******Input Stream Function******\n";
	inputA = "abcde<<";
	inputB = "abcd<e<";
	cout << "Input A: " << inputA << endl;
	cout << "Input B: " << inputB << endl;
	cout << "Are the two input streams equal? : ";
	if (inputStream(inputA, inputB))
		cout << "YES\n";
	else
		cout << "NO\n";
	cout << endl;
	
	cout << "******Simplify Directory Function******\n";
	dir = "/a/./b/../../c/";
	cout << "Original Path: " << dir << endl;
	cout << "Simplified Path: " << simplifyDir(dir) << endl;
	cout << endl;
	
	cout << "******Expand Expression Function******\n";
	expr = "3[abc]";
	cout << "Simplified Expression: " << expr << endl;
	cout << "Expanded Expression: " << expandString(expr) << endl;
	cout << endl;

	return 0;
}

bool isValid(string str) {
	stack<char> stack1;
	string::iterator it;
	map<char, char> x;
	x['('] = ')';
	x['['] = ']';
	x['{'] = '}';
	for (it = str.begin(); it < str.end(); ++it) {
		if (!stack1.empty()) {
			char c = stack1.top();
			if (x[c] == *it)
				stack1.pop();
			else
				stack1.push(*it);
		}
		else
			stack1.push(*it);
	}
	return stack1.empty();
}

bool inputStream(string inputA, string inputB) {
	stack<char> stack1, stack2;
	string::iterator it1, it2;
	for (it1 = inputA.begin(); it1 < inputA.end(); ++it1) {
		if (*it1 == '<')
			if (!stack1.empty())
				stack1.pop();
		else
			stack1.push(*it1);
	}
	for (it2 = inputB.begin(); it2 < inputB.end(); ++it2) {
		if (*it2 == '<')
			if (!stack2.empty())
				stack2.pop();
		else
			stack2.push(*it2);
	}
	if (stack1 == stack2)
		return true;
	else
		return false;
}

string simplifyDir(string dir) {
	stack<string> stack1, stack2;
	string org_dir, sim_dir, temp;
	int len_dir = dir.length();
	sim_dir.append("/");
	for (int i = 0; i < len_dir; ++i) {
		org_dir.clear();
		while (dir[i] == '/')
			++i;
		while (i < len_dir && dir[i] != '/') {
			org_dir.push_back(dir[i]);
			++i;
		}
		if (org_dir.compare("..") == 0) {
			if (!stack1.empty())
				stack1.pop();
		}
		else if (org_dir.compare(".") == 0)
			continue;
		else if (org_dir.length() != 0)
			stack1.push(org_dir);
	}
	while (!stack1.empty()) {
		stack2.push(stack1.top());
		stack1.pop();
	}
	while (!stack2.empty()) {
		temp = stack2.top();
		if (stack2.size() != 1)
			sim_dir.append(temp + "/");
		else
			sim_dir.append(temp);
		stack2.pop();
	}
	return sim_dir;
}

string expandString(string expr) {
	stack<string> stack1;
	string expand = "", numstr = "", lastexp = "";
	int it = 0, k =0;
	while (it < expr.size()) {
		if (expr[it] >= '0' && expr[it] <= '9') {
			while (expr[it] >= '0' && expr[it] <= '9') {
				numstr += expr[it];
				++it;
			}
			stack1.push(expand);
			stack1.push(numstr);
			expand = "";
		}
		else if (expr[it] >= 'a' && expr[it] <= 'z' || expr[it] >= 'A' && expr[it] <= 'Z')
			expand += expr[it];
		else if (expr[it] == ']') {
			numstr = stack1.top();
			stack1.pop();
			for (int j = 0; j < numstr.size(); ++j)
				k = 10 * k + (numstr[j] - '0');
			lastexp = stack1.top();
			stack1.pop();
			for (int l = 0; l < k; ++l)
				lastexp += expand;
			expand = lastexp;
		}
		++it;
	}
	return expand;
}
