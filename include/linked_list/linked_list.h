#include <iostream>

template <typename Object> 
class List_Node {
private:
    Object data;
    List_Node* next;
public:
/*
    List_Node(Object newData) {
        data = newData;
        next = NULL;
    }
*/

    List_Node(const Object& newData) : data(newData), next(NULL) {}

    List_Node* getNext() {
        return next;
    }

    void setNext(List_Node* nextNode) {
        next = nextNode;
    }

    Object getData() {
        return data;
    }
};

template <typename Object> 
class Linked_List {
private:
    List_Node<Object>* head;

public:
    Linked_List() {
        head = NULL;
    }

    void addNode(Object data) {
        List_Node<Object>* newNode = new List_Node<Object>(data);

        if (head == NULL) {
            head = newNode;
        } else {
            List_Node<Object>* currentNode = head;
            while(currentNode->getNext() != NULL) {
                currentNode = currentNode->getNext();
            }
            currentNode->setNext(newNode);
        }
    }

    void printList() {
        List_Node<Object>* currentNode = head;
        /*
        if (currentNode != NULL) {
            std::cout << "Head: ";
        }
        */
        while(currentNode != NULL) {
            if (currentNode == head) {
                std::cout << currentNode->getData() << "   ";
            }
            if (currentNode != head) {
                std::cout << "-->";
                std::cout << "   " << currentNode->getData() << "   ";
            }
            //std::cout << "\t" << currentNode->getData();
            currentNode = currentNode->getNext();
        }
    }
};
