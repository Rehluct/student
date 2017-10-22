student: main.o student.o
	g++ -o hw main.o student.o

main.o: main.cpp student.h
	g++ -c main.cpp

student.o: student.cpp student.h
	g++ -c student.cpp
	
clean:
	rm *.o *.gch hw
