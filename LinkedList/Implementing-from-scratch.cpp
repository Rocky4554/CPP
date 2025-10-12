#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // Node is a data type like int

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head; // attriutes
    Node *tail;

public:
    List()
    {
        head = tail = NULL; // initialising head and tail with null as no node is present in starting
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        { // if head is null then linked list is empty
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        { // if head is null then linked list is empty
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        { // if head is null then linked list is empty
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
        } // both approch are correct
        //  else{
        //     Node* temp = head->next;
        //     head->next= NULL;
        //     head=temp;
        // }
    }

    void pop_back()
    {
        if (head == NULL)
        { // if head is null then linked list is empty
            return;
        }
        else
        { // if tail exists
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = (*temp).next;
            }
            temp->next = NULL;
            delete tail; // delete the variable permanently from heap memory
            tail = temp;
        }
        //  else{ // if tail does not exists
        //     Node* temp = head;
        //     while(temp->next->next!=NULL){
        //         temp=(*temp).next;
        //     }
        //     temp->next = NULL;
        // }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insertAtPos(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid pos\n";
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtPos(int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid pos\n";
            return;
        }
        if (pos == 0)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if(temp->next->next==NULL){
            temp->next=NULL;
        }
        else{
            temp->next=temp->next->next;
            
        }
    }

    int search(int val)
    {
        Node *temp = head;
        int c = 0;
        while (temp->data != val)
        {
            temp = temp->next;
            c++;
        }
        if (temp->data == val)
        {
            return c;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original linked list" << endl;
    ll.print();

    cout << " pop_front from original linked list" << endl;
    ll.pop_front();
    ll.print();

    cout << " pop_back from original linked list" << endl;
    ll.pop_back();
    ll.print();

    cout << " InsertAtPos in linked list" << endl;
    ll.insertAtPos(1, 0); // inserting node 1 and position 0 (0 based indexing like array)
    ll.print();

    cout << " Searching in linked list" << endl;
    cout << "Element found at index:" << ll.search(1) << endl; // inserting node 1 and position 0 (0 based indexing like array)

    cout << " deleteAtPos in linked list" << endl;
    ll.deleteAtPos(0); // inserting node 1 and position 0 (0 based indexing like array)
    ll.print();
    return 0;
}