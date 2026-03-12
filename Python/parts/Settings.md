# Setting up python and Setting of python
  
## Contents


## Setting up python 
### Windows
1. Install interpreter from [Link](https://www.python.org)
   - Best to install in the directory, so the path won't include spaces or not English letters.
   - Include pip during installation.
   - Add python to path

### Linux
1. ``` sudo apt install python3.12```
2. ```sudo apt install python3-pip```
3. ```sudo apt install python3-venv```
4. Add ```python='python3'``` to **/home/<username>/.bashrc** and reload the terminal.

## Setting up extra tools

### Black (code styler)
#### Windows
```
pip install black
```
#### Linux
```bash
sudo apt install black -y
```

### Pylint (linter)
#### Windows
```
pip install pylint
```
#### Linux
```bash
sudo apt install pylint -y
```
### Ruff
#### Linux
```bash
RUFF_VERSION=$(curl -s "https://api.github.com/repos/astral-sh/ruff/releases/latest" | grep -Po '"tag_name": "v\K[0-9.]+')
wget -qO ruff.tar.gz https://github.com/astral-sh/ruff/releases/latest/download/ruff-$RUFF_VERSION-x86_64-unknown-linux-gnu.tar.gz
sudo tar xf ruff.tar.gz -C /usr/local/bin ruff
ruff --version
rm -rf ruff.tar.gz
```