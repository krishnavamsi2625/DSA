#include <bits/stdc++.h>
using namespace std;

void printSet(unordered_set<int> st)
{
    unordered_set<int>:: iterator it;
    cout << "\nSet contents are: ";

    for (it = st.begin(); it != st.end(); it++)
        cout << *it << " ";

    cout << "\nSize of Unordered Set " << st.size() << endl;
    cout << endl;
}

int main() {
    cout << "Example of set STL\n\n";
    unordered_set<int> st;
    unordered_set<int>:: iterator it;

    cout << "inserting 4\n";
    st.insert(4);
    cout << "inserting 6\n";
    st.insert(6);
    cout << "inserting 10\n";
    st.insert(10);
    cout << "inserting 20\n";
    st.insert(20);

    //result will be different on different compiler
    //way 1 of printing
    for (int i : st)
        cout << i << " ";

    cout << "" << endl;

    //way 1 of printing
    //result will be different on different compiler
    printSet(st); //printing current set

    cout << "Erasing 6..\n";
    st.erase(6); //prototype 1
    cout << "After erasing 6...\n";

    //result will be different on different compiler
    printSet(st);

    cout << "Erasing first element of the set now\n";
    st.erase(st.begin());//prototype 2
    cout << "After erasing first element of set now\n";

    //result will be different on different compiler
    printSet(st);

    if (st.empty()) //checking for empty
        cout << "Set is empty\n";
    else
        cout << "Set is not empty\n";

    //finding element 6
    if (st.find(6) != st.end())
        cout << *(st.find(6)) << "is present\n";
    else
        cout << "6 is not present\n";

    //finding element 10
    if (st.find(10) != st.end())
        cout << *(st.find(10)) << " is present\n";
    else
        cout << "20 is not present\n";

    st.insert(10);
    //finding element 4
    // returns 1 or 0 as returning the count and there can only be 1 unique item in hashtable
    if (st.count(10))
        cout << "10 is Present" << st.count(10) << " times" << endl;
    else
        cout << "10 Not Present\n";

    st.clear(); //clearing the set

    cout << "\nClearing the set\n";
    if (st.empty())
        cout << "Set is empty\n";
    else
        cout << "Set is not empty\n";

    return 0;
}