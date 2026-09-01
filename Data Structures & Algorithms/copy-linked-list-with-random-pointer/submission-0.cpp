/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* copyNode = &dummy;
        unordered_map<Node*, Node*> nodeMap;
        auto node = head;

        while (node) {
            copyNode->next = new Node(node->val);
            copyNode = copyNode->next;
            nodeMap[node] = copyNode;
            node = node->next;
        }
        
        copyNode = dummy.next;
        node = head;
        while (node) {
            if (node->random){
                copyNode->random = nodeMap[node->random];
            }
            copyNode = copyNode->next;
            node = node->next;
        }

        return dummy.next;
    }
};
