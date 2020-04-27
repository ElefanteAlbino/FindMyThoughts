#include "FindC.hpp"

template <typename KeyType, typename ValueType>
Hash<KeyType,ValueType>::Hash(){
  nBuckets = LIB_SIZE;
  buckets = new Cell*[nBuckets];
  for (int i = 0; i < nBuckets; i++)
    buckets[i] = nullptr;
  count = 0
}


HashMap<KeyType,ValueType>::~HashMap() {
 clear();
}

int HashMap<KeyType,ValueType>::size(){
  return count;
}

void HashMap<KeyType,ValueType>::clear(){
  for(int i = 0; i < nBuckets; i++){
    Cell *cp = buckets[i];
    while(cp != nullptr){
      Cell *oldCell = cp;
      cp = cp->link;
      delete oldCell;
    }
  }
  count = 0;
}

void HashMap<KeyType,ValueType>::insert(KeyType key , ValueType value[]){
  int bucket = get_hash(key) % nBuckets;
  Cell *cp = find_cell(bucket, key);
  if(cp == nullptr){
    cp = new Cell;
    cp->key = key;
    cp->link = buckets[bucket];
    buckets[bucket] = cp;
    count++;
  }
  cp->value = val;
}

void HashMap<KeyType,ValueType>::remove(KeyType){
  int index = hashCode(key);
  count --;
  Cell * ptr = buckets[index], *pr = nullptr;
  while(ptr != ptr->key){
    if(key == ptr->key){
      if(pr == nullptr){
        buckets[index] = ptr->link;
        delete ptr;
        break;
      }else{
        pr->link = ptr->link;
        delete ptr;
        break;
      }
    }else{
      pr = ptr;
      ptr = ptr->link;
    }
  }
}
 bool HashMap<KeyType,ValueType>::empty_hash(){
   return count == 0;
 }
