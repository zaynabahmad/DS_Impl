#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "stack/stack.h"
#include "queue/queue.h"
#include "customer_ser/customer_ser.h"

// global variables
Stack carStack;
Queue carQueue;

int main() {
    // initialize stack and queue
    CreateStack(&carStack);
    CreateQueue(&carQueue);

    int choice;
    do {
        // display menu
        printf("\n1. Add a New Customer.\n");
        printf("2. Serve a Customer.\n");
        printf("3. How many Customers are waiting?\n");
        printf("4. Display Customers Information.\n");
        printf("5. Display Customers information in a \"most-recent\" Order.\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                serveCustomer();
                break;
            case 3:
                printf("Number of waiting customers: %d\n", QueueSize(&carQueue));
                break;
            case 4:
                displayWaitingCustomers();
                break;
            case 5:
                displayCustomersInReverse();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    // clear stack and queue
    ClearStack(&carStack);
    ClearQueue(&carQueue);

    return 0;
}

