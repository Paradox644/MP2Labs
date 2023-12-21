#include <iostream>
template<class T>
class TStack {
protected:
  int size;
  int top;
  T* mas;
public:
  TStack(int n) {
    size = n;
    top = -1;
    mas = new T[size];
  }
  TStack(TStack<T> &stack){
    size = stack.size;
    top = stack.top;
    mas = new T[size];
    for (int i = 0; i<stack.size; i++)
    mas[i]=stack.mas[i];
  }
  ~TStack() { delete[]mas; }

  void Push(const T& a){
if(IsFull()){ throw -1; }
mas[++top] = a;
}
  T Get(){
if(IsEmpty()){ throw -1; }
return mas[top--];
}
  T TopView() { return mas[top]; }

  int GetSize() { return top+1; }
  int GetTop() { return top; }

  //операторы вводы и выводы

  bool IsFull() { return top == size-1; } 
  bool IsEmpty() { return top == -1; }

  TStack& operator=(const TStack<T> &stack) {
 if (this != &stack) {
    delete[]mas;
    size=stack.size;
    top=stack.top;
    mas = new T[size];
    for (int i = 0; i < size; i++)
        mas[i] = stack.mas[i];
return *this;
 }
  }
  bool operator==(const TStack<T> &stack) {
if (top != stack.top) return 0;
for (int i = 0; i < top; i++){
	if ( mas[i] != stack.mas[i] ) return 0;
}
return 1;
  }
   bool operator!=(const TStack<T> &stack) {
    return !(*this == stack);
  }
friend std::istream& operator>>(std::istream& istr, const TStack<T> &stack) { // ввод
    if (stack.IsFull()) { throw -1; }
    for (int i = 0; i < stack.GetSize(); i++)
    {
      istr >> stack.mas[i];
    }
    return istr;
  } 
friend std::ostream& operator<<(std::ostream& ostr, TStack<T> &stack) { // вывод
for (int i = 0; i < stack.GetSize(); i++) {
ostr << stack.mas[i] << ' ';
  }
return ostr;
}

};
