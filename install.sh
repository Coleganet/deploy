#!/bin/bash 
apt install docker docker.io sudo ncdu
sudo bash -c 'echo "{\"experimental\": true}" > /etc/docker/daemon.json'
sudo systemctl restart docker
sudo apt install curl
output "installing the latest docker-compose"
apt-get remove docker-compose && sudo rm /usr/local/bin/docker-compose
sudo curl -L "https://github.com/docker/compose/releases/download/1.29.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
bash version
$SHELL
