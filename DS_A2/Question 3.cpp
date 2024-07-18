//#include<iostream>
//using namespace std;
//template <typename T>
//class Node
//{
//private:
//	T data;
//	Node<T>* next;
//public:
//	//default constructor
//	Node()
//	{
//		data = 0, next = NULL;
//	}
//	//parameterized constructor
//	Node(const T& d, Node<T>* n)
//	{
//		data = d, next = n;
//	}
//	//getters and setters
//	void setdata(const T& d)
//	{
//		data = d;
//	}
//	T getdata()
//	{
//		return data;
//	}
//	void setnext(Node<T>* n)
//	{
//		next = n;
//	}
//	Node<T>* getnext()
//	{
//		return next;
//	}
//};
//template <typename T>
//class Undostack
//{
//private:
//	int size;
//	Node<T>* head;
//	Node<T>* current;
//public:
//	//default constructor
//	Undostack()
//	{
//		size = 0, head = NULL, current = NULL;
//	}
//	//parameterized constructor
//	Undostack(int s, Node<T>* h, Node<T>* c)
//	{
//		size = s, head = h, current = c;
//	}
//	bool isempty()
//	{
//		if (size == 0)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	void print()
//	{
//		if (isempty())
//		{
//			cout << "The stack is empty!" << endl;
//			return;
//		}
//		cout << "Elements in the stack are:" << endl;
//		//creating temporary node pointer so that original pointer is not dislocated
//		Node<T>* temp = current;
//		while (temp != NULL)
//		{
//			cout << temp->getdata() << " ";
//			temp = temp->getnext();
//		}
//		cout << endl;
//		//deleting temporary pointer
//		delete temp;
//	}
//	void push(int element)
//	{
//		if (size < 100)
//		{
//			Node<T>* newnode = new Node<T>(element, current);
//			current = newnode;
//			if (isempty())
//			{
//				//storing the first node in head pointer
//				head = newnode;
//			}
//			size++;
//		}
//		else
//		{
//			//poping the first pushed element
//			Node<T>* temp = current;
//			while (temp->getnext() != head)
//			{
//				temp = temp->getnext();
//			}
//			temp->setnext(NULL);
//			delete head;
//			head = temp;
//			//pushing the new node in the stack
//			Node<T>* newnode = new Node<T>(element, current);
//			current = newnode;
//		}
//	}
//	void pop()
//	{
//		if (isempty())
//		{
//			cout << "The stack is empty!" << endl;
//			return;
//		}
//		//deleting the first pushed node
//		//creating temporary node pointer so that actual one is not disloacted
//		Node<T>* temp = current;
//		current = current->getnext();
//		delete temp;
//		//updating the size
//		size--;
//		cout << "The element has been poped successfully!" << endl;
//	}
//};
////function to ask option from user
//int menu()
//{
//	int ch;
//	cout << "Code   Function" << endl;
//	cout << "1.    Push the element(s)" << endl;
//	cout << "2.    Pop the element" << endl;
//	cout << "3.    Print the stack" << endl;
//	cout << "---------------------------------------------" << endl;
//	cout << "Enter your choice:";
//	cin >> ch;
//	while (ch < 1 || ch>3)
//	{
//		cout << "Enter the valid choice (1-3):";
//		cin >> ch;
//	}
//	return ch;
//}
//int main()
//{
//	Undostack<int> stack;
//	int ch,num,element;
//	char hint = ' ';
//	do
//	{
//		ch = menu();
//		if (ch == 1)
//		{
//			cout << "Enter the number of elements to add:";
//			cin >> num;
//			while (num < 0)
//			{
//				cout << "Enter number greater than 0:";
//				cin >> num;
//			}
//			while (num > 0)
//			{
//				cout << "Enter the element to add:";
//				cin >> element;
//				stack.push(element);
//				num--;
//			}
//
//			cout << "The element(s) has been pushed successfully!" << endl;
//			cout << "---------------------------------------------" << endl;
//		}
//		else if (ch == 2)
//		{
//			stack.pop();
//			cout << "---------------------------------------------" << endl;
//		}
//		else if (ch == 3)
//		{
//			stack.print();
//			cout << "---------------------------------------------" << endl;
//		}
//		cout << "To perform another operation press'y':";
//		cin >> hint;
//		cout << "---------------------------------------------" << endl;
//	} while (hint == 'y' || hint == 'Y');
//	//handling the terminating condition
//	if (hint != 'y' && hint != 'Y')
//	{
//		cout << "The program has been terminated!" << endl;
//		cout << "---------------------------------------------" << endl;
//	}
//  //Amina Akhtar 22L-6198 BSE-3B
//}