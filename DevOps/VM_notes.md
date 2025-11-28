# Notes about virtual machines

## Providing programs
1. [Oracle VM VirtualBox](https://www.oracle.com/virtualization/technologies/vm/downloads/virtualbox-downloads.html)

## Creation of virtual machine 
[Example](/DevOps/VM_parts/installation.md)

## Creating VMs network
[Example](/DevOps/VM_parts/setting_up_VMs.md)

## Mounting 
There are several ways to bring files to a *virtual machine*, like *SCP* or setting the ability to drag and drop files. But from my point of view one of the most easiest ones is **mounting** VM's folder to host one's.

#### Steps to mount (VM: Ubuntu):
1. Open VirtualBox and select the Guest Machine you want to mount the folder on (it must be *powered off*).
2. Go to "Settings" and then "Shared Folders". Click on the "Add" button (the folder with a plus sign) to add a new shared folder.
	1. In the "Add Share" dialog box, select the "Folder Path" on the Host Machine that you want to share.
	2. Specify a "Folder Name" for the shared folder (e.g. "sharedfolder").
	3.  Check the "Auto-mount" and "Make Permanent" options.
	4. Leave the "Mount point" field blank.
	5. Click "OK" to save the shared folder settings.
3. Start the Guest Machine.
4. 
```Bash
sudo mkdir -p /<way_to_folder>/my_shared_folder
sudo mount -t vboxsf my_shared_folder /<full_way_to_folder>/my_shared_folder
```
5. You can now access the shared folder from both machines.

### Use
You can use shared folder for file exchange, for example pass pre-written script files from host machine to VM.
Folder */DevOps/materials/intercourse* is an example of this kind of folder use.

## SSHing 

How to ssh in V-machine ([source](https://www.youtube.com/watch?v=rhFLfwZzlGA))

1. Machine settings:
    1. sudo apt install openssh-server -y
    2. sudo systemctl status ssh
        1. (If not acrtive) sudo systemctl enable ssh --now
    3. [Check if SSH port is open]
        1. [Check if firewall is active] sudo ufw status
        2. (If yes) [Check that SSH port (22) is open] sudo lsof -i -P -n | grep LISTEN
        3. (If not) sudo  ufw allow ssh
        4. [Check status of the firewall] sudo ufw status verbose
2. VBox settings:
    1. In settings of the machine check that Network adapter is set to NAT
    2. [Add port forwarding] Advance -> Port forwarding
        1. Name connection; protocol - TCP; choose not taken Host port (22222); Guest port - 22.
3. Main system settings:
    1. sudo apt install openssh-client -y   (for Windows - PuTTY program can be used)
4. Connection:
    1. [At main machine] ssh -p 22222 v-machine_username@localhost

## Links:
* [SSH and TCP forwarding](/Linux/Linux_parts/SSH_stuff.md)
* [Practical work with Linux virtual machines](https://github.com/Georgiy-JO/DO_practice_projects) 
