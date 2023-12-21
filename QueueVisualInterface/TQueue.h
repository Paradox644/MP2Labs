#include<iostream>
template <class T>
class TQueue {
protected:
    int size, top, bottom, elementAmount;
  T* mas;

public:
  TQueue(int n=0) {
      if (n < 0) { throw - 1; }
    size = n;
    top = 0;
    bottom = 0;
    elementAmount = 0;
    mas = new T[size];
  }
  TQueue(TQueue <T> &q){
    size = q.size;
    top = q.top;
    bottom = q.bottom;
    elementAmount = q.elementAmount;
    mas = new T[size];
    for (int i =0; i< q.size; i++)
    mas[i]=q.mas[i];
  }
  ~TQueue(){ delete[] mas; }
void Push(const T& a){
    if (IsFull()) { throw -1; }
    mas[top] = a;
    top = (top + 1) % size;
    elementAmount++;
  }
  T Get(){
    if (IsEmpty()) { throw -1; }
    T element = mas[bottom];
    bottom = (bottom + 1) % size;
    elementAmount--;
    return element;
  }
  int GetSize() {
      return elementAmount;
  }
  int GetTop() {
      return top;
  }
  bool IsFull() { return top == size; } 
  bool IsEmpty() { return top == 0; }
TQueue& operator=(const TQueue<T> &que) {
 if (this != & que){
	 delete[]mas;
	 size = que.size;
	 top = que.top;
     bottom = que.bottom;
     elementAmount = que.elementAmount;
	 mas = new T[size];
	 for (int i = 0; i< size; i++)
		 mas[i] = que.mas[i];
	 return *this;
}
 return *this;
}
bool operator==(const TQueue<T> &que) {
if (top != que.top || size != que.size || bottom != que.bottom || elementAmount != que.elementAmount) return 0;
for (int i = 0; i < top; i++){
	if ( mas[i] != que.mas[i] ) return 0;
}
return 1;
}
   bool operator!=(const TQueue<T> &que) {
    return !(*this == que);
  }
friend std::istream& operator>>(std::istream& istr, const TQueue<T> &que) { // ввод
    if (que.IsFull()) { throw -1; }
    for (int i = 0; i < que.top; i++)
    {
      istr >> que.mas[i];
    }
    return istr;
  } 
friend std::ostream& operator<<(std::ostream& ostr, const TQueue<T>&que) { // вывод
    for (int i = 0; i < que.top; i++) {
        ostr << que.mas[i] << ' ';
    }
    return ostr;
   //операторы вводы и выводы
}};
