#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <vector>
#include <limits>

/*ONELINKED LIST*/
/*PART ONE - JUST AN OLL*/

struct Node
{
    int m_data;
    Node* m_next;
    Node(int _data) : m_data(_data), m_next(nullptr) {}
};

struct OneLinkedList
{
    Node* m_head;
    Node* m_tail;

    OneLinkedList() :   m_head(nullptr), m_tail(nullptr) {}

    bool isEmpty() { return m_head == nullptr; }

    void pushFront(int _data)
    {
        Node* pushNode = new Node(_data);
        if (isEmpty())
        {
            m_head = pushNode;
            m_tail = pushNode;
        }
        else
        {
            pushNode->m_next = m_head;
            m_head = pushNode;
        }
    }

    void pushBack(int _data)
    {
        Node* pushNode = new Node(_data);
        if (isEmpty())
        {
            m_head = pushNode;
            m_tail = pushNode;
            return;
        }
        m_tail->m_next = pushNode;
        m_tail = pushNode;
    }

    void pushBack(int _data) 
    {
        Node* pushNode = new Node(_data);
        if (isEmpty())
        {
            m_head = pushNode;
            m_tail = pushNode;
            return;
        } 
        m_tail->m_next = pushNode;
        m_tail = pushNode;
    } 

    void print()
    {
        if (isEmpty()) return;
        Node* pushNode = m_head;
        while (pushNode)
        {
            std::cout << pushNode->m_data << " ";
            pushNode = pushNode->m_next;
        }
        std::cout << std::endl;
    }

    Node* find(int _data)
    {
        Node* pushNode = m_head;
        while (pushNode && pushNode->m_data != _data) pushNode = pushNode->m_next;
        return (pushNode && pushNode->m_data == _data) ? pushNode : nullptr;
    }

    void removeFirst()
    {
        if (isEmpty()) return;
        Node* pushNode = m_head;
        m_head = pushNode->m_next;
        delete pushNode;
        if (m_head == nullptr) m_tail = nullptr;  // если удален последний элемент
    }

    void removeLast()
    {
        if (isEmpty()) return;
        if (m_head == m_tail)
        {
            removeFirst();
            return;
        }
        Node* pushNode = m_head;
        while (pushNode->m_next != m_tail) pushNode = pushNode->m_next;
        pushNode->m_next = nullptr;
        delete m_tail;
        m_tail = pushNode;
    }

    void remove(int index)  // удаление узла по индексу
    {
        if (isEmpty()) return; // удалять нечего
        if (index == 0)
        {// index = 0 ~> удаляем 1 элемент
            removeFirst();
            return;
        }
        Node* current = m_head;
        for (int i = 0; i < index - 1; i++)
        {
            if (!current->m_next) return;  // если индекс > длины списка
            current = current->m_next; // к следующему элементу
        }
        Node* toDelete = current->m_next;
        if (toDelete == m_tail) m_tail = current;  // удаляем последний элемент
        current->m_next = toDelete->m_next;
        delete toDelete; // yдаляем элемент toDelete
    }



    Node* operator[] (const int index) //это перегрузка оператора квадратных скобок, 
    // которая позволяет использовать экземпляры пользовательских классов и структур так же, 
    // как и массивы, для доступа к элементам по индексу..
    // перегрузили оператор [] для класса или структуры - сможем обращаться по индексу: object[k], k - номер элемента
    // Внутри можно реализовать логику, которая будет выполняться при доступе к элементу через указанный индекс
    {
        if (isEmpty()) return nullptr; // if (пусто) return nullptr 
        Node* pushNode = m_head; // иниц. головного узла, к-й будет двигаться по списку
        for (int i = 0; i < index; i++) 
        {
            pushNode = pushNode->m_next; // переход к следующему узлу
            if (!pushNode) return nullptr; // достигнут конец списка
        }
        return pushNode; // узел с заданным index
    }
};


int main()
{
    OneLinkedList list;
    int q;
    std::cin >> q;  // количество команд

    int* type = new int[q];
    int* numX = new int[q];
    int* numY = new int[q];

    for (int i = 0; i < q; i++)
    {
        std::cin >> type[i] >> numX[i];
        if (type[i] == 1) // для команды 1, считываем и numY
        {
            std::cin >> numY[i];
        }
    }

    for (int i = 0; i < q; i++)
    {
        switch (type[i])
        {
            case 1:  // 1 тип - добавить число numY после numX-ого числа в списке
            {
                if (numX[i] == 0)
                {
                    // если numX = 0, добавляем в начало списка тк X не сущ-ет
                    list.pushFront(numY[i]);
                }
                else
                {
                    // находим numX-ый элемент через перегрузку [] из методов списка
                    Node* X = list[numX[i] - 1];
                    if (X != nullptr)
                    {
                        // добавляем c У после numX-ого узла
                        Node* newNode = new Node(numY[i]);
                        newNode->m_next = X->m_next;
                        X->m_next = newNode;
                        if (X == list.m_tail)
                        {
                            list.m_tail = newNode;
                        }
                    }
                }
                break;
            }
           
            case 2:  // 2 тип - вывести число, которое находится на позиции numX в списке
            {
                Node* X = list[numX[i] - 1];
                if (X != nullptr)
                { 
                    std::cout << X->m_data << std::endl; // если узел найден, выводим его данные
                }
                else
                {
                    std::cout << "Error: Invalid index" << std::endl;
                }
                break;
            }

            case 3:  // 3 тип - удалить число, которое находится на позиции numX в списке
            {
                list.remove(numX[i] - 1); // убираем элемент с позиции numX[i] - 1
                break;
            }
        }
    }

    delete[] type;
    delete[] numX;
    delete[] numY;
    return 0;
}


// class Node
// {
//     public:
//     int m_data;
//     Node* m_next;
//     Node (int data) 
//     {
//         m_data = data;
//         m_next = nullptr;
//     }
// };

// class OneLinkedList
// {
//     public:
//     Node* m_head;
//     Node* m_tail; 
//     OneLinkedList () 
//     {
//         m_head = nullptr;
//         m_tail = nullptr;
//     }
//     ~OneLinkedList ()
//     {
//         while (m_head != nullptr) popFront();
//     }
// };

// void popFront ()
// {
//     if (m_head == nullptr) return;
//     if (m_head == m_tail) 
//     {
//         delete m_tail;
//         m_tail = nullptr;
//         m_head = nullptr;
//         return;
//     }
//     Node* newNodeTemp;
//     m_head = m_head->m_next;
//     delete NewnodeTemp;
// }

// void pushBack (int data)
// {
//     Node* newNode = new Node(data);
//     if (m_head == nullptr) m_head = newNode;
//     if (m_tail != nullptr) m_tail->m_next = newNode; 
//     m_tail = newNode;
// }

// void pushFront (int data)
// {
//     Node* newNode = new Node(data);
//     if (m_tail == nullptr) m_tail = newNode;
//     newNode->m_next = m_head;   
//     m_head = newNode;
// }

// void popBack() 
// {
//     if (m_tail == nullptr) return;
//     if (m_head == m_tail) {
//             delete m_tail;
//             m_head = m_tail = nullptr;
//             return;
//     }
//     Node* newNode = m_head;
//     for (; m_node->m_next != m_tail; newNode = newNode->m_next);
//     newNode->m_next = nullptr;
//     delete m_tail;
//     m_tail = newNode;
// }

// Node* getEltPtr(int k)
// {
//     if (k<0) return NULL;
//     Node* newNode = m_head;
//     int n = 0;
//     while (newNode && n != k && newNode->m_next) 
//     {
//         newNode = m_node->m_next;
//         n++;
//     }
//     return (n == k) ? newNode : NULL;
// }

// void insertElt (int k, int data) 
// {
//     Node* left = getEltPtr(k);
//     if (left == NULL) return;
//     Node* right = left->next;
//     Node* node = new Node(data);
//     left->next = node;
//     node->next = right;
//     if (right == NULL) m_tail = node;
// }

// void eraseElt (int k) 
//  {
//     if (k < 0) return;
//     if (k == 0)
//     {
//         popFront();
//         return;
//     }
//     Node* left = getEltPtr(k - 1);
//     Node* node = left->next;
//     if (node == NULL) return;
//     Node* right = node->next;
//     left->next = right;
//     if (node == tail) tail = left;
//     delete node;
// }

// int main()
//{
    // OneLinkedList lst;
    //     lst.pushFront(1);
    //     lst.pushBack(2);
            //     Node* n = lst.getEltPtr(0);
    //     double d = (n != NULL) ? n->data : 0;
    //     std::cout << d << std::endl;
    //     lst.eraseElt(1);
    //     lst.insertElt(0, 5);
    //     lst.insertElt(0, 2);
    //     lst.popBack();
    //     for (Node* node = lst.head; node != NULL; node = node->next) {
    //             std::cout << node->data << " ";
    //     }
    //     std::cout << std::endl;
    //     return 0;
// }
