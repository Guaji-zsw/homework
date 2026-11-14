#include <stdio.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    int isEnd;
} TrieNode;

// 创建节点
TrieNode *createNode(void) {
    TrieNode *node = malloc(sizeof(TrieNode));

    if (node == NULL) {
        return NULL;
    }

    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }

    node->isEnd = 0;

    return node;
}

// 插入单词
void insert(TrieNode *root, const char *word) {
    TrieNode *node = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (node->children[index] == NULL) {
            node->children[index] = createNode();

            if (node->children[index] == NULL) {
                return;
            }
        }

        node = node->children[index];
    }

    node->isEnd = 1;
}

// 查找完整单词
int search(TrieNode *root, const char *word) {
    TrieNode *node = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (node->children[index] == NULL) {
            return 0;
        }

        node = node->children[index];
    }

    return node->isEnd;
}

// 查找前缀
int startsWith(TrieNode *root, const char *prefix) {
    TrieNode *node = root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (node->children[index] == NULL) {
            return 0;
        }

        node = node->children[index];
    }

    return 1;
}

int main(void) {
    TrieNode *root = createNode();

    if (root == NULL) {
        return 1;
    }

    insert(root, "apple");
    insert(root, "banana");

    printf("%d\n", search(root, "apple"));
    printf("%d\n", search(root, "app"));

    printf("%d\n", startsWith(root, "app"));
    printf("%d\n", startsWith(root, "cat"));

    return 0;
}
