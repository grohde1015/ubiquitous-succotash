UHH = ./Simple/
brennanb_corr.o: brennanb_corr.cpp 
	g++ -o UHH $^
brennanb_corr.o: brennanb_corr.cpp brennanb_corr.hpp
	g++ -o UHH $^
brennanb_stats.o: brennanb_stats.cpp brennanb_corr.hpp
	g++ -c $^
brennanb_stats.o: brennanb_stats.cpp brennanb_stats.hpp
	g++ -c $^
all: brennanb_corr.o
clean:
	-rm -f *.o
	-rm -f *.gch
