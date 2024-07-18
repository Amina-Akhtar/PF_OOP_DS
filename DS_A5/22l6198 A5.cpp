#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<typename T>
class Node
{
private:
	string keyword;
	string url;
	int height;
	Node<T>* left;
	Node<T>* right;
public:
	Node()
	{
		keyword = " ", url = " ", height = 1;
		left = NULL, right = NULL;
	}
	Node(string k, string u)
	{
		keyword = k, url = u,height=1, left = NULL, right = NULL;
	}
	void display()
	{
		cout <<"Keyword: "<< keyword << endl;
		for (int i = 0; url[i] != '\0'; i++)
		{
			if (url[i] == ' ')
			{
				cout << endl;
			}
			else
			{
				cout << url[i];
			}
		}
		cout << endl;
	}
	void updateurl(string u)
	{
		url = url + " " + u;
	}
	string getkeyword()
	{
		return keyword;
	}
	string geturl()
	{
		return url;
	}
	void setleft(Node<T>* l)
	{
		left = l;
	}
	Node<T>*& getleft()
	{
		return left;
	}
	void setright(Node<T>* r)
	{
		right = r;
	}
	Node<T>*& getright()
	{
		return right;
	}
	void setheight(int h)
	{
		height = h;
	}
	int getheight()
	{
		return height;
	}
};

template<typename T>
class BST
{
private:
	Node<T>* root;
public:
	BST()
	{
		root = NULL;
	}
	Node<T>* getroot()
	{
		return root;
	}
	int height(Node<T>* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		return node->getheight();
	}
	int balanceFactor(Node<T>* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		return height(node->getleft()) - height(node->getright());
	}
	void updateHeight(Node<T>* node)
	{
		if (node != NULL)
		{
			node->setheight(1 + max(height(node->getleft()), height(node->getright())));
		}
	}
	Node<T>* insert(Node<T>*& root, string link, string word)
	{
		if (root == NULL)
		{
			return new Node<T>(word, link);
		}
		else if (word < root->getkeyword())
		{
			root->setleft(insert(root->getleft(), link, word));
		}
		else if (word > root->getkeyword())
		{
			root->setright(insert(root->getright(), link, word));
		}
		else
		{
			if (root->geturl().find(link) == -1)
			{
				root->updateurl(link);
			}
			return root;
		}
		updateHeight(root);
		int balance = balanceFactor(root);
		if (balance > 1)
		{
			if (word < root->getleft()->getkeyword())
			{
				return rotateRight(root);
			}
			else
			{
				root->setleft(rotateLeft(root->getleft()));
				return rotateRight(root);
			}
		}
		if (balance < -1)
		{
			if (word > root->getright()->getkeyword())
			{
				return rotateLeft(root);
			}
			else
			{
				root->setright(rotateRight(root->getright()));
				return  rotateLeft(root);
			}
		}
		return root;
	}
	void find(Node<T>* root, string search)
	{
		while (root != NULL)
		{
			if (search < root->getkeyword())
			{
				root = root->getleft();
			}
			else if (search > root->getkeyword())
			{
				root = root->getright();
			}
			else
			{
				root->display();
				return;
			}
		}
		cout << "No results found!" << endl;
	}
	bool loadfile(string f)
	{
		ifstream read;
		read.open(f + ".txt");
		if (read.fail())
		{
			return 0;
		}
		string find, link, line, word;
		while (!read.eof())
		{
			read >> find;
			getline(read, link);
			getline(read, line);
			for (int i = 0; line[i] != '\0'; i++)
			{
				if (line[i] == ' ')
				{
					root=insert(root, link, word);
					word.clear();
				}
				else
				{
					word = word + line[i];
				}
			}
		}
		read.close();
		return 1;
	}
	Node<T>* rotateLeft(Node<T>* z)
	{
		Node<T>* y = z->getright();
		Node<T>* T2 = y->getleft();
		y->setleft(z);
		z->setright(T2);
		updateHeight(z);
		updateHeight(y);
		return y;
	}
	Node<T>* rotateRight(Node<T>* y)
	{
		Node<T>* x = y->getleft();
		Node<T>* T2 = x->getright();
		x->setright(y);
		y->setleft(T2);
		updateHeight(y);
		updateHeight(x);
		return x;
	}
};
using namespace std;
int main()
{
	BST<int>engine;
	string file;
	int choice = 1;
	string search;
	cout << "Please enter a filename:";
	cin >> file;
	if (engine.loadfile(file))
	{
		cout << "File loaded successfully" << endl;
		cout << "------------------------------------------" << endl;
		while (choice == 1)
		{
			cout << "Enter the keyword to find:";
			cin >> search;
			engine.find(engine.getroot(), search);
			cout << "------------------------------------------" << endl;
			cout << "To find another key press 1:";
			cin >> choice;
			cout << "------------------------------------------" << endl;
		}
		if (choice != 1)
		{
			cout << "The program has been terminated!" << endl;
			cout << "------------------------------------------" << endl;
		}
	}
	else
	{
		cout << "File load unsuccessfull" << endl;
	}

}