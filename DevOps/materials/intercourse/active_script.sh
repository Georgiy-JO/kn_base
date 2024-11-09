#!/bin/bash
# The ultimate script for CI/CD projects
VAR_1=$2
VAR_URL_GITLAB="<GitLab_repository_URL>"
VAR_TOKEN_GITLAB="<GitLab_connection_tocken>"
VAR_URL_GITHUB="<GitHub_repository_URL>"
VAR_TOKEN_GITHUB="<GitHub_connection_tocken>"
VAR_USR="cave_j"  # 5th church

if [ $1 = "-h" ] || [ $1 = "0" ]; then
  echo "
                                          ###########*## #########                                      
                                    ####*##***********######*****##*####                                
                                ####******************#######***********####                            
                            ####**********************########**************####                        
                        ###**************************####**###****************####                     
                      ###****************************####**####******************###                   
                     ###******************************####****##********************###                 
                    ######*#*************************####*****###********************###               
                 ####  ##*##########******************####*******###*********************##             
                ##***##  ###****##########*#**********####********##******************###  #            
              #*******### ###**********############***####********####**************###  ###*#          
             ##*********### ###**************##*####### ####********###************### #####*##         
            ##***********###  #************#####            #####***####**********## #######**##        
          ##****************##  ##****#####                      ########******### ##***###*****##      
         ###*****************### ######*########           ###############***### ###***###******###     
        ###********************### ######    ######      ######    #### ###*## ###*****###*******###    
       #***********************##  *#*#         ####  ####         ####  ## ###******##***********#    
      #*********************###    ###            ######            ###    ##*******###************#   
     ##*****************######     ###            ######            ###     ##******###************##  
    ###***************####**#      ###          #### ####           ###      ##****####************### 
    ##*************#####**##       ####        ####    ####        ####       ##****#***************## 
    #************#####***##         ###  ######**#########*######  ###         #***###***************# 
    ##*********#####******##       #########*############################        ####******************#
    ##******######*******##     #########   *###            ###    ##*###*##     #####****************##
    #***#######*********###  #####    ###   ###              ###   ###    ###### ####******************#
    #*######************## ####        ####*##      ####      #######        #### ##*******************#
    #*###***************#####           #####     ###***##     #####           #####*******************#
                        ###             ####     ##******##     ####            ###                     
    #########################           #####     ###**###     #####           #########################
    #*******************#######        #######      ####      #######        ######*************######*#
    #*******************### ######    #### ####              *### ####    ###### ###**********######***#
    ##*****************####    ##########   ##*#            ####   ##########    ##*******######******##
    ##*****************#####       ########*########*#######*############        ##*****######********##
    #****************###*##         ### ########################## ###         #****#######**********# 
    ##***************###**##       ####        #*##    ####        ####       ##**#####*************## 
    ###*************###*****#      ###          ####  ####          ###      #*####****************### 
     ##**************##*****##     ###            ######            ###     #####******************##  
      #*************##*******##*   ###            ######            *##    ####********************#   
       #***********####********##  ####         ####  ####         ####    ##*********************#    
        ###**********##*******### ## ####     #####      #####     #### #### ###*****************###    
         ###********###******## #################          #######*#####***### ###**************###     
          ##********##*****## ###***#########                  ######*******###  ##*************##      
            ##*****##***###  ##*******####*####              ####**************##  ##*********##        
             ##****##**##  #***********####*****####### ############************##* ###******##         
              ##**#####  ###************####**********####****#############*******### ##****##          
                ###### ###***************####*********####**********##############**### ####            
                 ##  ###*******************####*******####*********************#########  #             
                    ##**********************####******####****************************###               
                     ###*********************####*****####**************************###                 
                      ###*********************###****####************************###                   
                        ####********************##***####*********************####                     
                            ####*****************####*####******************####                        
                              #*###**************########**************###*#                           
                                    #######*********######*******##*####                                
                                          ############# ##########                
" 
  sleep 2
  echo "
                           █████╗ ██████╗ ███████╗██████╗ ████████╗██╗   ██╗██████╗ ███████╗
                          ██╔══██╗██╔══██╗██╔════╝██╔══██╗╚══██╔══╝██║   ██║██╔══██╗██╔════╝
                          ███████║██████╔╝█████╗  ██████╔╝   ██║   ██║   ██║██████╔╝█████╗  
                          ██╔══██║██╔═══╝ ██╔══╝  ██╔══██╗   ██║   ██║   ██║██╔══██╗██╔══╝  
                          ██║  ██║██║     ███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║███████╗
                          ╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝
                                                                        
                              ███████╗ ██████╗██╗███████╗███╗   ██╗ ██████╗███████╗             
                              ██╔════╝██╔════╝██║██╔════╝████╗  ██║██╔════╝██╔════╝             
                              ███████╗██║     ██║█████╗  ██╔██╗ ██║██║     █████╗               
                              ╚════██║██║     ██║██╔══╝  ██║╚██╗██║██║     ██╔══╝               
                              ███████║╚██████╗██║███████╗██║ ╚████║╚██████╗███████╗             
                              ╚══════╝ ╚═════╝╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝     
"  
  sleep 2          
  echo "Welcome onto the system, human!"
  echo "  Here is the list of commands that this script provides:
        -h,0  --  help;
        1     --  first start installation;
        2     --  download and install [gitlab-runner];
        3     --  start and set up [gitlab-runner] ;
                  (don't forget to update token if it is necessary);
        4     --  check [gitlab-runner] status;
        5     --  download and unpack [github actions];
        6     --  set up [github actions] 
                  (don't forget to update token and url if it is necessary);
        7     --  start the [github actions];
        8     --  install Docker;
        9     --  check that docker works properly;
        10    --  configuring the shell to run docker by gitlab-runner (DANGEROUS); 
        11    --  install needed for C (compiling, checking and report);
        12    --  remove adjustments from #9;
        13    --  remove configuration of [github actions] to reconfigure;
        -1    --  installing sertain version of clang-format 
                  (conficure in the script);
        "
# 1-------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '1' ]; then
  sudo apt update && sudo apt upgrade -y
  sudo apt-get update && sudo apt-get upgrade -y
  sudo apt install openssh-server openssh-client mc htop sshpass -y
  if [ $? -eq 0 ]; then
    echo "installed: ssh, scp, mc, htop, sshpass;" >> log.txt
  else 
    echo "installation failed: ssh, scp, mc, htop, sshpass;" >> log.txt
  fi
# 2-------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '2' ]; then
  curl -L "https://packages.gitlab.com/install/repositories/runner/gitlab-runner/script.deb.sh" | sudo bash
  sudo apt-get update
  sudo apt-get install gitlab-runner -y
  if [ $? -eq 0 ]; then
    echo "installed: gitlab-runner;" >> log.txt
  else 
    echo "installation failed: gitlab-runner;" >> log.txt
  fi
# 8-------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '8' ]; then 
  # Add Docker's official GPG key:
  sudo apt-get update
  sudo apt-get install ca-certificates curl -y
  sudo install -m 0755 -d /etc/apt/keyrings -y
  sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
  sudo chmod a+r /etc/apt/keyrings/docker.asc
  # Add the repository to Apt sources:
  echo \
	"deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
  	$(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
  	sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
  sudo apt-get update
  sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin -y
  sudo systemctl start docker
# 4-------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '4' ]; then 
  sudo gitlab-runner status
  sudo gitlab-runner verify
# 9-------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '9' ]; then
  sudo systemctl status docker
  sudo docker run hello-world
  sudo docker rmi hello-world -f
# 11------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '11' ]; then
  sudo apt update && sudo apt-get update
  sudo apt install valgrind cppcheck clang-format gcc git-all make -y
  if [ $? -eq 0 ]; then
    echo "installed: valgrind, cppcheck, clang-format, gcc, make, git;" >> log.txt
  else 
    echo "installation failed: valgrind, cppcheck, clang-format, gcc, make, git;" >> log.txt
  fi
  sudo apt-get install check gcovr -y
  if [ $? -eq 0 ]; then
    echo "installed: check, gcovr;" >> log.txt
  else 
    echo "installation failed: check, gcovr;" >> log.txt
  fi
  sudo apt-get install gcov -y
  if [ $? -eq 0 ]; then
    echo "installed:  gcov;" >> log.txt
  else 
    echo "installation failed:  gcov;" >> log.txt
  fi
# 10------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '10' ]; then
  echo "To let gitlab-runner work with docker we will need to add it to the docker group. That is not too secure (basically we are giving gitlab-runner SUDO access)!"
  sleep 5
  sudo usermod -aG docker gitlab-runner
  sudo service docker restart
# 12------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '12' ];then
  sudo gpasswd -d gitlab-runner docker
  sudo service docker restart
# 3-------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '3' ]; then
  sudo gitlab-runner start
  sudo gitlab-runner register \
	--non-interactive \
	--url $VAR_URL_GITLAB \
	--registration-token $VAR_TOKEN_GITLAB\
	--executor "shell" \
	--description "CICD"
# 5-------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '5' ]; then
  mkdir actions-runner && cd actions-runner
  # Download the latest runner package
  curl -o actions-runner-linux-x64-2.320.0.tar.gz -L https://github.com/actions/runner/releases/download/v2.320.0/actions-runner-linux-x64-2.320.0.tar.gz
# # Optional: Validate the hash
# echo "93ac1b7ce743ee85b5d386f5c1787385ef07b3d7c728ff66ce0d3813d5f46900  actions-runner-linux-x64-2.320.0.tar.gz" | shasum -a 256 -c
  # Extract the installer
  tar xzf ./actions-runner-linux-x64-2.320.0.tar.gz
# 6-------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '6' ]; then
  # Create the runner and start the configuration
  cd actions-runner
  ./config.sh --url $VAR_URL_GITHUB --token $VAR_TOKEN_GITHUB
# 7-------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '7' ]; then  
  cd actions-runner
  # run it [github actions]
  ./run.sh
# 12------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '13' ]; then 
  cd actions-runner
  rm -fr .runner
  ./config.sh remove
# -1------------------------------------------------------------------------------------------------------------------------------------
elif [ $1 = '-1' ]; then
  wget https://apt.llvm.org/llvm.sh
  chmod +x llvm.sh
  sudo ./llvm.sh 17
  sudo apt install clang-format-17
fi
