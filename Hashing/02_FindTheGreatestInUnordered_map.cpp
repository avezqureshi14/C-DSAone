#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> findEntryWithLargestValue(unordered_map<int, int> map)
{
    // reference variable to help find the entry with the largest value
    pair<int, int> MaxValue = make_pair(0, 0);

    // Iterate the map
    unordered_map<int, int>::iterator currentEntry;

    for (currentEntry = map.begin();
         currentEntry != map.end();
         ++currentEntry)
    {
        // If the entry is more than the max value
        //  Set this entry as max value

        if (currentEntry->second > MaxValue.second)
        {
            MaxValue = make_pair(currentEntry->first, currentEntry->second);
        }
    }

    return MaxValue;
}

void print(unordered_map<int, int> map)
{
    unordered_map<int, int>::iterator currentEntry;
    for (currentEntry = map.begin(); currentEntry != map.end(); ++currentEntry)
    {
        cout << currentEntry->first << " : " << currentEntry->second;
    }
}

int main()
{
    // Creating map and insrting it inside the function
    unordered_map<int, int> map;
    map.insert(pair<int, int>(1, 40));
    map.insert(pair<int, int>(2, 30));
    map.insert(pair<int, int>(3, 60));

    // Get the entry with maximum value
    pair<int, int> MaxValue = findEntryWithLargestValue(map);

    // Print the entry
    cout << "Entry with highest value " << MaxValue.first << " : " << MaxValue.second;
    return 0;
}