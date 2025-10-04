#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for Stack
struct Stack
{
    int arr[MAX_SIZE];
    int top;
    int capacity;
};

// Function to initialize stack
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    printf("Stack created with capacity: %d\n", capacity);
    return stack;
}

// Function to check if stack is full
bool isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Function to check if stack is empty
bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack Overflow! Cannot push %d\n", item);
        return;
    }

    stack->arr[++stack->top] = item;
    printf("Pushed: %d\n", item);
    printf("Stack after push: ");
    display(stack);
}

// Function to pop an element
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1;
    }
    int item = stack->arr[stack->top--];
    printf("Popped: %d\n", item);
    printf("Stack after pop: ");
    display(stack);
    return item;
}

// Function to peek/top element
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    printf("Top element: %d\n", stack->arr[stack->top]);
    return stack->arr[stack->top];
}

// Function to display stack
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: [");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d", stack->arr[i]);
        if (i < stack->top)
            printf(", ");
    }
    printf("] <- Top\n");
}

// Function to get stack size
int size(struct Stack *stack)
{
    return stack->top + 1;
}

// Function to demonstrate all operations
void demonstrateOperations()
{
    printf("=== STACK OPERATIONS DEMONSTRATION ===\n\n");

    struct Stack *stack = createStack(5);

    printf("\n1. Initial State:\n");
    display(stack);
    printf("Is Empty: %s\n", isEmpty(stack) ? "Yes" : "No");
    printf("Is Full: %s\n", isFull(stack) ? "Yes" : "No");

    printf("\n2. Push Operations:\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("\n3. Peek Operation:\n");
    peek(stack);

    printf("\n4. Pop Operation:\n");
    pop(stack);

    printf("\n5. More Push Operations:\n");
    push(stack, 40);
    push(stack, 50);
    push(stack, 60); // This should cause overflow

    printf("\n6. Current Stack Status:\n");
    display(stack);
    printf("Stack size: %d\n", size(stack));
    printf("Is Full: %s\n", isFull(stack) ? "Yes" : "No");

    printf("\n7. Pop All Elements:\n");
    while (!isEmpty(stack))
    {
        pop(stack);
    }

    printf("\n8. Try Pop from Empty Stack:\n");
    pop(stack); // This should cause underflow

    free(stack);
}

int main()
{
    int choice, element;
    struct Stack *stack = createStack(5);

    while (1)
    {
        printf("\n=== STACK OPERATIONS MENU ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Get Size\n");
        printf("8. Demonstrate All Operations\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(stack, element);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            peek(stack);
            break;

        case 4:
            display(stack);
            break;

        case 5:
            printf("Stack is %s\n", isEmpty(stack) ? "Empty" : "Not Empty");
            break;

        case 6:
            printf("Stack is %s\n", isFull(stack) ? "Full" : "Not Full");
            break;

        case 7:
            printf("Stack size: %d\n", size(stack));
            break;

        case 8:
            demonstrateOperations();
            break;

        case 9:
            printf("Exiting program...\n");
            free(stack);
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for Queue
struct Queue
{
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
    int capacity;
};

// Function to initialize queue
struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    printf("Queue created with capacity: %d\n", capacity);
    return queue;
}

// Function to check if queue is full
bool isFull(struct Queue *queue)
{
    return queue->size == queue->capacity;
}

// Function to check if queue is empty
bool isEmpty(struct Queue *queue)
{
    return queue->size == 0;
}

// Function to enqueue an element
void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue Overflow! Cannot enqueue %d\n", item);
        return;
    }

    // If queue is empty, set front to 0
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
}

// Function to dequeue an element
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }

    int item = queue->arr[queue->front];

    queue->size--;
    printf("Dequeued: %d\n", item);
    printf("Queue after dequeue: ");
    display(queue);
    return item;
}

// Function to get front element
int front(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty! No front element\n");
        return -1;
    }

    printf("Front element: %d\n", queue->arr[queue->front]);
    return queue->arr[queue->front];
}

// Function to get rear element
int rear(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty! No rear element\n");
        return -1;
    }

    printf("Rear element: %d\n", queue->arr[queue->rear]);
    return queue->arr[queue->rear];
}

// Function to display queue
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: Front -> [");
    int i = queue->front;
    for (int count = 0; count < queue->size; count++)
    {
        printf("%d", queue->arr[i]);
        if (count < queue->size - 1)
            printf(", ");
        i = (i + 1) % queue->capacity;
    }
    printf("] <- Rear\n");
}

// Function to get queue size
int size(struct Queue *queue)
{
    return queue->size;
}

// Function to demonstrate all operations
void demonstrateOperations()
{
    printf("\n=== QUEUE OPERATIONS DEMONSTRATION ===\n\n");

    struct Queue *queue = createQueue(5);

    printf("\n1. Initial State:\n");
    display(queue);
    printf("Is Empty: %s\n", isEmpty(queue) ? "Yes" : "No");
    printf("Is Full: %s\n", isFull(queue) ? "Yes" : "No");

    printf("\n2. Enqueue Operations:\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("\n3. Front and Rear Operations:\n");
    front(queue);
    rear(queue);

    printf("\n4. Dequeue Operation:\n");
    dequeue(queue);

    printf("\n5. More Enqueue Operations:\n");
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60); // This should fill the queue
    enqueue(queue, 70); // This should cause overflow

    printf("\n6. Current Queue Status:\n");
    display(queue);
    printf("Queue size: %d\n", size(queue));
    printf("Is Full: %s\n", isFull(queue) ? "Yes" : "No");

    printf("\n7. Dequeue All Elements:\n");
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }

    printf("\n8. Try Dequeue from Empty Queue:\n");
    dequeue(queue); // This should cause underflow

    printf("\n9. Test Circular Nature:\n");
    enqueue(queue, 100);
    enqueue(queue, 200);
    dequeue(queue);
    enqueue(queue, 300);
    display(queue);

    free(queue);
}

int main()
{
    int choice, element;
    struct Queue *queue = createQueue(5);

    while (1)
    {
        printf("\n=== QUEUE OPERATIONS MENU ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Rear\n");
        printf("5. Display\n");
        printf("6. Check if Empty\n");
        printf("7. Check if Full\n");
        printf("8. Get Size\n");
        printf("9. Demonstrate All Operations\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(queue, element);
            break;

        case 2:
            dequeue(queue);
            break;

        case 3:
            front(queue);
            break;

        case 4:
            rear(queue);
            break;

        case 5:
            display(queue);
            break;

        case 6:
            printf("Queue is %s\n", isEmpty(queue) ? "Empty" : "Not Empty");
            break;

        case 7:
            printf("Queue is %s\n", isFull(queue) ? "Full" : "Not Full");
            break;

        case 8:
            printf("Queue size: %d\n", size(queue));
            break;

        case 9:
            demonstrateOperations();
            break;

        case 10:
            printf("Exiting program...\n");
            free(queue);
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for Circular Queue
struct CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
};

// Function to create circular queue
struct CircularQueue *createCircularQueue(int capacity)
{
    struct CircularQueue *cq = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    cq->arr = (int *)malloc(capacity * sizeof(int));
    cq->capacity = capacity;
    cq->front = -1;
    cq->rear = -1;
    cq->size = 0;

    printf("Circular Queue created with capacity: %d\n", capacity);
    printf("Array indices: 0 to %d (circular)\n\n", capacity - 1);
    return cq;
}

// Function to check if queue is empty
bool isEmpty(struct CircularQueue *cq)
{
    return cq->size == 0;
}

// Function to check if queue is full
bool isFull(struct CircularQueue *cq)
{
    return cq->size == cq->capacity;
}

// Function to get next position (circular)
int getNextPosition(int current, int capacity)
{
    return (current + 1) % capacity;
}

// Function to enqueue element
void enqueue(struct CircularQueue *cq, int item)
{
    printf("\n--- ENQUEUE OPERATION ---\n");
    printf("Attempting to enqueue: %d\n", item);

    if (isFull(cq))
    {
        printf("Queue Overflow! Cannot enqueue %d\n", item);
        printf("Queue is full with %d elements\n", cq->size);
        return;
    }
    if (isEmpty(cq))
    {
        cq->front = 0;
        cq->rear = 0;
    }
    else
    {
        cq->rear = getNextPosition(cq->rear, cq->capacity);
    }
    cq->arr[cq->rear] = item;
    cq->size++;
    printf(" Successfully enqueued: %d\n", item);
    printf("Position: arr[%d] = %d\n", cq->rear, item);
    printf("Front: %d, Rear: %d, Size: %d\n", cq->front, cq->rear, cq->size);
    displayCircularStructure(cq);
}

// Function to dequeue element
int dequeue(struct CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    int item = cq->arr[cq->front];
    printf("Dequeuing from position: arr[%d] = %d\n", cq->front, item);
    if (cq->size == 1)
    {
        cq->front = -1;
        cq->rear = -1;
    }
    else
    {
        cq->front = getNextPosition(cq->front, cq->capacity);
    }
    cq->size--;
    printf("Successfully dequeued: %d\n", item);
    printf("New Front: %d, Rear: %d, Size: %d\n",
           cq->front, cq->rear, cq->size);
    displayCircularStructure(cq);
    return item;
}

// Function to get front element
int front(struct CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty! No front element\n");
        return -1;
    }

    printf("Front element: %d (at position %d)\n", cq->arr[cq->front], cq->front);
    return cq->arr[cq->front];
}

// Function to get rear element
int rear(struct CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty! No rear element\n");
        return -1;
    }

    printf("Rear element: %d (at position %d)\n", cq->arr[cq->rear], cq->rear);
    return cq->arr[cq->rear];
}

// Function to display queue elements in order
void display(struct CircularQueue *cq)
{
    printf("\n--- QUEUE CONTENTS ---\n");

    if (isEmpty(cq))
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements (FIFO order): ");
    int current = cq->front;

    for (int i = 0; i < cq->size; i++)
    {
        printf("%d", cq->arr[current]);
        if (i < cq->size - 1)
            printf(" <- ");
        current = getNextPosition(current, cq->capacity);
    }
    printf("\n");
    printf("Direction: Front → → → Rear\n");
}

// Function to show circular structure visually
void displayCircularStructure(struct CircularQueue *cq)
{
    printf("\n--- CIRCULAR ARRAY VISUALIZATION ---\n");
    printf("Array: [");

    for (int i = 0; i < cq->capacity; i++)
    {
        if (isEmpty(cq))
        {
            printf(" _ ");
        }
        else
        {
            // Check if this position is within the queue
            bool inQueue = false;
            int current = cq->front;
            for (int j = 0; j < cq->size; j++)
            {
                if (current == i)
                {
                    inQueue = true;
                    break;
                }
                current = getNextPosition(current, cq->capacity);
            }

            if (inQueue)
            {
                printf("%2d", cq->arr[i]);
                if (i == cq->front && i == cq->rear)
                {
                    printf("(F,R)");
                }
                else if (i == cq->front)
                {
                    printf("(F)");
                }
                else if (i == cq->rear)
                {
                    printf("(R)");
                }
                else
                {
                    printf("   ");
                }
            }
            else
            {
                printf(" _ ");
            }
        }

        if (i < cq->capacity - 1)
            printf(" ");
    }
    printf("]\n");

    printf("Indices: ");
    for (int i = 0; i < cq->capacity; i++)
    {
        printf("%2d     ", i);
    }
    printf("\n");
    printf("Legend: F=Front, R=Rear, _=Empty\n");
}

// Function to demonstrate circular nature
void demonstrateCircularNature()
{
    printf("\n🔄 === CIRCULAR QUEUE DEMONSTRATION ===\n");

    struct CircularQueue *cq = createCircularQueue(6);

    printf("📋 STEP 1: Fill queue to show normal operation\n");
    enqueue(cq, 10);
    enqueue(cq, 20);
    enqueue(cq, 30);
    enqueue(cq, 40);
    display(cq);

    printf("\n📋 STEP 2: Remove some elements from front\n");
    dequeue(cq);
    dequeue(cq);
    display(cq);

    printf("\n📋 STEP 3: Add more elements (circular wraparound)\n");
    enqueue(cq, 50);
    enqueue(cq, 60);
    enqueue(cq, 70);
    enqueue(cq, 80); // This should demonstrate circular behavior
    display(cq);

    printf("\n📋 STEP 4: Try to exceed capacity\n");
    enqueue(cq, 90); // Should show overflow

    printf("\n📋 STEP 5: Show front and rear positions\n");
    front(cq);
    rear(cq);

    printf("\n📋 STEP 6: Empty the queue\n");
    while (!isEmpty(cq))
    {
        dequeue(cq);
    }

    printf("\n📋 STEP 7: Try dequeue from empty queue\n");
    dequeue(cq);

    free(cq->arr);
    free(cq);
}

// Main function with menu
int main()
{
    int choice, element, capacity;
    struct CircularQueue *cq = NULL;

    printf("🔄 CIRCULAR QUEUE IMPLEMENTATION\n");
    printf("================================\n");

    printf("Enter queue capacity: ");
    scanf("%d", &capacity);

    if (capacity <= 0)
    {
        printf("Invalid capacity! Setting to default: 5\n");
        capacity = 5;
    }

    cq = createCircularQueue(capacity);

    while (1)
    {
        printf("\n🔄 === CIRCULAR QUEUE MENU ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Front\n");
        printf("4. Display Rear\n");
        printf("5. Display Queue\n");
        printf("6. Check if Empty\n");
        printf("7. Check if Full\n");
        printf("8. Show Circular Structure\n");
        printf("9. Get Size\n");
        printf("10. Demonstrate Circular Nature\n");
        printf("11. Exit\n");
        printf("Enter your choice (1-11): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(cq, element);
            break;

        case 2:
            dequeue(cq);
            break;

        case 3:
            front(cq);
            break;

        case 4:
            rear(cq);
            break;

        case 5:
            display(cq);
            break;

        case 6:
            printf("Queue is %s\n", isEmpty(cq) ? "Empty ❌" : "Not Empty ✅");
            break;

        case 7:
            printf("Queue is %s\n", isFull(cq) ? "Full ❌" : "Not Full ✅");
            break;

        case 8:
            displayCircularStructure(cq);
            break;

        case 9:
            printf("Current queue size: %d/%d\n", cq->size, cq->capacity);
            break;

        case 10:
            demonstrateCircularNature();
            break;

        case 11:
            printf("Exiting program... 👋\n");
            free(cq->arr);
            free(cq);
            exit(0);

        default:
            printf("❌ Invalid choice! Please enter 1-11.\n");
        }
    }

    return 0;
}