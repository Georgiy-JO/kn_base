# Prefix sum
This concept is useful when we work with an array of elements and may need to calculate sums of different segments of it.

## Concept

- Input: array of numbers ```a[n]``.
- Logic: create a parallel array of elements ```sums[n+1]```, where ```sum[i]=sum[i-1]+a[i-1]``` and ```sum[0]=0```.
  - Remember to check for overloads.
  - Remember that if original array had ```n``` elements, array of prefix sums will have ```n+1``` elements.  
  ![ScShot_1](/General/Algorithms/media/prefix_1.png "Prefix_sum table")  
- Output: sum of elements from ```m``` (included) to ```k``` (not included) will be ```sums[k]-sums[m]```.


## The core of logic (why it works)
The idea will work for any operation that has reverse operation:
 - ```+``` and ```-```
 - ```*``` and ```/``` (EXCEPT ```0```).
   - When there is ```0``` in set of values it must be handled with caution! For exmaple:   
     1. ```prefix[i]=(a[i-1]==0)?1:prefix[i-1]*a[i-1]```
     2. if between ```a[l]``` and ```a[r]``` there is ```0``` return ```0```, else ```prefix[r]/prefix[l]```.
 - ```XOR``` and ```XOR```   
    | input| result|
    |---|---|
    |0^0| 0|
    |0^1| 1|
    |1^0| 1|
    |1^1| 0|
 - etc.
The idea will work if we are counting amount of something. 

## Usage examples   
### 1
- Input: array of numbers (with ```0```).
- Task: how many numbers are from ```l``` to ```r``` (not included)?
- Logic:
  - Create a prefix array with following logic: ```prefix[0]=0```, ```prefix[i]=prefix[i-1]+(a[i-1]==0)?1:0```.
- Output: ```prefix[r]-prefix[l]```.  
### 2 
Amount of certain latter in string.  
### 3 
- Input: array of ``n`` numbers.
- Task: find amount of sub-arrays with sum equal ``0``.
- Main idea: if some of all elements of the segment is equal ``0`` this segment in prefix array will start and end with the same number.
- Logic:
  - Create a prefix array with following logic: ```prefix[0]=0```, ```prefix[i]=prefix[i-1]+a[i-1]```.
    - We don't need to store the prefix sum array, we can just use one variable of the current sum (due to next step).
  - Create a dictionary of ```m``` and how many ```prefix[j]==m```. For example ```vect[m]``` equal amount of ```prefix[j]==m```.
  - Calculate how name pairs of can ```vect[i]``` create for each ```i```.   
    ![ScShot_2](/General/Algorithms/media/prefix_2.png "Amount of pairs")  
    - ```res(vect[i]) = vect[i]*(vect[i]-1)/2```
- Output: amount of sub-arrays equal sum of all amounts of pairs of ```vect[i]```.
     