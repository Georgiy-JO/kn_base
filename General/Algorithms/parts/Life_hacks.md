# Life hacks
Little algorithmic ides that can be useful in different situations.

## Ring buffer

Let's say we want to create a queue with set amount of elements ```n``` and amount of operations (adding element, removing element) ```m```.    

Conventional ways of realization:
- queue that moves every time the first element is removed;
- queue that has a movable pointer to the beginning of the queue, but elements are not moving.   
  
Issues if ```n``` or ```m``` are large:
 - Every time we remove element we need to copy all the others.
 - Pointer will move too far away.   

Solution: ring buffer.
- The buffer has a constant (or rarely changed) buffer of ```n```.
- Pointer to the first and last elements are moving around the buffer:```beg[n]``` is ```beg[0]``` etc.
  - Best way of realization is ```beg[i%n]```.    

With caution:
- the ring buffer is the best if the maximum amount of elements is knows from the beginning. Otherwise, we would need to make it larger during the process.












