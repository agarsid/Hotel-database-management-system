clean:
	rm main main.o hotel.o hoteldetails.o run.o
tar:
	tar -czvf main.tgz *.cpp *.h
hoteldetails.o:hoteldetails.cpp hoteldetails.h run.h
	g++ -c $<
hotel.o:hotel.cpp hotel.h hoteldetails.h run.h
	g++ -c $<
run.o:run.cpp hotel.h hoteldetails.h run.h
	g++ -c $<
main:run.o hoteldetails.o hotel.o
	g++ $^ -o $@
.PHONY:clean tar

