make:
	g++ -0 client.out -std=c++11 project/client/*.h project/client/*.cpp
	g++ -0 server.out -std=c++11 project/server/*.h project/server/*.cpp
