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
    int size;

public:
    Linked_List() {
        head = NULL;
        size = 0;
    }

    int getSize() {
        return size;
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

        size++;
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

    bool contains(Object inputData) {
        List_Node<Object>* currentNode = head;
        while(currentNode != NULL && currentNode->getData() != inputData) {
            currentNode = currentNode->getNext();
        }

        if (currentNode == NULL) {
            return false;
        }

        return true;
    }

    List_Node<Object>* deleteNode(Object nodeToDelete) {
        if (contains(nodeToDelete) == false) {
            return NULL;
        } 
        List_Node<Object>* currentNode = head;
        List_Node<Object>* previous = NULL;

        while (currentNode != NULL && currentNode->getData() != nodeToDelete) {

            previous = currentNode;
            currentNode = currentNode->getNext();
        }

        if (previous == NULL) {
            if (currentNode->getNext() == NULL) {
                head = NULL; 
                return currentNode;
            }
            else {
                List_Node<Object>* nextNode = currentNode->getNext();
                head = nextNode;
                return currentNode;
            }
        }
        else {
            if (currentNode->getNext() == NULL) { 
                previous->setNext(NULL);
                return currentNode;
            }
            else {
                List_Node<Object>* nextNode = currentNode->getNext();
                previous->setNext(nextNode);
                return currentNode;
            }
        }


    }


};
