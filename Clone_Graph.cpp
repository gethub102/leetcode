/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// version 1, use a queue
class Solution {
  public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (node == NULL) return NULL;
        // 建立一个 hash
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        // 建立一个队列
        queue<UndirectedGraphNode*> visit;
        visit.push(node);
        UndirectedGraphNode* nodeCopy = new UndirectedGraphNode(node->label);
        nodeMap[node] = nodeCopy;
        // 当这个队列不空
        while (visit.size() > 0) {
            // 把队列的第一个拿出来
            UndirectedGraphNode* cur = visit.front();
            visit.pop();
            // copy 它的邻居
            for (int i = 0; i < cur->neighbors.size(); ++i) {
                UndirectedGraphNode* neighb = cur->neighbors[i];
                // 如果在 hashmap 里没有，说明是新结点
                if (nodeMap.find(neighb) == nodeMap.end()) {
                    // no copy of neighbor node yet. create one and associate with the copy of cur
                    // 新建这个节点
                    UndirectedGraphNode* neighbCopy = new UndirectedGraphNode(neighb->label);
                    // 把这个节点塞到 copy 当前元素的neighbors 里
                    nodeMap[cur]->neighbors.push_back(neighbCopy);
                    // 在 hashmap 里加上这个节点
                    nodeMap[neighb] = neighbCopy;
                    // 放进队列一会儿遍历
                    visit.push(neighb);
                } else {
                    // already a copy there. Associate it with the copy of cur
                    // 只要加到当前节点的 neighbors 即可
                    nodeMap[cur]->neighbors.push_back(nodeMap[neighb]);
                }
            }
        }
        return nodeCopy;
    }
};

// version 2, recursion
/*
At the first look, this problem seems wired. Remind the Copy Constructor of a class object, when the class member contains pointers, the direct copy is shadow, we need deep copy. For this problem, there are two major tasks:
(1)  Traverse the graph
(2)  Construct the new graph at the same time.

Traverse the graph is similar to the tree traversal, both DFS and  BFS can be used. Slight difference  is to consider the loop in the graph (e.g., the 2-->2 in the above figure), thus we need store the visited vertex information. If the neighbor of current node has not been visited, then search that node.

Only one point should be noticed for constructing the new graph, in the code below, I used a map< int, node*> to store the visited information, so that if the node has been visited, just add the map[int] to the current node's neighbor list. Be careful the current node is the node you "newed", but not the node in the original graph (line 98 and 99 in the code below. If you set visited[v->label] = v, it is not correct.).
*/
class Solution {
  public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (!node) {
            return NULL;
        } else {
            map<int, UndirectedGraphNode*> visited;
            return dfs(node, visited);
        }
    }

    UndirectedGraphNode* dfs(UndirectedGraphNode* node, map<int, UndirectedGraphNode*>& visited) {
        UndirectedGraphNode* result = new UndirectedGraphNode(node->label);
        visited[node->label] = result;
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (!visited[node->neighbors[i]->label]) {
                result->neighbors.push_back(dfs(node->neighbors[i], visited));
            } else {
                result->neighbors.push_back(visited[node->neighbors[i]->label]);
            }
        }
        return result;
    }
};
