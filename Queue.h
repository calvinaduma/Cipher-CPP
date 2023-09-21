/*
 Calvin Aduma
 */

#ifndef QUEUE_H
#define QUEUE_H

class Queue{
    private:
        int size;
    public:
        struct linked_list{
            int data;
            linked_list *next;
            linked_list(int num, linked_list *nextPtr ){
                data = num;
                next = nextPtr;

            }
        };
        linked_list *head;
        linked_list *tail;

        // deafult constructor for linked list
        Queue();

        // returns last position of queue
        linked_list* rear();

        // returns first position of queue
        linked_list* front();

        // add element to the rear of queue
        void enqueue( int );

        // remove element from front of queue
        void dequeue();

        // returns TRUE if queue is full
        bool isFull();

        // returns TRUE is queue is empty
        bool isEmpty();

        // returns size of queue
        int getSize();
};

#endif
