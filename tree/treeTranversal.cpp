#include <bits/stdc++.h>
using namespace std;

/*
/* ===================================== tree ===================================== */ 
struct Node {
    char data;
    Node *left, *right;
};
class bst{
    Node* root;
    stack<Node*> st;
    public: bst(){
        root = NULL;
    }
    int isempty() {
        return(root == NULL);
    }
    void insert(string);
    void displayBinTree();
    void traversePostOrder(Node *);
    void traverseInOrder(Node *);
    void traversePreOrder(Node *);
     
};

/* ========== end of bst class ========== */
//--------------------------------------------------------

Node* createNode(char data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void bst::insert(string prefix) {
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c) || isalpha(c)) {
            Node* node = createNode(c);
            st.push(node);
        }
        else {
            Node* node = createNode(c);
            node->left = st.top();
            st.pop();
            node->right = st.top();
            st.pop();
            st.push(node);
        }
    }
    root =  st.top();
}

void bst::displayBinTree(){
    cout << "\n pre-order traversal: ";
    traversePreOrder(root);
    cout << "\n  in-order traversal: ";
    traverseInOrder(root);
    cout << "\npost-order traversal: ";
    traversePostOrder(root);
}

/*====== TRAVERSE* ======*/
void bst::traversePreOrder(Node *temp) {
    if (temp != NULL) {
        cout << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}
void bst::traverseInOrder(Node *temp) {
    if (temp != NULL) {
        traverseInOrder(temp->left);
        cout << temp->data;
        traverseInOrder(temp->right);
    }
}
void bst::traversePostOrder(Node *temp) {
    if (temp != NULL) {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << temp->data;
  }
}
/*====== TRAVERSE* ======*/
/* ===================================== tree ===================================== */


/* ===================================== prepare ===================================== */

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}
int getPriority(char C) {
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}
string infixToPostfix(string infix) {
	infix = '(' + infix + ')';
	int l = infix.size();
	stack<char> char_stack;
	string output;

	for (int i = 0; i < l; i++) {

		// If the scanned character is an
		// operand, add it to output.
		if (isalpha(infix[i]) || isdigit(infix[i])){
            output += infix[i];
        }
		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (infix[i] == '(') {
            char_stack.push('(');
        }
		// If the scanned character is an
		// ‘)’, pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (infix[i] == ')') {
			while (char_stack.top() != '(') {
				output += char_stack.top();
				char_stack.pop();
			}
			// Remove '(' from the stack
			char_stack.pop();
		}
		// Operator found
		else {
			if (isOperator(char_stack.top())) {
				if(infix[i] == '^') {
					while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
						output += char_stack.top();
						char_stack.pop();
					}
					
				} else {
					while (getPriority(infix[i]) < getPriority(char_stack.top())) {
						output += char_stack.top();
						char_stack.pop();
					}
				}
				// Push current Operator on stack
				char_stack.push(infix[i]);
			}
		}
	}
	while(!char_stack.empty()){
		output += char_stack.top();
		char_stack.pop();
	}
	return output;
}

string infixToPrefix(string infix){
	/* Reverse String
	* Replace ( with ) and vice versa
	* Get Postfix
	* Reverse Postfix * */
	int l = infix.size();
	// Reverse infix
	reverse(infix.begin(), infix.end());
	// Replace ( with ) and vice versa
	for (int i = 0; i < l; i++) {
		if (infix[i] == '(') {
			infix[i] = ')';
		} else if (infix[i] == ')') {
			infix[i] = '(';
		}
	}
	string prefix = infixToPostfix(infix);
	// Reverse postfix
	reverse(prefix.begin(), prefix.end());
	return prefix;
}

/* ===================================== prepare ===================================== */

int main() {
    bst b;
	string s = "((A+B)*C+(D-E+F)/G)";
    string exp = infixToPrefix(s);
    b.insert(exp);
    cout << infixToPrefix(s);
    b.displayBinTree();
	return 0;
}
