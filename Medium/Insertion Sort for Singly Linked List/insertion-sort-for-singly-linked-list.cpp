//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        int mini = head_ref->data;
        struct Node* t = head_ref, *ans = head_ref,*temp,*cur,*prev = nullptr;
        while(t && t->next){
            if(t->data > t->next->data){
                temp = t->next;
                t->next = t->next->next;
                cur = ans;
                while(cur->data < temp->data){
                    prev = cur;
                    cur = cur->next;
                }
                if(prev)
                prev->next = temp;
                temp->next = cur;
                prev = nullptr;
                if(temp->data <= mini){
                    ans = temp;
                    mini = temp->data;
                }
            }
            else t = t->next;
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends