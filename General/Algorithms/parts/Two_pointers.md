# Two pointers
This method allows to minimize the number of cycle iterations by moving through the set simultaneously with 2 different pointers.

## Main idea
Two pointers are moving through an array independently (one does not reset another).

## Concept
### Example #1
- Input: array of ``n`` numbers ordered from smallest to biggest (include equal numbers) - ```a[n]``` and number **K** - ```k```.
- Task: find amount of pairs of numbers **A** and **B** so that **B-A>K**.
- Main idea: let's say we have 2 pointers (***r*** and ***l***).
  - If we have found a pair of ***l***+***r***>**K** then ***l*** + any element righter than ***r**>**K**.
  - If we have found a pair of ***l***+***r***>**K** and moved ***l***, any element lefter than ***r*** + ***l***<***K***.
- Logic:
  - ```res = 0```.
  - Let's go through the ```a[n]``` with 2 iterators: ```r``` and ```l```.
  - We set those at the beginning of the array and started moving the ```r``` pointer.
  - As soon as ```a[l] + a[r] > k``` we calculate: ```res += (n - r)```.
  - ```l++``` and find a new pair so ```a[l] + a[r] > k``` by moving the ```r```.
  - etc.
- Output: amount of pairs of numbers **A** and **B** so that **B-A>K** is equal to ```res``` and was calculated in **O(n)**.

### Example #2
- Input: array of ``n`` numbers ordered from smallest to biggest (include equal numbers) - ```a[n]```.
- Task: the maximum sum of the elements of ```a[n]``` so that sum of any pair of selected elements is smaller than the largest selected element.
- Main idea: we need to find a set of elements of the original array with the maximum sum of elements.
  - If ```a[i] + a[i+1] > a[j]```, then ```a[k] + a[m] > a[j]``` for any ```k``` and ```m``` bigger or equal to ```i``` and smaller or equal to ```j```.
  - Even if ```a[z] + a[i] > a[j]``` with ```z < i-1```, it is better to take ```z = i-1``` to maximize the resulting sum of the elements of the set.
  - If all previous is true, and ```a[i] + a[i+1] <= a[j+1]``` and ```a[i-1] + a[i] <= a[j]``` then the set of elements goes from ```a[i]``` to ```a[j]``` and include all the numbers between.
- Logic:
  - ```res = 0```.
  - Let's start with ```i = 0``` and find the last ```j``` (by moving it from ```i+1``` to ```n```) so that the conditions are met.
  - Calculate the sum and if it is larger than ```res``` set ```res``` equal to it.
  - Set ```i=i+1``` and repeat.
  - To minimize the work time instead of calculating the sum of the set every time we can save it through the iteration as ```sum``` and just do ```sum += a[j]``` after moving ```j``` right and ```sum -= a[i]``` before moving ```i``` right.
- Output: ```res``` is equal to the maximum sum (it took **O(n)**).

### Example #3
- Input: two arrays (```a[n]``` and ```b[m]```)
- Task: make into one sorted array.
- Logic:
  - Sort both arrays.
  - Create pointers in both arrays and go through them simultaneously comparing ```a[i]``` and ```b[j]```:
    - if ```a[i] <= b[j]```, ```res.push_back(a[i])``` and ```i++```,
    - if ```a[i] > b[j]```, ```res.push_back(b[j])``` and ```j++```.
  - If one of arrays ended all the elements of the second one goes to the end of ```res```.  
    ![ScShot_1](/General/Algorithms/media/pointers_1.png "Two arrays and two pointers (python)") 

- Output: ```res```.

### Example #4
- Input: a string and ```k``` number.
- Task: find the largest substring so any element's amount will be smaller or equal to ```k```.
- Logic:   
  ![ScShot_2](/General/Algorithms/media/pointers_2.png "Example 4 (python)") 