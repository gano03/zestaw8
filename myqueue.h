// myqueue.h
#include <iostream>
template <typename T>
class MyQueue {
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
public:
    MyQueue(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyQueue() { delete [] tab; }
    MyQueue(const MyQueue& other)
    {
        tab = new T[other.msize];
        head = other.head;
        tail = other.tail;
        for(int i = 0; i < other.msize; i++){
            tab[i] = other.tab[i];
        }
    } // copy constructor
    MyQueue(MyQueue&& other)
    {
        tab = new T[other.msize];
        head = other.head;
        tail = other.tail;
        other.head = 0;
        other.tail = 0;
        for(int i = 0; i < other.msize; i++){
            tab[i] = other.tab[i];
            other.tab[i] = 0;
        }
        delete [] other.tab;
    } // move constructor
    MyQueue& operator=(const MyQueue& other)
    {
        tab = new T[other.msize];
        head = other.head;
        tail = other.tail;
        for(int i = 0; i < other.msize; i++){
            tab[i] = other.tab[i];
        }
        delete [] other.tab;
        return *this;
    } // copy assignment operator, return *this
    MyQueue& operator=(MyQueue&& other)
    {
        tab = new T[other.msize];
        head = other.head;
        tail = other.tail;
        other.head = 0;
        other.tail = 0;
        for(int i = 0; i < other.msize; i++){
            tab[i] = other.tab[i];
            other.tab[i] = 0;
        }
        delete [] other.tab;
        return *this;
    } // move assignment operator, return *this
    bool empty() const { return head == tail; }
    bool full() const { return (head + msize -1) % msize == tail; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    void push(const T& item); // dodanie na koniec
    void push(T&& item); // dodanie na koniec
    T& front() { return tab[head]; } // zwraca poczatek
    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec
    void pop()
    {
        if(empty()){
            std::cout << "Kolejka jest pusta\n";
            return;
        }
        tab[head] = 0;
        head = (head + 1) % msize;
    } // usuwa poczatek
    void clear()
    {
        for(int i = head; i != tail; i = (i+1) % msize){
            tab[i] = 0;
        }
        display();
        delete [] tab;
    } // czyszczenie listy z elementow
    void display();
};
template <typename T>
void MyQueue<T>::push(const T& item) {
    tab[tail] = item;
    tail = (tail + 1) % msize;
}
template <typename T>
void MyQueue<T>::push(T&& item) {
    tab[tail] = std::move(item);
    tail = (tail + 1) % msize;
}
template <typename T>
void MyQueue<T>::display() {
    for (int i = head; i != tail; i=(i+1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}
