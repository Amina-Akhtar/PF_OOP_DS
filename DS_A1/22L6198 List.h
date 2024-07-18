#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Node {
private:
	T data;
	Node* next;
public:
	Node()
	{
		data = 0;
		next = NULL;
	}
	Node(const T& d, Node* n = NULL)
	{
		data = d;
		next = n;
	}
	T get()
	{
		return data;
	}
	void set(const T& d)
	{
		data = d;
	}
	void setnext(Node* n)
	{
		next = n;
	}
	Node* getnext()
	{
		return next;
	}
};

template <typename T>
class sortedset
{
private:
	int size;
	Node<T>* head;
	Node<T>* tail;
	Node<T>* current;
	Node<T>* lastcurrent;
public:
	sortedset()
	{
		head = new Node <T>();
		tail = current = lastcurrent = NULL;
		size = 0;
	}
	bool check(int data)
	{
		current = head->getnext();
		lastcurrent = head;
		while (current != NULL)
		{
			if (current->get() == data)
			{
				return false;
			}
			current = current->getnext();
			lastcurrent = current;
		}
		return true;
	}
	void insert(int value)
	{
		if (size == 0 || value <= (head->getnext())->get())
		{
			Node<T>* newnode = new Node<T>(value, head->getnext());
			head->setnext(newnode);
			if (size == 0)
			{
				tail = newnode;
			}
			current = newnode;
		}
		else
		{
			Node<T>* newNode = new Node<T>(value, NULL);
			current = head->getnext();
			lastcurrent = head;
			while ((current != NULL) && (value >= current->get()))
			{
				lastcurrent = current;
				current = current->getnext();
			}
			lastcurrent->setnext(newNode);
			newNode->setnext(current);
		}
		size++;
	}
	void delete_element()
	{
		int index;
		cout << "Enter the index to delete:";
		cin >> index;
		if (size == 0)
		{
			cout << "The list is empty!" << endl;
			cout << "-------------------------------------------------------------" << endl;
			return;
		}
		while (index<0 || index>size)
		{
			cout << "Enter the index less than " << size << ":";
			cin >> index;
		}
		current = head->getnext();
		lastcurrent = head;

		int i = 1;
		while (current != NULL)
		{
			if (i == index)
			{
				if (lastcurrent != NULL)
				{
					lastcurrent->setnext(current->getnext());
				}
				else
				{
					head = current->getnext();
				}
				current->setnext(NULL);
				delete current;
				current = lastcurrent->getnext();
				size--;
			}
			else
			{
				lastcurrent = current;
				current = current->getnext();
			}
			i++;
		}
		cout << "Element deleted from the list successfully!" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
	void print()
	{
		current = head->getnext();
		if (current == NULL)
		{
			cout << "The list is empty!" << endl;

			cout << "-------------------------------------------------------------" << endl;
			return;
		}
		cout << "Elements present in the list:" << endl;
		while (current != NULL)
		{
			cout << current->get();
			if (current->getnext() != NULL)
			{
				cout << "->";
			}
			current = current->getnext();
		}
		cout << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
	void union_set(sortedset& otherset)
	{
		sortedset<int> unionSet;
		current = head->getnext();
		otherset.current = otherset.head->getnext();
		while (current != NULL || otherset.current != NULL)
		{
			if (current == NULL)
			{
				unionSet.insert(otherset.current->get());
				otherset.current = otherset.current->getnext();
			}
			else if (otherset.current == NULL)
			{
				unionSet.insert(current->get());
				current = current->getnext();
			}
			else
			{
				T value1 = current->get();
				T value2 = otherset.current->get();

				if (value1 < value2)
				{
					unionSet.insert(value1);
					current = current->getnext();
				}
				else if (value1 > value2)
				{
					unionSet.insert(value2);
					otherset.current = otherset.current->getnext();
				}
				else
				{
					unionSet.insert(value1);
					current = current->getnext();
					otherset.current = otherset.current->getnext();
				}
			}
		}
		unionSet.print();
	}
	void rotate()
	{
		int k;
		cout << "Enter the value to rotate the list: ";
		cin >> k;
		while (k < 1 || k >size)
		{
			cout << "Enter the value from 1 - " << size << ":" << endl;
			cin >> k;
		}
		Node<T>* temp = head->getnext();
		current = head->getnext();
		if (current == NULL)
		{
			cout << "The list is empty!" << endl;

			cout << "-------------------------------------------------------------" << endl;
			return;
		}
		if (k == size)
		{
			goto done;
		}
		lastcurrent = head;
		for (int i = 0; i < k; i++)
		{
			lastcurrent = current;
			current = current->getnext();
		}
		head->setnext(lastcurrent->getnext());
		lastcurrent->setnext(NULL);
		while (current->getnext() != NULL)
		{
			current = current->getnext();
		}
		current->setnext(temp);
	done:
		cout << "List has been rotated successfully!" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
	void reverse()
	{
		Node<T>* previous = NULL;
		current = head->getnext();
		if (current == NULL)
		{
			cout << "The list is empty!" << endl;

			cout << "-------------------------------------------------------------" << endl;
			return;
		}
		Node<T>* next = NULL;
		while (current != NULL)
		{
			next = current->getnext();
			current->setnext(previous);
			previous = current;
			current = next;
		}
		tail = head->getnext();
		head->setnext(previous);
		cout << "Reversed list " << endl;
		print();
	}
	void clear()
	{
		lastcurrent = head;
		current = head;
		while (current != NULL)
		{
			lastcurrent = lastcurrent->getnext();
			current = lastcurrent;
		}
		tail = NULL;
		head->setnext(NULL);
		lastcurrent = NULL;
		current = NULL;
		size = 0;
	}
};