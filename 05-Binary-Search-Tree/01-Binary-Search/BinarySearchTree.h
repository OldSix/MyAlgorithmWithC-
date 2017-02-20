//
// Created by Queen on 2017/2/19.
//

#ifndef INC_01_BINARY_SEARCH_BINARYSEARCHTREE_H
#define INC_01_BINARY_SEARCH_BINARYSEARCHTREE_H

#include <iostream>
#include <cassert>
#include <queue>

template <typename Key, typename Value>
class BST
{
private:
    struct Node {
        Key key;
        Value value;
        Node * left;
        Node * right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;

            this->left = this->right = NULL;
        }

        Node(Node * node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node * root;
    int count;

public:

    BST() {
        root = NULL;
        count = 0;
    }

    ~BST() {
        destroy(root);
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

    bool contain(Key key) {
        return contain(root, key);
    }

    Value * search(Key key) {
        return search(root, key);
    }

    void preOrder() {
        return preOrder(root);
    }

    void inOrder() {
        return inOrder(root);
    }

    void postOrder() {
        return postOrder(root);
    }

    void levelOrder() {
        std::queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node * node = q.front();
            q.pop();

            std::cout << node->key << std::endl;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    Key minimum() {
        assert(count > 0);
        Node * minNode = minimum(root);

        return minNode->key;
    }

    Key maximum() {
        assert(count > 0);
        Node * maxNode = maximum(root);

        return maxNode->key;
    }

    void removeMin() {
        if (root)
            root = removeMin(root);
    }

    void removeMax() {
        if (root)
            root = removeMax(root);
    }

    void remove(Key key) {
        root = remove(root, key);
    }

private:

    // 向以 node 为根的二叉搜索树中,插入节点(key, value)
    // 返回插入新节点后的二叉搜索树的根
    Node * insert(Node * node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }

        if (node->key == key)
            node->value = value;
        else if (node->key < key) // 节点比根节点大，
            node->right = insert(node->right, key, value);
        else
            node->left = insert(node->left, key, value);

        return  node;
    }

    bool contain(Node * node, Key key) {
        if (node == NULL)
            return false;

        if (node->key == key)
            return true;
        else if (node->key < key)
            return contain(node->right, key);
        else
            return contain(node->left, key);
    }

    Value * search(Node * node, Key key)
    {
        if (node == NULL)
            return NULL;

        if (node->key == key)
            return node->value;
        else if (node->key < key)
            return search(node->right, key);
        else
            return search(node->left, key);
    }

    void preOrder(Node * node)
    {
        if (node != NULL) {
            std::cout << node->key << std::endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node * node)
    {
        if (node != NULL) {
            inOrder(node->left);
            std::cout << node->key << std::endl;
            inOrder(node->right);
        }
    }

    void postOrder(Node * node)
    {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->key << std::endl;
        }
    }

    void destroy(Node * node) {
        if (node != NULL) {
            destroy(node->left);
            destroy(node->right);

            delete node;
            count--;
        }
    }

    Node * minimum(Node * node)
    {
        if (node->left == NULL)
            return node;

        return minimum(node->left);
    }

    Node * maximum(Node * node)
    {
        if (node->left == NULL)
            return node;

        return maximum(node->left);
    }

    Node * removeMin(Node * node)
    {
        if (node->left == NULL) {
            Node * rightNode = node->right;
            delete node;
            count --;
            return rightNode;
        }

        node->left = removeMin(node->left);

        return node;
    }

    Node * removeMax(Node * node)
    {
        if (node->right == NULL) {
            Node * leftNode = node->left;
            delete node;
            count --;
            return leftNode;
        }

        node->right = removeMin(node->right);

        return node;
    }

    // 删除掉以node为根的二分搜索树中键值为key的节点
    // 返回删除节点后新的二分搜索树的根
    Node * remove(Node * node, Key key) {
        if (node == NULL)
            return NULL;

        if (key < node->key) {
            node->left = remove(node->left, key);
            return node;
        } else if (key > node->key) {
            node->right = remove(node->right, key);
            return node;
        } else {

            if (node->left == NULL) {
                Node * leftNode = node->left;
                delete node;
                count --;
                return leftNode;
            }

            if (node->right == NULL) {
                Node * leftNode = node->left;
                delete node;
                count --;
                return leftNode;
            }

            Node * delNode = node;
            Node * successor = new Node(minimum(node->right));
            count ++;

            successor->right = removeMin(node->right);
            successor->left = node->left;

            delete node;
            count --;

            return successor;
        }
    }


};

#endif //INC_01_BINARY_SEARCH_BINARYSEARCHTREE_H





























