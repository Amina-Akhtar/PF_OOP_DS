//#include<iostream>
//using namespace std;
//template<typename T>
//class Node
//{
//private:
//    T data;
//    Node<T>* next;
//public:
//    Node()
//    {
//        data = 0;
//        next = NULL;
//    }
//    Node(T d, Node<T>* n = NULL)
//    {
//        data = d;
//        next = n;
//    }
//    T getdata()
//    {
//        return data;
//    }
//    void setdata(T d)
//    {
//        data = d;
//    }
//    Node<T>* getnext()
//    {
//        return next;
//    }
//    void setnext(Node<T>* n)
//    {
//        next = n;
//    }
//};
//template <typename T>
//class Queue
//{
//private:
//    Node<T>* front;
//    Node<T>* rear;
//    int size;
//public:
//    Queue()
//    {
//        front = NULL, rear = NULL, size = 0;
//    }
//    void enqueue(const T& data)
//    {
//        Node<T>* newNode = new Node<T>(data);
//        if (rear != NULL)
//        {
//            rear->setnext(newNode);
//        }
//        else
//        {
//            front = newNode;
//        }
//        newNode->setnext(NULL);
//        rear = newNode;
//        size++;
//    }
//    T dequeue()
//    {
//        if (front != NULL)
//        {
//            Node<T>* p = front;
//            T q = front->getdata();
//            front = front->getnext();
//            delete p;
//            size--;
//            //if only element in queue was deleted
//            if (front == NULL)
//            {
//                rear = NULL;
//            }
//            return q;
//        }
//        else
//        {
//            cout << "The queue is empty!" << endl;
//            return 0;
//            //return T() returns default value
//        }
//    }
//    void print()
//    {
//        Node<T>* temp = front;
//        //prints queue from front to rear
//        if (temp == NULL)
//        {
//            cout << "The queue is empty!" << endl;
//            return;
//        }
//        cout << "Winner: ";
//        while (temp != NULL)
//        {
//            cout << temp->getdata();
//            if (temp->getnext() != NULL)
//            {
//                cout << " , ";
//            }
//            temp = temp->getnext();
//        }
//        cout << endl;
//    }
//    void getwinner(int k)
//    {
//        while (front != rear)
//        {
//            for (int i = 1; i < k; i++)
//            {
//                this->enqueue(this->dequeue());
//            }
//            this->dequeue();
//        }
//    }
//};
//int main()
//{
//    Queue<int>q;
//    int n, k;
//    cout << "Enter the number of players:";
//    cin >> n;
//    while (n <= 0)
//    {
//        cout << "Enter number of players greater than 0:";
//        cin >> n;
//    }
//    cout << "Enter the value to rotate:";
//    cin >> k; 
//    while (k < 0)
//    {
//        cout << "Enter value greater than 0:";
//        cin >> k;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        q.enqueue(i);
//    }
//    cout << "Players added successfully!" << endl;
//    q.getwinner(k);
//    q.print();
//    system("pause");
//    return 0;
//}