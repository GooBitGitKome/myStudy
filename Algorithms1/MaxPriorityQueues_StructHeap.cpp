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
//MaxHeap
class MyMaxHeap : public MyHeap
{
	public:
	//Strurecures
	//Prototype Declarations
	void MaxHeapify(struct Data *heapTree,int i);//up to bottom
	void BuildMaxHeap();//bottom to up
	void HeapSort();//not yet
	//Global Variables
};
void MyMaxHeap::MaxHeapify(struct Data *heapTree,int i)
{
	int l = Left(i);
	int r = Right(i);
	int large = 0;
	if(l <= heapSize && heapTree[l].key > heapTree[i].key)
	{
		large = l;
	}else large = i;
	if(r <= heapSize && heapTree[r].key > heapTree[large].key)
	{
		large = r;
	}
	if(large != i)// there is any change
	{
		struct Data tmp = heapTree[i];
		heapTree[i] = heapTree[large];
		heapTree[large] = tmp;
		MaxHeapify(heapTree, large);
	}
}
void MyMaxHeap::BuildMaxHeap()
{
	heapSize = heapLength;
	for(int i = heapLength/2 ; i >= 1; i--)
	{
		MaxHeapify(heapTree,i);
	}
}
//Priority queue
class MyMaxPriorityQueue_STRUCT : public MyMaxHeap
{
	public:
	MyMaxPriorityQueue_STRUCT()//Constructor
	{
	}
	//Structures
	//Prototype Declarations
	struct Data HeapMaximum();//made
	struct Data ExtractMax();//made
	void HeapIncreaseKey(int i , struct Data item);
	void MaxHeapInsert(struct Data item);
    //Global Variables
};
//Functions--------------------------------------------------------------------
void MyMaxPriorityQueue_STRUCT::MaxHeapInsert(struct Data item)
{
	heapSize++;
	heapTree[heapSize].key = INT_MIN;
	MyMaxPriorityQueue_STRUCT::HeapIncreaseKey(heapSize, item);
}
struct MyMaxPriorityQueue_STRUCT::Data MyMaxPriorityQueue_STRUCT::HeapMaximum(){return heapTree[1];}// check the top value
struct MyMaxPriorityQueue_STRUCT::Data MyMaxPriorityQueue_STRUCT::ExtractMax()//Extract and return the top value
{
	struct Data max;
	if(heapSize < 1)
	{
		//error
	}else{
		max = heapTree[1];
		heapTree[1] = heapTree[heapSize];
		heapSize--;
		MaxHeapify(heapTree,1);
	}
	return max;
}
void MyMaxPriorityQueue_STRUCT::HeapIncreaseKey(int i , struct Data item)
{
	if(item.key < heapTree[i].key){//need being chenged when make MinHeap
		//error new key need being greater than current key
	}
	heapTree[i] = item;
	while( i > 1 && heapTree[Parent(i)].key < heapTree[i].key)
	{
		struct Data tmp = heapTree[Parent(i)];
		heapTree[Parent(i)] = heapTree[i];
		heapTree[i] = tmp;
		i = Parent(i);
	}
}

//Prototype Declarations
//Global Variables
int main()
{
	MyMaxPriorityQueue_STRUCT mpq;
	int n;
	scanf("%d",&n);
	mpq.heapLength = n;
	for(int i = 1 ; i <= n ; i++)
	{
		int id,key;
		scanf("%d%d",&id,&key);
		struct MyMaxPriorityQueue_STRUCT::Data tmp;
		tmp.id = id;
		tmp.key = key;
		mpq.MaxHeapInsert(tmp);
	}
	cout << mpq.ExtractMax().key <<endl;
	return 0;
}

