
#include <assert.h>
#include <map>
#include <limits>
#include <iostream>
#include <algorithm>

#include <stdlib.h>
#include <time.h>

// interval_map<K,V> is a data structure that efficiently associates intervals of keys of type K with values of type V. 
// Your task is to implement the assign member function of this data structure, which is outlined below. 

// interval_map<K, V> is implemented on top of std::map. In case you are not entirely sure which functions std::map provides,
// what they do and which guarantees they provide, we have attached an excerpt of the C++1x draft standard at the end of this
// file for your convenience. 

// Each key-value-pair (k,v) in the m_map member means that the value v is associated to the interval from k (including) to
// the next key (excluding) in m_map.
// Example: the std::map (0,'A'), (3,'B'), (5,'A') represents the mapping
// 0 -> 'A'
// 1 -> 'A'
// 2 -> 'A'
// 3 -> 'B'
// 4 -> 'B'
// 5 -> 'A' 
// 6 -> 'A'
// 7 -> 'A'
// ... all the way to numeric_limits<key>::max()

// The representation in m_map must be canonical, that is, consecutive map entries must not have the same value: 
// ..., (0,'A'), (3,'A'), ... is not allowed.
// Initially, the whole range of K is associated with a given initial value, passed to the constructor.

// Key type K
// - besides being copyable and assignable, is less-than comparable via operator< ;
// - is bounded below, with the lowest value being std::numeric_limits<K>::min();
// - does not implement any other operations, in particular no equality comparison or arithmetic operators.

// Value type V
// - besides being copyable and assignable, is equality-comparable via operator== ;
// - does not implement any other operations.

void IntervalMapTest();

template< class K, class V >
class interval_map {
    
	friend void IntervalMapTest();
	
private:
    //! private data
    typedef std::map<K, V> Container;
    //! associated map
	Container m_map;

    //! iterator types
    typedef typename Container::iterator               iterator;
    typedef typename Container::const_iterator         const_iterator;
    typedef typename Container::size_type              size_type;

public:
    //! public typedefs
    
    typedef K                                   key_type;
    typedef V                                   mapped_type;
    typedef std::pair< const K, V >             value_type;
    typedef typename Container::allocator_type  allocator_type;
public:
    
	//! constructor associates whole range of K with val by inserting (\c K_min, \c val) into the map
	interval_map(V const& val) {
		m_map.insert(m_map.begin(), std::make_pair(std::numeric_limits<K>::min(),val));
	}

public:
    
    //! public methods:
    
    //! Assign value \c val to interval [keyBegin, keyEnd).
    //! Overwrites previous values in this interval. Do not change values outside this interval.
    //! If !( keyBegin < keyEnd ), this designates an empty interval, and assign must do nothing.
    void assign2(K const& keyBegin, K const& keyEnd, const V& val) {
     
        if(!(keyBegin < keyEnd)) // empty interval
            return;
        
        // use lower_bound instead of 'insert' to save on V objects'
        // assignments
        auto i_end = m_map.lower_bound(keyEnd); // i_end.key >= keyEnd 
        // position where we stop erasing
        auto erase_end = i_end;
        
        // i_end.key >= keyEnd && keyEnd >= i_end.key => keys are equal
        if(!(keyEnd < i_end->first) && i_end != m_map.end()) {
            // if val is equal => need to erase until the next element
            if(i_end->second == val)
                erase_end++;
        } else {
            // keys are not equal => need to check the previous key
            auto prev = std::prev(i_end);
            if(!(prev->second == val)) {
                // emplace_hint tries to insert before and after 'hint' 
                // need to erase everything until keyEnd
                erase_end = m_map.emplace_hint(prev, keyEnd, prev->second);
                
                if(i_end == std::next(erase_end))
                    printf("YAAAAAAAAAAAAAA!\n");
                else
                    throw "oops!";
            }
        }
      
        auto i1 = m_map.emplace(keyBegin, val);
        // position from where we start erasing
        iterator erase_beg = std::next(i1.first);
        
        if(!i1.second) { 
            // keyBegin already exists && its value differs from 'val'
            if(!(i1.first->second == val)) {
                // see if previous key has a value equal to 'val' 
                if(i1.first != m_map.begin()) {
                    auto prev = std::prev(i1.first);
                    if(prev->second == val) {
                        erase_beg = i1.first;
                    }
                } 
                // set keyBegin value to 'val' unless we are going to erase it
                if(erase_beg != i1.first)
                    i1.first->second = val;
            } 
        } else { // keyBegin does not exist in the map
        // see if prev. value equals to 'val' => then erase from keyBegin
            auto prev = std::prev(i1.first);
            if(prev->second == val) {
                erase_beg = i1.first;
            }
        }

        m_map.erase(erase_beg, erase_end);
    }
    

	void assign(K const& keyBegin, K const& keyEnd, const V& val) {

        if(!(keyBegin < keyEnd)) // empty interval
            return;

        typedef std::pair< iterator, iterator > ipair;

        // equal_range is more efficient than 2 calls to lower/upper_bound
        ipair i1 = m_map.equal_range(keyBegin), i2(i1.second, i1.second);

        iterator t = i1.second;
        // slight optimization to avoid 2nd call to equal_range
        if(i1.second != m_map.end() && !(keyEnd < (--t)->first)) {
            i2 = m_map.equal_range(keyEnd); // no need to compute i2 if we hit the end of map
        }
        iterator i1left = i1.first, i2right = i2.second;

        bool left_merge = ((--i1left)->second == val); // whether we need to insert keyBegin
        bool right_merge = left_merge;                 // whether we need to insert keyEnd
        if(i1left != --i2right)                        // save on comparison
            right_merge = (i2right->second == val);

//          std::cout << "merge: " << left_merge << "; " << t->first << "\n";
//         std::cout << "i1: " << i1.first->second << "; " <<
//                 i1.second->second << "\n";
//         std::cout << "i2: " << i2.first->second << "; " <<
//                 i2.second->second << "\n";

        // i1.first != i1.second means exact key match for keyBegin
        // i1.first != i2right means we can overwrite i1_low->second
        // without changing i2right->second
        if(!left_merge && i1.first != i1.second && i1.first != i2right) {
            i1.first->second = val;
            i1.first++;
        }

        // on right merge and exact key match for keyEnd: erase
        // right boundary of the interval
        if(right_merge && i2.first != i2.second)
            i2.first++;

        m_map.erase(i1.first, i2.first);

        // need to insert previous value at KeyEnd only if no key match
        if(!right_merge && i2.first == i2.second) {
            m_map.insert(std::make_pair(keyEnd, i2right->second));
        }

        // only insert keyBegin if not left_merge
        if(!left_merge) {
            m_map.insert(std::make_pair(keyBegin, val));
        }
	}

	//! look-up of the value associated with \c key
	V const& operator[](K const& key) const {
        
		return (--m_map.upper_bound(key))->second;
	}

    //! delete all but the original interval initialized by constructor
	void clear() {
        m_map.erase(std::next(m_map.begin()), m_map.end());
    }

private:
    //! debug only

    //! tests whether intervals satisfy canonical representation
	void intervals_check() {
        
        auto next = m_map.begin(), it = next++;
        V prev = 0;
        for( ; it != m_map.end(); it++, next++) {
       // uncomment this to print intervals in the container
#if 0
            std::cout << "[" << it->first << "; ";
            if(next != m_map.end())
                std::cout << next->first << ") = ";
            else
                std::cout << "+oo) = ";
            std::cout << it->second << "\n";
#endif            
            if(prev != 0 && prev == it->second) {
                std::cout << "FATAL: incorrect intervals..";
                throw 1;
            }
            prev = it->second;
        }
    }
};

//! use placeholder object for keys to make sure
//! we do not implicitly rely on 'operator =='
template < class T >
struct Placeholder {
    
    typedef T inner_type;
    typedef Placeholder< T > Self;

    Placeholder(T _i) : i(_i) { }
    
    friend bool operator <(const Self& x, const Self& y) {
        return x.i < y.i;
    }

    friend std::ostream& operator <<(std::ostream& os,
                  const Self& x) {
        os << x.i;
        return os;
    }
    T i;
};

//! forward numeric limits from type T
namespace std {

template<>
template< class T >
struct numeric_limits< Placeholder< T > > :
    public numeric_limits< T > {   };
}

void IntervalMapTest() {

    typedef interval_map< Placeholder<int>, char> Container;
    Container cont('a');

    try { // simple tests first
    
       //cont.assign2(std::numeric_limits< int >::min(), 1, 'S');

      cont.assign2(1, 5, 'S');
      cont.assign2(1, 5, 'S');
      
      cont.assign2(2, 10, 'B');
      cont.assign2(std::numeric_limits< int >::min(), 1, 'S');
      
      cont.assign(2, std::numeric_limits< int >::max(), 'S');
      
        cont.intervals_check();
       
//         return;
       
       cont.assign2(2, 1, 'B');
       cont.assign2(2, 2, 'B');
       
       cont.assign2(1, 4, 'B');
       cont.assign2(1, 4, 'A');
       cont.assign2(1, 4, 'B');
       cont.assign2(1, 2, 'C');

       cont.assign2(20,-20, 'B') ;

       cont.intervals_check();

//        return;
       cont.assign2(5, 6, 'B');
       
       cont.intervals_check();
       
       cont.assign2(7, 8, 'B');
       cont.assign2(9, 10, 'B');

//        return;
       
       cont.assign2(1, 10, 'A');
       cont.intervals_check();
      
       cont.clear();
       cont.intervals_check();

       srand(time(NULL));

    int niters = 2000000;
    int range = 10;
    int nchars = 10; // # of characters to use

    // on the second pass use only 3 different characters to
    // test special cases
    //for(int i = 0; i < 2; i++, nchars = 3, niters = 1000) {
        
    while(niters--) {
        // boundaries of the interval [l; r]
        int l = rand() % range;// - range/2;
        int r = l + rand() % (range/2);
        char c = (rand() % nchars) + 'a'; // value to be inserted

        if(l % 91 == 0) {  // occasional clear of the container..
            std::cout << "clear\n";
//             cont.clear();
        }

        // keep previous values for comparison
        char lprev = (--cont.m_map.lower_bound(l))->second;
        char rprev = cont[r];
        
        std::cout << "inserting: [" << l << "; " << r << "]: " << c << "\n";
        cont.assign2(l, r, c);
        cont.intervals_check();

        if(l < r && cont[l] != c) { // skip trivial intervals
            std::cout << "FATAL: left bound incorrect!\n";
            throw 1;
        }

        if(l + 1 < r && cont[(l + r)/2] != c) { // make sure interval is inserted correctly
            std::cout << "FATAL: value in the interval incorrect!\n";
            throw 1;
        }

        if(rprev != cont[r]) {  // make sure right boundary is intact
            std::cout << "FATAL: right bound incorrect!\n";
            throw 1;
        }
        // make sure values below left boundary are intact
        if(lprev != (--cont.m_map.lower_bound(l))->second) {
            std::cout << "FATAL: value below left bound incorrect!\n";
            throw 1;
        }
    } // while(iters)
  //  } // for

    } catch(...) {
        std::cout << "\n TEST FAILED!\n";
        return;
    }
    std::cout << "\n TEST PASSED!\n";
}

// Provide a function IntervalMapTest() here that tests the functionality of the interval_map,
// for example using a map of unsigned int intervals to char.
// Many solutions we receive are incorrect. Consider using a randomized test to discover 
// the cases that your implementation does not handle correctly.

int main(int argc, char* argv[]) {
	IntervalMapTest();
	return 0;
}
