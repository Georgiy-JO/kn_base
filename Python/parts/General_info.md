# General info

## Contents


## Main
- Creation of python started in 1991.
- Python 3 was released in 2008.
- Fields of usage:
  - AI and NN (ML&AI)
  - Website Backend (Django, Flask, etc.)
  - Big data
  - Mobile games
  - etc.
- Python is mostly [interpreted language](/General/Dictionaty.md#interpreted-languages). 
- Python is [dynamically typed language](/General/Dictionaty.md#dynamically-typed-languages): [example](Python#types)
- The Python interpreter is a program that reads and executes Python code, converting it into machine code that the computer can understand. I can be used on a go for interactive coding (running scripts just by writing those).
  - Can do math (work like calculator) too.


## Interpreter
### Running
To run interpreter:
- Can use console (CMD/Terminal) to use Python interpreter. To do so activate interpreter in console.
  - To enter it:
    ```bash
    python
    #or
    python3
    ```
  - To exit
    ```bash
    exit()
    ```S
    or   
    **Ctrl+Shift+C**
- Can use **IDLE shell**.

### Usage
- Writing ```import <module_name>``` will import module to the current interpreter session (functions from the module can be used now).
- Creating variables is allowed, those can be used inside current interpreter session.


## Run code file
```bash
python file.py
#or
python3 file.py
```

## Language's keywords
```bash
python3         # to enter interpreter
help()          # to enter help
keywords        # to get the list of keywords of the language
```

## Code style and Ideas

### Local code style
All the code style rules can be found at [**PEP 8**](https://peps.python.org/pep-0008/)


### Code philosophy
Python has its own philosophy (**PEP 20**):
```
The Zen of Python, by Tim Peters

Beautiful is better than ugly.
Explicit is better than implicit.
Simple is better than complex.
Complex is better than complicated.
Flat is better than nested.
Sparse is better than dense.
Readability counts.
Special cases aren't special enough to break the rules.
Although practicality beats purity.
Errors should never pass silently.
Unless explicitly silenced.
In the face of ambiguity, refuse the temptation to guess.
There should be one-- and preferably only one --obvious way to do it.
Although that way may not be obvious at first unless you're Dutch.
Now is better than never.
Although never is often better than *right* now.
If the implementation is hard to explain, it's a bad idea.
If the implementation is easy to explain, it may be a good idea.
Namespaces are one honking great idea -- let's do more of those!
```  

You can get it yourself by running:  
```python
import this
```

### Helpers
There are programs that can help with code styling and keeping your program nice and clean.  

- Linters - static code analyzes instrument (without running it). 
  - Those check for:
    - issues (unused variables, unneeded includes, some bugs);
    - **PEP 8** (code style);
    - "*code smells*" - too complicated functions, code doubles etc.;
    - elements that may need refactoring (show some suggestions).
  - Examples:
    - *flake8*;
    - *pylint*;
    - *ruff*.
- Code formatters - format the code according to **PEP 8** or something else - code styling.
  - Examples:
    - *black*;
    - *autopep8*;
    - *yapf*

#### Black for Python
A code formatter (style the code).
- Automatically rewrites code to the standard style (PEP 8 + own rules).
- Has almost no settings, is fast.
- [Installing](Settings.md#black-code-styler). 
- The checker can be integrated into VScode: *python.analysis.typeCheckingMode* in settings.
- Run: ```black file.py```

#### Pylint
A linter (static code analyzer, not just code styler).
- What it does:
  - code styling: **PEP 8** + 1000+ more rules;
  - bugs search (ex.:```except: pass```);
  - rate the code (0 to 10);
  - suggest refactoring
- [Installing](Settings.md#pylint).
- Run: ```pylint file.py```

### Ruff
A linter (static code analyzer and code styler).
- Does the same as **Pylint**, but faster.
- [Installing](Settings.md#ruff).
- Run: ```ruff file.py```
  
#### Notes
- **Black** checks and changes code automatically, while **Pylint** only gives suggestions.
- Best practice: run **Black** first, then **Pylint**/**Ruff**.
- In modern project it is usual practice to have **pyproject.toml** file that configures code check. And during CI/CD (GitHub Actions, GitLab CI, pre-commit) this file can be used via *CI/CD-yaml* file to check code and fail pipeline in case of an issue. 
  - Example: [pyproject.toml](../materials/pyproject.toml) + [CI_CD_exaample.yaml](../materials/CI_CD_exaample.yaml)

## Links
### Learning order
1. Python for beginners (RU) - [Link](https://www.youtube.com/playlist?list=PLA0M1Bcd0w8yWHh2V70bTtbVxJICrnJHd)
2. Python standard library (RU) - [Link](https://www.youtube.com/playlist?list=PLA0M1Bcd0w8yw3Cm7xQwiZuXBTCL8b_gJ)
3. Harvard CS50’s Introduction to Programming with Python (EN) - [Link](https://www.youtube.com/watch?v=nLRL_NcnK-4)
4. 5 good Python habits (EN) - https://www.youtube.com/watch?v=I72uD8ED73U&t=9s
5. 5 python concepts (EN) - https://www.youtube.com/watch?v=Gx5qb1uHss4 
6. OOP with Python (RU) - [Link](https://www.youtube.com/playlist?list=PLA0M1Bcd0w8zPwP7t-FgwONhZOHt9rz9E)
7. NumPy (RU) - [Link](https://www.youtube.com/playlist?list=PLA0M1Bcd0w8zmegfAUfFMiACPKfdW4ifD)
8. NN (Neuron networks) with Python (RU) - [Link](https://www.youtube.com/playlist?list=PLA0M1Bcd0w8yv0XGiF1wjerjSZVSrYbjh)
9. Signals analysis with Python (RU) - [Link](https://www.youtube.com/playlist?list=PLA0M1Bcd0w8yZNgl5J814WQykTZnzj771)
10. WxPython (GUI with Python) (RU) - [Link](https://www.youtube.com/playlist?list=PLA0M1Bcd0w8zyJOJXbvTKROHs2JJVGB6C)
11. Pygame (RU) - [Link](https://www.youtube.com/playlist?list=PLA0M1Bcd0w8xg_hyqpPpHdbZnPubSyIQ_)
