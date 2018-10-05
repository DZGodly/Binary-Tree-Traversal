#include<iostream>
using namespace std;

typedef struct BinaryTree {
	char data;
	BinaryTree* lchild;
	BinaryTree* rchild;
}*BTree;

//----递归算法----
void visit(BTree t) {
	cout << t->data;
}
void preOrder(BTree t) {				//前序遍历
	if (t != NULL) {
		visit(t);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}

void inOrder(BTree t) {					//中序遍历
	if (t != NULL) {
		inOrder(t->lchild);
		visit(t);
		inOrder(t->rchild);
	}
}
		
void pastOrder(BTree t) {				//后序遍历
	if (t != NULL) {
		pastOrder(t->lchild);
		pastOrder(t->rchild);
		visit(t);
	}
}
//非递归算法
typedef struct TNode {
	BTree tree;
	TNode* nextT;
}*T;
class TreeStark {

private:
	T top;
	int size;

public:
	TreeStark() {
		top = NULL;
		size = 0;
	}
	~TreeStark() {
		delete top;
	}
	//入栈操作
	void push(BTree t) {
		T in = new TNode;
		in->tree = t;
		in->nextT = top;
		top = in;
		size++;
	}
	//出栈操作
	void pop() {
		if (top) {
			T out = top;
			top = top->nextT;
			delete out;
			size--;
		}
		else cout << "栈为空";
	}

	bool empty() {
		return top == NULL;
	}

	int getSize() {
		return size;
	}

	BTree getTop() {
		return top->tree;
	}

	void visitTop() {
		if (top->tree) {
			cout << top->tree->data;
		}
	}
};

void preOrderS(BTree root) {							//前序遍历
	TreeStark s;
	BTree t = root;
	s.push(t);
	s.visitTop();
	while (!s.empty()) {
		while (t){
			t = t->lchild;
			s.push(t);
			s.visitTop();
		}
		s.pop();

		if (!s.empty()) {
			t = s.getTop();
			s.pop();
			t = t->rchild;
			s.push(t);
			s.visitTop();
		}
	}
}

void inOrderS(BTree root) {								//中序遍历
	TreeStark s;
	BTree t = root;
	s.push(t);
	while (!s.empty()) {
		while (t) {
			t = t->lchild;
			s.push(t);
		}
		s.pop();

		if (!s.empty()) {
			s.visitTop();
			t = s.getTop();
			s.pop();
			t = t->rchild;
			s.push(t);
		}
	}
}

void createTree(BTree& root) {
	char data;
	cin >> data;
	if (data == '#') {
		root = NULL;
		return;
	}
	else {
		root = new BinaryTree;
		root->data = data;
		createTree(root->lchild);
		createTree(root->rchild);
	}
}

int main() {
	//生成树
	BTree root = new BinaryTree;
	cout << "输入树：";
	createTree(root);
	/*root->data = '-';
	BTree t1 = new BinaryTree; t1->data = '+';
	BTree t2 = new BinaryTree; t2->data = '/';
	BTree t3 = new BinaryTree; t3->data = 'a';
	BTree t4 = new BinaryTree; t4->data = '*';
	BTree t5 = new BinaryTree; t5->data = 'e';
	BTree t6 = new BinaryTree; t6->data = 'f';
	BTree t7 = new BinaryTree; t7->data = 'b';
	BTree t8 = new BinaryTree; t8->data = '-';
	BTree t9 = new BinaryTree; t9->data = 'c';
	BTree t0 = new BinaryTree; t0->data = 'd';
	root->lchild = t1; root->rchild = t2;
	t1->lchild = t3; t1->rchild = t4;
	t2->lchild = t5; t2->rchild = t6;
	t3->lchild = NULL; t3->rchild = NULL;
	t4->lchild = t7; t4->rchild = t8;
	t5->lchild = NULL; t5->rchild = NULL;
	t6->lchild = NULL; t6->rchild = NULL;
	t7->lchild = NULL; t7->rchild = NULL;
	t8->lchild = t9; t8->rchild = t0;
	t9->lchild = NULL; t9->rchild = NULL;
	t0->lchild = NULL; t0->rchild = NULL;*/


	//-----递归算法-----
	//前序遍历
	cout << "递归先序遍历:";
	preOrder(root);
	cout << endl;
	//中序遍历
	cout << "递归中序遍历:";
	inOrder(root);
	cout << endl;
	//后序遍历
	cout << "递归后序遍历:";
	pastOrder(root);
	cout << endl;
	//-----非递归算法-----
	//前序遍历
	cout << "非递归先序遍历:";
	preOrderS(root);
	cout << endl;
	//中序遍历
	cout << "非递归中序遍历:";
	inOrderS(root);
	cout << endl;

	system("pause");
	return 0;
}