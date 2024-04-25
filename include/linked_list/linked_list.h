#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <type_traits>
#include <cassert>


// << OPERATOR
template <typename Object, typename = void>
struct has_ostream_operator : std::false_type {};

template <typename Object>
struct has_ostream_operator<Object, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<Object>())>> : std::true_type {};


// == OPERATOR
template <typename T, typename = void>
struct has_equality_operator : std::false_type {};

template <typename T>
struct has_equality_operator<T, std::void_t<decltype(std::declval<T>() == std::declval<T>())>> : std::true_type {};


// != OPERATOR
template <typename T, typename = void>
struct has_inequality_operator : std::false_type {};

template <typename T>
struct has_inequality_operator<T, std::void_t<decltype(std::declval<T>() != std::declval<T>())>> : std::true_type {};



template <typename Object>
class List_Node {
private:
    typename std::conditional< 
    std::is_same<Object, int>::value || 
    std::is_same<Object, char>::value || 
    std::is_same<Object, float>::value || 
    std::is_same<Object, double>::value || 
    std::is_same<Object, bool>::value || 
    std::is_same<Object, short>::value || 
    std::is_same<Object, long>::value || 
    std::is_same<Object, long long>::value || 
    std::is_same<Object, unsigned short>::value || 
    std::is_same<Object, unsigned int>::value || 
    std::is_same<Object, unsigned long>::value || 
    std::is_same<Object, unsigned long long>::value, 
    Object, 
    Object*
    >::type data;
    List_Node* next;

public:
    template <typename T = Object, typename std::enable_if<!std::is_same<T, int>::value && !std::is_same<T, char>::value && !std::is_same<T, float>::value && !std::is_same<T, double>::value && !std::is_same<T, bool>::value && !std::is_same<T, short>::value && !std::is_same<T, long>::value && !std::is_same<T, long long>::value && !std::is_same<T, unsigned short>::value && !std::is_same<T, unsigned int>::value && !std::is_same<T, unsigned long>::value && !std::is_same<T, unsigned long long>::value>::type* = nullptr>
    List_Node(Object* newData) {
        data = newData;
        next = NULL;
    }

    template <typename T = Object, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, char>::value || std::is_same<T, float>::value || std::is_same<T, double>::value || std::is_same<T, bool>::value || std::is_same<T, short>::value || std::is_same<T, long>::value || std::is_same<T, long long>::value || std::is_same<T, unsigned short>::value || std::is_same<T, unsigned int>::value || std::is_same<T, unsigned long>::value || std::is_same<T, unsigned long long>::value>::type* = nullptr>
    List_Node(Object newData) {
        data = newData;
        next = NULL;
    }

    List_Node* getNext() {
        return next;
    }

    void setNext(List_Node* nextNode) {
        next = nextNode;
    }

    auto getData() {
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


    template <typename T = Object, typename std::enable_if<!std::is_same<T, int>::value && !std::is_same<T, char>::value && !std::is_same<T, float>::value && !std::is_same<T, double>::value && !std::is_same<T, bool>::value && !std::is_same<T, short>::value && !std::is_same<T, long>::value && !std::is_same<T, long long>::value && !std::is_same<T, unsigned short>::value && !std::is_same<T, unsigned int>::value && !std::is_same<T, unsigned long>::value && !std::is_same<T, unsigned long long>::value>::type* = nullptr>
    void addNode(Object* data) {
        //static_assert(has_equality_operator<Object>::value, "operator== is not defined for this type");
        //static_assert(has_inequality_operator<Object>::value, "operator!= is not defined for this type");  

     
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

    template <typename T = Object, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, char>::value || std::is_same<T, float>::value || std::is_same<T, double>::value || std::is_same<T, bool>::value || std::is_same<T, short>::value || std::is_same<T, long>::value || std::is_same<T, long long>::value || std::is_same<T, unsigned short>::value || std::is_same<T, unsigned int>::value || std::is_same<T, unsigned long>::value || std::is_same<T, unsigned long long>::value>::type* = nullptr>
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

    template <typename T = Object, typename std::enable_if<!std::is_same<T, int>::value && !std::is_same<T, char>::value && !std::is_same<T, float>::value && !std::is_same<T, double>::value && !std::is_same<T, bool>::value && !std::is_same<T, short>::value && !std::is_same<T, long>::value && !std::is_same<T, long long>::value && !std::is_same<T, unsigned short>::value && !std::is_same<T, unsigned int>::value && !std::is_same<T, unsigned long>::value && !std::is_same<T, unsigned long long>::value && has_ostream_operator<T>::value>::type* = nullptr>
    void printList() {
        List_Node<Object>* currentNode = head;
        while(currentNode != NULL) {
            if (currentNode == head) {
                std::cout << *(currentNode->getData()) << "   ";
            }
            if (currentNode != head) {
                std::cout << "-->";
                std::cout << "   " << *(currentNode->getData()) << "   ";
            }
            //std::cout << "\t" << currentNode->getData();
            currentNode = currentNode->getNext();
        }
        std::cout << "\n";
    }

    // IS A CHARACTER OR INT
    template <typename T = Object, std::enable_if_t<has_ostream_operator<T>::value && (std::is_same<T, int>::value || std::is_same<T, char>::value || std::is_same<T, float>::value || std::is_same<T, double>::value || std::is_same<T, bool>::value || std::is_same<T, short>::value || std::is_same<T, long>::value || std::is_same<T, long long>::value || std::is_same<T, unsigned short>::value || std::is_same<T, unsigned int>::value || std::is_same<T, unsigned long>::value || std::is_same<T, unsigned long long>::value), int> = 0>
    void printList() {
        List_Node<Object>* currentNode = head;
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
        std::cout << "\n";
    }

    // if is an object, but the ostream operator doesn't exist
    template <typename T = Object, std::enable_if_t<!has_ostream_operator<T>::value, int> = 0>
    void printList() {
        static_assert(has_ostream_operator<T>::value, "operator<< is not defined for this type");
    }



    template <typename T = Object, typename std::enable_if<!std::is_same<T, int>::value && !std::is_same<T, char>::value && !std::is_same<T, float>::value && !std::is_same<T, double>::value && !std::is_same<T, bool>::value && !std::is_same<T, short>::value && !std::is_same<T, long>::value && !std::is_same<T, long long>::value && !std::is_same<T, unsigned short>::value && !std::is_same<T, unsigned int>::value && !std::is_same<T, unsigned long>::value && !std::is_same<T, unsigned long long>::value>::type* = nullptr>
    bool contains(Object* inputData) {
        List_Node<Object>* currentNode = head;
        while(currentNode != NULL && currentNode->getData() != inputData) {
            currentNode = currentNode->getNext();
        }

        if (currentNode == NULL) {
            return false;
        }

        return true;
    }

    template <typename T = Object, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, char>::value || std::is_same<T, float>::value || std::is_same<T, double>::value || std::is_same<T, bool>::value || std::is_same<T, short>::value || std::is_same<T, long>::value || std::is_same<T, long long>::value || std::is_same<T, unsigned short>::value || std::is_same<T, unsigned int>::value || std::is_same<T, unsigned long>::value || std::is_same<T, unsigned long long>::value>::type* = nullptr>
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

    
    template <typename T = Object, typename std::enable_if<!std::is_same<T, int>::value && !std::is_same<T, char>::value && !std::is_same<T, float>::value && !std::is_same<T, double>::value && !std::is_same<T, bool>::value && !std::is_same<T, short>::value && !std::is_same<T, long>::value && !std::is_same<T, long long>::value && !std::is_same<T, unsigned short>::value && !std::is_same<T, unsigned int>::value && !std::is_same<T, unsigned long>::value && !std::is_same<T, unsigned long long>::value>::type* = nullptr>
    List_Node<Object>* deleteNode(Object* nodeToDelete) {
        //static_assert(has_equality_operator<Object>::value, "operator== is not defined for this type");
        //static_assert(has_inequality_operator<Object>::value, "operator!= is not defined for this type");   

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

    template <typename T = Object, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, char>::value || std::is_same<T, float>::value || std::is_same<T, double>::value || std::is_same<T, bool>::value || std::is_same<T, short>::value || std::is_same<T, long>::value || std::is_same<T, long long>::value || std::is_same<T, unsigned short>::value || std::is_same<T, unsigned int>::value || std::is_same<T, unsigned long>::value || std::is_same<T, unsigned long long>::value>::type* = nullptr>
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


    template <typename T = Object, typename std::enable_if<!std::is_same<T, int>::value && !std::is_same<T, char>::value && !std::is_same<T, float>::value && !std::is_same<T, double>::value && !std::is_same<T, bool>::value && !std::is_same<T, short>::value && !std::is_same<T, long>::value && !std::is_same<T, long long>::value && !std::is_same<T, unsigned short>::value && !std::is_same<T, unsigned int>::value && !std::is_same<T, unsigned long>::value && !std::is_same<T, unsigned long long>::value>::type* = nullptr>
    Object* getObjAtIndex(int index) {
        assert(index < size);

        int counter = 0;
        List_Node<Object>* currentNode = head;
        while(counter < index) {
            currentNode = currentNode->getNext();
            counter++;
        }

        return currentNode->getData();

    }

    template <typename T = Object, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, char>::value || std::is_same<T, float>::value || std::is_same<T, double>::value || std::is_same<T, bool>::value || std::is_same<T, short>::value || std::is_same<T, long>::value || std::is_same<T, long long>::value || std::is_same<T, unsigned short>::value || std::is_same<T, unsigned int>::value || std::is_same<T, unsigned long>::value || std::is_same<T, unsigned long long>::value>::type* = nullptr>
    Object getObjAtIndex(int index) {
        assert(index < size);

        int counter = 0;
        List_Node<Object>* currentNode = head;
        while(counter < index) {
            currentNode = currentNode->getNext();
            counter++;
        }

        return currentNode->getData();

    }
};



#endif