/**
I have two methods of an object, and they each access a critical section of code. I want to restrict access to the section so that in one method, I allow multiple threads to access the critical section. In the other method, I want only one thread to have access. If a caller calls the second method, it should lock out all clients from accessing the critical section in either of the two functions. Here is the basic structure of the class:
*/

/** Exception safety guarantees:
    The basic guarantee: that the invariants of the component are preserved, and no resources are leaked.
    The strong guarantee: that the operation has either completed successfully or thrown an exception, leaving the program state exactly as it was before the operation started.
    The no-throw guarantee: that the operation will not throw an exception.

// strong guarantee:
     Container tmp(c); // Copy c
    op(tmp); // Work on the copy
    c.swap(tmp); // Cannot fail7
**/

class ClassThatNeedsFixing
{

    Semaphore s;
    Mutex m;
public:

ClassThatNeedsFixing(int count) : s(count) {
}

// Problem: starvation
    
// Will allow many concurrent threads through, unless there is a
// call to the other method.
void AllowMany() {

    s2.wait();      // s2 required to prevent thread starvation
    s2.signal();
    
    s.wait();
    if(already_in == 0) {
        m.Acquire();
    }
    already_in++;
    s.signal();
    
// Here is the critical section that must be protected
...

    s.wait();
    already_in--;
    if(already_in == 0) {
        m.Release();
    }
    s.signal();
}
// Will lock out any client, including callers to the other method.
void AllowOne() {

// TODO: once a writer arrives: no readers can enter
// the room anymore
    try {

    s2.wait();
    m.Acquire();
// Here is the critical section that must be protected
...
    m.Release();
    s2.signal();
    } catch(...) {
        m.Release();
        throw;
    }
}
private:
// Assume there are members here that need protecting
// above.
...
};

/** In order to solve this problem, you are provided with two classes: Mutex and Semaphore. They have the standard behavior of the concepts that share their class names. Here are the public interfaces for each of these classes: */
class Mutex
{
public:
Mutex();
void Acquire();
void Release();
};
class Semaphore
{
public:
// At it's creation, one can specify the count
// of the semaphore.
Semaphore(unsigned int count);
void Acquire();
void Release();
};

/** 
Fix the ClassThatNeedsFixing implementation so that the critical section is protected.

Your solution will be graded on flexibility and robustness (i.e., we should be able to re-use your solution in a generic case and it should be exception safe). You are allowed to create as many classes/objects/templates/etc that you need. Feel free to use the STL if necessary. Document your code as you would for real-world maintainability. **/