//  Create a timebased key-value store class TimeMap, that supports two operations.
//
//  1. set(string key, string value, int timestamp)
//
//  Stores the key and value, along with the given timestamp.
//  2. get(string key, int timestamp)
//
//      @ Returns a value such that set(key, value, timestamp_prev) was called previously, with timestamp_prev <= timestamp.
//      @ If there are multiple such values, it returns the one with the largest timestamp_prev.
//      @ If there are no values, it returns the empty string ("").
//
//  Example 1:
//
//  Input: inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
//  Output: [null,null,"bar","bar",null,"bar2","bar2"]
//  Explanation:
//  TimeMap kv;
//  kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1
//  kv.get("foo", 1);  // output "bar"
//  kv.get("foo", 3); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"
//  kv.set("foo", "bar2", 4);
//  kv.get("foo", 4); // output "bar2"
//  kv.get("foo", 5); //output "bar2"
//
//  Example 2:
//
//  Input: inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
//  Output: [null,null,null,"","high","high","low","low"]
//
//
//  Note:
//
//  1. All key/value strings are lowercase.
//  2. All key/value strings have length in the range [1, 100]
//  3. The timestamps for all TimeMap.set operations are strictly increasing.
//  4. 1 <= timestamp <= 10^7
//  5. TimeMap.set and TimeMap.get functions will be called a total of 120000 times (combined) per test case.

//  class TimeMap {
//  public:
//      /** Initialize your data structure here. */
//      TimeMap() {
//
//      }
//
//      void set(string key, string value, int timestamp) {
//
//      }
//
//      string get(string key, int timestamp) {
//
//      }
//  };

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

#if 0
ass TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        s_[key].emplace(timestamp, std::move(value));
    }

    string get(string key, int timestamp)
    {
        auto m = s_.find(key);
        if (m == s_.end()) return "";
        auto it = m->second.upper_bound(timestamp);
        if (it == begin(m->second)) return "";
        return prev(it)->second;
    }
private:
    unordered_map<string, map<int, string>> s_;
};
#endif

/*g++ -std=c++11 main.cpp is able to build pass*/

#include <utility>          // std::move
#include <string>           // std::string
#include <map>              // std::map
#include <unordered_map>    // std::unordered_map
#include <vector>           // std::vector
#include <algorithm>        // std::find

#include <iostream>

class TimeMap {
private:
    std::unordered_map<std::string, std::map<int, std::string>> s_; /*unordered_map has to include unordered_map*/
public:
    /** Initialize your data structure here. */
    TimeMap()
    {
    }
    void set(std::string key, std::string value, int timestamp);
    std::string get(std::string key, int timestamp);
};

void
TimeMap::set(std::string key, std::string value, int timestamp)
{
    s_[key].emplace(timestamp, std::move(value));
}

std::string
TimeMap::get(std::string key, int timestamp)
{
    auto m = s_.find(key);
    if (m == s_.end()) return "";
    auto it = m->second.upper_bound(timestamp);
    if (it == begin(m->second)) return "";
    return prev(it)->second;
}

static void
_vector_example1_cpp11(void)
{
    using namespace std;
    cout << "_vector_example1_cpp11 {" << endl;
    vector<int>a = {1, 2, 3, 4, 5};
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    cout << "}" << endl;
}

static void
_unordered_map_example2(void)
{
    using namespace std;
    // Declaring umap to be of <string, double> type
    // key will be of string type and mapped value will
    // be of double type
    unordered_map<string, double> umap;
    // inserting values by using [] operator
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;
    // inserting value by insert function
    umap.insert(make_pair("e", 2.718));
    string key = "PI";
    // If key not found in map iterator to end is returned
    if (umap.find(key) == umap.end())
        cout << key << " not found\n\n";
    // If key found then iterator to that key is returned
    else
        cout << "Found " << key << "\n\n";
    key = "lambda";
    if (umap.find(key) == umap.end())
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;
    // iterating over all value of umap
    unordered_map<string, double>:: iterator itr;
    cout << "\nAll Elements : \n";
    for (itr = umap.begin(); itr != umap.end(); itr++) {
        // itr works as a pointer to pair<string, double>
        // type itr->first stores the key part and
        // itr->second stroes the value part
        cout << itr->first << " " << itr->second << endl;
    }
}

static void
_unordered_map_example1(void)
{
    using namespace std;
    cout << "_unordered_map_example1 {" << endl;
    // Declaring umap to be of <string, int> type
    // key will be of string type and mapped value will
    // be of double type
    unordered_map<string, int> umap;
    // inserting values by using [] operator
    umap["GeeksforGeeks"] = 10;
    umap["Practice"] = 20;
    umap["Contribute"] = 30;
    // Traversing an unordered map
    for (auto x : umap)
        cout << x.first << " " << x.second << endl;
    cout << "}" << endl;
}


int
main(void)
{
    _vector_example1_cpp11();
    _unordered_map_example1();
    TimeMap kv;
    kv.set("foo", "bar", 1);
    std::cout << kv.get("foo", 1) << std::endl;
    std::cout << kv.get("foo", 3) << std::endl;
    kv.set("foo", "bar2", 4);
    std::cout << kv.get("foo", 4) << std::endl;
    std::cout << kv.get("foo", 5) << std::endl;
    return 0;
}
