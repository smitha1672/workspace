#include <iostream>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode *head;

    SinglyLinkedList()
    {
        this->head = nullptr;
    }

};

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data)
{
    SinglyLinkedListNode* newnode = new SinglyLinkedListNode(data);

    if (head == nullptr)
        head = newnode;
    else {
        SinglyLinkedListNode* temp = head;

        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newnode;
    }

    return head;
}

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data)
{
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);

    if (head == nullptr)
        head = node;
    else {
        SinglyLinkedListNode* temp = node;
        temp->next = head;
        head = temp;
    }

    return head;
}


void print_singly_linked_list(SinglyLinkedListNode* node)
{
    while (node) {
        cout << node->data << "\n";
        node = node->next;
    }
}

int main(void)
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    for (int i = 1; i <= 5; i++) {
        SinglyLinkedListNode* llist_head;
        llist_head = insertNodeAtTail(llist->head, i);
        llist->head = llist_head;
    }

    for (int i = 6; i <= 10; i++) {
        SinglyLinkedListNode* llist_head;
        llist_head = insertNodeAtHead(llist->head, i);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head);


    return 0;
}
