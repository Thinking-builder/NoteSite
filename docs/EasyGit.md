# EasyGit

## Basic Command

>I recommand you to learn ``shell`` previous to ``Git command``,because the latter is based on the former.And You will grasp the real meaning of the structure of every command instead of just memorizing these without logic.

What I should highlight is that I won't introduce all the command. The command I mention is likely to be these most useful ones.

### Init-Config

To first know what is Git repo,I think you should know what is ``Config``

```shell
git config --list
```

After executing the command, you will get all the information contained in ``.gitconfig`` file.  
So now, how do we edit the ``.gitconfig``:

```shell
git config -e #target at the pwd
```

or:

```shell
git config -e --global # target at all the git repo.
```

However, you needn't to edit the config at most cases.  
Basically, you need to set your name and email,which will be part of the log imformation.

```shell
git config --global user.name"Kerry"
git config --global user.email"Kerry@gmail.com"
```

Note - ``"Kerry"`` is an alternative example.

### Set Up Our Repository

You can use the command below to create a repository **under presennt work directory("pwd")**.

```shell
git init
```

To check what have been included in the git repository,you can try the commmand:

```shell
ls -al
```

### Push the file under track

First, I should introduce  various states of the files. Git has three types of file states: **working directory**, **staging area**, and **local repository**. When you connect your local repo to remote repo,the file will have a new state - **remote repository**.

![Various file states](./file%20states.png "Various file states")

Notice 

How to add/update files to the Git repo.

```shell
git add *.c
git add README
```

After the action, you need to commit these changes to Git.

```shell
git commit -m 'First Commmit'
```

!!! Note Instructions
    'First Commit' is an alternative example.  

    Notice,when your environment is **Linux Bash or Mac Terminal**,the info you commit should be surrounded by  ``''``.When your environment is **Windows shell**,it is supposed to be surrounded by ``""``

### Check Information

To check the information of 'Git object', we often use the command below:

```shell
git show
```

Usually, we need to track information connected with the project's update.

```shell
git log 
```

## Make Connection with Github


## Set Regular WorkFlow
