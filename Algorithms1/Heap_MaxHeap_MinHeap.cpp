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

int main()
{
	MyMaxHeap maxh;
	MyMinHeap minh;
	int n;
	scanf("%d",&n);
	maxh.heapLength = minh.heapLength = n;
	int key,id;
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d%d",&id,&key);
		maxh.heapTree[i].key = key;
		maxh.heapTree[i].id = id;
		minh.heapTree[i].key = key;
		minh.heapTree[i].id = id;
	}
	maxh.BuildMaxHeap();
	minh.BuildMinHeap();
	for(int i = 1 ; i <= n ; i++)
	{
		cout << maxh.heapTree[1].id<< endl;
		cout << minh.heapTree[1].id << endl;
	}
	return 0;
}