"""Return reference of new head of the reverse linked list
  The input list will have at least one element
  Node is defined as

class Node:
    def __init__(self, data):
		self.data = data
		self.next = None
  This is method only submission.
  You only need to complete the method.
"""
class Solution:
    def reverse(self,head, k):
        pr = None
        t, ret = head, [None]
        
        def revK(prev, T, K, ret):
            x = None
            pr2 = T
            while T and K:
                t1 = T.next
                T.next = x
                x = T
                T = t1
                K -= 1
            if prev:
                prev.next = x
            else:
                ret[0] = x
            prev = pr2
            
            return [prev, T]
        
        while t:
            pr, t = revK(pr, t, k, ret)
        return ret[0]


#{ 
 # Driver Code Starts
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None
        # self.tail

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data, end=" ")
            # arr.append(str(temp.data))
            temp = temp.next
        print()


if __name__ == '__main__':
    t = int(input())
    while (t > 0):
        llist = LinkedList()

        values = list(map(int, input().split()))
        for i in reversed(values):
            llist.push(i)
        k = int(input())
        new_head = LinkedList()
        ob = Solution()
        new_head = ob.reverse(llist.head, k)
        llist.head = new_head
        llist.printList()
        t -= 1

        print("~")

# } Driver Code Ends