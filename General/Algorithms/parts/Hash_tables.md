# Hash Tables
Note: Most text is in EN, some screenshots are in RU.

## Theory
- Function that allows to systemize storing and working with data - **hash function**.
- **Hash table** connects hash values and values/sets of values.
- **Collision** - situation when two values has same hash values.

## Properties
- Hash functions are good for not changing values.
  - Hash sum can be created when the object is.
- Good hash function creates uniform distribution.
- Values are ordered by hash/

### Time complexity
Due to [balancing](#balance) the complexity of using hash tables is from O(1) to O(N) depending on if the rebuild of the table is required.
It is called **Amortized Complexity**

![ScShot_2](/General/Algorithms/media/hash_2.png "Calculation of complexity of N operations")    
![ScShot_3](/General/Algorithms/media/hash_3.png "Summery")  


## Example 
- Hash function for 150 elements:
```c++
int HashFunc(long long val){
    return val%150;
}
int main(){
    std::vector<std::vector> hash_list (150);
    long long n;
    std::cin >> n;
    hash_list[HashFunc(n)].push_back(n);
    return 0;
}
```
- Strings in ***Python***.

## Issues
### Balance
- Too big hash table - takes too much space - O(N).
- Too small table - too big filling factor (too many elements has the same hash value) - search and remove for O(K/N), where K - amount of elements, N - hash table size.
#### Solution
- Balance the filling factor so that filling factor will be low (for example **=1**). 
  - This can be achieved by rebuilding the table (double the size) when it fills.
![ScShot_1](/General/Algorithms/media/hash_1.png "Resizing hash table")  


### Hash tables in languages
Many programming languages use hash tables for some included complex data types and classes.
#### Example 
- **C++**: *std::unordered_map*, *std::unordered_set*, *std::unordered_multimap*, *std::unordered_multiset*.
- **Python**: *dict*, *set*.
- **Java**: *HashMap*, *HashSet*.
- **Go**: *map*.