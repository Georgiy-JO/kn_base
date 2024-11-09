# Some notes and tips about Linux

## Contents
- [[#Useful commands, utilities, daemons, etc.|Useful commands, utilities, daemons, etc.]]
	- [[#Useful commands, utilities, daemons, etc.#Table 1|Table 1]]
	- [[#Useful commands, utilities, daemons, etc.#Table 2|Table 2]]
	- [[#Useful commands, utilities, daemons, etc.#Table 3|Table 3]]
	- [[#Useful commands, utilities, daemons, etc.#Table 4|Table 4]]
	- [[#Useful commands, utilities, daemons, etc.#\*0 (restart audio system)|\*0 (restart audio system)]]
	- [[#Useful commands, utilities, daemons, etc.#\*8 (chmod)|\*8 (chmod)]]
		- [[#\*8 (chmod)#Symbolic mode|Symbolic mode]]
		- [[#\*8 (chmod)#Numeric mode|Numeric mode]]
- [[#Server Ubuntu installation|Server Ubuntu installation]]
- [[#Fedora after installation setting up|Fedora after installation setting up]]
- [[#SSH and TCP forwarding|SSH and TCP forwarding]]
- [[#OS family|OS family]]
- [[#Extra|Extra]]
	- [[#Extra#[Fedora ultimate update script](/Linux/materials/Scripts/update.sh)|Fedora ultimate update script]]
	- [[#Extra#[Fedora libraries paths](/Linux/materials/libraries%20paths.txt)|Fedora libraries locations]]
- [[#Links:|Links:]]


* ***`Ctrl+Shift+C` stop the current process***
* [Standard shell: **sh**, **bash**. ](/Bash/Bash_notes.md)
## Useful commands, utilities, daemons, etc.
🔴🟡🟢
* tag-list: *system*, *install*, *file*, *management*, *memory*, *network*.

### Table 1

| Command                                                                    | Meaning                                                                                                                                                    | Tag                   | System                                         | Orb |
| -------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------- | ---------------------------------------------- | --- |
| `uname`                                                                    | command  is used to display system information (`uname` stands for "Unix name")                                                                            | system                | -                                              | 🟡  |
| `chmod`                                                                    | command-line utility used to change the file system modes (permissions) of files and directories [(*8)](#8-chmod)                                          | file<br>management    | -                                              | 🟡  |
| `locate \<something>`                                                      | find something                                                                                                                                             | file<br>management    | -                                              | 🟡  |
| `dnf list installed`                                                      | list installed                                                                                                                                               | management    | -                                              | 🟡  |
| `xdg-open`                                                                 | Open file accordingly                                                                                                                                      | file<br>management    | -                                              | 🟡  |
| `diff`                                                                     | command compares the contents of the two files *9                                                                                                          | file                  | -                                              | 🟡  |
| `/dev/null`                                                                | which is a special file that discards all data written to it.                                                                                              | management<br>file    | -                                              | 🟡  |
| `sudo dnf clean all`                                                       | clean temple                                                                                                                                               | install               | RPM-based Linux distributions (such as Fedora) | 🟡  |
| `sudo dnf clean dbcache`                                                   | clean cache                                                                                                                                                | install               | RPM-based Linux distributions (such as Fedora) | 🟡  |
| `sudo dnf remove`                                                          | deleting some installed package/app/etc                                                                                                                    | install<br>management | RPM-based Linux distributions (such as Fedora) | 🟡  |
| `neofetch`                                                                 | system info                                                                                                                                                | management<br>system  | install separately                             | 🟢  |
| `fdisk -l`                                                                 | list the disk partitions and their details                                                                                                                 | memory<br>management  | -                                              | 🟢  |
| `wget`                                                                     | used to download files from internet                                                                                                                       | management<br>network | -                                              | 🟡  |
| `curl`                                                                     | command-line tool used for transferring data with URLs (like getting data from websites), it supports various protocols, including HTTP, HTTPS, FTP, etc.  | network               | -                                              | 🟡  |
| `SSH <remote_user_name>@<device_ip> "\<commands>"/\<nothing>`              | command used to connect to a remote server using the SSH protocol and make some actions there. Allow online control or passing list of commands [(*7)](#7) | management<br>network | -                                              | 🟡  |
| `SCP <files_to_copy> <remote_user_name>@<device_ip>:<place_where_to_copy>` | Secure Copy Protocol, which is used to securely transfer files between hosts over SSH [(*7)](#7)                                                           | management<br>network | -                                              | 🟡  |
| `sshpass -p '\<password>' <SCP/SSH> ...`                                   | allow to automate **SSH** and **SCP**, aka pass the password in the line of the command                                                                    | management<br>network | install separately                             | 🟡  |
| `ip r`                                                                     | view the current routing table [(*6)](#6)                                                                                                                  | network               | -                                              | 🟢  |
| `ipcalc`<br>`ipcalc-jodies`<br>`ipcalk`                                    | perform calculations related to IP addresses and subnets                                                                                                   | network               | differ in different systems                    | 🟢  |
| `ps`                                                                       | information about the currently running processes                                                                                                          | management            | -                                              | 🟡  |
### Table 2

| Command                                                                       | Meaning                                                                                                                                                                                                                                                                                                                                                      | Tag                 | System                                         | Orb |
| ----------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------- | ---------------------------------------------- | --- |
| `sudo reboot`                                                                 | restart/reboot                                                                                                                                                                                                                                                                                                                                               | system              | -                                              | 🟢  |
| `touch <file_name>`                                                           | is used primarily for two purposes:<br>1. **Creating Empty Files**: If the specified file does not exist, `touch` will create an empty file with that name.<br>2. **Updating Timestamps**: If the specified file already exists, `touch` will update the file's access and modification timestamps to the current time without modifying the file's content. | file <be>management | -                                              | 🟢  |
| `sudo apt update <br> sudo apt-get update`                                    | updates the local package index with the latest information about available packages and their versions from the repositories configured on your system                                                                                                                                                                                                      | install             | Debian-based Linux distributions (like Ubuntu) | 🟢  |
| `sudo apt upgrade<br> sudo apt-get upgrade`                                   | upgrades all the installed packages on your system to their latest versions based on the updated package index                                                                                                                                                                                                                                               | install             | Debian-based Linux distributions (like Ubuntu) | 🟢  |
| `sudo dnf updateinfo <br>sudo yum updateinfo`                                 | updates the local package index with the latest information about available packages and their versions from the repositories configured on your system                                                                                                                                                                                                      | install             | RPM-based Linux distributions (such as Fedora) | 🟢  |
| `sudo dnf upgrade<br>sudo yum upgrade<br>sudo dnf update <br>sudo yum update` | upgrades all the installed packages on your system to their latest versions based on the updated package index                                                                                                                                                                                                                                               | install             | RPM-based Linux distributions (such as Fedora) | 🟢  |
| `sudo <apt/apt-get/dnf/yum> install <package_name>`                           | installing app/package/daemon/etc                                                                                                                                                                                                                                                                                                                            | install             | -                                              | 🟢  |
| `mc`                                                                          | UI file manager in terminal (+ text file redactor `mcedit <file_name>` )                                                                                                                                                                                                                                                                                     | file<br>management  | install separately                             | 🟢  |
| `top <br>htop`                                                                | task managers                                                                                                                                                                                                                                                                                                                                                | management          | -                                              | 🟢  |
| `sl`                                                                          | -                                                                                                                                                                                                                                                                                                                                                            | -                   | install separately                             | 🟢  |
| `ssh-keygen`                                                                  | command-line utility used to generate, manage, and convert authentication keys for SSH (Secure Shell), it is a fundamental tool for creating SSH key pairs, which are used for secure authentication without the need for a password                                                                                                                         | network             | -                                              | 🟢  |
| `ping -c <number_of_packets> <url_adress>`                                    | ping an address                                                                                                                                                                                                                                                                                                                                              | network             | -                                              | 🟢  |
### Table 3

| Command           | Meaning                                                                                                             | Tag     | System               | Orb |
| ----------------- | ------------------------------------------------------------------------------------------------------------------- | ------- | -------------------- | --- |
| `netstat`         | displays network connections, routing tables, interface statistics, and more                                        | network | -                    | 🟡  |
| `netstat -rn<br>` | view the current routing table (r - routing table, n - do not convert IP to names) [(*5)](#5)                       | network | -                    | 🟡  |
| `netplan`         | command-line utility for managing network configuration   [(*1)](#1)                                                | network | Ubuntu-based systems | 🟡  |
| `iptables`        | utility used for configuring and managing the packet filtering rules of the Linux kernel's net filter **framework** | network | -                    | 🟡  |
### Table 4

| Command             | Meaning                                                                                             | Tag                  | System             | Orb |
| ------------------- | --------------------------------------------------------------------------------------------------- | -------------------- | ------------------ | --- |
| `df \<directory>`   | display information about the disk space usage [(*3)](#3)                                           | memory<br>management | -                  | 🟡  |
| `du \<directory>`   | display the disk space usage of the current directory and all its sub-directories [(*4)](#4)        | memory<br>management | -                  | 🟡  |
| `ncdu \<directory>` | "NCurses Disk Usage" and is a disk usage analyzer with a text-based UI (more user friendly **du**)  | memory<br>management | install separately | 🟡  |
| `cron`              | allows users to schedule scripts or commands to run automatically at specified intervals [(*2)](#2) | management           | -                  | 🟡  |
| `ifconfig`          | lists network interfaces (includingloopback interface)                                              | network              | -                  | 🟡  |
| `nmap`              | powerful open-source tool used for network discovery and security auditing                          | network              | install separately | 🔴  |



### \*0 (restart audio system)
```Bash
systemctl --user restart wireplumber pipewire pipewire-pulse
```
### \*1
```bash
sudo netplan #generates network configuration file 
# aka   00-installer-config.yaml or 01-netcfg.yaml
sudo nano /etc/netplan/00-installer-config.yaml  #adjust the file

sudo netplan apply # apply the changes
```
* Configuration of this *.yaml*   file changes the network configuration of the machine.

### \*2
```bash
crontab -l #check for active cron tasks;
crontab -e  #to edite (create) cron task file:
```

### \*3
#### Flag examples
| Flag | Meaning                             |
| ---- | ----------------------------------- |
| `-h` | human interpretation of memory size |
| `-T` | type of memory management           |

### \*4
* the directory can be NOT specified
#### Flag examples
| Flag                   | Meaning                                 |
| ---------------------- | --------------------------------------- |
| -h                     | human interpretation of memory size     |
| -b                     | show in bytes                           |
| `--max-depth=<number>` | set how deep to go into sub-directories |

### \*5
`netstat` (short for "network statistics") itself is a command-line utility used to display network connections, routing tables, interface statistics, masquerade connections, and multicast memberships.

### \*6
`ip` suite of commands used in Linux for managing network interfaces, routing, and other networking tasks.
#### Options
Not flags 
* `r` -  show the current routing table
* `a` - show the IP addresses assigned to all network interfaces, along with their status and other relevant information

### \*7
- `-o StrictHostKeyChecking=no` - flag of SCP and SSH that tells them to automatically add the remote host's key to the list of known hosts without prompting the user

### \*8 (chmod)
* The basic **syntax** for the *chmod* command is:
	```Bash
	chmod [options] mode file(s)
	```
* **Types** of access:
	- **Read (r)/(4)** - Permission to read the contents of a file or list the contents of a directory.
	- **Write (w)/(2)** - Permission to modify or delete a file or add/remove files in a directory.
	- **Execute (x)/(1)** - Permission to execute a file as a program or script or to enter a directory.

* Typical **categories of users**:
	- **Owner (u)**: The user who owns the file.
	- **Group (g)**: The group that owns the file.
	- **Others (o)**: All other users.
	- **ALL (a)**: user, group, and others.

* There are two primary ways to specify the mode when using *chmod*: 
	- Symbolic mode 
	- Numeric mode.


#### Symbolic mode 
- In symbolic mode, you use letters to specify the permissions you want to add or remove.
- You can specify the permissions to add (+), remove (-), or set explicitly (=). 
Examples:
```Bash
#Add execute permission for the owner
chmod u+x filename
#Remove write permission for the group
chmod g-w filename
#Set read and write permissions for everyone
chmod a=rw filename
#make a script executable
chmod +x script.sh
```

#### Numeric mode
- In numeric mode, you specify permissions using a three-digit octal number. Each digit represents a different category of users:
	- The first digit is for the owner.
	- The second digit is for the group.
	- The third digit is for others.
- You can combine these numbers by adding them together. For example:
	- Read and write: 4 + 2 = 6
	- Read and execute: 4 + 1 = 5 
	- All permissions: 4 + 2 + 1 = 7
Examples:
```Bash
#Set permissions to read, write, and execute for the owner, and read and execute for group and others
chmod 755 filename
#Set permissions to read and write for the owner, and read for group and others
chmod 644 filename
```
#### Flag examples

| Flag                   | Meaning                                                                              | Use                                            |
| ---------------------- | ------------------------------------------------------------------------------------ | ---------------------------------------------- |
| -R                     | Apply changes recursively to all files and directories within a specified directory. | `chmod -R 755 directory_name`                  |
| --reference=<ref_file> | Set the mode of the files to the same as that of the reference file.                 | `chmod --reference=reference_file target_file` |

### \*9
- If the files are identical, `diff` will not produce any output and will return an exit status of 0. 
- If the files differ, `diff` will output the differences and return a non-zero exit status.

## Server Ubuntu installation 
[Example](/DevOps/VM_parts/installation)

## Fedora after installation setting up
[My list](/Linux/materials/fedora_start_up.md)


## SSH and TCP forwarding 
[Click](/Linux/Linux_parts/SSH_stuff.md)

## OS family
![family](big_family.png)

## Extra
### [Fedora ultimate update script](/Linux/materials/Scripts/update.sh)
### [Fedora libraries paths](/Linux/materials/libraries%20paths.txt)

## Links:
* [Practical working with Linux projects + some more theory](https://github.com/Georgiy-JO/DO_practice_projects) 
