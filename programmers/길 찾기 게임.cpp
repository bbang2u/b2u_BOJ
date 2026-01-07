#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 트리의 노드
struct Node {
    int id; // 노드 번호
    int x, y; // 좌표
    Node* left = NULL;
    Node* right = NULL;
};

// 정렬 기준: y값 내림차순 -> y가 같다면 x값 오름차순
bool compareNodes(const Node& a, const Node& b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

// 트리에 노드를 삽입하는 함수
void addNode(Node* parent, Node* child) {
    if (child->x < parent->x) { // 부모보다 x가 작으면 왼쪽
        if (parent->left == NULL) parent->left = child;
        else addNode(parent->left, child);
    } else { // 부모보다 x가 크면 오른쪽
        if (parent->right == NULL) parent->right = child;
        else addNode(parent->right, child);
    }
}

// 전위 순회 (Root -> Left -> Right)
void preorder(Node* node, vector<int>& list) {
    if (node == NULL) return;
    list.push_back(node->id);
    preorder(node->left, list);
    preorder(node->right, list);
}

// 후위 순회 (Left -> Right -> Root)
void postorder(Node* node, vector<int>& list) {
    if (node == NULL) return;
    postorder(node->left, list);
    postorder(node->right, list);
    list.push_back(node->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node> nodes;
    
    // 1. nodeinfo를 Node 구조체 벡터로 변환
    for(int i = 0; i < nodeinfo.size(); i++) {
        nodes.push_back({i + 1, nodeinfo[i][0], nodeinfo[i][1], NULL, NULL});
    }
    
    // 2. 좌표 기준 정렬
    sort(nodes.begin(), nodes.end(), compareNodes);
    
    // 3. 트리 구성
    Node* root = &nodes[0]; 
    
    // 나머지 노드들을 순서대로 트리에 삽입
    for(int i = 1; i < nodes.size(); i++) {
        addNode(root, &nodes[i]);
    }
    
    
    vector<int> preList, postList;
    preorder(root, preList);
    postorder(root, postList);
    
    return {preList, postList};
}
