#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Queue {
	private:
		stack<int> s1, s2;
	public:
		void enqueue(int element);
		void dequeue();
		int peekFront();
		bool isEmpty();
};

struct TreeNode {
	int value;
	TreeNode *left;
	TreeNode *right;
};

TreeNode* addNode(int value);
void levelOrder(TreeNode* root);
void inOrder(TreeNode* root);
int treeSumCalc(TreeNode* root, int val);
int treeSum(TreeNode* root);

int main() {
	cout << "\n******Implementation of Queue******\n";
	Queue q;
	cout << "Is the Queue empty? : ";
	if (q.isEmpty() == 1)
		cout << "True\n";
	else
    	cout << "False\n";
	q.enqueue(5);
	q.enqueue(11);
	q.enqueue(1);
	q.enqueue(7);
	q.enqueue(13);
	q.enqueue(11);
	cout << "Original First Element: " << q.peekFront() << endl;
	q.dequeue();
	cout << "Element After Dequeue: " << q.peekFront() << endl;
	cout << "Is the Queue empty? : ";
	if (q.isEmpty() == 1)
		cout << "True\n";
	else
    	cout << "False\n";	
	cout << endl;
	
	cout << "******Binary Tree I: Level Order******\n";
	TreeNode* root = addNode(3);
	root->left = addNode(9);
	root->right = addNode(20);
	root->right->left = addNode(15);
	root->right->right = addNode(7);
	levelOrder(root);
	cout << endl;
	
	cout << "******Binary Tree II: In-Order******\n";
	TreeNode* root1 = addNode(1);
	root1->right = addNode(2);
	root1->right->left = addNode(3);
	inOrder(root1);
	cout << endl;
	
	cout << "\n******Binary Tree III: Sum of Root->Leaf Numbers******\n";
	TreeNode* root2 = addNode(1);
	root2->left = addNode(2);
	root2->right = addNode(3);
	cout << "The sum of the tree is: " << treeSum(root2) << endl;
	cout << endl;
	
	return 0;	
}

void Queue::enqueue(int element) {
	s1.push(element);
}

void Queue::dequeue() {
	if (!s2.empty()) {
		s2.pop();
	}
	else {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}
}

int Queue::peekFront() {
	if (!s2.empty()) {
		return s2.top();
	}
	else {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		return s2.top();
	}
}

bool Queue::isEmpty() {
	return (s1.empty() && s2.empty());
}

TreeNode* addNode(int value) {
	TreeNode* temp = new TreeNode;
	temp->value = value;
	temp->left = temp->right = NULL;
	return temp;
}

void levelOrder(TreeNode* root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	while (1) {
		int tree_size = q.size();
		if (tree_size == 0)
			break;
		while (tree_size > 0) {
			TreeNode* node = q.front();
			cout << node->value << " ";
			q.pop();
			if (node->left != NULL)
				q.push(node->left);
			if (node->right != NULL)
				q.push(node->right);
			tree_size--;
		}
		cout << endl;
	}
}

void inOrder(TreeNode* root) {
	stack<TreeNode*> s;
	TreeNode* curr = root;
	while (!s.empty() || curr != nullptr) {
		if (curr != nullptr) {
			s.push(curr);
			curr = curr->left;
		}
		else {
			curr = s.top();
			s.pop();
			cout << curr->value << " ";
			curr = curr->right;
		}
	}
}

int treeSumCalc(TreeNode* root, int val) {
	if (root == NULL)
		return 0;
	val = (val * 10 + root->value);
	if (root->left == NULL && root->right == NULL)
		return val;
	return treeSumCalc(root->left, val) + treeSumCalc(root->right, val);
}

int treeSum(TreeNode* root) {
	 return treeSumCalc(root, 0);
}
