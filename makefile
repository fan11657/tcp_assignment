all: main
main: main.o tcpClient.o packetListNode.o packet.o
	gcc bin/main.o bin/tcpClient.o bin/packetListNode.o bin/packet.o -o bin/main
main.o: src/main.c
	gcc -c src/main.c -o bin/main.o
tcpClient.o: src/tcpClient.c
	gcc -c src/tcpClient.c -o bin/tcpClient.o
packetListNode.o: src/packetListNode.c
	gcc -c src/packetListNode.c -o bin/packetListNode.o
packet.o: src/packet.c
	gcc -c src/packet.c -o bin/packet.o
clean:
	rm bin/*.o bin/main