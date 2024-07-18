//#include<iostream>
//#include<stack>
//using namespace std;
//class treeNode
//{
//private:
//	char data;
//	treeNode* left;
//	treeNode* right;
//public:
//	treeNode()
//	{
//		data = ' ',left=NULL,right=NULL;
//	}
//	treeNode(char d)
//	{
//		data = d, left = NULL, right = NULL;
//	}
//	void setleft(treeNode *l)
//	{
//		left = l;
//	}
//	void setright(treeNode* r)
//	{
//		right = r;
//	}
//	char getdata()
//	{
//		return data;
//	}
//	treeNode* getleft()
//	{
//		return left;
//	}
//	treeNode* getright()
//	{
//		return right;
//	}
//};
//void print(treeNode* root)
//{
//	if (root != NULL)
//	{
//		print(root->getleft());
//		cout << root->getdata() << " ";
//		print(root->getright());
//	}
//}
//treeNode* builtexpressiiontree(char postfix[])
//{
//	int n = 15;
//	stack<treeNode*> s;
//	cout << "Inorder traversal of expression tree:" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		if (postfix[i] >= '0' && postfix[i] <= '9')
//		{
//			treeNode *obj=new treeNode(postfix[i]);
//			s.push(obj);
//		}
//		else
//		{
//			treeNode *obj=new treeNode(postfix[i]);
//			obj->setleft(s.top());
//			s.pop();
//			obj->setright(s.top());
//			s.pop();
//			s.push(obj);
//		}
//		print(s.top());
//		cout << endl;
//	}
//	return s.top();
//}
//int main()
//{
//	char postfix[] = { '6','2','3','+','-','3','8','2','/','+','*','2','^','3','+' };
//	treeNode* root = builtexpressiiontree(postfix);
//	cout << "Final expression tree:" << endl;
//	print(root);
//}