#include <iostream>
#include <cmath>
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
        data = 0;
        next = NULL;
    }
    Node(T d, Node<T>* n = NULL)
    {
        data = d;
        next = n;
    }
    T getdata()
    {
        return data;
    }
    void setdata(T d)
    {
        data = d;
    }
    Node<T>* getnext()
    {
        return next;
    }
    void setnext(Node<T>* n)
    {
        next = n;
    }
};

template <typename T>
class Queue
{
private:
    Node<T>* front;
    Node<T>* rear;
    int size;
public:
    Queue()
    {
        front = NULL, rear = NULL, size = 0;
    }
    void enqueue(const T& data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (rear != NULL)
        {
            rear->setnext(newNode);
        }
        else
        {
            front = newNode;
        }
        newNode->setnext(NULL);
        rear = newNode;
        size++;
    }
    T dequeue()
    {
        if (front != NULL)
        {
            Node<T>* p = front;
            T q = front->getdata();
            front = front->getnext();
            delete p;
            size--;
            //if only element in queue was deleted
            if (front == NULL)
            {
                rear = NULL;
            }
            return q;
        }
        else
        {
            cout << "The queue is empty!" << endl;
            return 0;
            //return T() returns default value
        }
    }
    void print()
    {
        Node<T>* temp = front;
        //prints queue from front to rear
        if (temp == NULL)
        {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "Elements in the queue are:" << endl;
        while (temp != NULL)
        {
            cout << temp->getdata();
            if (temp->getnext() != NULL)
            {
                cout << " , ";
            }
            temp = temp->getnext();
        }
        cout << endl;
    }
    int getdigit(int number, int i)
    {
        //returns the i_th digit of the given number
        return ((number / static_cast<int>(pow(10, i - 1))) % 10);
        //pow return double so typecast it to int
    }
    int getcharacter(string s, int i)
    {
        //returns the ASCII code of ith index of string
        if (i >= 0 && i < s.length())
        {
            return static_cast<int>(s[i]);
        }
        else
        {
            return 0;// returns 0 for shorter strings
        }
    }
    ~Queue()
    {
        //deallocating the memory
        while (front != NULL)
        {
            Node<T>* temp = front;
            front = front->getnext();
            delete temp;
        }
    }
    //sort the queue having integer data
    void radixsort(int number)
    {
        int digits = 0, maximum = 0;
        Node<T>* temp = front;
        //finding the maximum number in the queue
        while (temp != NULL)
        {
            if (temp->getdata() > maximum)
            {
                maximum = temp->getdata();
            }
            temp = temp->getnext();
        }
        //counting its number of digits of maximum number
        while (maximum != 0)
        {
            maximum /= 10;
            digits++;
        }
        //creating an intermediate array to store data sorted on the basis of the i_th digits
        Queue<T> temp_queue[10];
        for (int i = 1; i <= digits; i++)
        {
            while (this->front != NULL)
            {
                T object = this->dequeue();
                int place = getdigit(object, i);
                temp_queue[place].enqueue(object);
            }
            // Concatenate the temporary queues back into the original queue
            for (int j = 0; j < 10; j++)
            {
                while (temp_queue[j].front != NULL)
                {
                    T hint = temp_queue[j].dequeue();
                    this->enqueue(hint);
                }
            }
        }
    }
    //sort the queue having string data
    void radixsort(string word)
    {
        int digits = 0;
        Node<T>* temp = front;
        //finding the maximum length word in the queue
        while (temp != NULL)
        {
            if (temp->getdata().length() > digits)
            {
                digits = temp->getdata().length();
            }
            temp = temp->getnext();
        }
        //creating an intermediate array to store data sorted on the basis of the i_th digits ACSII values
        Queue<T> temp_queue[256];
        for (int i = digits - 1; i >= 0; i--)
        {
            while (front != NULL)
            {
                T item = this->dequeue();
                int place = getcharacter(item, i);
                temp_queue[place].enqueue(item);
            }
            // Concatenate the temporary queues back into the original queue
            for (int j = 0; j < 256; j++)
            {
                while (temp_queue[j].front != NULL)
                {
                    string item = temp_queue[j].dequeue();
                    enqueue(item);
                }
            }
        }
    }
};
int main()
{
    Queue<int> qi;
    Queue<string> qs;
    int menu;
    cout << "Press 1 for integer and 2 for string:";
    cin >> menu;
    while (menu != 1 && menu != 2)
    {
        cout << "Enter valid choice 1-2:";
        cin >> menu;
    }
    int number = 0;
    string word = " ";
    if (menu == 1)
    {
        while (number != -1)
        {
            cout << "Enter the number to add to the queue. To stop, press -1: ";
            cin >> number;
            if (number != -1)
            {
                qi.enqueue(number);
            }
        }
        cout << "Elements added to the queue successfully!" << endl;
        cout << "-------------------------------------------------" << endl;
        qi.print();
        cout << "-------------------------------------------------" << endl;
        cout << "After applying radix sort:" << endl;
        qi.radixsort(number);
        qi.print();
        cout << "-------------------------------------------------" << endl;
    }
    else  if (menu == 2)
    {
        cin.ignore();
        while (word != "-1")
        {
            cout << "Enter the string to add to the queue. To stop, press -1: ";
            getline(cin, word);
            if (word != "-1")
            {
                qs.enqueue(word);
            }
        }
        cout << "Elements added to the queue successfully!" << endl;
        cout << "-------------------------------------------------" << endl;
        qs.print();
        cout << "-------------------------------------------------" << endl;
        cout << "After applying radix sort:" << endl;
        qs.radixsort(word);
        qs.print();
        cout << "-------------------------------------------------" << endl;
    }
    system("pause");
    //Amina Akhtar BSE-3B 22L-6198
}
