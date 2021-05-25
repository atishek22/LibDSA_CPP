#include"priority_queue.hpp" 

/* Constructors and Destructor*/

template<typename K, typename D>
Priority_Queue<K, D>::Priority_Queue(int flag) {
  if(flag == priority_queue::MIN_QUEUE) {
    type = priority_queue::MIN_QUEUE;
    compare = min_queue;
  } else {
    type = priority_queue::MAX_QUEUE;
    compare = max_queue;
  }
}

template<typename K, typename D>
Priority_Queue<K, D>::~Priority_Queue() {
  pq.clear();
}

/* Private Functions */
template<typename K, typename D>
void Priority_Queue<K, D>::bottom_up(int i) {
  int p = PARENT(i);
  if(p >= 0) {
    if(compare(pq[i], pq[p])) {
      std::swap(pq[i], pq[p]);
      bottom_up(p);
    }
  }
}

template<typename K, typename D>
void Priority_Queue<K, D>::top_down(int i) {
  int l = LEFT(i);
  int r = RIGHT(i);
  int largest = 0;
  if(l < pq.size() && compare(pq[l], pq[i])) {
    largest = l;
  } else largest = i;
  if(r < pq.size() && compare(pq[r], pq[largest])) {
    largest = r;
  }

  if(largest != i) {
    std::swap(pq[i], pq[largest]);
    top_down(largest);
  }
}

template<typename K,  typename D>
int Priority_Queue<K, D>::containsInternal(K k) {
  int index = -1;
  for(int i = 0; i < size(); i++) {
    if(pq[i].key == k) {
      index = i;
    }
  }
  return index;
}

/* Public Functions */

template<typename K, typename D>
bool Priority_Queue<K, D>::insert(K key, D data) {
  Data newData(key, data);
  pq.push_back(newData);
  bottom_up(pq.size() - 1);
  return true;
}

template<typename K, typename D>
bool Priority_Queue<K, D>::insert(std::pair<K, D> val) {
  return insert(val.first, val.second);
}

template<typename K, typename D>
std::pair<K, D> Priority_Queue<K, D>::poll() {
  if(isEmpty()) throw std::runtime_error("Empty Queue Polling\n");
  Data ret;
  if(size() == 1) {
    ret = pq[0];
    clear();
  } else {
    ret = pq[0];
    pq[0] = pq.back();
    pq.pop_back();
    top_down(0);
  }
  return std::make_pair(ret.key, ret.data);
}

template<typename K, typename D>
std::pair<K, D> Priority_Queue<K, D>::peek() {
  if(isEmpty()) throw std::runtime_error("Empty Queue Peeking\n");
  auto ret = pq[0];
  return std::make_pair(ret.key, ret.data);
}

template<typename K, typename D>
bool Priority_Queue<K, D>::remove(K key) {
  if(isEmpty()) throw std::runtime_error("Empty Queue Removing\n");
  int index = containsInternal(key);
  if(index != -1) {
    for(int i = index; i < size() - 1; i++) {
      pq[i] = pq[i + 1];
    }
    pq.pop_back();
    return true;
  }
  return false;
}

template<typename K, typename D>
bool Priority_Queue<K, D>::remove(std::pair<K, D> val) {
  return remove(val.first);
}

template<typename K, typename D>
bool Priority_Queue<K, D>::contains(K key) {
  int index = containsInternal(key);
  if(index == -1) return false;
  else return true;
}

template<typename K, typename D>
bool Priority_Queue<K, D>::modifyKey(K oldKey, K newKey) {
  if(isEmpty()) throw std::runtime_error("Empty Queue\n");
  int index = containsInternal(oldKey);
  if(index == -1) return false;
  pq[index].key = newKey;
  if(oldKey < newKey) {
    if(type == priority_queue::MAX_QUEUE) {
      bottom_up(index);
    } else {
      top_down(index);
    }
  } else {
    if(type == priority_queue::MAX_QUEUE) {
      top_down(index);
    } else {
      bottom_up(index);
    }
  }
  return true;
}
