#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "stack.h"
#include "queue.h"
#include "customer_ser.h"

Stack carStack;
Queue carQueue;

void addCustomer() {
    // get customer information
    char name[MAX_NAME];
    int id, year;
    printf("Enter customer name: ");
    scanf("%s", name);
    printf("Enter customer ID: ");
    scanf("%d", &id);
    printf("Enter car model year: ");
    scanf("%d", &year);

    // create new customer
    ElementType customer;
    strcpy(customer.name, name);
    customer.id = id;
    customer.model_year = year;

    // add customer to queue
    if (!isQueueFull(&carQueue)) {
        enqueue(customer.id, &carQueue);
        printf("Customer added to waiting list.\n");
    } else {
        printf("Waiting list is full, please try again later.\n");
    }
}

void serveCustomer() {
    // check if there are customers waiting
    if (!isQueueEmpty(&carQueue)) {
        // get customer from queue
        ElementType customer;
        dequeue(&customer.id, &carQueue);

        // push customer onto stack
        if (!isStackFull(&carStack)) {
            push(customer, &carStack);
            printf("Serving customer: %s (ID: %d, Model Year: %d)\n", customer.name, customer.id, customer.model_year);
        } else {
            printf("Unable to serve customer, stack is full.\n");
        }
    } else {
        printf("No customers waiting to be served.\n");
    }
}

void displayWaitingCustomers() {
    // create temporary queue to hold customers
    Queue tempQueue;
    CreateQueue(&tempQueue);

    // serve all customers and add them to temporary queue
    printf("Customers currently waiting:\n");
    while (!isQueueEmpty(&carQueue)) {
        ElementType customer;
        dequeue(&customer.id, &carQueue);
        printf("%s (ID: %d, Model Year: %d)\n", customer.name, customer.id, customer.model_year);
        enqueue(customer.id, &tempQueue);
    }

    // add customers back to original queue
    while (!isQueueEmpty(&tempQueue)) {
    ElementType customer;
    dequeue(&customer.id, &tempQueue);
    enqueue(customer.id, &carQueue);
    }
    }


    void displayCustomersInReverse() {
// create temporary stack to hold customers
Stack tempStack;
CreateStack(&tempStack);
// serve all customers and add them to temporary stack
while (!isQueueEmpty(&carQueue)) {
    ElementType customer;
    dequeue(&customer.id, &carQueue);
    push(customer, &tempStack);
}

// add customers back to original queue and display in reverse order
printf("Customers in most-recent order:\n");
while (!isStackEmpty(&tempStack)) {
    ElementType customer;
    pop(&customer, &tempStack);
    printf("%s (ID: %d, Model Year: %d)\n", customer.name, customer.id, customer.model_year);
    enqueue(customer.id, &carQueue);
}
    }
