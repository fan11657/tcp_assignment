# About this repo:
An assignment from JigenTec.

# Dev env:
1. Ubuntu-20.04.
2. gcc 9.3.0
3. GNU Make 4.2.1

# How to build:
1. Clone this repo and cd into it.
2. Check if you have gcc installed by `gcc --version`. If it's not there, follow the steps below:  
   1. `sudo apt update`
   2. `sudo apt install build-essential`
3. Check if you have GNU Make installed by `make --version`. If it's not there, follow the steps below:  
   1. `sudo apt update`
   2. `sudo apt install make`
4. `make`

# How to run:
1. `.bin/main <domain name> <port> [<file name>]`  
   e.g. `./main "assignment.jigentec.com" 49152 "download"`
2. The download file is defaultly at the base of the repo, but you can change it as you want.
3. Use `sha256sum <file name>` to verify if checksum of the download file is `093afcce35604b2ef9119f39981073e7ccd3530b569325fc9f6b2c40925b4e6d`
