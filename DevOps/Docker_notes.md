#  Some docker tips

## Contents
- [[#Theory|Theory]]
	- [[#Theory#Docker|Docker]]
	- [[#Theory#Dockle|Dockle]]
	- [[#Theory#Docker Compose|Docker Compose]]
- [[#Commands and flags|Commands and flags]]
- [[#Docker file|Docker file]]
- [[#Docker-compose file|Docker-compose file]]
	- [[#Docker-compose file#General Structure|General Structure]]
- [[#Links:|Links:]]

## Theory

### Docker

A container is a new "executable file" that includes all the dependencies the product needs.
The main advantage of containerisation is the isolation of dependencies and a single, simple software start-up point.

Basic terms:

- Docker image - the "package" for the application and dependencies (including system ones).
- Container - an instance of an image, i.e. a 'alive' image.

**Docker** is a platform that is designed to develop, deploy and run applications in containers.
**Docker** is the 'de-facto' standard containerisation tool in the industry, but it is not the first or last among containerisation technologies.

The forerunners of **Docker** containers were virtual machines.
A virtual machine, like a container, isolates the application and its dependencies from the outside environment.
However, **Docker** containers have advantages over virtual machines.
For example, they are very easy to port, consume fewer resources, start and run faster.

A docker image consists of layers. Each layer describes some change to be performed to the data on the running container.
The structure of links between layers is hierarchical. There is a base layer on which the other layers are "overlaid".
The *Dockerfile* is used to create an image. Each instruction in it creates a new layer.

### Dockle

**Dockle** is a container image security checking tool that can be used to find vulnerabilities.

Key features and benefits of **Dockle**:

- searches for vulnerabilities in images;
- helps in creating a proper Dockerfile;
- easy to use, you only need to specify the image name;
- support for *CIS Benchmarks*.

### Docker Compose

Docker Compose is a tool for handling tasks related to projects deployment.
Docker Compose can be helpful if several services are used to keep the project running.
Docker Compose is used to simultaneously manage multiple containers that are part of an application.
This tool offers the same features as Docker, but allows to work with more complex distributed applications, e.g. microservices.

## Commands and flags
🔴🟡🟢

| Command                                                                                                                          | Meaning                                                                                                                                                                                                              | Kind                        | Orbs |
| -------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------- | ---- |
| `sudo systemctl start docker`                                                                                                    | start docker via terminal in linux                                                                                                                                                                                   | above docker                | 🟡   |
| `docker pull <image_id\|repository>`                                                                                             | download an image from Docker Hub                                                                                                                                                                                    | docker command              | 🟡   |
| `docker images`                                                                                                                  | check for the docker image at local place                                                                                                                                                                            | docker command              | 🟡   |
| `docker rmi \<image_id\|repository>`                                                                                             | delete an image                                                                                                                                                                                                      | docker command              | 🟡   |
| `docker run \<docker_flags\|options> \<image_id\|repository> \<commands_executed_in_container> \<arguments_passed_to_container>` | run docker image (*1)                                                                                                                                                                                                | docker command              | 🟡   |
| `-d`                                                                                                                             | this flag tells Docker to run the container in detached mode, which means it will run in the background and not attach to the current terminal session                                                               | docker `run` flag           | 🟡   |
| `-p \<host_port\|container_port>`                                                                                                | setting ports for container and mapping those to the host machine                                                                                                                                                    | docker `run` flag           | 🟡   |
| `--name <container_name>`                                                                                                        | name the container you start                                                                                                                                                                                         | docker `run` flag           | 🟡   |
| `-v <local_host_directory>:<inside_container_directory>`                                                                         | this option mounts a volume - maps a directory or file from the host machine to a directory or file inside the container                                                                                             | docker `run` flag           | 🟡   |
| `docker ps`                                                                                                                      | check containers                                                                                                                                                                                                     | docker command              | 🟡   |
| `docker inspect <container_id\|container_name>`                                                                                  | get container info                                                                                                                                                                                                   | docker command              | 🟡   |
| `docker stop \<container_id\|container_name>`                                                                                    | stop the container                                                                                                                                                                                                   | docker command              | 🟡   |
| `docker restart\<container_id\|container_name>`                                                                                  | restart the container                                                                                                                                                                                                | docker command              | 🟡   |
| `docker rm <container_id\|container_name>`                                                                                       | delete the container                                                                                                                                                                                                 | docker command              | 🟡   |
| `docker exec <container_id\|container_name> \<command>`                                                                          | command is used to run a command in a running container - allows you to interact with the container's file-system and processes                                                                                      | docker command              | 🟡   |
| `-i`                                                                                                                             | start an interactive shell session inside a running Docker container (*2)                                                                                                                                            | docker `exec` flag          | 🟡   |
| `-t`                                                                                                                             | allocates a pseudo-TTY (terminal) - gives a terminal interface (useful for running interactive commands like a shell) (*2)                                                                                           | docker `exec` flag          | 🟡   |
| `docker cp <way_to_file_on_host> <container_id\|container_name>:<way_to_file_on_container>`                                      | copy a file from your local filesystem to a running Docker container                                                                                                                                                 | docker command              | 🟡   |
| `docker export <container_id\|container_name>  > <name_of_archive>.tar`                                                          | export the file system of a running or stopped Docker container to a tar archive (captures the current state of the container's file system)                                                                         | docker command              | 🟡   |
| `docker import \<archive>`                                                                                                       | import a tar archive into Docker as a new image                                                                                                                                                                      | docker command              | 🟡   |
| `dockle <image_id\|repository>`                                                                                                  | check an image with dockle for issues (security reasons)                                                                                                                                                             | dockle command              | 🟡   |
| `docker build`                                                                                                                   | command used to build a Docker image from a Dockerfile                                                                                                                                                               | docker command              | 🟡   |
| `-t`                                                                                                                             | option allows you to tag the image with a name (give the resulting image a name)                                                                                                                                     | docker `build` flag         | 🟡   |
| `docker-compose`                                                                                                                 | command-line tool for defining and running multi-container Docker applications, it uses a  *.yml* file to configure the services, networks, volumes, containers                                                      | docker-compose command      | 🟡   |
| `docker-compose build`                                                                                                           | This subcommand tells Docker Compose to build the images specified in the file (if no other instructions- `docker-compose.yml`). If the images are already built and there are no changes, it will not rebuild them. | docker-compose command      | 🟡   |
| `--no-cache`                                                                                                                     | docker-compose flag that makes it rebuild images even if they are already built and there are no changes                                                                                                             | docker-compose `build` flag | 🟡   |
| `docker-compose  up`                                                                                                             | This subcommand is used to create and start the containers defined in the file (usually `docker-compose.yml`). It will also start any linked services that are required by the main services.                        | docker-compose command      | 🟡   |
| `-d`                                                                                                                             | flag stands for "detached mode", it will start the containers in the background, allowing you to continue using the terminal without being attached to the container's output                                        | docker-compose `up` flag    | 🟡   |

#### \*1
Examples:
```Shell
#1
docker run -d nginx
#2
docker run -p 80:80 -p 443:443 -d nginx
#3
sudo docker run -d -p 80:80 -p 443:443 74c5c472c8866fa551 nginx -g "daemon off;
```

#### \*2
Example:
```Shell
sudo docker exec -it child bash
exit
```
*  **`-it`**: These are two flags combined:
    - **`-i`**: This flag stands for "interactive." It keeps the standard input (stdin) open, allowing you to interact with the shell.
    - **`-t`**: This flag allocates a pseudo-TTY (terminal). It gives you a terminal interface, which is useful for running interactive commands like a shell.
* **`child`**: This is the name (or ID) of the running Docker container in which you want to execute the command.
* **`bash`**: This is the command you want to run inside the container. In this case, it starts a Bash shell. If the container does not have Bash installed, you might use `sh` or another shell available in the container.
* **`exit`**: To exit the container terminal.

## Docker file 

The Dockerfile contains a set of instructions on how to create the image, including the base image, any files to copy, commands to run, and any environment variables to set.
- `Dockerfile` - standard docker file name.

Example 1:
```Dockerfile
FROM nginx:latest

# copy the config-file
COPY ./nginx.conf /etc/nginx/nginx.conf
  
# copy exe-file
COPY ./theApp /home/theApp

# install needed
RUN apt update && \
apt install spawn-fcgi -y && \
apt-get install libfcgi-dev -y

CMD spawn-fcgi -p 8080 /home/theApp && nginx -g "daemon off;"
```

- `FROM` - this line specifies that the base image for this Docker image.
- `COPY` - this line copies a custom the file  from the host machine (the directory where the Dockerfile is located) into the container (replacing if necessary).
- `RUN` - this line execute commands in the container during the image build process.
- `CMD` - this line specifies the command that will be executed when the container starts.

Example 2:
```Dockerfile
FROM ubuntu:24.04

# install needed
RUN apt update && \
apt install spawn-fcgi -y && \
apt-get install libfcgi-dev -y && \
apt install nginx -y && \
apt install curl -y && \
apt-get clean && \
rm -rf /var/lib/apt/lists/*

# adding user and needed rights for them (usermod -aG sudo new_user - is not safe)
RUN useradd -ms /bin/bash new_user && \
chown -R new_user:new_user /var && \
chown -R new_user:new_user /usr/bin && \
chown -R new_user:new_user /usr/sbin && \
chown -R new_user:new_user /run

# setting a user to work with
USER new_user

# copy the config-file
COPY ./nginx.conf /etc/nginx/nginx.conf

# copy exe-file
COPY ./theApp /home/theApp

# do during any container built
CMD spawn-fcgi -p 8080 /home/theApp && nginx -g "daemon off;"

# checking
HEALTHCHECK --interval=30s --timeout=30s --start-period=5s --retries=3 \
	CMD curl -f http://localhost:80 || exit 1
```
- `USER` - sets the default user for the following commands, meaning that any subsequent commands will run as this user instead of the root user.
- `HEALTHCHECK` - -  instruction defines how to check if the container is healthy. In this example:
    - It attempts to access `http://localhost:80` every 30 seconds.
    - If the request fails (i.e., returns a non-200 status), it will exit with a status of 1, indicating an unhealthy state.
    - The health check starts 5 seconds after the container starts and will retry 3 times before considering the container unhealthy.

## Docker-compose file
Docker Compose file is used to define and manage multi-container Docker applications
- `docker-compose.yml` - standard docker file name.
Example 1:
```yml
services:
#only lower case
  theserver:
	build:
	  context: .
	  dockerfile: Dockerfile
	volumes:
	  - ./nginxes/nginx-server/nginx.conf:/etc/nginx/nginx.conf
    container_name: theServer
  
  mysroxy:
    image: nginx
    ports:
      - 80:8080
    volumes:
      - ./nginxes/nginx-proxy/nginx.conf:/etc/nginx/nginx.conf
    container_name: child_6.1_proxy
```

### General Structure

- `services` - is the top-level key that defines all the services (containers) that will be created as part of this Docker Compose application.
- `build` - this section specifies how to build the Docker image for this service.
- `context` -  set the directory that Docker will look for the Dockerfile and any other files it needs in.
- `dockerfile` - specifies the name of the Dockerfile to use for building the image.
- `volumes` - this section defines a volume that maps a file from the host machine to a file in the container. In this example:
	 - The `nginx.conf` file located in the `nginxes/nginx-server` directory on the host will be mounted to `/etc/nginx/nginx.conf` inside the container. 
- `container_name` - this specifies a custom name for the container.
- `image` - this specifies the Docker image to use for this service. 
- `ports` - this section maps a port on the host machine to a port in the container. In this example:
	- Port 80 on the host will be mapped to port 8080 in the container. 
## Links:
* [Practical work with Docker](https://github.com/Georgiy-JO/DO_practice_projects) 