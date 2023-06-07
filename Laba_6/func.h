#pragma once
#include <iostream>
#include <string>

using namespace std;


template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    int size;
    Node* head;

    Node* getNode(int index) const {
        if (index < 0 || index >= size) {
            cout << "\nError!\n";
            return nullptr;
        }

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr;
    }

public:
    List() : head(nullptr), size(0) {}
    ~List() {}

    bool Empty() const { return size == 0; }

    void clear() {
        while (!Empty()) {
            Remove(0);
        }
    }

    T& get(int index) const {
        Node* node = getNode(index);
        if (node) {
            return node->data;
        }
        static T value;
        return value;
    }

    int getSize() const { return size; }

    void Remove(int index) {
        if (index < 0 || index >= size) {
            cout << "\nError!\n";
            return;
        }

        Node* remove;
        if (index == 0) {
            remove = head;
            head = head->next;
        }
        else {
            Node* prev = getNode(index - 1);
            if (!prev) {
                return;
            }
            remove = prev->next;
            prev->next = remove->next;
        }

        delete remove;
        size--;
    }

    void insert(const T& value) {
        Node* newNode = new Node(value);

        if (Empty()) {
            head = newNode;
            head->next = head;
        }
        else {
            Node* last = getNode(size - 1);
            if (!last) {
                delete newNode;
                return;
            }
            newNode->next = head;
            last->next = newNode;
        }
        size++;
    }

    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* start) : current(start) {}

        T& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
};

template <typename T>
void print(List<T>& lst);

template <typename T>
void input(List<T>& lst);

template <typename T>
void Main(List<T>& lst);