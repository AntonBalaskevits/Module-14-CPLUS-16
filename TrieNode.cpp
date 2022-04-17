#include "TrieNode.h"

TrieNode* getNewNode(void)
{

	struct TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		pNode->children[i] = nullptr;
	}

	return pNode;
}

void insert(TrieNode* root, std::string key)
{
	struct TrieNode* node = root;

	int s;

	for (int i = 0; i < key.size(); i++)
	{
		s = key[i] - 'a';

		if (!node->children[s])
		{
			node->children[s] = getNewNode();
		}
		node = node->children[s];
	}
	node->isEndOfWord = true;
}

bool search(struct TrieNode* root, std::string key)
{
	TrieNode* node = root;

	for (int i = 0; i < key.size(); i++)
	{
		int index = key[i] - 'a';

		if (!node->children[index])
		{
			return false;
		}
		node = node->children[index];
	}
	return (node != nullptr && node->isEndOfWord);
}

bool isEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			return false;
		}

	}
	return true;
}

TrieNode* remove(TrieNode* root, std::string key, int depth = 0)
{
	if (!root)
	{
		return nullptr;
	}
	if (depth == key.size())
	{
		if (root->isEndOfWord)
		{
			root->isEndOfWord = false;
		}
		if (isEmpty(root))
		{
			delete (root);
			root = nullptr;
		}

		return root;
	}


	int index = key[depth] - 'a';
	root->children[index] = remove(root->children[index], key, depth + 1);

	if (isEmpty(root) && root->isEndOfWord == false)
	{
		delete (root);
		root = nullptr;
	}
	return root;
}

void showWordByPrefix(struct TrieNode* root, std::string prefix)
{
	TrieNode* node = root;
	TrieNode* postfixNode;
	bool arr[ALPHABET_SIZE];

	for (int i = 0; i < ALPHABET_SIZE; i++) // array to remember visited postition 
	{                                       // of first letter in trie
		arr[i] = false;
	}

	char symbol;
	int index = 0;


	for (int i = 0; i < prefix.size(); i++)
	{
		index = prefix[i] - 'a';

		if (node->children[index])
		{
			node = node->children[index];
		}
	}

	postfixNode = node;


	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i] != nullptr)
		{
			if (arr[i])
			{
				continue;
			}

			symbol = i + 'a';
			std::cout << symbol << " ";
			node = node->children[i];

			for (int j = 0; j < ALPHABET_SIZE; j++)
			{
				if (node->isEndOfWord)
				{
					node = postfixNode;
					break;
				}

				if (node->children[j] != nullptr)
				{

					symbol = j + 'a';
					std::cout << symbol << " ";

					node = node->children[j];
					j = 0;
				}

			}

			std::cout << std::endl;

			arr[i] = true; // flag that last letter from input word was visited

		}
	}
}