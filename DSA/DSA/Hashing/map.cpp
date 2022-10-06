#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map <int, string> mymap;

    // insert elements in map
    mymap[1] = "Mumbai";
    //can also do   mymap["PrepInsta"] = "1"
    // will need to change to   map <string, int> mymap;
    mymap.insert({2, "Bengaluru"});
    mymap.insert(pair <int, string> (3, "Pune"));
    mymap.insert(pair <int, string> (4, "Kolkata"));
    mymap.insert(pair <int, string> (5, "Hyderabad"));

    // printing map elements
    unordered_map <int, string> :: iterator it;
    cout << "Elements in map : " << endl;

    for (auto x : mymap)
        cout << "Key: " << x.first << " Value: " << x.second << endl;

    //erase element having key = 1
    mymap.erase(1);

    cout << "\nElements in map after erasing element having key = 1 : " << endl;
    for (it = mymap.begin(); it != mymap.end(); it++)
    {
        cout  << "Key: " << it->first << " value: " << it->second << endl;
    }

    if (mymap.find(4) == mymap.end())
        cout << "Not Found" << endl;
    else
        cout << (mymap.find(4)->first) << " Found" << endl;

    auto it2 = mymap.find(3);
    if (it2 != mymap.end())
        cout << it2->second << " Found" << endl;

    if (mymap.count(4) == 1)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "The size of map is: " << mymap.size() << endl;

    mymap.erase(1);
    mymap.erase(mymap.begin());

    for (auto x : mymap)
        cout << "Key: " << x.first << " Value: " << x.second << endl;

    mymap.clear();

    for (auto x : mymap)
        cout << "Key: " << x.first << " Value: " << x.second << endl;

    cout << "As you say nothing got printed" << endl;


    return 0;
}