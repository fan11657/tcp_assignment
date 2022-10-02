# About this repo:
An assignment from JigenTec.

# Dev env:
0. It's devloped on Ubuntu-20.04.
1. It's devloped with gcc 9.3.0

# How to build:
1. Clone this repo and cd into it.
2. `cd src`
3. Check if you have gcc installed by `gcc --version`. If it's not there, follow the steps below:  
   1. `sudo apt update`
   2. `sudo apt install build-essential`
4. `gcc main.c tcpClient.c packetListNode.c packet.c -o ../bin/main`

# How to run:
1. Back to the root of the repo.
2. `cd bin`
3. `./main <domain name> <port> [<file name>]`  
   e.g. `./main "www.assignment.jigentec.com" 49152 "download"`
4. The download file is defaultly at `bin`, but you can change it as you want.
5. Use `sha256sum <file name>` to verify if checksum of the download file is `093afcce35604b2ef9119f39981073e7ccd3530b569325fc9f6b2c40925b4e6d`
