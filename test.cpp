#include "myqueue.h"
#include <iostream>
#include <cstdlib>

int main ()
{   
    MyQueue<int> obj;
    MyQueue<int> L;
    
    
    std::cout << "Empty " << obj.empty() <<"\n";
    obj.push(1);
    obj.push(3);
    obj.push(7);
    std::cout << "Empty " << obj.empty() <<"\n";

    obj.push(12);
    obj.push(14);
    obj.display();
    std::cout << obj.front() << "\n";
    std::cout << obj.back() << "\n";

    L = obj;
    L.display();

    std::cout << "Rozmiar listy to " <<L.size() <<"\n";

    L.pop();
    L.pop();
    L.push(8);
    L.display();

    L.clear();
    

    return 0;
}