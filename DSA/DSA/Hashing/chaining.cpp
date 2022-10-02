#include<bits/stdc++.h>
using namespace std;

struct Hash
{
    int BUCKET; // no of buckets / memory slots in the hash table
    list<int> *hash_table; // Pointer to an array containing buckets

    Hash(int b)
    {
        BUCKET = b;
        hash_table = new list<int>[BUCKET];
    }
    void insert(int k)
    {
        int i = k % BUCKET;
        hash_table[i].push_back(k); // insert it in particular buckets's list
    }
    bool search(int k)
    {
        int i = k % BUCKET;
        for (auto x : hash_table[i])
            if (x == k)
                return true;
        return false;
    }
    void deleteItem(int k)
    {
        int i = k % BUCKET;
        hash_table[i].remove(k);// delete from  particular buckets's list
    }
};

int main()
{
    Hash h(7);
    h.insert(3);
    h.insert(8);
    h.insert(5);
    h.insert(1);
    h.insert(10);
    h.insert(6);

    cout << h.search(10) << endl;
    h.deleteItem(10);
    cout << h.search(1);

}