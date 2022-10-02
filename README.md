# About this repo:
An assignment from JigenTec.

# Dev env:
It's devloped on Ubuntu-20.04

# How to build:
0. Clone this repo and cd into it.
1. `cd src`
2. `gcc main.c tcpClient.c packetListNode.c packet.c -o ../bin/main`

# How to run:
0. Back to the root of the repo.
1. `cd bin`
2. `./main <domain name> <port> [<file name>]`  
   e.g. `./main "www.assignment.jigentec.com" 49152 "download"`
3. The download file is defaultly at `bin`, but you can change it as you want.
