#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<typename T>
class Node
{
private:
	T data;
	Node<T>* next;
public:
	Node()
	{
		data = 0, next = NULL;
	}
	Node(T d, Node<T>* n)
	{
		data = d, next = n;
	}
	void setdata(T d)
	{
		data = d;
	}
	void setnext(Node<T>* n)
	{
		next = n;
	}
	T getdata()
	{
		return data;
	}
	Node<T>* getnext()
	{
		return next;
	}
};
class XMLData
{
private:
	string value;
	int line;
public:
	XMLData()
	{
		value = " ", line = 0;
	}
	string getvalue()
	{
		return value;
	}
	int getline()
	{
		return line;
	}
	void setline(int no)
	{
		line = no;
	}
	void setvalue(string v)
	{
		value = v;
	}
};

template<typename T>
class stack
{
private:
	Node<T>* top;
public:
	stack()
	{
		top = NULL;
	}
	bool isempty()
	{
		if (top == NULL)
		{
			return true;
		}
		else {
			return false;
		}
	}
	Node<T>* gettop()
	{
		return top;
	}
	void push(const T& v)
	{
		Node<T>* newnode = new Node<T>(v, NULL);
		newnode->setnext(top);
		top = newnode;
	}
	void pop()
	{
		if (isempty())
		{
			return;
		}
		else
		{
			Node<T>* temp = top;
			top = top->getnext();
			delete temp;
		}
	}
	void checkattribute()//function to identify errors from xml file
	{
		XMLData temp;
		ifstream read;
		string info, tag;
		int count = 1;
		read.open("Input.txt");
		//reading the input file linewise and checking for errors
		while (!read.eof())
		{
			int oab = -1, cab = -1, hint = 0;
			getline(read, info, '\n');
			oab = info.find('<');
			cab = info.find('>');
			int size = info.size();
			if (count == 1)
			{
				//check for xml file header
				if (oab == -1 || cab == -1)
				{
					cout << "ERROR! Tag Prolog header <? missing on line 1" << endl;
				}
				else if (info[oab + 1] == '?' && info[cab - 1] == '?')
				{
				}
			}
			else
			{
				//check for balancing of comments
				if (info[oab + 1] == '!')
				{
					if (info[oab + 2] == '-' && info[oab + 3] == '-' && info[cab - 1] == '-' && info[cab - 2] == '-')
					{
					}
					else if ( info[oab + 2] == '-' || info[oab + 3] == '-' || info[cab - 1] == '-' || info[cab - 2] == '-')
					{
						cout << "ERROR! Comment tag <!-- missing on line " << count << endl;
					}
				}
				else 
				{
				//check for balancng of tags
				int j = 0, space = -1;
				for (int i = 0; i < size; i++)
				{
					if (info[i] == '<')
					{
						if (info[i + 1] != '/')//opening tag found
						{
							//retrieving the opening tag
							j = i + 1;
							while (info[j] != '>')
							{
								j++;
							}
							if (j < size)
							{
								tag = info.substr(i, j - i + 1);
								space = tag.find(' ');
								//excluding the attribute values from tags
								if (space != -1)
								{
									tag = tag.substr(0, space);
									tag = tag + ">";
								}
								//pushing the opening tag to stack
								temp.setline(count);
								temp.setvalue(tag);
								this->push(temp);
							}
						}
						else//closing tag found
						{
							//retrieving the closing tag
							j = i + 2;
							while (info[j] != '>')
							{
								j++;
							}
							if (j < size)
							{
								tag = info.substr(i, j - i + 1);
								tag = "<" + tag.substr(2);
								//poping the opening tag of corresponding closing tag
								if (!this->isempty() && this->gettop()->getdata().getvalue() == tag)
								{
									this->pop();
								}
								else
								{
									//poping the elements from stack until opening tag of corresponding closing tag is not found
									while (!this->isempty())
									{
										if (this->gettop()->getdata().getvalue() == tag)
										{
											this->pop();//poping the opening tag
											break;
										}
										else {
											cout << "ERROR! Tag " << this->gettop()->getdata().getvalue();
											cout << " missing on line " << this->gettop()->getdata().getline() << endl;
											this->pop();
										}
									}
								}
							}
						}
					}
				}
			}

			}
		//check for balancing single and double quotes
		for (int i = 0; i < size; i++) {
			if (info[i] == '"' || info[i] == '\'') {
				hint++;
			}
		}
		if (hint % 2 != 0)
		{
			cout << "ERROR! Quotes ''(') missing on line " << count << endl;
		}
			count++;
		} 
		//printing any mismatched tags at the end
		while (!this->isempty())
		{
			cout << "ERROR! Matching tag " << this->gettop()->getdata().getvalue();
			cout << " missing on line " << this->gettop()->getdata().getline() << endl;
			this->pop();
		}
	}
};
int main()
{
	stack<XMLData>s;
	s.checkattribute();
	//Amina Akhtar BSE-3B 22L-6198
}