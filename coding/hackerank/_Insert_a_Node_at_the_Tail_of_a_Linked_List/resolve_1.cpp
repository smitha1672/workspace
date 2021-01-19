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

    if (head == nullptr) {
        head = newnode;
    } else {
        SinglyLinkedListNode* cur_node = head;

        while (cur_node->next != nullptr)
            cur_node = cur_node->next;
        cur_node->next = newnode;
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

    for (int i = 0; i < 5; i++) {
        SinglyLinkedListNode* llist_head;
        llist_head = insertNodeAtTail(llist->head, i+1);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head);


    return 0;
}
