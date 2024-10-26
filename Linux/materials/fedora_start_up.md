# On startup (Fedora 39 -Gnome 45)
## Step by step:
### 1)  DNF Configuration
```Bash
sudo nano /etc/dnf/dnf.conf
```
* add for speed:  
	fastestmirror=True  
	max_parallel_downloads=10  
	defaultyes=True  
	keepcache=True  
	
* ref: https://dnf.readthedocs.io/en/latest/conf_ref.html

### 2) Enable RPM repository:

```Bash
sudo dnf install https://mirrors.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm https://mirrors.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm
sudo dnf groupupdate core
```
* ref. https://rpmfusion.org/Configuration

### 3) Add flatPack repository:

```Bash
flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo
```

* ref.https://flatpak.org/setup/Fedora

### 4) Install Media Codecs

```Bash
sudo dnf groupupdate multimedia --setop="install_weak_deps=False" --exclude=PackageKit-gstreamer-plugin
sudo dnf groupupdate sound-and-video
sudo dnf group upgrade --with-optional Multimedia
```
* ref. https://rpmfusion.org/Howto/Multimedia

### 5) Go do settings:

* sys settings (don't forget buttons)
* terminal settings

### 6)Install:

- Opera
- OBS studio
- Chromium
- VLC
- Zoom
- DISCORD
- Dr.Web (https://download.drweb.ru/linux/)
- Obsidian
- Rythmbox
- Oracle VM virtual box
- Amnesia/Outline
- VS code
- Libre Office
- Grub Customizer
- Docker desctop (+ docker for terminal)
- pgAdmin (+ SQL)
- Postman
- etc.

### 7) switch to "GNOME with xorg"

### 8)install: 

* gnome TWEAKS
* Extensions (green one)

### 9) ```dnf install unrar unzip python3-pip cargo p7zip ntfs-3g neofetch mpv vlc ```

### 10)Install Timeshift backup:

```bash
sudo dnf install timeshift
```

### 11)Install Preload:

```bash
sudo dnf copr enable elxreno/preload -y && sudo dnf install preload -y
```

### 12) ```sudo dnf isntall dnfdragora```   

* aka. Better repository + themes and icons 	

### 13) https://extensions.gnome.org

- CHC-E - Custom Hot Corners - Extended 
- Dash to Panel
- Pano - Clipboard Manager              (needs: sudo dnf install libgda libgda-sqlite)
- [QSTweak] Quick Setting Tweaker 
- Vitals
- Gnome 4x UI Improvements
- impatience
- ArcMenu
- blur my shell
- Caffeine
- removable Drive menu
- Vitals

### 14) Extension + Extensions + gnome TWEAKS  settings 
### 15)apps settings

### 16) Install stuff or programming:
- CHECK.h + gcovr:  
	```bash
	sudo yum install check  
	sudo yum install check-devel  
	sudo dnf install gcovr  
	```
- etc.

### 17) install stuff forterminal  
* mc
* etc.
### 18)reload

## Notes:

### Instructions:

1) https://www.youtube.com/watch?v=RrRpXs2pkzg  
2) https://www.youtube.com/watch?v=a3ePEjpg3lU  
3) https://www.youtube.com/watch?v=AimXnFPYO3w  
4) https://www.youtube.com/watch?v=TTPjZUo44-k  

### Opera video problem fix:
- read later: https://www.linuxcapable.com/install-opera-on-fedora-linux/
####  Fix
- source-->https://www.youtube.com/watch?v=zI32GSl7p3I

1) in opera opera://about
	- get: ->Chrome/119.0.0.0
1) find same version at (Here are some ways to find a compatible libffmpeg.so for Opera (you may need to extract it from a zip, tar.xz / gz / zst or deb file): 
	- https://archlinux.org/packages/community/x86_64/opera-ffmpeg-codecs/
	- https://packages.ubuntu.com/search?keywords=chromium-codecs-ffmpeg-extra
	- https://ftp.osuosl.org/pub/ubuntu/pool/universe/c/chromium-browser/
	- https://repo.herecura.eu/herecura/x86_64/
	- https://github.com/nwjs-ffmpeg-prebuilt/nwjs-ffmpeg-prebuilt/releases
	- https://onedrive.live.com/?authkey=%21AC7ddalBsUiWsUE&id=75D48EF8D3750510%21234&cid=75D48EF8D3750510
3) Download libffmpeg.so
4) 
```
cd /var/lib/flatpak/app/com.opera.Opera/x86_64/stable/c022b1eac07adf69b953b2e0125b8bff88f32d952cb95440d8999b5356491fd4/files/opera
``` 
5) sudo mkdir lib_extra
6) move libffmpeg.so to `/var/lib/flatpak/app/com.opera.Opera/x86_64/stable/c022b1eac07adf69b953b2e0125b8bff88f32d952cb95440d8999b5356491fd4/files/opera/lib_extra`