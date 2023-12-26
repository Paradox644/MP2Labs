#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;  
public:
	THeadList();
	~THeadList() {}
	void InsertFirst(T item); 
	void DeleteFirst(); 
};

template<class T>
THeadList<T>::THeadList()
{
	this->pHead = new TNode<T>();
	this->pFirst = this->pHead->GetPointer();
	this->pCurrent = this->pFirst;
	this->pStop = new TNode<T>();
	this->pLast = this->pStop;
	this->length = 0;
}


template <class T>
void THeadList<T>::InsertFirst(T item)
{
	TNode<T>* newN = new TNode<T>(item);
	newN->SetPointer(pFirst);
	this->pFirst = newN;
	this->length++;
}

template <class T>
void THeadList<T>::DeleteFirst()
{
	if (this->pFirst == nullptr) throw "You are trying to delete element from an empty list";
	TNode<T>* temp = this->pFirst;
	this->pFirst = this->pFirst.GetPointer();
	delete temp;
	this->length--;
}