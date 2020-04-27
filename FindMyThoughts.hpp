#ifndef _FindC_hpp_
#define _FindC_hpp_
#include <iostream>
#include <string>
using namespace std;

const int LIB_SIZE = 10;

template <typename KeyType, typename ValueType>
class Hash{
private:

  struct Cell{
    KeyType key;
    ValueType value[];
    Cell *link;
  };
  Cell **buckets;
  int nBuckets;
  int count;

  Cell *find_cell(int bucket, ValueType value){
    Cell *cp = buckets[bucket];
    while (cp != nullptr && key != cp->key){
      cp = cp->link;
    return cp;
    }
  }
  const int HASH_SEED = 5381;
  const int HASH_MULTIPLIER = 33;
  const int HASH_MASK = unsigned(-1) >> 1;

  int hashCode(KeyType key) {
  string str = to_string(key);
  unsigned hash = HASH_SEED;
  int n = str.length();
  for (int i = 0; i < n; i++)
    hash = HASH_MULTIPLIER * hash + str[i];
  return int(hash & HASH_MASK);
  }

public:
  Hash();
  ~Hash();
  int size();
  void clear();//good
  void insert(KeyType key , ValueType value[]);
  void remove(KeyType key);
  bool empty_hash();//good
};

#endif // _FindC_hpp_
