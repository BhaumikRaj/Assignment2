#include <iostream>

using namespace std;

// Node class 
template <class T>
class Node
{
public:
    // priority to store priority
    int priority;
    // data to store user delaread data
    T data;
    // next will point to next Node
    Node* next;

    // default constructor
    Node()
    {
        priority = 0;
        next = nullptr;
    }

    // paramterized constructor
    // to initialize data members
    Node(int priority, T data)
    {
        this->priority = priority;
        this->data = data;
        next = nullptr;
    }
};

// PrioriyQueue class 
template <class T>
class PriorityQueue
{
private:
    // head will store the head of the linked list
    Node<T>* head;

public:
    //default constructor 
    PriorityQueue()
    {
        // intializes head with null
        head = nullptr;
    }

    // IsEmpty function 
    
    bool IsEmpty()
    {
        // if head is null
        if (head == nullptr)
        {
            // then return true
            return true;
        }
        // else return false
        return false;
    }

    // Pop function 
   
    void Pop()
    {
        // checking whether PriorityQueue is empty or not
        if (IsEmpty())
        {
            // if empty , then simply returns from the function
            return;
        }

        // else store pointer address of head to deleteNode
        Node<T>* deleteNode = head;
        // then assign head pointer with its next node address
        head = head->next;
        // now, release memory by deleting deleteNode
        delete deleteNode;
    }

    // Push function definition
    // use to insert element into the PriorityQueue based on its priority
    void Push(int priority, T data)
    {
        // creating a newNode with the given priority and data
        Node<T>* newNode = new Node<T>(priority, data);

        // check if PriorityQueue is empty or not
        if (IsEmpty())
        {
            // if empty, then assign head to point the newNode
            head = newNode;
            // then returns from the function
            return;
        }

        // else assign temp with head address
        Node<T>* temp = head;
        // assign prev with null value
        Node<T>* prev = nullptr;

        
        
        while (temp != nullptr)
        {
            // if temp node's priority is greater than equal to 
            // given priority then just exit the loop
            if (temp->priority >= priority)
            {
                break;
            }

            // else
            // assign prev with temp's address
            prev = temp;
            // assign temp node with its next node's address
            temp = temp->next;
        }

       
        if (prev == nullptr)
        {
            // assign newNode next with the address of head
            newNode->next = head;
            // assign head with the address of newNode
            head = newNode;
        }
        // else
        else
        {
            // assign prev node's next with the address of newNode
            prev->next = newNode;
            // and assign new node's next with the address of temp
            newNode->next = temp;
        }
    }

    // Front function definition
    // returns the front element from the PriorityQueue
    T Front()
    {
        if (IsEmpty())
        {
            return (T)0;
        }
        T val = head->data;
        return val;
    }
};


int main()
{
    // created PriorityQueue class's object 'pq'
    PriorityQueue<int> pq;

    
    pq.Push(4, 2); //pq: 2
    pq.Push(1, 4); //pq: 4 2 
    pq.Push(2, 3); //pq: 4 3 2
    pq.Push(3, 24);//pq: 4 3 24 2
    pq.Push(5, 10);//pq: 4 3 24 2 10
    cout << pq.Front() << endl; //this will give output 4

    // call to Pop function to remove front element
    pq.Pop(); // removes 4, pq: 3 24 2 10
    pq.Push(1, 3); //pq: 3 3 24 2 10

   
    while (!pq.IsEmpty())
    {
        cout << pq.Front() << endl;
        pq.Pop();
    }

    // final expected output will be:
    // 4
    // 3
    // 3
    // 24
    // 2
    // 10
    return 0;
}