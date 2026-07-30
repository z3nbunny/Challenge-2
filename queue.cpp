/* *************************************************
* Name: David McGovern
* Assignment: Challenge 2: Queues
* Purpose: Implements a linked-list-based queue capable
*          of operating with FIFO or LIFO behavior.
************************************************* */

#include "queue.h"

Queue::Queue(bool queue_type) {
/* *************************************************
* Initializes an empty FIFO or LIFO queue.
*
* @param queue_type : flag specifying FIFO or LIFO behavior
* @exception : none
* @return none : constructor
* @note : The queue type cannot change after construction.
* ************************************************* */
    head = nullptr;
    tail = nullptr;
    size = 0;
    fifo = queue_type;
}

Queue::~Queue() {
/* *************************************************
* Deallocates all dynamically allocated queue nodes.
*
* @param : none
* @exception : none
* @return none : destructor
* @note : Delegates memory cleanup to clear().
* ************************************************* */
    clear();
}

bool Queue::push(int id, const std::string& information) {
/* *************************************************
* Adds a new item to the head of the queue.
*
* @param id : positive identifier for the new item
* @param information : non-empty string associated with the item
* @exception : none
* @return bool : true on success, false for invalid data
* @note : Allocation occurs only after input validation.
* ************************************************* */
    bool success = false;
    Node* new_node = nullptr;

    if (id > 0 && !information.empty()) {
        new_node = new Node;
        new_node->data.id = id;
        new_node->data.information = information;
        new_node->prev = nullptr;
        new_node->next = head;

        if (head != nullptr) {
            head->prev = new_node;
        } else {
            tail = new_node;
        }

        head = new_node;
        size++;
        success = true;
    }

    return success;
}

bool Queue::pull(Data& return_data) {
/* *************************************************
* Removes and returns the next item according to the
* queue's FIFO or LIFO algorithm.
*
* @param return_data : Data struct populated with the removed item
* @exception : none
* @return bool : true on success, false when the queue is empty
* @note : FIFO removes the tail; LIFO removes the head.
* ************************************************* */
    bool success = false;

    if (head != nullptr) {
        if (fifo) {
            pullTail(return_data);
        } else {
            pullHead(return_data);
        }

        size--;
        success = true;
    } else {
        return_data.id = -1;
        return_data.information = "";
    }

    return success;
}

int Queue::peek() const {
/* *************************************************
* Retrieves the id of the next item that could be pulled.
*
* @param : none
* @exception : none
* @return int : next id, or -1 when the queue is empty
* @note : Does not modify the queue.
* ************************************************* */
    int id = -1;

    if (head != nullptr) {
        if (fifo) {
            id = tail->data.id;
        } else {
            id = head->data.id;
        }
    }

    return id;
}

int Queue::count() const {
/* *************************************************
* Retrieves the number of items currently in the queue.
*
* @param : none
* @exception : none
* @return int : current number of queue items
* @note : Uses the maintained size attribute.
* ************************************************* */
    return size;
}

void Queue::clear() {
/* *************************************************
* Removes and deallocates every item in the queue.
*
* @param : none
* @exception : none
* @return void : none
* @note : Restores all empty-queue invariants.
* ************************************************* */
    Node* current = head;
    Node* next_node = nullptr;

    while (current != nullptr) {
        next_node = current->next;
        delete current;
        current = next_node;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool Queue::exists(int id) const {
/* *************************************************
* Determines whether an id exists anywhere in the queue.
*
* @param id : identifier to locate
* @exception : none
* @return bool : true if found, false otherwise
* @note : Searches without modifying the queue.
* ************************************************* */
    bool found = false;
    Node* current = head;

    while (current != nullptr && !found) {
        if (current->data.id == id) {
            found = true;
        } else {
            current = current->next;
        }
    }

    return found;
}

int Queue::find(int id) const {
/* *************************************************
* Finds the zero-based position of an id in the queue.
*
* @param id : identifier to locate
* @exception : none
* @return int : zero-based position, or -1 if not found
* @note : Per the challenge specification, FIFO positions
*         begin at the head and LIFO positions begin at the tail.
* ************************************************* */
    bool found = false;
    int position = -1;
    int current_position = 0;
    Node* current = nullptr;

    if (fifo) {
        current = head;
    } else {
        current = tail;
    }

    while (current != nullptr && !found) {
        if (current->data.id == id) {
            position = current_position;
            found = true;
        } else {
            current_position++;

            if (fifo) {
                current = current->next;
            } else {
                current = current->prev;
            }
        }
    }

    return position;
}

void Queue::pullHead(Data& return_data) {
/* *************************************************
* Removes and returns the current head node.
*
* @param return_data : Data struct populated from the head
* @exception : none
* @return void : none
* @note : Called only when the queue is not empty.
* ************************************************* */
    Node* removed_node = head;

    return_data.id = removed_node->data.id;
    return_data.information = removed_node->data.information;

    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete removed_node;
}

void Queue::pullTail(Data& return_data) {
/* *************************************************
* Removes and returns the current tail node.
*
* @param return_data : Data struct populated from the tail
* @exception : none
* @return void : none
* @note : Called only when the queue is not empty.
* ************************************************* */
    Node* removed_node = tail;

    return_data.id = removed_node->data.id;
    return_data.information = removed_node->data.information;

    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete removed_node;
}