CXXFLAGS=-Wall #-O3 -g
OBJECTS=main.o
BINARIES=pitendo

# Where our library resides. It is split between includes and the binary
# library in lib
RGB_INCDIR=RGBMatrixInclude
RGB_LIBDIR=RGBMatrixLib
RGB_LIBRARY_NAME=rgbmatrix
RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a
LDFLAGS+=-L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -lrt -lm -lpthread -lbcm2835

all : $(BINARIES)

$(RGB_LIBRARY):
	$(MAKE) -C $(RGB_LIBDIR)

pitendo : main.o SNESController.o $(RGB_LIBRARY)
	$(CXX) $(CXXFLAGS) main.o SNESController.o -o $@ $(LDFLAGS)

main.o : main.c
	$(CC) -c -o $@ $<

SNESController.o : SNESController.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(BINARIES)
	$(MAKE) -C $(RGB_LIBDIR) clean
