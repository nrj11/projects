all:
	@echo "To make a testing executable, write a driver main() of your creation"
	@echo "Then update this makefile rule (or write your own) to compile/link it"
Audiobook.o: Audiobook.cpp Audiobook.h Book.h Date.h
	g++ -c Audiobook.cpp

Paperback.o: Paperback.cpp Paperback.h Book.h Date.h
	g++ -c Paperback.cpp

Catalog.o: Catalog.cpp Catalog.h Book.h Date.h Paperback.h Audiobook.h
	g++ -c Catalog.cpp

Book.o: Book.cpp Book.h Date.h
	g++ -c Book.cpp

Date.o: Date.cpp Date.h
	g++ -c Date.cpp

submit:
	@echo "Update your makefile by modifying the zip command (below) to use your netID"
# Update the first argument of this command to use your netID in the filename
	zip netIDp2.zip HONOR makefile Date.h Date.cpp Book.h Book.cpp Catalog.h Catalog.cpp \
		Paperback.h Paperback.cpp Audiobook.h Audiobook.cpp

clean:
	rm *.o a.out
