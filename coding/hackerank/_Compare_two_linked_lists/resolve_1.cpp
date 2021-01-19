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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position)
{
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);

    if (head == nullptr)
        head = node;
    else {
        SinglyLinkedListNode* tail = head;

        if (position == 0) {
            node->next = tail->next;
            tail->next = node;
        } else if (position > 0) {
            for (int i = 1; i < position; i++)
                tail = tail->next;

            node->next = tail->next;
            tail->next = node;
        }
    }

    return head;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position)
{
    SinglyLinkedListNode* cur_node = nullptr;
    SinglyLinkedListNode* pre_node = nullptr;

    if (head == nullptr)
        return head;

    if (position == 0) {
        cur_node = head;
        head = cur_node->next;
        delete cur_node;
    } else if (position > 0) {
        cur_node = pre_node = head;

        for (int i = 0; i < position; i++) {
            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        pre_node->next = cur_node->next;
        cur_node->next = nullptr;
        delete cur_node;
    }

    return head;
}

void print_singly_linked_list(SinglyLinkedListNode* node)
{
    while (node != nullptr) {
        cout << node << "\t" <<node->data << "\n";
        node = node->next;
    }
    cout << "\n";
}

void reversePrint(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* node = head;
    SinglyLinkedList* revllist = new SinglyLinkedList();
    SinglyLinkedListNode* revll_head = revllist->head;

    while (node != nullptr) {
        SinglyLinkedListNode* temp = new SinglyLinkedListNode(node->data);

        if (revll_head == nullptr)
            revll_head = temp;
        else {
            temp->next = revll_head;
            revll_head = temp;
        }

        node = node->next;
    }

    while (revll_head != nullptr) {
        SinglyLinkedListNode* node = revll_head;

        cout << node->data << "\n";
        revll_head = revll_head->next;
        delete node;
    }
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* r = nullptr;
    SinglyLinkedListNode* m = nullptr;
    SinglyLinkedListNode* l = nullptr;

    if (head == nullptr)
        return head;

    m = head;
    while (m != nullptr) {
        r = m->next;
        m->next = l;
        l = m;
        m = r;
    }

    head = l;
    return head;
}

// My think
// 1. compare list length
//  ll1.size == ll2.size
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    SinglyLinkedListNode* m1 = head1;
    SinglyLinkedListNode* m2 = head2;

    if (m1 == nullptr || m2 == nullptr)
        return false;

    while (m1 != nullptr || m2 != nullptr) {
        if (m1->data != m2->data)
            return false;

        m1 = m1->next;
        m2 = m2->next;

        if (m1 == nullptr || m2 == nullptr)
            break;
    }

    if (m1 != m2)
        return false;

    return true;
}

int main(void)
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    SinglyLinkedListNode* llist_head;
    SinglyLinkedList* llist2 = new SinglyLinkedList();
    SinglyLinkedListNode* llist_head2;

    for (int i = 1; i <= 5; i++) {
        llist_head = insertNodeAtTail(llist->head, i);
        llist->head = llist_head;
    }
    cout << "list1\n";
    print_singly_linked_list(llist->head);

    for (int i = 1; i <= 5; i++) {
        llist_head2 = insertNodeAtTail(llist2->head, i+1);
        llist2->head = llist_head2;
    }
    cout << "list2\n";
    print_singly_linked_list(llist2->head);

    cout << compare_lists(llist->head, llist2->head) << endl;

#if 0
    cout << "reverse\n";
    llist_head = reverse(llist->head);
    llist->head = llist_head;
    print_singly_linked_list(llist->head);
#endif

#if 0
    cout << "reversePrint:\n";
    reversePrint(llist->head);
    cout << "\n";
#endif

#if 0
    cout << "insertNodeAtPosition\n";
    llist_head = insertNodeAtPosition(llist->head, 10, 1);
    llist->head = llist_head;
    print_singly_linked_list(llist->head);
#endif

#if 0
    llist_head = deleteNode(llist->head, 2);
    llist->head = llist_head;
    print_singly_linked_list(llist->head);
#endif

    return 0;
}
