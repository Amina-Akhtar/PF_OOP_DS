#pragma once
#include<Windows.h>
#include<iostream>
using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;


template<typename T>
public ref class Node
{
private:
    T data;
    Node<T>^ next;
public:
    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(T d, Node<T>^ n)
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
    Node<T>^getnext()
    {
        return next;
    }
    void setnext(Node<T>^ n)
    {
        next = n;
    }
};
template <typename T>
public ref class queue_data
{
public:
    Node<T>^ front;
    Node<T>^ rear;
    int size;
public:
    queue_data()
    {
        front = nullptr, rear = nullptr, size = 0;
    }
    void enqueue(const T& data)
    {
        Node<T>^ newNode = gcnew Node<T>(data,nullptr);
        if (rear != nullptr)
        {
            rear->setnext(newNode);
        }
        else
        {
            front = newNode;
        }
        newNode->setnext(nullptr);
        rear = newNode;
        size++;
    }
    T dequeue()
    {
        if (front != nullptr)
        {
            Node<T>^ p = front;
            T q = front->getdata();
            front = front->getnext();
            delete p;
            size--;
            //if only element in queue was deleted
            if (front == nullptr)
            {
                rear = nullptr;
            }
            return q;
        }
        else
        {
            return 0;
            //return T() returns default value
        }
    }
    void print()
    {
        Node<T>^ temp = front;
        //prints queue from front to rear
        if (temp == nullptr)
        {
            MessageBox::Show("The queue is empty!");
            return ;
        }
        else
        {
            StreamWriter^ input = gcnew StreamWriter("Random.txt");
            while (temp != nullptr)
            {
                input->WriteLine( temp->getdata());
                temp = temp->getnext();
            }
            input->Close();
        }
    }
    void getwinner(int k)
    {
        for (int i = 1; i < k; i++)
        {
            this->enqueue(this->dequeue());
        }
        this->dequeue();
        print();
    }
    void setfront(int n)
    {
        Node<T>^ temp = front;
        for (int i = 0; i < n; i++)
        {
            temp = temp->getnext();
        }
        front = temp;
    }
};