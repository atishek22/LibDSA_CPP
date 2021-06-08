#ifndef DATA_STRUCTURES_PRIORITY_QUEUE_HPP
#define DATA_STRUCTURES_PRIORITY_QUEUE_HPP

#include<vector>
#include<functional>
#include<stdexcept>

/*
 * Priority Queue implementation using std::vector
 */
namespace priority_queue {
  const int MAX_QUEUE = 0;
  const int MIN_QUEUE = 1;
}

// macros

#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
#define PARENT(i) ((i - 1) / 2)

// class implementation

template<typename K, typename D>
class Priority_Queue {
  private:
    class Data {
      public:
        K key;
        D data;

        Data(){}

        Data(K k, D d) {
          key = k;
          data = d;
        }

        bool operator == (const Data& other) {
          return this->key == other.key;
        }
        bool operator > (const Data& other) {
          return this->key > other.key;
        }
        bool operator < (const Data& other) {
          return this->key < other.key;
        }
    };
    std::vector<Data> pq;
    int type;
    std::function<bool(Data, Data)> compare;

    // MAX_QUEUE and MIN_QUEUE comparison functions
    std::function<bool(Data, Data)> min_queue = [](Data first, Data second) {
      return first < second;
    };

    std::function<bool(Data, Data)> max_queue = [](Data first, Data second) {
      return first > second;
    };
    
    /* Private functions */

    void bottom_up(int i);

    void top_down(int i);

    int containsInternal(K key);

  public:
    /* Default constructor: empty max priority queue */
    Priority_Queue() {
      type = priority_queue::MAX_QUEUE;
      compare = max_queue;
    }

    /* Constructor: Empty priority queue of the argument-type */
    Priority_Queue(int flag);

    /* Destructor */
    ~Priority_Queue();

    /* Checks if the queue is empty */
    bool isEmpty() noexcept{
      return pq.empty();
    }

    /* return the number of elements in the queue */
    size_t size() noexcept {
      return pq.size();
    }

    /* Queue Opertions */

    /* Insert a key and the corressponding data */
    bool insert(K key, D data);

    /* Inserts the first element as the key and the second as the Data element */
    bool insert(std::pair<K, D> val);

    /* Remove the root element */
    std::pair<K, D> poll();

    /* Get the root element's value */
    std::pair<K, D> peek();

    /* Remove a particular value using the key*/
    bool remove(K key);
    
    /* Remove the element using the key-data pair (not really needed) */
    bool remove(std::pair<K, D> val);

    /* Clear the queue */
    void clear() {
      pq.clear();
    }

    /* Checks if the queue contains a key */
    bool contains(K key);

    /* Change the key for an element returns false if the key does not exist*/
    bool modifyKey(K oldKey, K newKey);

};


#endif //DATA_STRUCTURES_PRIORITY_QUEUE_HPP
