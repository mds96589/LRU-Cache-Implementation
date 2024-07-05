# LRU-Cache-Implementation
Implementing LRU cache data structure using Doubly Linked List and Hashmap in C++
This implementation supports following operations in O(1) time -->
-insert(key, value)
-getValue(key)
-getMostRecentKey()
The class also has a property MaxSize to denote maximum possible number of key-value pairs that can be stored in the cache.

Input file should be in the following format:
First line should contain the cache's maximum size.
Each subsequent line should contain a command: INSERT, GET, or RECENT.
INSERT key value: Inserts a key-value pair into the cache.
GET key: Retrieves the value associated with the key.
RECENT: Retrieves the most recent key.
