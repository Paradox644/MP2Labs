#include<iostream>
template <class T>
class TQueue {
protected:
  int size;
  int top;
  T* mas;
void shiftQueue() {
for (int i = 0; i < this.top; i++)
    this.mas[i] = this.mas[i]+1;
top--;
}
public:
  TQueue(int n) {
    size = n;
    top = -1;
    mas = new T[size];
  };
  TQueue(TQueue <T> &q){
    size = q.size;
    top = q.top;
    mas = new T[size];
    for (int i =0; i< q.size; i++)
    mas[i]=q.mas[i];
  };
  ~TQueue(){ delete[] mas; }
void Push(const T& a){
    if (IsFull()) { throw -1; }
    mas[++top] = a;
  };
  T Get(){
    if (IsEmpty()) { throw -1; }
    return mas[0];
    shiftQueue();
  }

  bool IsFull() { return top == size-1; } 
  bool IsEmpty() { return top == -1; }
TQueue& operator=(const TQueue<T> &que) {
 if (this != & que){
	 delete[]mas;
	 size = que.size;
	 top = que.top;
	 mas = new T[size];
	 for (int i = 0; i< size; i++)
		 mas[i] = que.mas[i];
	 return *this;
}
}
  bool operator==(const TQueue<T> &que) {
if (top != que.top) return 0;
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
