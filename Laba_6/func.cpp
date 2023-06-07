#include "func.h"


template <typename T>
void Main(List<T>& lst) {
    int c;

    typename List<T>::Iterator it = lst.begin();

    do {
        cout << "\n\n\t\tMain Menu:\n"
            << "============================================\n";
        cout << "1) Check if the list is empty\n";
        cout << "2) Add element to the list\n";
        cout << "3) Access an element at a given position\n";
        cout << "4) Remove an element at a given position\n";
        cout << "5) Print the list\n";
        cout << "6) Clear the list\n";
        cout << "7) Set iterator to the beginning of the list\n";
        cout << "8) Access the value of the current element \n";
        cout << "9) Move the iterator to the next element\n";
        cout << "10) Show last element\n";
        cout << "11) Choose data\n";
        cout << ">> ";
        cin >> c;

        switch (c) {
        case 1:
            if (lst.Empty()) {
                cout << "\n\nThe list is empty\n";
            }
            else {
                cout << "\n\nThe list isn't empty\n";
            }
            break;
        case 2: {
            T element;
            cout << "\n\nEnter the element to insert: ";
            cin >> element;
            lst.insert(element);
            cout << "Element has been inserted into the list\n";
            break;
        }
        case 3: {
            int index;
            cout << "\n\nEnter the position of the element: ";
            cin >> index;
            T& element = lst.get(index);
            if (&element != nullptr) {
                cout << "Element at position " << index << ": " << element << "\n";
            }
            break;
        }
        case 4: {
            int removeIndex;
            cout << "\n\nEnter the position of the element to remove: ";
            cin >> removeIndex;
            lst.Remove(removeIndex);
            cout << "Element at position " << removeIndex << " has been removed\n";
            break;
        }
        case 5:
            print(lst);
            break;
        case 6: {
            lst.clear();
            cout << "\n\nThe list has been cleared\n";
            break;
        }
        case 7: {
            it = lst.begin();
            cout << "\n\nIterator set to the beginning of the list\n";
            break;
        }
        case 8: {
            if (it != lst.end()) {
                cout << "\n\nValue of the current element: " << *it << "\n";
            }
            else {
                cout << "\n\nIterator is at the end of the list\n";
            }
            break;
        }
        case 9: {
            if (it != lst.end()) {
                ++it;
                cout << "\n\nIterator moved to the next element\n";
            }
            else {
                cout << "\n\nIterator reached the end of the list!\n";
            }
            break;
        }
        case 10:
            cout << "\n\nLast value of the list\n";
            if (lst.Empty()) {
                cout << "\n\nThe list is empty\n";
            }
            else {
                int lastIndex = lst.getSize() - 1;
                T& lastElement = lst.get(lastIndex);
                cout << "Element at position " << lastIndex << ": " << lastElement << "\n";
            }
            break;
        case 11:
            return;
        default:
            cout << "\nInvalid choice!\n";
            break;
        }
    } while (c != 11);
}

template <typename T>
void print(List<T>& lst) {
    cout << "\nList elements:\n";
    typename List<T>::Iterator it = lst.begin();
    do {
        cout << *it << " ";
        ++it;
    } while (it != lst.begin());
    cout << endl;
}

template <typename T>
void input(List<T>& lst) {
    int size;
    cout << "\nEnter the size of the list: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        T value;
        cout << "Enter element " << i << ": ";
        cin >> value;
        lst.insert(value);
    }
}