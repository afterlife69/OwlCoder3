//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* rev(Node* h){
        Node* x = nullptr,*t1;
        while(h){
            t1 = h->next;
            h->next = x;
            x = h;
            h = t1;
        }
        return x;
    }
    int cnt(Node* h){
        int c = 0;
        for(;h;h = h->next)c++;
        return c;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        while(head1 && head1->data == 0){
            head1 = head1->next;
        }
        while(head2 && head2->data == 0){
            head2 = head2->next;
        }
        if(!head1 && !head2)return new Node(0);
        if(!head1)return head2;
        if(!head2)return head1;
        int c1 = cnt(head1), c2 = cnt(head2);
        if(c2 > c1)swap(head1,head2);
        else if(c1 == c2){
            Node* h1 = head1, * h2 = head2;
            while(h1){
                if(h2->data > h1->data){
                    swap(head1,head2);
                    break;
                }
                if(h1->data > h2->data)break;
                h1 = h1->next;
                h2 = h2->next;
            }
        }
        head1 = rev(head1);
        head2 = rev(head2);
        Node* t = head1, * t2 = head2,*p;
        c1 = min(c1,c2);
        bool f = 0;
        while(t && t2){
            int v1 = t->data, v2 = t2->data;
            if(v1 == v2){
                if(f){
                    v1--;
                    v1 += 10;
                    v1 -= v2;
                    t->data = v1;
                }
                else{
                    t->data = 0;
                }
            }
            else if(v1 < v2){
                if(!f){
                    v1 += 10;
                    v1 -= v2;
                    t->data = v1;
                    f = 1;
                }
                else{
                    v1 += 10;
                    v1--;
                    v1 -= v2;
                    t->data = v1;
                }
            }
            else{
                if(!f){
                    v1 -= v2;
                    t->data = v1;
                }
                else{
                    v1--;
                    v1 -= v2;
                    t->data = v1;
                    f = 0;
                }
            }
            p = t;
            t = t->next;
            t2 = t2->next;
        }
        while(f && t){
            if(t->data == 0)t->data = 9;
            else{
                t->data--;
                break;
            }
            t = t->next;
        }
        head1 = rev(head1);
        for(;head1 && head1->data==0;head1=head1->next);
        if(!head1)return new Node(0);
        return head1;
    }
    
    
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends