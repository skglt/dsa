//dijstra's algorithm

#include<bits/stdc++.h>
using namespace std;

template<typename t>

class graph
{
    unordered_map<t,list<pair<t,int>>> m;

    public:

    void addEdge(t u,t v,int distance,bool bidirectional=true)
    {
        m[u].push_back(make_pair(v,distance));
        if(bidirectional)
        {
            m[v].push_back(make_pair(u,distance));
        }
    }
    
    void print()
    {
        for(auto x:m)
        {
            cout<<x.first<<"->";
            for(auto z:x.second)
            {
                cout<<" ("<<z.first<<","<<z.second<<") ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void dijsktra(t source)
    {
        unordered_map<t,int> dist;
        for(auto x:m)
        {
            dist[x.first]=INT_MAX;
        }
        dist[source]=0;
        set<pair<int,t>> s;
        s.insert(make_pair(0,source));
        while(!s.empty())
        {
            auto p = *(s.begin());
            t node=p.second;
            int nodedistance=p.first;
            s.erase(s.begin());
            for(auto child:m[node])
            {
                if(nodedistance + child.second < dist[child.first])
                {
                    t destination = child.first;
                    auto zz = s.find(make_pair(dist[destination],destination));
                    if(zz!=s.end())
                    {
                        s.erase(zz);
                    }
                    dist[destination]=nodedistance + child.second;
                    s.insert(make_pair(dist[destination],destination));
                }
            }
        }
        for(auto d:dist){
            
            cout<<d.first<<" is located at distance of  "<<d.second<<endl;
        }
    }

};


int main()
{
    graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    // india.print();
    india.dijsktra("Amritsar");
    return 0;
}






























//travelling salesman problem

#include<bits/stdc++.h>
using namespace std;
int n=4;
int visited=(1<<n)-1;
int dist[4][4] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};


int tsp(int bitmask,int pos)
{
    if(bitmask==visited)
    {
        return dist[pos][0];
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(((1<<i) & bitmask)==0)
        {
            int newans = dist[pos][i] + tsp((1<<i)|bitmask,i);
            ans = min ( ans,newans );
        }
    }
    return ans;
}


int main()
{
    cout<<" The minimum distance is "<<tsp(2,2);
    return 0;
}


























//floodfill algorithm

#include<bits/stdc++.h>
using namespace std;

void floodfill(int screen[][8],int r, int c,int m,int n)
{
    if(r<0||c<0||r>=8||c>=8||screen[r][c]!=m)
    {
        return ;
    }
    screen[r][c]=n;
    floodfill(screen,r,c+1,m,n);
    floodfill(screen,r+1,c,m,n);
    floodfill(screen,r,c-1,m,n);
    floodfill(screen,r-1,c,m,n);
}

int main()
{
    int screen[8][8]={{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}};
    int r=4,c=4,n=6;
    int m=screen[r][c];
    floodfill(screen,r,c,m,n);
    for(int i=0;i<8;i++)
    {
        for(auto j=0;j<8;j++)
        {
            cout<<screen[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



























//snake and ladder

#include<bits/stdc++.h>
using namespace std;

class graph
{
    int v;
    list<int> *adjlist;
    public:
    graph(int x)
    {
        v=x;
        adjlist = new list<int>[v];
    }
    void addedge(int u, int v, bool bidirectional=true)
    {
        adjlist[u].push_back(v);
        if(bidirectional)
        {
            adjlist[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i=0;i<v;i++)
        {
            cout<<i;
            for(auto x:adjlist[i])
            {
                cout<<"->"<<x;
            }
            cout<<endl;
        }
    }
    void bfs(int x,int destination)
    {
        queue<int> q;
        bool *visited = new bool[v]{0};
        int *distance = new int[v]{0};
        int *parent = new int[v] ;
        for(auto i=0;i<v;i++)
        {
            parent[i]=-1;
        }
        q.push(x);
        visited[x]=true;
        while(!q.empty())
        {
            int z= q.front();
            q.pop();
            cout<<z<<" ";
            for(auto p:adjlist[z])
            {
                if(!visited[p])
                {
                    q.push(p);
                    visited[p]=true;
                    distance[p]=distance[z]+1;
                    parent[p]=z;
                }
            }
        }
        cout<<endl;
        int temp=destination;
        while(temp!=-1)
        {
            cout<<temp<<"<-";
            temp=parent[temp];
        }
    }
};


int main()
{
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    graph g(50);
    for(auto u=0;u<36;u++)
    {
        for(auto dice=1;dice<=6;dice++)
        {
            int v=u+dice+board[u+dice];
            if(v<=36)
            g.addedge(u,v,false);
        }
    }
    g.bfs(0,36);
    return 0;
}
































//shortest path

#include<bits/stdc++.h>
using namespace std;

class graph
{
    int v;
    list<int> *adjlist;
    public:
    graph(int x)
    {
        v=x;
        adjlist = new list<int>[v];
    }
    void addedge(int u,int v,bool bidirectional=true)
    {
        adjlist[u].push_back(v);
        if(bidirectional )
        {
            adjlist[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i=0;i<v;i++)
        {
            cout<<i<<" ";
            for(auto x:adjlist[i])
            {
                cout<<"->"<<x;
            }
            cout<<endl;
        }
    }
    void bfs(int x,int destination)
    {
        queue<int> q;
        bool *visited = new bool[v]{0};
        int *distance = new int[v]{0};
        int *parent = new int[v];
        for(auto i=0;i<v;i++)
        {
            parent[i]=-1;
        }
        q.push(x);
        visited[x]=true;
        while(!q.empty())
        {
            int z=q.front();
            q.pop();
            cout<<z<<" ";
            for(auto p:adjlist[z])
            {
                if(!visited[p])
                {
                    q.push(p);
                    visited[p]=true;
                    distance[p] = distance[z]+1;
                    parent[p]=z;
                }
            }
        }
        cout<<endl;
        for(auto i=0;i<v;i++)
        {
            cout<<distance[i]<<" ";
        }
        cout<<endl;
        int temp=destination;
        while(temp!=-1)
        {
            cout<<temp<<"<-";
            temp=parent[temp];
        }
    }

};



int main()
{
    graph g(6);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(1,2);
    g.addedge(2,4);
    g.addedge(3,2);
    g.addedge(2,3);
    g.addedge(3,5);
    g.addedge(4,3);
    g.bfs(0,5);
    return 0;
}






















//breadth first search

#include<bits/stdc++.h>
using namespace std;

class graph
{
    int v;
    list<int> *adjlist;
    public:
    graph(int x)
    {
        v=x;
        adjlist = new list<int>[v];
    }
    void addedge(int u, int v,bool bidirectional = true)
    {
        adjlist[u].push_back(v);
        if(bidirectional)
        {
            adjlist[v].push_back(v);
        }
    }
    void print()
    {
        for(auto i=0;i<v;i++)
        {
            cout<<i<<" ";
            for(auto x:adjlist[i])
            {
                cout<<"->"<<x;
            }
            cout<<endl;
        }
    }
    void bfs(int x)
    {
        queue<int> q;
        bool *visited = new bool[v]{0};
        q.push(x);
        visited[x]=true;
        
        while(!q.empty())
        {
            int z=q.front();
            q.pop();
            cout<<z<<" ";
            for(auto p:adjlist[z])
            {
                if(!visited[p])
                {
                    q.push(p);
                    visited[p]=true;
                }
            }
        }
    }
};



int main()
{
    graph g(6);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(1,2);
    g.addedge(2,4);
    g.addedge(3,2);
    g.addedge(2,3);
    g.addedge(3,5);
    g.addedge(4,3);
    g.bfs(0);
    return 0;
}





















#include<bits/stdc++.h>
#include<map>
#include<cstring>
#include<list>
using namespace std;

template<typename t>
class graph
{
    map<t,list<t>> adjlist;

    public:
    graph()
    {

    }
    void addedge(t u, t v, bool bidirectional=true)
    {
        adjlist[u].push_back(v);
        if(bidirectional)
        {
            adjlist[v].push_back(u);
        }
    }
    void print()
    {
        for(auto x:adjlist)
        {
            cout<<x.first<<" ";
            for(auto z : x.second)
            {
                cout<<"->"<<z;
            }
            cout<<endl;
        }
    }
};


int main()
{
    graph<string> g;
    g.addedge("delhi","siachen");
    g.addedge("delhi","banglore");
    g.addedge("delhi","agra");
    g.addedge("amritsar","delhi");
    g.addedge("amritsar","jaipur");
    g.addedge("amritsar","siachen");

    g.print();
    return 0;
}





















#include<bits/stdc++.h>
using namespace std;


class graph
{
    int v;
    list<int> *adjlist;
    public:
    graph(int x)
    {
        v=x;
        adjlist = new list<int>[v];
    }
    void addedge(int u, int v, bool bidirectional=true)
    {
        adjlist[u].push_back(v);
        if(bidirectional)
        {
            adjlist[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i=0;i<v;i++)
        {
            cout<<i;
            for(auto x:adjlist[i])
            {
                cout<<"->"<<x;
            }
            cout<<endl;
        }
    }
};


int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(0,3);
    g.addedge(1,3);
    g.addedge(3,2);

    g.print();
    return 0;
}
