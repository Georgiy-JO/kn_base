# Git tips

## Contents
- [Commands and flags](#commands-and-flags)
- [Connected files](#connected-files)
- [Special situations](#special-situations)
  - [Erasing previous commits in remote repository](#erasing-previous-commits-in-remote-repository)
  - [Renaming a branch in web github](#renaming-a-branch-in-web-github)
  - [Work with large files](#work-with-large-files)
    - [Tweaking repository](#tweaking-repository)


## Commands and flags
### Table 1

| Command                                                                                                                 | Meaning                                   | Kind            | Orbs |
| ----------------------------------------------------------------------------------------------------------------------- | ----------------------------------------- | --------------- | ---- |
| ```git config --global user.name "New Author Name"```<br>```git config --global user.email "<email@address.example>"``` | setting personal information in local git | command<br>flag | 🟡   |
| ```--author="Author Name <email@address.com>"```                                                                        | set an author of particular commit        | flag            | 🔴   |
| ```git reflog```                                                                                                        | show the commit list                      | command         | 🔴   |
| ```git branch -d <branch_name>```<br>```git branch -D <branch_name>```                                                  | delete local branch                       | command<br>flag | 🔴   |
| ```git push -d <remote_repo> <branchname>``` <br>```git push <remote_repo> --delete <branch_name>```                    | deleting remote branch                    | command<br>flag | 🔴   |
| `git log -1 --pretty=%B`                                                                                                | get the last commit's massage             | command<br>flag | 🔴   |
| `git diff`<br> `git diff --quiet`                                                                                       | show the changes made from last commit (flag allows to silence the output)             | command<br>flag | 🟡   |
### Table 2

| Command                                                                          | Meaning                                                                                                              | Kind            | Orbs |
| -------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- | --------------- | ---- |
| ```git clone <repository-url>```                                                 | creates a local copy of a remote repository                                                                          | command         | 🟢   |
| ```git fetch <remote_repo> <remote_branch>``` <br> ```git fetch <remote_repo>``` | downloads commits, files, and refs from a remote repository into a local repo                                        | command         | 🟢   |
| ```git pull <remote_repo>/<remote_branch>```                                     | combines two operations: `git fetch` and `git merge`. It updates your local branch with changes from a remote branch | command         | 🟢   |
| ```git add <files>```                                                            | add files to the commit                                                                                              | command         | 🟢   |
| ```git commit -m"<massage>"```                                                   | committing changes with the certain massage                                                                          | command<br>flag | 🟢   |
| ```git push <remote_repo> <remote_branch>```                                     | uploads local repository content to a remote repository                                                              | command         | 🟢   |
| ```git checkout -b <new_branch_name>```                                          | change a current branch into new one                                                                                 | command<br>flag | 🟢   |
| ```git checkout <existing_branch_name```                                         | change into another existing branch                                                                                  | command         | 🟢   |
| ```git branch```                                                                 | check your local branch list and what branch you are in (`--show-current` - will make it show only current)          | command<br>flag | 🟡   |
| ```git merge <another_branch>```                                                 | allows to integrate (combine) the changes made in one branch into another (from other branch into current one)       | command         | 🟢   |
| `git status`                                                                     | get the current git repository status                                                                                | command         | 🟢   |
| `git log`                                                                        | get the repository log (list of commits with information)                                                            | command         | 🟢   |

## Connected files
- `.gitignor` - list of files to avoid tracking by git.
- `.gitattributes` - specifically formatted list of types of big files to be pushed the special way.  
- `.gitkeep` - empty file put into empty folder to make it tracked by git.

## Special situations

### Erasing previous commits in remote repository
Can be useful if making repository with sensitive information public.

1. Go to desired commit:
```
git checkout <your_commit_hash>
```
2. Go down to the initial commit(*) leaving all current changes:
```
git reset <intial_commit_hash_here> --soft
```
3. Then commit with amend option:
```
git commit --amend -m"My new initial commit"
```
4. Push to your public repository(*):
```
git push <your_remote> <branch_name>
```
* The original change history will still be available with ```git reflog``` locally but will not be pushed to remote repository.

* To get the id of the first commit use the command from this answer:
```
git rev-list --max-parents=0 HEAD
```
* There will be conflict if you are pushing to an already existing branch of the remote repository. That can be by-passed by pushing into new branch, and then deleting the old one and renaming new one accordingly.

### Renaming a branch in web github
In case you renamed a branch you are locally using in web github page.
```
git branch -m <old_branch_name> <new_branch_name>
git fetch <your_remote>
git branch -u <your_remote>/<new_branch_name> <new_branch_name>
git remote set-head <your_remote> -a
```
* Example:
    ```
    git branch -m main_1 main
    git fetch origin
    git branch -u origin/main main
    git remote set-head origin -a
    ```

### Work with large files

#### Installation 
To be able to push large files you need to [install Git LFS](https://git-lfs.com/)
1. Install package:
```bash
#fedora, etc
curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.rpm.sh | sudo bash
sudo yum install git-lfs
#ubuntu, etc.
curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | sudo bash
sudo apt-get install git-lfs
```
2. ```git lfs install```
#### Tweaking repository
In each Git repository where you want to use Git LFS, select the file types you'd like Git LFS to manage (or directly edit your `.gitattributes` file in main directory). You can configure additional file extensions at anytime.
* Example:
```bash
git lfs track "*.psd"
```