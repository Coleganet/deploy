#!/bin/bash 
ssh-keygen -t rsa 
apt install docker docker.io 
sudo bash -c 'echo "{\"experimental\": true}" > /etc/docker/daemon.json'
sudo systemctl restart docker

bash build.sh

$SHELL
