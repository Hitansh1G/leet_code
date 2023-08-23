#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
    string name;
    vector<Node*> children;
    Node(string name) : name(name) {}
};

void dfs(Node* node, unordered_map<string, Node*>& m) {
    if (m[node->name]->children.size() == 0) return;
    for (auto child : m[node->name]->children) {
        node->children.push_back(new Node(child->name));
        dfs(node->children.back(), m);
    }
}

void print(Node* node, int indent = 0) {
    for (int i = 0; i < indent; i++) cout << ' ';
    cout << "{\n";
    for (int i = 0; i <= indent; i++) cout << ' ';
    cout << "name: "<< node->name << ",\n";
    if (node->children.size() > 0) {
        for (int i = 0; i <= indent; i++) cout << ' ';
        cout << "children: [\n";
        for (auto child : node->children) {
            print(child, indent + 4);
            cout << ",\n";
        }
        for (int i = 0; i <= indent; i++) cout << ' ';
        cout << "]\n";
    }
    for (int i = 0; i < indent; i++) cout << ' ';
    cout << "}";
}

int main() {
    vector<pair<string, string>> input = {{"Bangalore", "Karnataka"}, {"Tamilnadu", "India"}, {"Mysore", "Karnataka"}, {"India", "Asia"}, {"Karnataka", "India"}, {"Chennai", "Tamilnadu"}, {"Asia", "null"}, {"Africa", "null"}, {"China", "Africa"},{"antartica", "null"}};
    unordered_map<string, Node*> m;
    for (auto p : input) {
        if (m.find(p.first) == m.end()) m[p.first] = new Node(p.first);
        if (m.find(p.second) == m.end()) m[p.second] = new Node(p.second);
        if (p.second != "null") m[p.second]->children.push_back(m[p.first]);
    }
    
    for (auto p : input) {
        if (p.second == "null") {
            Node* root = new Node(p.first);
            dfs(root, m);
            print(root);
            cout << endl;
        }
    }
}
