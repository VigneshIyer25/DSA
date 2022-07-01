// Creates binary tree given the preorder sequence
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

class binaryTree{
    public:
        Node* createNode(int data){
            Node *node = new Node();
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            return node;
        }

        int idx = -1;
        Node* buildTree(int nodes[]){
            idx++;
            if(nodes[idx] == -1) return NULL;

            Node *root = createNode(nodes[idx]);
            //create left subtree
            root->left = buildTree(nodes);
            //create right subtree
            root->right = buildTree(nodes);

            return root;
        }
        //DFS with recursion
        void preorder(Node *root){
            if(root == NULL) return;
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }

        void preorder_iterative(Node *root){
            if(!root) return;
            stack<Node*> s;
            s.push(root);
            while(!s.empty()){
                Node *currNode = s.top();
                cout<<currNode->data<<" ";
                s.pop();
                if(currNode->right) s.push(currNode->right);
                if(currNode->left) s.push(currNode->left);
            }
        }

        void inorder(Node *root){
            if(root == NULL) return;
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }

        void postorder(Node *root){
            if(root == NULL) return;
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
        // BFS with iteration
        void levelOrder(Node *root){
            if(!root) return;
            queue<Node*> q;
            q.push(root);

            while(!q.empty()){
                Node *currNode = q.front();
                q.pop();
                cout<<currNode->data<<" ";
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
        }

        int countNodes(Node *root){
            return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
        }

        int treeHeight(Node *root){
            return root ? 1 + max(treeHeight(root->left), treeHeight(root->right)) : 0;
        }

        int treeDiameter(Node *root){
            return root ? max({treeDiameter(root->left), treeDiameter(root->right), 1 + treeHeight(root->left) + treeHeight(root->right)}) : 0;
        }
};

int main(){
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    binaryTree tree;
    Node *root = tree.buildTree(nodes);
    /*
    creates below binary tree and returns the root
                 1
                / \
              2    3
             / \    \
            4   5    6
    */
    tree.preorder(root); // prints preorder sequence of the tree:- 1 2 3 4 5 6
    cout<<endl;
    tree.preorder_iterative(root); // prints preorder sequence of the tree:- 1 2 3 4 5 6
    cout<<endl;
    tree.inorder(root); // prints inorder sequence of the tree:- 4 2 5 1 3 6
    cout<<endl;
    tree.postorder(root); // prints inorder sequence of the tree:- 4 5 2 6 3 1
    cout<<endl;
    tree.levelOrder(root); // prints level order sequence of the tree:- 1 2 3 4 5 6
    cout<<endl;
    cout<<tree.countNodes(root); // prints number of nodes in the tree:- 6
    cout<<endl;
    cout<<tree.treeHeight(root); // prints height of the tree:- 3
    cout<<endl;
    cout<<tree.treeDiameter(root); // prints the diameter(longest path between two nodes) of the tree:- 5
}