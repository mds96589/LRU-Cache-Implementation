#include <iostream>
#include <list>
#include <unordered_map>
#include <fstream>
using namespace std;

//Node to store the data (Linked List)
class Node{
public:
    string key;
    int value;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

//LRU Cache Data Structure
class LRUCache{
public:
    int maxSize;
    list<Node> l;
    unordered_map<string, list<Node>::iterator> m;

    LRUCache(int maxSize)
    {
        this->maxSize = maxSize;
    }

    //Inserts key and corresponding value
    void insertKeyValue(string key, int value)
    {
        //2 cases: Cache Hit or Cache Miss
        if(m.count(key) != 0) //Cache hit
        {
            auto it = m[key];
            it->value = value;
        }
        else //Cache Miss
        {
            if(l.size() == maxSize) //Cache full, remove least recently used item from cache
            {
                Node last = l.back();
                m.erase(last.key);
                l.pop_back();
            }

            Node newNode(key, value);
            l.push_front(newNode);
            m[key] = l.begin();
        }
    }

    //If key is present, returns corresponding value and moves up the key-value pair to most recently used position(Front of list)
    int* getValue(string key)
    {
        if(m.count(key) != 0)
        {
            auto it = m[key];
            int value = it->value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return &l.begin()->value;
        }
        else
        {
            return NULL;
        }
    }

    //Returns most recently used key
    string getMostRecentKey()
    {
        return l.front().key;
    }

};

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int maxSize;
    infile >> maxSize;
    LRUCache cache(maxSize);

    string command, key;
    int value;

    while (infile >> command) 
    {
        if (command == "INSERT") 
        {
            infile >> key >> value;
            cache.insertKeyValue(key, value);
            outfile << "Inserted (" << key << ", " << value << ")" << endl;
        } 
        else if (command == "GET") 
        {
            infile >> key;
            int* val = cache.getValue(key);
            if (val) 
            {
                outfile << "Value for " << key << " is " << *val << endl;
            } 
            else 
            {
                outfile << key << " not found" << endl;
            }
        } 
        else if (command == "RECENT") 
        {
            outfile << "Most recent key is " << cache.getMostRecentKey() << endl;
        }
    }

    infile.close();
    outfile.close();
    return 0;
}