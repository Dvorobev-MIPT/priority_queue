#include "Priority_queue.h"
#include "Vector.h"

// It is NOT TESTS
// It is just EXAMPLE how PriorityQueue can be used

int main(){
    PriorityQueue<double> q;
    std::cout << "Push/Pop/PopTop/Size/Empty/Print" << std::endl;
    std::cout << "Empty 1: " << q.Empty() << std::endl;
    q.Push(2.0);
    q.Push(3.0);
    q.Push(10.0);
    q.Push(1.0);

    std::cout << "Priority Queue after  Push 2.0, 3.0, 10.0, 1.0: ";
    q.Print();

    std::cout << "Empty 2: " << q.Empty() << std::endl;
    std::cout << "Size 1: " << q.Size() << std::endl;
    q.Pop(3.0);
    std::cout << "Priority Queue after  Pop 3.0: ";
    q.Print();
    q.PopTop();
    std::cout << "Priority Queue after PopTop: ";
    q.Print();
    std::cout << "Size 2: " << q.Size() << std::endl;
    q.PopTop();
    std::cout << "Priority Queue after PopTop: ";
    q.Print();
    std::cout << "Size 3: " << q.Size() << std::endl;

    PriorityQueue<double> another_q;
    another_q.Push(3.0);
    another_q.Push(-10.0);

    std::cout << "\nMerge \n";
    q.Merge(another_q);
    std::cout << "Priority Queue after Merge with PQ{3.0, -10.0}: ";
    q.Print();
    
    std::cout << "\nFind\n";
    std::cout << "Constains 5.1: " <<  q.Contains(5.1) << std::endl;
    std::cout << "Constains 3.0: " << q.Contains(3.0) << std::endl;
    std::cout << "Find(3.0)->value: " << q.Find(3.0)->value << std::endl;
    q.Clear();
    std::cout << "Priority Queue after Clear: ";
    q.Print();
    std::cout << q.Size() << std::endl;

    std::cout << "\nOperators\n";
    PriorityQueue<double> copy_q = another_q;
    std::cout << "Copy Priority Queue: ";
    copy_q.Print();
    q.Push(2.0);
    copy_q = copy_q + copy_q + q + copy_q + q;
    std::cout << "Priority Queue = copy_PQ + copy_PQ + PQ + Copy_PQ + PQ: ";
    copy_q.Print();
    std::cout << "Size 4: " << copy_q.Size() << std::endl;

    std::cout << "\nConstructors" << std::endl;

    PriorityQueue<double> copy_constr(copy_q);
    std::cout << "Copy Constructor: ";
    copy_constr.Print();
    std::cout << "Size 5: " << copy_constr.Size() << std::endl;


    Vector<double> vector;
    vector.PushBack(1.0);
    vector.PushBack(2.0);
    vector.PushBack(0.0);

    PriorityQueue<double> vector_constr(vector);
    std::cout << "Constructor with data assignment via Vector(0.0, 1.0, 2.0): ";
    vector_constr.Print();
    std::cout << "Size 6: " << vector_constr.Size() << std::endl;

    PriorityQueue<double> move_constr(std::move(copy_q));
    std::cout << "Move Constructor: ";
    move_constr.Print();
    std::cout << "Size 7: " << copy_constr.Size() << std::endl;
}