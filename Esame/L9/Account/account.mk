CC=g++
CFLAGS=-std=c++11
DEPS = Account.h CheckingAccount.h SavingsAccount.h
OBJ = accountTest.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

accountTest: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)