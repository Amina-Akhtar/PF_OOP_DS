//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//struct node
//{
//	char data;
//	int frequency;
//	node* left;
//	node* right;
//	node()
//	{
//		data = ' ', frequency = 0, left = NULL, right = NULL;
//	}
//};
//struct comparenodes
//{
//	bool operator()(node*& a, node*& b)
//	{
//		if (a->frequency > b->frequency)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//};
//node* buildhuffmantree(vector<node*>& nodes)
//{
//	priority_queue <node*, vector<node*>, comparenodes>pq;
//	for (int i = 0; i < nodes.size(); i++)
//	{
//		pq.push(nodes[i]);
//	}
//	while (pq.size() > 1)
//	{
//		node* left = pq.top();
//		pq.pop();
//		node* right = pq.top();
//		pq.pop();
//		node* temp = new node();
//		temp->data = '\0';
//		temp->frequency = left->frequency + right->frequency;
//		temp->left = left;
//		temp->right = right;
//		pq.push(temp);
//	}
//	return pq.top();
//}
//void print(node* root)
//{
//	if (root != NULL)
//	{
//		print(root->left);
//		cout << root->data << " " << root->frequency << "\t";
//		print(root->right);
//	}
//}
//void generatehuffmancode(node* root, string codes[], string cod = "")
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	if (root->data != '\0')
//	{
//		codes[root->data] = cod;
//		return;
//	}
//	generatehuffmancode(root->left, codes, cod + "0");
//	generatehuffmancode(root->right, codes, cod + "1");
//}
//int main()
//{
//	string text = "The definition of heap is that it is a complete binary tree that conforms to the heap order";
//	vector<node*>nodes;
//	int length = text.length();
//	//calculating frequency of each character
//	for (int i = 0; i < length; i++)
//	{
//		bool found = false;
//		for (int j = 0; j < nodes.size(); j++)
//		{
//			node* nod = nodes[j];
//			if (nod->data == text[i])
//			{
//				nod->frequency++;
//				found = true;
//				break;
//			}
//		}
//		if (found == false)
//		{
//			node* nod = new node();
//			nod->data = text[i];
//			nod->frequency = 1;
//			nodes.push_back(nod);
//		}
//	}
//	//sorting
//	for (int i = 0; i < nodes.size(); i++)
//	{
//		for (int j = 0; j < nodes.size(); j++)
//		{
//			if (nodes[i]->frequency > nodes[j]->frequency)
//			{
//				swap(nodes[i], nodes[j]);
//			}
//		}
//	}
//	//generate huffman tree
//	node* root = buildhuffmantree(nodes);
//	cout << "Inorder traversal of huffman tree:" << endl;
//	print(root);
//	cout << "\n------------------------------------------------------------------------" << endl;
//	//generate huffman codes for each character
//	string codes[256];
//	generatehuffmancode(root, codes);
//	cout << "Huffman codes for each character:" << endl;
//	for (int i = 0; i < 256; i++)
//	{
//		if (!codes[i].empty())
//		{
//			cout << "Character '" << static_cast<char>(i) << "' Code: " << codes[i] << endl;
//		}
//	}
//	cout << "------------------------------------------------------------------------" << endl;
//	cout << "Encoded string:" << endl;
//	for (int i = 0; i < length; i++)
//	{
//		cout << codes[text[i]];
//	}
//	cout << "\n------------------------------------------------------------------------" << endl;
//}