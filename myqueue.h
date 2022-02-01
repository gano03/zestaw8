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
        msize = other.msize;
        for(int i = 0; i < other.msize; i++){
            tab[i] = other.tab[i];
        }
    } // copy constructor
    MyQueue(MyQueue&& other)
    {
        tab = other.tab;
        head = other.head;
        tail = other.tail;
        msize = other.msize;
        other.head = 0;
        other.tail = 0;
        other.msize = 0;
        other.tab = nullptr;
    } // move constructor
    MyQueue& operator=(const MyQueue& other)
    {
        delete [] this->tab;
        tab = new T[other.msize];
        this->head = 0;
        this->tail = 0;
        this->msize = 0;
        this->head = other.head;
        this->tail = other.tail;
        this->msize = other.msize;
        for(int i = 0; i < other.msize; i++){
            tab[i] = other.tab[i];
        }
        return *this;
    } // copy assignment operator, return *this
    MyQueue& operator=(MyQueue&& other)
    {
        delete [] this->tab;
        this->head = 0;
        this->tail = 0;
        this->msize = 0;
        this->tab = other.tab;
        this->head = other.head;
        this->tail = other.tail;
        this->msize = other.msize;
        other.tab = nullptr;
        other.msize = 0;
        other.head = 0;
        other.tail = 0;
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
