#include <iostream>
#include "LinkedList.h"


int main()
{
    linked_list<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.insert(5, 6);

    list.remove_at(0);

    std::cout << list.peek_front() << std::endl;
    std::cout << list.peek_back() << std::endl;
    std::cout << list.peek_at(3) << std::endl;

    return 0;
    system("pause");
}