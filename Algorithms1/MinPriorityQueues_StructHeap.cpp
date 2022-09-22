#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//READ ME
//you have to assign the value to heapLength
//class
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
		DataPointer next;
	};
	//Prototype Declarations
	int Parent(int);
	int Left(int);
	int Right(int);
	//Global Variables
	static const int MAX = 10000; //Max heap size
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
//Functions--------------------------------------------------------------------
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

int main()
{
	MyMinPriorityQueue_STRUCT mpq;
	int n;
	scanf("%d",&n);
	mpq.heapLength = n;
	for(int i = 1 ; i <= n ; i++)
	{
		int id,key;
		scanf("%d%d",&id,&key);
		struct MyMinPriorityQueue_STRUCT::Data tmp;
		tmp.id = id;
		tmp.key = key;
		mpq.MinHeapInsert(tmp);
	}
	cout << mpq.ExtractMin().key <<endl;
	return 0;
}

