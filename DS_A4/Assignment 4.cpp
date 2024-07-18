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
	Node<T>* left;
	Node<T>* right;
public:
	Node()
	{
		keyword = " ", url = " ";
		left = NULL, right = NULL;
	}
	Node(string k,string u)
	{
		keyword = k, url = u, left = NULL, right = NULL;
	}
	void display()
	{
		int count = 1;
		for (int i=0;url[i] != '\0';i++)
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
	void insert(Node<T>*& root, string link, string word)
	{
		if (root == NULL)
		{
			root = new Node<T>(word, link);
		}
		else if (word < root->getkeyword())
		{
			insert(root->getleft(), link, word);
		}
		else if (word > root->getkeyword())
		{
			insert(root->getright(), link, word);
		}
		else
		{
			if (root->geturl().find(link) == -1)
			{
				root->updateurl(link);
			}
		}
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
	Node<T>* deleted(Node<T>*root,string search)
	{	
		if (root == NULL)
		{
			return root;
		}
		if (root->getkeyword() > search)
		{
			root->setleft(deleted(root->getleft(), search));
			return root;
		}
		else if (root->getkeyword() < search)
		{
			root->setright(deleted(root->getright(), search));
			return root;
		}
		if (root->getleft() == NULL) 
		{
			Node<T>* temp = root->getright();
			delete root;
			return temp;
		}
		else if (root->getright() == NULL) 
		{
			Node<T>* temp = root->getleft();
			delete root;
			return temp;
		}
		else
		{
			Node<T>* successor = root;
			Node<T>* child = root->getright();
			while (child->getleft() != NULL)
			{
				successor = child;
				child = child->getleft();
			}
			if (successor != root)
			{
				successor->setleft( child->getright());
			}
			else
			{
				successor->setright(child->getright());
			}
			delete root;
			return child;
		}

	}
	bool loadfile(string f)
	{
		ifstream read;
		read.open(f + ".txt");
		if (read.fail())
		{
			return 0;
		}
		string find,link,line,word;
		while (!read.eof())
		{
			read >> find;
			getline(read, link);
			getline(read, line);
			for (int i = 0; line[i] != '\0'; i++)
			{
				if (line[i] == ' ')
				{
					insert(root,link, word);
					 word.clear();
				}
				else
				{
					word=word+ line[i];
				}
			}
		}
		read.close();
		return 1;
	}
};
using namespace std;
int main()
{
	BST<int>engine;
	string file;
	int choice = 1, menu;
	string search;
	cout << "Please enter a filename:";
	cin >> file;
	if (engine.loadfile(file))
	{
     	cout << "File loaded successfully" << endl;
		cout << "------------------------------------------" << endl;
		while (choice == 1)
		{
			cout << "Code    Function" << endl;
			cout << "1.    Find Node" << endl;
			cout << "2.    Delete Node" << endl;   
			cout << "Enter your choice:";
			cin >> menu;
			while (menu != 1 && menu != 2)
			{
				cout << "Invalid input! Please enter the correct code:";
				cin >> menu;
			}
			if (menu == 1)
			{
				cout << "Enter the keyword to find:";
				cin >> search;
				engine.find(engine.getroot(),search);
			}
			else if (menu == 2)
			{
				cout << "Enter the keyword to delete:";
				cin >> search;
				engine.deleted(engine.getroot(),search);
				cout << "The node has been deleted!" << endl;
			}
			cout << "------------------------------------------" << endl;
			cout << "To perform another operation press 1:";
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