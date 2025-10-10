# EasyGit

Some reference:

|Reference| Description|
| :---: | :---:|
| Runoob Git Instruction | [Click And See](https://www.runoob.com/git/git-remote-repo.html) |

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

### Push the file under track{#file-States}

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

!!! Note "Instructions"
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

Now welcome to Practice: How to create and track the project with the help of Git and Github?

### Emmbed Git to Your Computer

The installation is too easy to say.Please check relevant introduction to learn yourself.And You can execute the command below to check whether it is installed properly.

```shell
git --version
```

### Create Local Repo

You can refer to the [file states pic](#push-the-file-under-trackfile-states) above.So we need to create Local repo.If you have had a directory already,you just need to initiate:

```shell
git init # create git repo (local repo) under pwd.
```

If not, you can use the directory you specified as the Git repository:

```shell
git init newrepo
```

Else, You can set a new repo on Github and then clone:

```shell
git clone <repo> <directory> # standard format
git clone git@github.com:username/repo-name myproject # the tail of the sentence is the name of repo.
```

Then you can follow the first part of the article to set up config and check.

### Add Remote Repo

Now you come to the core part of the Practice.

```shell
git remote add [shortname] [url]
```

Then you can use the command below to check if right:

```shell
git remote
git remote -v #Visualize - You can see the actual link address for each alias
```

What's more, you need a **SSH** to achieve the mutual trust between Git repositories and Github sites.
Now I recommend [this ariticle](https://www.runoob.com/git/git-remote-repo.html) to you to learn.

### Regular Workflow

Now let me introduce how to achieve regular workflow,which contains ``Update``,``Remove``,``Edit``and so on.

First, you should fetch the Remote Repo

!!! Note "Why To fetch"
    If you don't fetch Remote Repo, you can't know what includes in that. As a result, you won't achieve the change properly.

```shell
git fetch #Fetch all remotes
git fetch origin #Fetch certain remote called 'origin'
```

Then you can synchronize updates locally using the following command:

```shell
git merge origin
```

Then we can pull all updates to Remote Repo:

```shell
git pull [alias] [branch]
```

### [*]Appliaction: Build Mkdocs Website

!!! tip "Tip"
    This part is based on Git and Shell, but the concerned knowledge will **exceed** what includes in Git.
