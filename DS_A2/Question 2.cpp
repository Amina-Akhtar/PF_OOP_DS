//#include<iostream>
//using namespace std;
//template<typename T>
//class Node
//{
//private:
//	T data;
//	Node<T>* next;
//	Node<T>* prev;
//public:
//	//default and parameterized constructors
//	Node()
//	{
//		data = 0, next = NULL, prev = NULL;
//	}
//	Node(T d, Node<T>* n, Node<T>* p)
//	{
//		data = d, next = n, prev = p;
//	}
//	//getters and setters
//	void setdata(T d)
//	{
//		data = d;
//	}
//	void setnext(Node<T>* n)
//	{
//		next = n;
//	}
//	void setprev(Node<T>* p)
//	{
//		prev = p;
//	}
//	T getdata()
//	{
//		return data;
//	}
//	Node<T>* getnext()
//	{
//		return next;
//	}
//	Node<T>* getprev()
//	{
//		return prev;
//	}
//};
//template <typename T>
//class stack
//{
//private:
//	int size, capacity;
//	Node<T>* head;//pointer to first node inserted in stack
//	Node<T>* current;//points to last inserted element in the stack
//	//to keep the check of inverted stack
//	bool flip;
//public:
//	stack(int c = 0)
//	{
//		capacity = c, size = 0, head = NULL, current = NULL, flip = true;
//	}
//	bool isempty()
//	{
//		if (size == 0)
//		{
//			return 0;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	void push(int element)
//	{
//		//if stack is original i.e. that was inserted by user
//		if (flip)
//		{
//			Node<T>* newnode = new Node<T>(element, NULL, NULL);
//			if (current == NULL)
//			{
//				head = newnode;
//				head->setprev(NULL);
//			}
//			else
//			{
//				current->setnext(newnode);
//				newnode->setprev(current);
//			}
//			current = newnode;
//			//to maintain a circular linked list
//			current->setnext(head);
//			head->setprev(current);
//		}
//		//if the stack has been inverted
//		else
//		{
//			Node<T>* newnode = new Node<T>(element, NULL, NULL);
//			newnode->setnext(head);
//			head->setprev(newnode);
//			head = newnode;
//			//making dubly linked list circular
//			current->setnext(head);
//			head->setprev(current);
//		}
//        //updating size
//		size++;
//	}
//	void print()
//	{
//		//if satck is empty
//		if (isempty())
//		{
//			cout << "The stack is empty!" << endl;
//			return;
//		}
//		cout << "Elements in the stack:" << endl;
//		//if stack is original i.e. inerted by user
//		if (flip)
//		{
//			Node<T>* temp = current;
//			do
//			{
//				cout << temp->getdata() << " ";
//				temp = temp->getprev();
//			} while (temp != current);
//			cout << endl;
//		}
//		//if stack has been inverted
//		else
//		{
//			Node<T>* temp = head;
//			do
//			{
//				cout << temp->getdata() << " ";
//				temp = temp->getnext();
//			} while (temp != head);
//			cout << endl;
//		}
//	}
//	void flipstack()
//	{
//		//Actual reversing the list is done in O(n)
//		//to do it in O(1) there is a check that if stack is inverted
//		//flip(true) means stack is original and flip (false) means stack has been inverted
//		if (flip)
//		{
//			flip = false;
//		}
//		else
//		{
//			flip = true;
//		}
//	}
//	void pop()
//	{
//		//stack is original i.e. inserted by user
//		if (flip)
//		{
//			Node<T>* temp = current;
//			//updating cuurent pointer for further use
//			current = current->getprev();
//			current->setnext(temp->getnext());
//			temp->getnext()->setprev(current);
//			delete temp;
//		}
//		//stack has been reversed
//		else
//		{
//			Node<T>* temp = head;
//			//updating headpointer for further use
//			head = head->getnext();
//			head->setprev(current);
//			current->setnext(temp->getnext());
//			delete temp;
//		}
//		//decreasing the size
//		size--;
//	}
//	void resize()
//	{
//		int cap;//check for capacity which is distinct for even and odd
//		if (capacity % 2 == 0)
//		{
//			cap = capacity / 2;
//		}
//		else
//		{
//			cap = (capacity / 2) + 1;
//		}
//		if (size == capacity)
//		{
//			//stack is full so increasing the size by double
//			capacity *= 2;
//		}
//		else if (size < cap)
//		{
//			//more than half of stack is empty so reducing the size by half
//			capacity /= 2;
//		}
//	}
//};
// int menu()
//{
//	int ch;
//	cout << "Code   Function" << endl;
//	cout << "1.    Push the element(s)" << endl;
//	cout << "2.    Pop the element" << endl;
//	cout << "3.    Flip the stack" << endl;
//	cout << "4.    Print the stack" << endl;
//	cout << "---------------------------------------------" << endl;
//	cout << "Enter your choice:";
//	cin >> ch;
//	//handling invalid input
//	while (ch < 1 || ch>4)
//	{
//		cout << "Enter the valid choice (0-4):";
//		cin >> ch;
//	}
//	return ch;
//}
//int main()
//{
//	int cap;
//	//initial capacity of stack as user input
//	cout << "Enter the capacity of stack:";
//	cin >> cap;
//	stack<int>s(cap);
//	int ch, num, element;
//		char hint = ' ';
//		do
//		{
//			ch = menu();
//			if (ch == 1)
//			{
//				cout << "Enter the number of elements to add:";
//				cin >> num;
//				while (num < 0)//handling invalid input
//				{
//					cout << "Enter the element from greater than 0:";
//					cin >> num;
//				}
//				while (num > 0)
//				{
//					cout << "Enter the element:";
//					cin >> element;
//					s.push(element);
//					num--;
//					s.resize();
//				}
//				cout << "The element(s) has been pushed successfully!" << endl;
//				cout << "---------------------------------------------" << endl;
//			}
//			else if (ch == 2)
//			{
//				if (s.isempty())
//				{
//					cout << "The stack is empty!" << endl;
//				}
//				else
//				{
//					s.pop();
//					cout << "The element has been poped successfully!" << endl;
//				}
//				cout << "---------------------------------------------" << endl;
//			}
//			else if (ch == 3)
//			{
//				s.flipstack();
//				cout << "the stack has been fliped successfully!" << endl;
//				cout << "---------------------------------------------" << endl;
//				s.print();
//					cout << "---------------------------------------------" << endl;
//
//			}
//			else if (ch == 4)
//			{
//				s.print();
//				cout << "---------------------------------------------" << endl;
//			}
//			//continuity of functions
//			cout << "To perform another operation press'y':";
//			cin >> hint;
//			cout << "---------------------------------------------" << endl;
//		} while (hint == 'y' || hint == 'Y');
//		//handling the terminating condition
//		if (hint != 'y' && hint != 'Y')
//		{
//			cout << "The program has been terminated!" << endl;
//			cout << "---------------------------------------------" << endl;
//		}
//		//Amina Akhtar 22L-6198 BSE-3B
//	}