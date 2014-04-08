/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
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
