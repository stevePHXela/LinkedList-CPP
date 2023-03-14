#include <iostream>

template<typename T>
class linked_list
{
public:
    linked_list()
    {
        head = NULL;
    }

    ~linked_list()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

public:
    size_t size() const
    {
        size_t current = 0;
        Node* current_node = head;
        while (current_node != NULL)
        {
            current++;
            current_node = current_node->next;
        }
        return current;
    }

    T peek_front() const
    {
        return head->data;
    }

    T peek_back() const
    {
        Node* last = head;
        while (last->next != NULL) { last = last->next; }

        return last->data;
    }

    T peek_at(size_t index)
    {
        Node* current = head;
        size_t current_index = 0;

        while (current != NULL && current_index != index)
        {
            current = current->next;
            current_index++;
        }

        if (current == NULL) { throw std::out_of_range("Index out of bounds!"); }

        return current->data;
    }

    void push_front(T data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T data)
    {
        Node* newNode = new Node(data);
        newNode->next = NULL;

        if (head == NULL) { head = newNode; }

        Node* last = head;
        while (last->next != NULL) { last = last->next; }
        last->next = newNode;
    }

    void pop_front()
    {
        if (head == NULL) { return; }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL) { return; }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* last = head;
        Node* prev = NULL;
        while (last->next != NULL)
        {
            prev = last;
            last = last->next;
        }

        delete last;
        prev->next = NULL;
    }

    void insert(size_t index, T data)
    {
        Node* newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        size_t current_index = 0;
        while (current != nullptr && current_index != index)
        {
            prev = current;
            current = current->next;
            current_index++;
        }

        if (current == nullptr && current_index != index)
        {
            throw std::out_of_range("Index out of bounds!");
        }

        newNode->next = current;
        prev->next = newNode;
    }

    void remove_at(size_t index)
    {
        if (head == nullptr) { return; }

        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        size_t current_index = 0;
        while (current != nullptr && current_index != index)
        {
            prev = current;
            current = current->next;
            current_index++;
        }

        if (current == nullptr && current_index != index)
        {
            throw std::out_of_range("Index out of bounds!");
        }

        prev->next = current->next;
        delete current;
    }


private:
    class Node
    {
    public:
        T data;
        Node* next;

        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
private:
    Node* head;
};