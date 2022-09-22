	#include <iostream>
	#include <bits/stdc++.h>
	using namespace std;
	#define WHITE 0
	#define GRAY 1
	#define BLACK 2
	#define MAX 10000
	//READ ME
	// please check below
	// setting hashLength : hashlength
	//HEAP
	class MyHeap// 1 origine
	{
		public:
		MyHeap()//Constructor
		{
			heapSize = 0;
			heapLength = 0;
			for(int i = 1; i <= MAX; i++)
			{
				heapTree[i].key = heapTree[i].key = 0;
				heapTree[i].next = nullptr;
			}
		}
		//Structures
		typedef struct Data* DataPointer;
		struct Data{
			int key;
			int id;
			int parentId;
			DataPointer next;
		};
		//Prototype Declarations
		int Parent(int);
		int Left(int);
		int Right(int);
		//Global Variables
		int heapSize;
		int heapLength;
		struct Data heapTree[MAX];// 1 origine : heap max size
	};
	int MyHeap::Parent(int i){return i/2;}
	int MyHeap::Left(int i){return 2*i;}
	int MyHeap::Right(int i){return 2*i + 1;}
	//MinHeap
	class MyMinHeap : public MyHeap
	{
		public:
		//Strurecures
		//Prototype Declarations
		int  MinHeapify(struct Data *,int i);
		void BuildMinHeap();//bottom to up
		void HeapSort();//not yet
		//Global Variables
	};
	int MyMinHeap::MinHeapify(struct Data *heapTree,int i)
	{
		int l = Left(i);
		int r = Right(i);
		int smallest = 0;
		if(l <= heapSize && heapTree[l].key < heapTree[i].key)
		{
			smallest = l;
		}else smallest = i;
		if(r <= heapSize && heapTree[r].key < heapTree[smallest].key)
		{
			smallest = r;
		}
		if(smallest != i)// there is any change
		{
			struct Data tmp = heapTree[i];
			heapTree[i] = heapTree[smallest];
			heapTree[smallest] = tmp;
			MinHeapify(heapTree, smallest);
		}
		return 0;
	}
	void MyMinHeap::BuildMinHeap()
	{
		heapSize = heapLength;
		for(int i = heapLength/2 ; i >= 1; i--)
		{
			MinHeapify(heapTree,i);
		}
	}
	//Priority queue
	class MyMinPriorityQueue_STRUCT : public MyMinHeap
	{
		public:
		MyMinPriorityQueue_STRUCT()//Constructor
		{
		}
		//Structures
		//Prototype Declarations
		struct Data HeapMinimum();//ok
		struct Data ExtractMin();//ok
		void MinHeapInsert(struct Data item);//ok
		void HeapDecreaseKey(int i , struct Data item);//ok
		
		//Global Variables
	};
	void MyMinPriorityQueue_STRUCT::MinHeapInsert(struct Data item)
	{
		heapSize++;
		heapTree[heapSize].key = INT_MAX;
		MyMinPriorityQueue_STRUCT::HeapDecreaseKey(heapSize, item);
	}
	struct MyMinPriorityQueue_STRUCT::Data MyMinPriorityQueue_STRUCT::HeapMinimum(){return heapTree[1];}// check the top value
	struct MyMinPriorityQueue_STRUCT::Data MyMinPriorityQueue_STRUCT::ExtractMin()//Extract and return the top value
	{
		struct Data min;
		if(heapSize < 1)
		{
			//error
		}else{
			min = heapTree[1];
			heapTree[1] = heapTree[heapSize];
			heapSize--;
			MinHeapify(heapTree,1);
		}
		return min;
	}
	void MyMinPriorityQueue_STRUCT::HeapDecreaseKey(int i , struct Data item)
	{
		if(item.key > heapTree[i].key){//need being chenged when make MinHeap
			//error new key need being greater than current key
		}
		heapTree[i] = item;
		while( i > 1 && heapTree[Parent(i)].key > heapTree[i].key)
		{
			struct Data tmp = heapTree[Parent(i)];
			heapTree[Parent(i)] = heapTree[i];
			heapTree[i] = tmp;
			i = Parent(i);
		}
	}
	//READ ME
	// please check below
	// setting edgeNum : for expressing the graph it is needed
	//Graph
	class MyGraph{
		public:
		MyGraph()
		{
			time = 0;
			edgeNum = 0;
		}
		//Structures
		struct Vertix{
			int key;
			int id;
			int parentId;
			struct Vertix* p;//parent vertix
			struct Vertix* u;//the place having the key : original pointer
			struct Vertix* next;//next adjacency node
		};
		//Global Variables
		int time;//used for timestanping
		int edgeNum;
		typedef struct Vertix* VertixPointer;
		struct Vertix G[MAX];//used as 1 origine 
		int color[MAX];//used for DFS : 1 origine
		int discover[MAX];//used for DFS : 1 origine
		int finished[MAX];//used for DFS : 1 origine
		map<int, bool> visited;//binary Tree like array
		//Prototype Declarations
		void MakeGraphAsAdjacencyList(int n);//n edges Graph make
		VertixPointer MakeNewEdge(VertixPointer u);
		VertixPointer FindLastNode(VertixPointer v);
		void Display(VertixPointer v,int n); 
		void DFS();
		void DFS_VISIT(int u);
	};
	void MyGraph::MakeGraphAsAdjacencyList(int n)
	{
		edgeNum = n;
		VertixPointer lastNode;
		// making adjacent list
		for(int i = 1 ; i <= edgeNum ; i++)// 1 origine loop
		{
			int v = i;//target vertex
			G[v].next = G[v].p = nullptr;
			G[v].key = 0;
			G[v].id = v;
			G[v].parentId = 0;
			lastNode = FindLastNode(&G[v]);
			for(int j = 1 ; j <= edgeNum ; j++)
			{
				int u;
				scanf("%d",&u);
				if(u != -1)
				{
					//search the last node of target vertex
					VertixPointer newNode= MakeNewEdge(&G[v]);//send this parent;
					newNode->id = j;
					newNode->key = u;
					newNode->parentId = G[v].id;
					newNode->u = &G[j];
					lastNode->next = newNode;
					lastNode = newNode;//next last node of v
				}
			}
		}
	}
	void MyGraph::DFS()
	{
		for(int i = 1; i <= edgeNum; i++)//1 origine
		{
			color[i] = WHITE;//initialize as WHITE color
		}
		// This loop is for some dependent node
		// If there is nothing, This loop finish once
		for(int u = 1; u <= edgeNum; u++)
		{
			if(color[u] ==WHITE)
			{
				DFS_VISIT(u);
			}
		}
	}
	void MyGraph::DFS_VISIT(int u)
	{
		time = time + 1;
		discover[u] = time;//timestamping
		color[u] = GRAY;//chenge color
		for(VertixPointer tmp = G[u].next; tmp != nullptr ; tmp = tmp->next)
		{
			if(color[tmp->id]==WHITE)
			{
				DFS_VISIT(tmp->id);//using Adjecent vertex,implement DFS_VISIT(key)
			}
		}
		color[u] = BLACK;
		time = time + 1;
		finished[u] = time;
	}
	MyGraph::VertixPointer MyGraph::MakeNewEdge(VertixPointer u)
	{
		VertixPointer tmp;
		tmp = (struct Vertix *)malloc(sizeof(struct Vertix));
		tmp->p = u;
		tmp->next = nullptr;
		return tmp;
	}
	MyGraph::VertixPointer MyGraph::FindLastNode(VertixPointer v)
	{
		VertixPointer tmp;
		for(tmp = v; tmp->next != NULL ; tmp = tmp->next);
		return tmp;
	}
	void MyGraph::Display(VertixPointer v,int n)
	{
		for(int i = 1 ; i <= n; i++)
		{
			//check the discover and finished time
			//cout << i << " " << discover[i]<< " " << finished[i] << endl;
			//check the adjacency lists
			cout << i <<":";
			for(VertixPointer j = G[i].next; j != nullptr ; j = j->next)
			{
				cout << " " <<j->key;
			}
			cout << endl;
		}
	}
	//Prim
	class MyPrim : public MyMinPriorityQueue_STRUCT, public MyGraph
	{
		public:
		MyPrim()
		{
			totalCost = 0;
		}
		//prototype declaration
		void MST_Prim(int);
		void PushAdjaVertix(int u);
		//Global Variables
		int totalCost;
		int lastId;
	};
	// function-----
	void MyPrim::MST_Prim(int r)
	{
		for(int i = 1 ; i <= edgeNum ; i++)// 1 origine
		{
			color[i] = WHITE;
			discover[i] = INT_MAX;
		}
		discover[r] = 0; //start point is zero
		color[r] = BLACK;
		// enter each vertex belonging to r into priority queues
		PushAdjaVertix(r);
		while(heapSize != 0)
		{
			struct Data u = ExtractMin();
			if(color[u.id] == WHITE && discover[u.id] > u.key)
			{
				discover[u.id] = u.key;
				color[u.id] = BLACK;
			}else continue;
			PushAdjaVertix(u.id);
		}
		for(int i = 0; i<=edgeNum ; i++)
		{
			totalCost += discover[i];
		}
	}
	void MyPrim::PushAdjaVertix(int u)
	{
		for(VertixPointer i = G[u].next; i != nullptr ; i = i->next)
		{
			if(color[i->id] == WHITE)
			{
				//input the priority queue (min)
				struct Data tmp;
				tmp.id = i->id;
				tmp.key = i->key;
				tmp.parentId = i->parentId;
				MinHeapInsert(tmp);
			}
		}
	}
	int main()
	{
		MyPrim pm;
		int t;
		int total = 0;
		scanf("%d",&pm.edgeNum);
		pm.heapLength = pm.edgeNum * pm.edgeNum;
		//input the relationship
		pm.MakeGraphAsAdjacencyList(pm.edgeNum);
		//pm.Display(pm.G,pm.edgeNum); //check adjacency list
		pm.MST_Prim(1);
		for(int i = 1 ; i <= pm.edgeNum ; i++)// 1 origine
		{
			total += pm.discover[i];
		}	
		cout << total << endl;
		return 0;
	}


