#include<iostream>
using namespace std;
template <typename T>
class Node
{
    //node class holding customer attributes
private:
    T items, age;
    Node<T>* next;
public:
    Node()
    {
        items = 0, age = 0;
        next = NULL;
    }
    Node(T i, T a, Node<T>* n = NULL)
    {
        items = i, age = a, next = n;
    }
    T getitems()
    {
        return items;
    }
    void setitems(T i)
    {
        items = i;
    }
    T getage()
    {
        return age;
    }
    void setage(T a)
    {
        age = a;
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
template<typename T>
class Queue
{
    //class for each queue
private:
    Node<T>* front;
    Node<T>* rear;
    int size;
public:
    Queue()
    {
        front = NULL, rear = NULL, size = 0;
    }
    void print()
    {
        Node<T>* temp = front;
        if (temp == NULL)
        {
            cout << "The queue is empty!" << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << "Items: " << temp->getitems() << " Age: " << temp->getage() << endl;
            temp = temp->getnext();
        }
    }
    ~Queue()//destructor
    {
        while (front != NULL)
        {
            Node<T>* temp = front;
            front = front->getnext();
            delete temp;
        }
    }
    void dequeue()
    {
        if (front != NULL)
        {
            Node<T>* p = front;
            front = front->getnext();
            delete p;
            size--;
            if (front == NULL)
            {
                rear = NULL;
            }
        }
        else
        {
            cout << "The queue is empty!" << endl;
            return;
        }
    }
    T getfrontage()//returns age of front customer
    {
        if (front == NULL)
        {
            return 0;
        }
        return this->front->getage();
    }
    T getitems()//returns items number of front customer
    {
        Node<T>* temp = front;
        if (temp == NULL)
        {
            return 0;
        }
        int sum = 0;
        while (temp != NULL)
        {
            sum += this->front->getitems();
            temp = temp->getnext();
        }
        return sum;
    }
    int getsize()//returns size of each queue
    {
        return size;
    }
    void enqueue_rear(const T& i, const T& a)
    {
        //inserts customer at last
        Node<T>* newNode = new Node<T>(i, a);
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
    void enqueue_front(const T& i, const T& a)
    {
        //inserts customer at front
        Node<T>* newNode = new Node<T>(i, a);
        if (front != NULL)
        {
            newNode->setnext(front);
        }
        else
        {
            newNode->setnext(NULL);
            rear = newNode;
        }
        front = newNode;
        size++;
    }
};
int main()
{
    Queue<int>q1, q2, q3, q4;
    char choice;
    int age, items;
    do
    {
        bool flag = false;
        cout << "Do you want to pay your bills (Y/N):";
        cin >> choice;
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            cout << "Enter a valid choice:";
            cin >> choice;
        }
        if (choice == 'n' || choice == 'N')//termination condition
        {
            cout << "The program has been terminated!" << endl;
            cout << "---------------------------------------" << endl;
            break;
        }
        cout << "Please enter how many items do you want to purchase:";
        cin >> items;
        cout << "Please enter your age:";
        cin >> age;
        //condition to get queue with least items
        //using bool variable to check if element has been inserted or not
        if (((q1.getitems() <= q2.getitems()) && (q1.getitems() <= q3.getitems()) && (q1.getitems() <= q4.getitems())) && flag == false)
        {
            if (age > q1.getfrontage())
            {
                q1.enqueue_front(items, age);
                flag = true;
            }
            else if (age < q1.getfrontage())
            {
                q1.enqueue_rear(items, age);
                flag = true;
            }
        }
        if (((q2.getitems() <= q1.getitems()) && (q2.getitems() <= q3.getitems()) && (q2.getitems() <= q4.getitems())) && flag == false)
        {
            if (age > q2.getfrontage())
            {
                q2.enqueue_front(items, age);
                flag = true;
            }
            else if (age < q2.getfrontage())
            {
                q2.enqueue_rear(items, age);
                flag = true;
            }
        }
        if (((q3.getitems() <= q1.getitems()) && (q3.getitems() <= q2.getitems()) && (q3.getitems() <= q4.getitems())) && flag == false)
        {
            if (age > q3.getfrontage())
            {
                q3.enqueue_front(items, age);
                flag = true;
            }
            else if (age < q3.getfrontage())
            {
                q3.enqueue_rear(items, age);
                flag = true;
            }
        }
        if (((q4.getitems() <= q1.getitems()) && (q4.getitems() <= q2.getitems()) && (q4.getitems() <= q3.getitems())) && flag == false)
        {
            if (age > q4.getfrontage())
            {
                q4.enqueue_front(items, age);
                flag = true;
            }
            else if (age < q4.getfrontage())
            {
                q4.enqueue_rear(items, age);
                flag = true;
            }
        }
        //printing the customer in all queues
        cout << "---------------------------------------" << endl;
        cout << "Queue 1:" << endl;
        q1.print();
        cout << "Queue 2:" << endl;
        q2.print();
        cout << "Queue 3:" << endl;
        q3.print();
        cout << "Queue 4:" << endl;
        q4.print();
        cout << "---------------------------------------" << endl;
    } while (choice == 'Y' || choice == 'y');
}