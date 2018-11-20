all: driver.o helper.o
	gcc driver.o helper.o

driver.o: driver.c helper.h
	gcc -c driver.c

helper.o: helper.c helper.h
	gcc -c helper.c

run:
	./a.out

clean:
	rm *.o
