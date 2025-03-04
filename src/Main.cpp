#include "Priority_queue.h"

// It is NOT TESTS
// It is just EXAMPLE how PriorityQueue can be used

int main(){
    PriorityQueue<double> q;
    std::cout << "Empty 1: " << q.Empty() << std::endl;
    q.Push(2.0);
    q.Push(3.0);
    q.Push(10.0);
    q.Push(1.0);

    std::cout << "Empty 2: " << q.Empty() << std::endl;
    std::cout << "Size 1: " << q.Size() << std::endl;
    q.Pop(3.0);
    q.Print();
    std::cout << std::endl;
    q.PopTop();
    q.Print();
    std::cout << std::endl;
    std::cout << "Size 2: " << q.Size() << std::endl;
    q.PopTop();
    q.Print();
    std::cout << std::endl;
    std::cout << "Size 3: " << q.Size() << std::endl;

    PriorityQueue<double> another_q;
    another_q.Push(3.0);
    another_q.Push(-10.0);

    std::cout << "Merge \n";
    q.Merge(another_q);
    q.Print();
    
    std::cout << "\nFind\n";
    std::cout << q.Contains(5.1) << std::endl;
    std::cout << q.Contains(3.0) << std::endl;
    std::cout << q.Find(3.0)->value << std::endl;
    q.Clear();
    q.Print();
    std::cout << q.Size() << std::endl;

    std::cout << "\nOperators\n";
    PriorityQueue<double> copy_q = another_q;
    copy_q.Print();
    q.Push(2.0);
    copy_q = copy_q + copy_q + q + copy_q + q;
    copy_q.Print();
    std::cout << copy_q.Size() << std::endl;
}