#include "TrieNode.h"

#include <iostream>
#include <string>

int main()
{
	std::string input; // input fo words
	bool on = true; // just for while loop 
	int choice = 0; // for switch choice

	std::string dictionary[50] = { "accolcde", "acrimony", "angst", "anomaly", "avantgcrde", "boroque",
	"bonhomie", "boondoggle", "bourgeois", "bravado", "brogue", "brusque", "cacophony", "camaraderie",
	"capricious", "caustic", "charisma", "cloying", "dejavu", "dichotomy", "dilettante", "disheveled",
	"elan", "ennui", "ephemeral", "epitome", "equivocate", "ersatz", "esoteric", "euphemism", "facetions",
	"fait", "fastidious", "fauxpas", "fiasco", "finagle", "glib" };

	struct TrieNode* root = getNewNode();

	for (int i = 0; i < dictionary->size(); i++) // filing in the Trie
	{
		insert(root, dictionary[i]);
	}


	while (on)
	{
		std::cout << "type in any word (1)" << std::endl;
		std::cout << "or press quit    (0)" << std::endl;
		std::cout << "choice : ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "input word : ";
			std::cin >> input;
			std::cout << "possible postfix : " << std::endl;
			showWordByPrefix(root, input);
			break;
		case 0:
			on = false;
			break;
		default:
			std::cout << "You made an illegal choice, please try again" << std::endl;
			break;
		}
	}

	std::cout << "program end." << std::endl;

	return 0;
}
