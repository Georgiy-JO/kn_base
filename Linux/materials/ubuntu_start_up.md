# On startup (Ubuntu 24.04)
Step by step Ubuntu settings doc.

## Step by step:
### 1. **Software and updates** app
- Set the fastest server for updates;
- Set the update period.
### 2. **Additional drivers** app
Install additional drivers if needed 
### 3. Initial update
```bash
sudo apt update && sudo apt-get update && sudo apt upgrade -y && sudo apt-get upgrade -y
```
### 4. Install preload
Make working with most used programs faster
```bash
sudo apt install preload -y
```
### 5. Install not-open source elements
A collection of common proprietary or non-open-source components that many users need.
```bash
sudo apt install ubuntu-restricted-extras -y
```
### 6. Uninstall preinstalled LibreOffice
Sometimes preinstalled version is not what you need.
```bash
sudo apt remove "libreoffice*" -y
sudo apt autoremove -y
```

### 7. Set the settings:
* System settings (don't forget buttons);
  * Go to region settings and add languages (add languages in System settings before adding layout):
        * For japanese use:```sudo apt install ibus-mozc mozc-utils-gui fonts-noto-cjk -y```, restart and in settings choose ***mozc***;
  * Go to setting and set DNS:
    - ipv4: 8.8.8.8,8.8.4.4
    - ipv6: 2001:4860:4860::8888,2001:4860:4860::8844
* Terminal settings;
* Text editor settings;
* Files setting.

### 8. Install apps: 
* gnome TWEAKS;
* Extensions (green one).

### 9. Install Gnome extensions and setup 
1. **Install** Gnome extensions from [website](https://extensions.gnome.org):
   - CHC-E - Custom Hot Corners - Extended 
   - Dash to Panel (by charlesg99)
   - Dash to Dock
   - multyple copy manager (choose one):
     1. Pano - Clipboard Manager
        - needs: 
           ```bash
           sudo apt install gir1.2-gda-5.0 gir1.2-gsound-1.0 -y  --  source: https://ubuntuhandbook.org/index.php/2022/08/clipboard-history-ubuntu-new-style/
           ```
     2. Clipboard Indicator
   - [QSTweak] Quick Setting Tweaker 
   - Vitals
   - Gnome 4x UI Improvements
   - Impatience
   - ArcMenu (by andrew_z)
   - Caffeine 
   - Removable Drive Menu
2. **Setup** extensions (use gnome TWEAKS and Extensions from [step 8](#8-install-apps)).

### 10. Firewall
- Enable firewall:
    ```bash
    sudo ufw enable
    ```
- For GUI version:
    ```bash
    sudo apt install gufw -y
    ```

### 11. Synaptic Package Manager
Installs Synaptic Package Manager on Ubuntu.
Synaptic is:
- Synaptic is a graphical package manager that lets you:
- Browse all available packages
- Install or remove software
- See dependencies
- Lock package versions
- Search and filter installed/available packages
- Manage repositories

```bash
sudo apt install synaptic -y
```

### 12. Uninstall not needed apps
```bash
    dpkg --list
	sudo apt remove <PACKAGE_NAME>
	sudo apt autoremove -y
```

### 13. Install and setup TimeShift for backups

### 14. Switch to "GNOME with xorg" (if needed)

### 15. Add more repositories
#### Flat pack
```bash
sudo apt install flatpak -y
flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo
```

### 16. Install & setup apps
- Opera
- VLC
    ```bash
    sudo apt install vlc
    ```
- OBS studio
    ```bash
    sudo apt install obs-studio -y
    ```
- Visual Studio code (VScode)
- zoom
- libreoffice 
- discord
- rythmbox
- gnome calendar
- rocketchat
- telegram
- dr.web - [link](https://download.drweb.com/linux/?lng=en)
- Obsidian
    ```bash
    flatpak install flathub md.obsidian.Obsidian
    ```
- Doxigen
  - install from [link](https://www.doxygen.nl/index.html)
  - or with: 
    ```bash
    sudo apt install doxygen && sudo apt-get install doxygen-gui
    ```
- Amnesia
  1. 
    ```bash
    sudo apt install libxcb-xinerama0
    sudo apt install libxcb-cursor0
    ```
  2. Download archive from [link](https://github.com/amnezia-vpn/amnezia-client/releases/download/4.8.2.3/AmneziaVPN_4.8.2.3_Linux_installer.tar.zip)
  3. Install it
- Hiddify
  1.  
    ```bash
    sudo apt install libfuse2 -y  #with caution
    ```
  2. Download AppImage or install deb version - [link](https://github.com/hiddify/hiddify-app/releases) 
  3. chmod it (can just run it when needed)
- pgsql (PostgreSQL) - [Link](https://www.postgresql.org/download/linux)
    ```bash
    sudo apt install postgresql -y
	sudo apt install postgresql-client -y
    ```
- Other (choose the ones you need):
    ```bash
    sudo apt install python3-pip unzip unrar cargo p7zip ntfs-3g neofetch mpv vlc check gcovr lcov openssh-client openssh-server mc htop sl sshpass valgrind cppcheck clang-format gcc g++ make cmake git gthumb rhythmbox ipcalc postgresql curl git-lfs python3.12 python3-pip python3-venv -y
    ```

### 17. Install gtest (if needed)
1. 
    ```bash
    sudo apt-get install libgtest-dev -y
    sudo apt-get install cmake -y # install cmake
    ```
2. There are 2 ways:
    ```bash
    cd /usr/src/gtest
    sudo mkdir build
    cd build
    sudo cmake ..
    sudo make
    ```
    **or** 
    ```bash
    cd /usr/src/gtest
    sudo mkdir build && cd build
    sudo cmake ..
    sudo make install
    ```
3. 
    ```bash
    cd ..
    sudo rm -fr build
    ```

### 18. Install Virtual box (if needed)
```bash
sudo apt install virtualbox
sudo apt install virtualbox-ext-pack
```
or
```
sudo sh -c 'echo "deb [arch=amd64] https://download.virtualbox.org/virtualbox/debian noble contrib" >> /etc/apt/sources.list.d/virtualbox.list'
wget -q https://www.virtualbox.org/download/oracle_vbox_2016.asc -O- | sudo tee /etc/apt/trusted.gpg.d/oracle_vbox_2016.asc
wget -q https://www.virtualbox.org/download/oracle_vbox.asc -O- | sudo tee /etc/apt/trusted.gpg.d/oracle_vbox.asc

sudo apt update
sudo apt install virtualbox-7.0
```

### 19. Install and setup grub-customizer 
```bash
sudo add-apt-repository ppa:danielrichter2007/grub-customizer 
sudo apt-get update 
sudo apt-get install grub-customizer
```

### 20. Set "shift+alt" to change layout:
```bash
gsettings set org.gnome.desktop.wm.keybindings switch-input-source "['<Alt>Shift_L', '<Alt>Shift_R', '<Shift>Alt_L', '<Shift>Alt_R', '<Super>Space']"
```

### 21. If Opera has videos issue
Make opera video player work.
1. Check chromium version and Opera installation location with ```opera://about```;
2. Download **libffmpeg.so** according to chromium version from:
    - https://gist.github.com/Thomas-Ln/c4ae803e90f9984b6612c8983c8fde1f
    - https://onedrive.live.com/?id=75D48EF8D3750510%21234&cid=75D48EF8D3750510&authkey=%21AC7ddalBsUiWsUE
3. Put in into Opera installation folder (replace if required)
4. Reload Opera


### 22. Clean the system
```bash
sudo apt install bleachbit -y
```

### 23. Set your own names for terminal commands
[Info](/Linux/Linux_notes.md#personal-names-for-linux-terminal-commands)

### 24. Programming elements (if needed)
- Install Postman - [link](https://www.postman.com/downloads/) or App center
- QT - [link](https://www.qt.io/development/download)
- pgAdmin (for postgreSQL) - *idk, try one from the App center*.

## In case internet die, try:
```bash
nmcli device
nmcli connection delete <name_of_sus_connection>
```
