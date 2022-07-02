#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Linked_List {
    public:
        Node* CreateNode(int data){
            Node *head = new Node();
            head->data = data;
            head->next = NULL;
            return head;
        }

        Node* CreateLinkedList(vector<int> nodes,int i, int n){
            if(i == n) return NULL;
            Node *newNode = CreateNode(nodes[i]);
            newNode->next = CreateLinkedList(nodes, i+1, n);
            return newNode;
        }

        void PrintLL(Node *head){
            if(!head) return;
            head->next ? cout<<head->data<<"->" : cout<<head->data;
            PrintLL(head->next);
        }

        void PrintReverse(Node *head){
            if(!head) return;
            PrintReverse(head->next);
            cout<<head->data<<" ";
        }

        Node* RemoveDuplicates(Node *head){
            if(!head) return head;

            head->next = RemoveDuplicates(head->next);
            if(head->next != NULL && head->data == head->next->data){
                return head->next;
            }
            return head;
        }
};

int main(){
    vector<int> nodes = {1, 2, 3, 3, 3, 4, 5, 6, 7, 7, 7};
    Linked_List L;
    int n = nodes.size();
    Node *head = L.CreateLinkedList(nodes, 0, n);
    L.PrintLL(head);
    cout<<endl;
    L.PrintReverse(head);
    cout<<endl;
    Node *newHead = L.RemoveDuplicates(head);
    L.PrintLL(newHead);
}