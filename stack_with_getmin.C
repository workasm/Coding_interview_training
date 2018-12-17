
/**
implement a stack with three operations: push/pop and getmin in constant
time

Non-constant-space solution

Keep a "duplicate" stack of "minimum of all values lower in the stack". When you pop the main stack, pop the min stack too. When you push the main stack, push either the new element or the current min, whichever is lower. getMinimum() is then implemented as just minStack.peek().

*/
          stack     min_stack
push 2:    [ 2 ]       [ 2 ]
push 4:   [4  2 ]      [ 2 2 ]
push 1:   [1 4 2 ]     [1 2 2 ]
push 5:   [5 1 4 2 ]   [1 1 2 2 ]
pop 5:   [1 4 2 ]      [1 2 2 ]
pop 1:   [4 2 ]        [2 2 ]
