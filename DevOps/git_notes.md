# Git tips


## Commands and flags

| Command                                                                                                                 | Meaning                                                                                                              | Kind            |
| ----------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- | --------------- |
| ```git config --global user.name "New Author Name"```<br>```git config --global user.email "<email@address.example>"``` | setting personal information in local git                                                                            | command<br>flag |
| ```git fetch <remote_repo> <remote_branch>``` <br> ```git fetch <remote_repo>```                                        | downloads commits, files, and refs from a remote repository into a local repo                                        | command         |
| ```git pull <remote_repo>/<remote_branch>```                                                                            | combines two operations: `git fetch` and `git merge`. It updates your local branch with changes from a remote branch | command         |
| ```git push <remote_repo> <remote_branch>```                                                                            | uploads local repository content to a remote repository                                                              | command         |
| ```git checkout -b <new_branch_name>```                                                                                 | change a current branch into new one                                                                                 | command<br>flag |
| ```git checkout <existing_branch_name```                                                                                | change into another existing branch                                                                                  | command         |
| ```git branch```                                                                                                        | check your local branch list and what branch you are in                                                              | command         |
| ```git merge <another_branch>```                                                                                        | allows to integrate (combine) the changes made in one branch into another (from other branch into current one)       | command         |
| ```--author="Author Name <email@address.com>"```                                                                        | set an author of particular commit                                                                                   | flag            |
| ```git reflog```                                                                                                        | show the commit list                                                                                                 | command         |

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
