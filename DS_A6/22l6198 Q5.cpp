//#include<iostream>
//#include<list>
//#include<queue>
//using namespace std;
//class graphsearch
//{
//private:
//    int V;
//    list<int>* adj;
//public:
//    graphsearch(int v)
//    {
//        V = v;
//        adj = new list<int>[V];
//    }
//    void addEdgeToGraph(int v, int w)
//    {
//        adj[v - 65].push_back(w - 65);
//        adj[w - 65].push_back(v - 65);
//    }
//    void BFSearch(int s)
//    {
//        bool* visit = new bool[V];
//        for (int i = 0; i < V; i++)
//        {
//            visit[i] = false;
//        }
//        queue<int> q;
//        q.push(s - 65);
//        visit[s - 65] = true;
//        while (!q.empty())
//        {
//            int n = q.front();
//            cout << char(n + 65) << " ";
//            q.pop();
//            for (auto i = adj[n].begin(); i != adj[n].end(); i++)
//            {
//                int a = *i;
//                if (visit[a] == false)
//                {
//                    visit[a] = true;
//                    q.push(a);
//                }
//            }
//        }
//    }
//};
//int main()
//{
//    graphsearch g(6);
//    cout << "The inserted tree is (A,B) (A,C) (B,C) (B,D) (B,E) (D,E) (C,F) (F,E)" << endl;
//    g.addEdgeToGraph('A', 'B');
//    g.addEdgeToGraph('A', 'C');
//    g.addEdgeToGraph('B', 'C');
//    g.addEdgeToGraph('B', 'D');
//    g.addEdgeToGraph('B', 'E');
//    g.addEdgeToGraph('D', 'E');
//    g.addEdgeToGraph('C', 'F');
//    g.addEdgeToGraph('F', 'E');
//    cout << "BFS from A: ";
//    g.BFSearch('A');
//    return 0;
//}