Design an node with member "end" and array[26] of next pointer since the input only include lowercase alphabets.

Insert: Loop through the word while traversing the trie. If a character in the word does not exist in the tree, allocate the node. Set end flag when inserting the last character.

Search: Traverse the tree and check if the end flag at last node is set.

Start with: Traverse the tree