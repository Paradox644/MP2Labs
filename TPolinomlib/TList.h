#pragma once
#include <iostream>
using namespace std;


template<class T>
struct TNode
{
	T value;
	TNode<T>* pNext;
public:
	TNode() {
		value = T();
		this->pNext = nullptr;
	}
	TNode(const T& data) {
		this->value = data;
		this->pNext = nullptr;
	}
	TNode(const TNode<T>& node) {
		this->value = node.value;
		this->pNext = node.pNext;
	}
	void SetValue(T val) { this->value = val; }
	void SetPointer(TNode<T>* ptr) { this->pNext = ptr; }
	TNode<T>* GetPointer() { return this->pNext; }
	T* GetValue() { return &this->value; }
};


template<class T>
class TList
{
protected:
	TNode<T>* pFirst; 
	TNode<T>* pLast; 
	TNode<T>* pCurrent; 
	TNode<T>* pPrevious; 
	TNode<T>* pStop; 
	int length; 

public:

	TList();
	~TList();
	TList(const TList<T>& l);
	int GetLength() { return length; }
	bool IsEmpty() { return pFirst == nullptr; } 
	void InsertFirst(T item); 
	void InsertCurrent(T item); 
	void InsertNextCurrent(T item); 
	void InsertLast(T item);  
	void DeleteFirst(); 
	void DeleteCurrent(); 
	void GoNext();
	void Reset(); 
	bool IsEnd(); 
	T GetCurrentItem();
	TNode<T>* GetCurrentItemPointer();
	void SetCurrentItem(T item) { pCurrent->value = item; }
	void SetCurrentAt(int ind);
	TList<T>& operator=(const TList<T>& other);
	bool operator==(const TList<T>& other);
	bool operator!=(const TList<T>& other);
};

template <class T>
TList<T>::TList()
{
	pFirst = nullptr;
	pLast = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pStop = nullptr;
	length = 0;
}

template <class T>
TList<T>::~TList()
{
}

template<class T>
inline TList<T>::TList(const TList<T>& other)
{
	TNode<T>* otherptr = other.pFirst;
	if (other.pFirst != nullptr) {
		pFirst = new TNode<T>(other);
		TNode<T>* nextptr = pFirst;
		while (otherptr->pNext != nullptr) {
			TNode<T>* t = new TNode<T>(otherptr->pNext);
			nextptr->SetPointer(t);
			otherptr = otherptr->pNext;
			nextptr = nextptr->pNext;
		}
	}
	else { this->pFirst = other.pFirst }
	this->length = other.length;
	this->pCurrent = other.pCurrent;
	this->pLast = other.pLast;
	this->pPrevious = other.pPrevious;
	this->pStop = other.pStop;
}

template<class T>
TList<T>& TList<T>::operator=(const TList<T>& other)
{
	TNode<T>* otherptr = other.pFirst;
	if (other.pFirst != nullptr) {
		pFirst = new TNode<T>(other);
		TNode<T>* nextptr = pFirst;
		while (otherptr->pNext != nullptr) {
			TNode<T>* t = new TNode<T>(otherptr->pNext);
			nextptr->SetPointer(t);
			otherptr = otherptr->pNext;
			nextptr = nextptr->pNext;
		}
	}
	else { this->pFirst = other.pFirst; }
	this->length = other.length;
	this->pCurrent = other.pCurrent;
	this->pLast = other.pLast;
	this->pPrevious = other.pPrevious;
	this->pStop = other.pStop;

	return *this;
}

template<class T>
bool TList<T>::operator==(const TList<T>& other)
{
	if (this->length != other.length || this->pCurrent != other.pCurrent || this->pLast != other.pLast || this->pPrevious != other.pPrevious
		|| this->pStop != other.pStop || this->pFirst || other.pFirst) return false;

	TNode<T>* ptr1 = this->pFirst;
	TNode<T>* ptr2 = other.pFirst;

	while (ptr1 != nullptr && ptr2 != nullptr)
	{
		if (ptr1->value != ptr2->value()) return false;
		ptr1 = ptr1->pNext;
		ptr2 = ptr2->pNext;
	}
	return true;
}

template<class T>
bool TList<T>::operator!=(const TList<T>& other)
{
	if (this->length != other.length || this->pCurrent != other.pCurrent || this->pLast != other.pLast || this->pPrevious != other.pPrevious
		|| this->pStop != other.pStop || this->pFirst || other.pFirst) return true;

	TNode<T>* ptr1 = this->pFirst;
	TNode<T>* ptr2 = other.pFirst;

	while (ptr1 != nullptr && ptr2 != nullptr)
	{
		if (ptr1->value != ptr2->value()) return true;
		ptr1 = ptr1->pNext;
		ptr2 = ptr2->pNext;
	}
	return false;
}

template <class T>
void TList<T>::InsertFirst(T item)
{
	TNode<T>* newNode = new TNode<T>(item);
	if (pFirst == nullptr) { 
		pStop = new TNode<T>;
		pFirst = newNode;
		pLast = newNode;
		pCurrent = newNode;
	}
	else {
		newNode->SetPointer(pFirst);
		pFirst = newNode;
	}
	length++;
}

template <class T>
void TList<T>::InsertLast(T item)
{
	TNode<T>* newNode = new TNode<T>(item);

	if (pFirst == nullptr) {
		pStop = new TNode<T>;
		pFirst = newNode;
		pCurrent = newNode;
	}
	else {
		pLast->SetPointer(newNode);
	}
	pLast = newNode;
	length++;
}

template <class T>
void TList<T>::InsertCurrent(T item)
{
	TNode<T>* newNode = new TNode<T>(item);

	if (pFirst == pCurrent) {
		newNode->SetPointer(pFirst);
		pFirst = newNode;
		pPrevious = newNode;
	}
	else {
		pPrevious->SetPointer(newNode);
		newNode->SetPointer(pCurrent);
	}
	length++;
}

template <class T>
void TList<T>::InsertNextCurrent(T item)
{
	TNode<T>* newNode = new TNode<T>(item);

	if (pLast == pCurrent) {
		pLast->SetPointer(newNode);
		pLast = newNode;
	}
	else {
		newNode->SetPointer(pCurrent->GetPointer());
		pCurrent->SetPointer(newNode);
	}
	length++;
}

template <class T>
void TList<T>::DeleteFirst()
{
	if (pFirst == nullptr) {
		return;
	}
	if (pFirst == pCurrent) {
		pCurrent = pCurrent->GetPointer();
	}
	TNode<T>* temp = pFirst;
	pFirst = pFirst->GetPointer();
	delete temp; 
	if (pFirst == nullptr) {
		pStop = nullptr;
		pLast = nullptr;
	}

	length--;
}

template <class T>
void TList<T>::DeleteCurrent()
{
	if (pCurrent == nullptr || pFirst == nullptr) {
		return;
	}

	if (pCurrent == pFirst) {
		DeleteFirst();
	}
	else {
		pPrevious->SetPointer(pCurrent->GetPointer());
		pCurrent = pCurrent->GetPointer();
		length--;
	}
	if (pCurrent == pStop) pStop = pPrevious;
	if (pCurrent == pLast) pLast = pPrevious;
}

template <class T>
T TList<T>::GetCurrentItem()
{
	if (pCurrent == nullptr)
		throw "current element is Null";
	if (pFirst == nullptr)
		throw "the list is empty";
	return *pCurrent->GetValue();
}

template <class T>
TNode<T>* TList<T>::GetCurrentItemPointer()
{
	if (pCurrent == nullptr)
		throw "current element is Null";
	if (pFirst == nullptr)
		throw "the list is empty";
	return pCurrent;
}

template <class T>
void TList<T>::Reset()
{
	if (pCurrent == pFirst) return;
	pCurrent = pFirst;
	pPrevious = nullptr;
}

template <class T>
void TList<T>::GoNext()
{
	if (IsEmpty()) throw "List is empty";
	if (IsEnd()) throw "There is no elements to go to";
	pPrevious = pCurrent;
	pCurrent = pCurrent->GetPointer();
}

template <class T>
bool TList<T>::IsEnd()
{
	return pCurrent->GetPointer() == pStop;
}

template <class T>
void TList<T>::SetCurrentAt(int ind) {
	if (ind < 0 || ind >= length) throw "wrong index";
	this->Reset();
	for (size_t i = 0; i < ind; i++) GoNext();
}