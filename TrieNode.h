#pragma once
#include <iostream>

#define ALPHABET_SIZE 26

struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];

	bool isEndOfWord;
};

TrieNode* getNewNode(void);

void insert(TrieNode* root, std::string key);

bool search(struct TrieNode* root, std::string key);

bool isEmpty(TrieNode* root);

TrieNode* remove(TrieNode* root, std::string key, int depth = 0);

void showWordByPrefix(struct TrieNode* root, std::string prefix);

