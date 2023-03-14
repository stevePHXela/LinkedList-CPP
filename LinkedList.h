#pragma once
#include <iostream>

template<typename T>
class linked_list
{
public:
    linked_list();
    ~linked_list();

    size_t size() const;
    T peek_front() const;
    T peek_back() const;
    T peek_at(size_t index);
    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
    void insert(size_t index, T data);
    void remove_at(size_t index);

private:
    class Node
    {
    public:
        T data;
        Node* next;

        Node(T data);
    };

private:
    Node* head;
};
