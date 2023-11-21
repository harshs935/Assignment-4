test:
	g++ -c Q1_Q2.cpp
	g++ -o main1 Q1_Q2.o
	g++ -O3 -o optimized Q1_Q2.o
	./main1

	g++ -c Q3.cpp
	g++ -o main2 Q3.o
	g++ -O3 -o optimized Q3.o
	./main2

	g++ -c Q4.cpp
	g++ -o main3 Q4.o
	g++ -O3 -o optimized Q4.o
	./main3
