
# Makefile for f2022, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp

CC = g++ -std=c++14
CFLAGS = -I/opt/homebrew/include

LDFLAGS = -L/Users/group/vcpkg/installed/arm64-osx/lib -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl
INC	=	ecs36b_Common.h
INC_CL	=	JvTime.h Person.h Car.h Motorcycle.h Auto.h
OBJ	=	JvTime.o Person.o Car.o Motorcycle.o Auto.o

# rules.
all: 	lane3 lane2 lane1 # hw5server hw5client

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>

hw5client.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client

hw5server.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client

hw5client.o:		hw5client.cpp hw5client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5client.cpp

Record.o:		Record.cpp Record.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) Record.cpp

hw5server.o:		hw5server.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5server.cpp

Auto.o:		Auto.cpp Auto.h $(INC)
	$(CC) -c $(CFLAGS) Auto.cpp

Car.o:		Car.cpp Car.h $(INC)
	$(CC) -c $(CFLAGS) Car.cpp

Motorcycle.o:		Motorcycle.cpp Motorcycle.h $(INC)
	$(CC) -c $(CFLAGS) Motorcycle.cpp

lane3.o:		lane3.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) lane3.cpp

lane2.o:		lane2.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) lane2.cpp

lane1.o:		lane1.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) lane1.cpp

ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp

Person.o:	Person.cpp Person.h $(INC)
	$(CC) -c $(CFLAGS) Person.cpp

# Thing.o:	Thing.cpp Thing.h $(INC)
# 	$(CC) -c $(CFLAGS) Thing.cpp

lane1:	lane1.o ecs36b_JSON.o $(OBJ)
	$(CC) -o lane1 lane1.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

lane3:	 lane3.o ecs36b_JSON.o $(OBJ)
	$(CC) -o lane3 lane3.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

lane2:	 lane2.o ecs36b_JSON.o $(OBJ)
	$(CC) -o lane2 lane2.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

hw5server:	hw5server.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5server hw5server.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

hw5client:	hw5client.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5client hw5client.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o *~ core Lane1MotorFile.json Lane3MotorFile.json Lane1RiderFile.json Lane3RiderFile.json hw5client.h hw5server.h hw5client hw5server lane3 lane2 lane1


