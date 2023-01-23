make:
	g++ -o client.out -pthread -std=c++11 client/*.h client/*.cpp
	g++ -o server.out -pthread -std=c++11 server/*.h server/*.cpp
