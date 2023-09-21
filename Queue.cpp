/*
 Calvin Aduma
 */

#include "Queue.h"
#include <iostream>

using namespace std;

const int MAX_QUEUE_SIZE = 100;

Queue::Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

Queue::linked_list* Queue::rear(){
    return tail;
}

Queue::linked_list* Queue::front(){
    return head;
}

void Queue::enqueue( int num ){
    linked_list *temp = new linked_list( num, NULL );
    if( head==NULL ){ // Queue is empty
        head = temp;
        tail = head;
    } else if( !isFull() ){ // Queue is not empty and not full
        tail->next = temp;
        tail = tail->next;
    } else { // Queue is full
        return;
    }
    size++;
}

void Queue::dequeue(){
    if( isEmpty() ){ // Queue is empty
        return;
    } else { // Queue is not empty
        linked_list *temp = head;
        head = head->next;
        delete( temp ); // deletes unused memory to prevent leakage
    }
    size--;
}

bool Queue::isFull(){
    return size == MAX_QUEUE_SIZE;
}

bool Queue::isEmpty(){
    return size == 0;
}

int Queue::getSize(){
    return size;
}
