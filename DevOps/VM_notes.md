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
Folder /DevOps/VM_parts/intercourse is an example of this kind of folder use.

## Links:
* [SSH and TCP forwarding](/Linux/Linux_parts/SSH_stuff.md)
* [Practical work with Linux virtual machines](https://github.com/Georgiy-JO/DO_practice_projects) 
