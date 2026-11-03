/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        
        std::queue<Node*> tQueue;
        std::unordered_map<Node*, Node*> tHashMap;
        Node *tNode = new Node(node->val);
        tHashMap[node] = tNode;
        tQueue.push(node);

        while (tQueue.empty() == false)
        {
            // Pop off the front of the queue
            auto tNode = tQueue.front();
            tQueue.pop();

            // Now we will visit each of its neighbors

            for (auto tNeighbor : tNode->neighbors)
            {
                // If this node is not in our hash map then we need to create it
                if (tHashMap.find(tNeighbor) == tHashMap.end())
                {
                    // create the mapping of the old node to the new node
                    tHashMap[tNeighbor] = new Node(tNeighbor->val);

                    // Push the neighbor to the queue to be processed
                    tQueue.push(tNeighbor);
                }

                // we have to unconditionally add the neighbor
                tHashMap[tNode]->neighbors.push_back(tHashMap[tNeighbor]);
            }
        }

        return tHashMap[node];
    }
};
