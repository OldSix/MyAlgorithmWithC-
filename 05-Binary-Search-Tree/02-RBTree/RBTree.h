//
// Created by Queen on 2017/2/21.
//

#ifndef INC_02_RBTREE_RBTREE_H
#define INC_02_RBTREE_RBTREE_H

#include <cstdio>
#include <cstdint>
#include <cassert>
#include "RBTree_Defs.h"

namespace RBTree
{
    template <typename KeyT, typename ValueT>
    class RBTree: public RBTreeAbstract {
    private:
        struct KVNode: public rbtree_node_t {
            KeyT key;
            ValueT value;
        };
#define KVNode(node) static_cast<KVNode *>(node)
        void destruct(KVNode *n) {
            if (n == NULL) return;
            destruct(KVNode(n->left));
            destruct(KVNode(n->right));
            delete n;
        }

    public:
        ~RBTree() {
            destruct(KVNode(get_root()));
        }

        /**
         * rbtree_insert
         * insert a key-value pair into red-black tree
         */

        void insert(const KeyT& key, const ValueT& value) {
            KVNode * inserted_node = new_node(key, value, RED, NULL, NULL);
        }

        KVNode * new_node(KeyT key, ValueT value, color rbtree_node_c)


    };
}


#endif //INC_02_RBTREE_RBTREE_H
