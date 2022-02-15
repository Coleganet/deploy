#!/bin/bash
$rootb=/root/.backup

#####Check and create the folder if not exist

mkdir [ -d /root/.backup ] || mkdir /root/.backup

####Backup Butcoin #########
mkdir [ -d /root/.backup/.butcoin ] || mkdir /root/.backup/.butcoin
cp /root/.butkoin/wallet.{dat,bak.dat} /root/.backup/.butcoin
cp /root/.butkoin/but.{conf,bak.conf} /root/.backup/.butcoin

