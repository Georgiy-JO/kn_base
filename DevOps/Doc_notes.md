# Documentation notes 
Include info and notes about code documentation


## Code documentation generator  
Applications that allows to automatically generate documentation (description files) from code files.


### Doxygen  
Can work with multiple programming languages (inc. C++) and generate files and structures of file in different formats (inc. HTML).

#### Instruction:
1. Create generation file, that stores settings and parameters of the generation.
    ```bash
    doxywizard # opens GUI app that simplify creating generation file
    ```
2. Run the file 
    ```bash
    doxygen <file_name>
    ```

#### Use   
App is looking for particular comment format and allows using tags in the code file's comments that will be structured and shown in the resulting documentation.

[Tag examples](/C&C++/Parts/C++.md#comments-standards) (not all supported tags inc.):
```c++
    /**
    * @brief Main function role.
    * @attention Some important info.
    * @return What finction returns.
    * @note Some notes.
    */
    void foo();
```  
#### [Example of Doxygen file](/DevOps/materials/Doxyfile)