

struct LRU_cache
{


    Data find(Key& key) {

        x = container.find(key);
        if(x != 0) {
            LRU->head = x;
            return x->data;
        } else {
            return 0;
        }
    }

    bool insert(Key& key, Data& data) {

        if(find(key))
            return false;

        if(size == max_size) {
            key = LRU->last;
            container.remove(key);
            size--;
        }
        x = container.insert(key, data);
        LRU->head = x;
        size++;
        return true;
    }

    std::hashmap< Key, Data > container;
    std::list< Key > LRU;

    int max_size;   // maximal and current size
    int size;

};