all: solution1 solution2 solution4 solution5 solution6 solution8 poj1007 poj1590 poj2538 poj3299bad 8queen

solution1:
	g++ -std=c++11 -Wall -pedantic solution1.cpp -o solution1
solution2:
	g++ -std=c++11 -Wall -pedantic solution2.cpp -o solution2
solution4:
	g++ -std=c++11 -Wall -pedantic solution4.cpp -o solution4
solution5:
	g++ -std=c++11 -Wall -pedantic solution5.cpp -o solution5
solution6:
	g++ -std=c++11 -Wall -pedantic solution6.cpp -o solution6
solution8:
	g++ -std=c++11 -Wall -pedantic solution8.cpp -o solution8
poj1007:
	g++ -std=c++11 -Wall -pedantic poj_1007_40percentAC.cpp -o poj1007
poj1590:
	g++ -std=c++11 -Wall -pedantic poj_1590_33percentAC.cpp -o poj1590
poj2538:
	g++ -std=c++11 -Wall -pedantic poj_2538_47percentAC.cpp -o poj2538
poj3299bad:
	g++ -std=c++11 -Wall -pedantic poj3299_WA.cpp -o poj3299bad
8queen:
	g++ -std=c++11 -Wall -pedantic 8queen.cpp -o 8queen
clean:
	rm solution1 solution2 solution4 solution5 solution6 solution8 poj1007 poj1590 poj2538 poj3299bad 8queen