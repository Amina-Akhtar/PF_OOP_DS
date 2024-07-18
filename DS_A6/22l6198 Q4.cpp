#include<iostream>
#include<string>
#include <list>
using namespace std;
class ChainingHashTable
{
private:
    int TableSize = 10;
    list<string> table[10];
public:
    ChainingHashTable()
    {}
    int hashCode(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            sum = sum + s[i];
        }
        return sum % TableSize;
    }
    void insert(string key) 
    {
        int index = hashCode(key);
        table[index].push_back(key);
    }
    void print()
    {
        for (int i = 0; i < TableSize; i++) 
        {
            if (!table[i].empty())
            {
                cout << "Bucket " << i << ": ";
                for (auto j = table[i].begin(); j != table[i].end(); j++)
                {
                    cout << *j << " ";
                }
                cout << endl;
            }
        }
    }
};

class OpenAddressingHashTable 
{
private:
    int TableSize = 17;
    string* table;
public:
    OpenAddressingHashTable()
    {
        table = new string[TableSize];
        for (int i = 0; i < TableSize; i++)
        {
            table[i] = " ";
        }
    }
    int hashCode(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum = sum + s[i];
        }
        return sum % TableSize;
    }
    void insert(string key)
    {
        int collision = 0;
        int index = hashCode(key);
        while (table[index] != " ")
        {
            index = (index + 1) % TableSize;
            collision++;
        }
        table[index] = key;
    }
    void print()
    {
        for (int i = 0; i < TableSize; i++) 
        {
            if (table[i]!=" ")
            {
                cout << "Bucket: " << i << " Data:"<<table[i] << endl;
            }
        }
    }
};

int main()
{
	string data[10] = {"Dijkstra","Kosaraju","Turing","Lovelace","Knuth",
        "Backus","Neumann","Shannon","Church","Chomsky"};
    ChainingHashTable chaining;
    cout << "Separate Chaining Hash Table:\n" << endl;
    for (int i = 0;i < 10;i++)
    {
        chaining.insert(data[i]);
        chaining.print();
        cout << "---------------------------------------------------" << endl;
    }
    OpenAddressingHashTable openAddress;
    cout << "\nOpen Addressing Hash Table with Linear Probing:\n" << endl;
    for (int i = 0; i < 10; i++)
    {
        openAddress.insert(data[i]);
        openAddress.print();
        cout << "---------------------------------------------------" << endl;
    }
}