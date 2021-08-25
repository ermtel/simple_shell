# Simple Shell

## About
Modeled after the first [Unix shell](https://en.wikipedia.org/wiki/Thompson_shell) by Ken Thompson, the `hsh` handles commands located in the [$PATH](https://en.wikipedia.org/wiki/PATH_%28variable%29) and supports a number of additional, built-in features listed below.

### Built-In Commands
| Built-in | Use |
|--|--|
| `exit` | exits the shell |
| `env` | prints the current environment |

### Aditional Features
- Handles Ctrl+C signal
- Exits upon end-of-file (Ctrl+D)
- Contains no Memory leaks

## Getting Started
A starter's guide to setting up `hsh`.

### 1. Install
To download a copy of the source code locally, please run the following command in your terminal:
```
$ git clone https://github.com/ermtel/simple_shell.git
```

### 2. Compile
After downloading the source code, you can use the following command to compile a working version of the shell:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### 3. Use
`hsh` should now be ready to use. To start the shell in interactive mode, please use the following command:
```
./hsh
```
You should now see a `$`, which means `hsh` is awaiting input.
## Executing Commands
There are many commands you can execute from within `hsh`. Below are some examples of things you can try.

---------
### `ls -l`

`ls` lists the contents of your current directory. The `-l` flag specifies the listing should be in long format.

```
$ ls -l
total 80
-rw-r--r-- 1 root root   157 Apr 29 05:56 AUTHORS
-rw-r--r-- 1 root root  1420 Apr 29 06:08 README.md
-rw-r--r-- 1 root root   906 Apr 29 05:56 builtin.c
-rw-r--r-- 1 root root  2563 Apr 29 05:56 env.c
-rw-r--r-- 1 root root  1327 Apr 29 05:56 error_message.c
-rw-r--r-- 1 root root  1377 Apr 29 05:56 exec.c
-rw-r--r-- 1 root root  1275 Apr 29 05:56 holberton.h
-rwxr-xr-x 1 root root 18771 Apr 29 06:10 hsh
-rw-r--r-- 1 root root   677 Apr 29 05:56 man_1_simple_shell
-rw-r--r-- 1 root root  2109 Apr 29 05:56 mem.c
-rw-r--r-- 1 root root   501 Apr 29 05:56 prompt.c
-rw-r--r-- 1 root root   647 Apr 29 05:56 shell.c
-rw-r--r-- 1 root root  1372 Apr 29 05:56 split.c
-rw-r--r-- 1 root root  1875 Apr 29 05:56 str.c
-rw-r--r-- 1 root root   392 Apr 29 05:56 str2.c
-rw-r--r-- 1 root root   784 Apr 29 05:56 strtok.c
```
---------
### `echo anything`
`echo` displays a line of text. It takes a string of characters to be displayed as an argument.
```
$ echo anything
anything
```
---------
### `touch file.txt`
`touch` creates a new file in the current directory. It takes a file name, such as `file.txt` as an argument.
```
$ touch file.txt
$ ls
AUTHORS  README.md  builtin.c  env.c  error_message.c  exec.c  file.txt  holberton.h  hsh  man_1_simple_shell  mem.c  prompt.c  shell.c  split.c  str.c  str2.c  strtok.c
```
---------
### `rm file.txt`
`rm` deletes a file. It takes a file name, such as `file.txt` as an argument.
```
$ rm file.txt
$ ls
AUTHORS  README.md  builtin.c  env.c  error_message.c  exec.c  holberton.h  hsh  man_1_simple_shell  mem.c  prompt.c  shell.c  split.c  str.c  str2.c  strtok.c
```
---------
### `exit`
`exit` exits the shell.
```
$ exit
root@90e0ba427cf3:/simple_shell#
```
---------
### `man`
To view documentation on each command, you can use `man` followed by the command you would like to know more about. For example, `man ls` will display information about the command `ls`. 

## Interactive vs. Non-Interactive Mode
You can use the shell in both interactive and non-interactive mode. The examples above are done in interactive mode. You can tell because the shell runs continuously, awaiting and executing commands, until you explicitly `exit` using EOF command or `exit` command.

Non-interactive mode, however, is when you indirectly feed commands into the executable `hsh` file from outside the shell. For example, we can list files by indirectly piping `ls` into `hsh` using `echo`:
```
$ echo "ls" | ./hsh
AUTHORS  README.md  builtin.c  env.c  error_message.c  exec.c  holberton.h  hsh  man_1_simple_shell  mem.c  prompt.c  shell.c  split.c  str.c  str2.c  strtok.c
```

## Environment Information
This shell was built and tested in the following environment by [Ermias Telahun](https://github.com/ermtel) and [Shelter Mashonganyika](https://github.com/gigashelter) as a project for [ALX Africa](https://www.alxafrica.com/) in collaboration with [Holberton School](https://www.holbertonschool.com/).

| Feature | Version |
|--|--|
| **Language** | C |
| **Operating System** | Ubuntu 14.04 LTS |
| **Compiler** | `gcc 4.8.4` |
| **Style Guidelines** | [`Betty`](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") |