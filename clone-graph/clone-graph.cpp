#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        map<Node *, Node *> newMap;
        Node *cloneGraph = new Node();
        dfs(newMap, node, cloneGraph);
        auto val = newMap[node];
        return cloneGraph->neighbors[0];
    }
    void dfs(map<Node *, Node *> newMap, Node *originalNode, Node *cloneNode)
    {
        auto newClone = new Node(originalNode->val);
        cloneNode->neighbors.push_back(newClone);
        newMap[originalNode] = newClone;

        for (auto neighbour : originalNode->neighbors)
        {
            if (newMap.find(neighbour) != newMap.end())
            {
                newClone->neighbors.push_back(newMap[neighbour]);
            }
            else
            {
                dfs(newMap, neighbour, newClone);
            }
        }
    }

    // unordered_map<Node *, Node *> mp;
    // void dfs(Node *node)
    // {
    //     Node *copy = new Node(node->val);
    //     mp[node] = copy;
    //     for (auto ng : node->neighbors)
    //     {
    //         if (mp.find(ng) != mp.end())
    //         {
    //             copy->neighbors.push_back(mp[ng]);
    //         }
    //         else
    //         {
    //             dfs(ng);
    //             copy->neighbors.push_back(mp[ng]);
    //         }
    //     }
    // }
    // Node *cloneGraph(Node *node)
    // {
    //     if (node == NULL)
    //         return NULL;
    //     dfs(node);
    //     return mp[node];
    // }
};

int main()
{
    auto node1 = new Node(1);
    auto node2 = new Node(2);
    auto node3 = new Node(3);
    auto node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node3);
    node4->neighbors.push_back(node1);

    auto sol = new Solution();
    auto result = sol->cloneGraph(node1);
    return 0;
}
