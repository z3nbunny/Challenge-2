/* *************************************************
* Name: David McGovern
* Assignment: Challenge 2: Queues
* Purpose: Defines a linked-list-based queue capable
*          of operating with FIFO or LIFO behavior.
************************************************* */

#ifndef QUEUE_H
#define QUEUE_H

#include <string>

/*
 * Queue algorithm flags used during construction.
 */
const bool FIFO = true;
const bool LIFO = false;

/*
 * Stores the user-provided queue information.
 */
struct Data {
    int id;
    std::string information;
};

/*
 * Stores queue data and links neighboring nodes.
 */
struct Node {
    Data data;
    Node* next;
    Node* prev;
};

class Queue {
public:
    /**********************
    * Constructors/Destructor
    ***********************/
    Queue(bool);
    ~Queue();

    /**********************
    * Getters/Accessors
    ***********************/
    int peek() const;
    int count() const;
    bool exists(int) const;
    int find(int) const;

    /**********************
    * Setters/Mutators
    ***********************/
    bool push(int, const std::string&);
    bool pull(Data&);
    void clear();

    /**********************
    * Printing Methods
    ***********************/
    // Intentionally blank; the queue performs no console output.

private:
    /**********************
    * Methods
    ***********************/
    void pullHead(Data&);
    void pullTail(Data&);

    /**********************
    * Attributes
    ***********************/
    Node* head;
    Node* tail;
    int size;
    bool fifo;
};

#endif /* QUEUE_H */