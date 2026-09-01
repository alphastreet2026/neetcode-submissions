class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        // 1. Insert each copy directly after its original node.
        Node* node = head;
        while (node) {
            Node* copy = new Node(node->val);
            copy->next = node->next;
            node->next = copy;

            node = copy->next;
        }

        // 2. Assign random pointers for copied nodes.
        node = head;
        while (node) {
            Node* copy = node->next;

            if (node->random) {
                copy->random = node->random->next;
            }

            node = copy->next;
        }

        // 3. Separate the original and copied lists.
        Node* copyHead = head->next;
        node = head;

        while (node) {
            Node* copy = node->next;

            node->next = copy->next;

            if (copy->next) {
                copy->next = copy->next->next;
            }

            node = node->next;
        }

        return copyHead;
    }
};