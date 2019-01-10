#include <stdbool.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // Hash the word received
    unsigned int hcode = hash(word);

    // Search through the hash table to find it
    htnode *trav = hashtable[hcode];
    while (trav != NULL)
    {
        // Case insensitive comparison
        if (!strcasecmp(trav->word, word))
        {
            return true;
        }

        // Advance the traversal pointer
        trav = trav->next;
    }

    // Must not have found anything
    return false;
}

/**
 * Hash function, adapted from djb2 http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;
    while ((c = (tolower(*word++))))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % SIZE;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // Initialize dictionary size to 0
    dsize = 0;

    // Attempt to open our file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    // Iterate through our file, one word at a time
    while (true)
    {
        // Create space for a new hash table node
        htnode *newnode = malloc(sizeof(htnode));
        if (newnode == NULL)
        {
            return false;
        }

        // Read the next string from the source dictionary into the new node
        fscanf(source, "%s", newnode->word);

        // If we've reached the end of the file, break out
        if (feof(source))
        {
            free(newnode);
            break;
        }

        // Hash that string to obtain a hash value
        unsigned int hcode = hash(newnode->word);

        // Insert into the hash table at that location, at the front of the chain
        newnode->next = hashtable[hcode];
        hashtable[hcode] = newnode;

        // Increment our word counter
        dsize++;
    }

    // close the dictionary file, success!
    fclose(source);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dsize;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // Iterate over every element of our hash table, freeing its list
    for (int i = 0; i < SIZE; i++)
        vacate_list(hashtable[i]);

    // Barring a fail of the free() function, no possible way to return false
    return true;
}

/**
 * Recursively deletes a linked list
 */
void vacate_list(htnode *head)
{
    // If the list is empty, nothing else to do
    if (head == NULL)
    {
        return;
    }

    // Free the next element in the chain, then free this one
    vacate_list(head->next);
    free(head);
}
