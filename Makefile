GCC_FLAG = -std=c++11 -O3  -Wall -pedantic
ALL_PROGRAMS = solution1 solution2 solution4 solution5 solution6 solution8 poj1007 poj1590 poj2538 poj2386 poj3299bad 8queen

all: $(ALL_PROGRAMS)

solution1:
	g++ $(GCC_FLAG) src/solution1.cpp -o bin/solution1
solution2:
	g++ $(GCC_FLAG) src/solution2.cpp -o bin/solution2
solution4:
	g++ $(GCC_FLAG) src/solution4.cpp -o bin/solution4
solution5:
	g++ $(GCC_FLAG) src/solution5.cpp -o bin/solution5
solution6:
	g++ $(GCC_FLAG) src/solution6.cpp -o bin/solution6
solution8:
	g++ $(GCC_FLAG) src/solution8.cpp -o bin/solution8
poj1007:
	g++ $(GCC_FLAG) src/poj_1007_40percentAC.cpp -o bin/poj1007
poj1590:
	g++ $(GCC_FLAG) src/poj_1590_33percentAC.cpp -o bin/poj1590
poj2538:
	g++ $(GCC_FLAG) src/poj_2538_47percentAC.cpp -o bin/poj2538
poj2386:
	g++ $(GCC_FLAG) src/poj_2386_49percentAC.cpp -o bin/poj2386
poj3299bad:
	g++ $(GCC_FLAG) src/poj3299_WA.cpp -o bin/poj3299bad
8queen:
	g++ $(GCC_FLAG) src/8queen.cpp -o bin/8queen
clean:
	cd bin;rm $(ALL_PROGRAMS);
