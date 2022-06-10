// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Time Complexity: O(N) 
// Space Complexity: O(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        
        Node* prevNode = root;
        Node* currNode = NULL;
        
        while(prevNode->left) {
            currNode = prevNode;
            
            while(currNode) {
                currNode->left->next = currNode->right;
                
                if(currNode->next) {
                    currNode->right->next = currNode->next->left;
                }
                
                currNode = currNode->next;
            }
            
            prevNode = prevNode->left;
        }
        
        return root;
    }
};