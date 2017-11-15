GCC_FLAG = -std=c++11 -O3  -Wall -pedantic
ALL_PROGRAMS = 8queen poj3299bad poj3278 01pack_v1.0 poj1007 solution6 poj1590 solution4 solution5 solution2 solution3 poj2538 solution1 solution8 poj2386 

all: $(ALL_PROGRAMS)

8queen:
	g++ $(GCC_FLAG) src/8queen.cpp -o bin/$@
poj3299bad:
	g++ $(GCC_FLAG) src/poj3299_WA.cpp -o bin/$@
poj3278:
	g++ $(GCC_FLAG) src/poj_3278_31percentAC.cpp -o bin/$@
01pack_v1.0:
	g++ $(GCC_FLAG) src/01pack_v1.0.cpp -o bin/$@
poj1007:
	g++ $(GCC_FLAG) src/poj_1007_40percentAC.cpp -o bin/$@
solution6:
	g++ $(GCC_FLAG) src/solution6.cpp -o bin/$@
poj1590:
	g++ $(GCC_FLAG) src/poj_1590_33percentAC.cpp -o bin/$@
solution4:
	g++ $(GCC_FLAG) src/solution4.cpp -o bin/$@
solution5:
	g++ $(GCC_FLAG) src/solution5.cpp -o bin/$@
solution2:
	g++ $(GCC_FLAG) src/solution2.cpp -o bin/$@
solution3:
	g++ $(GCC_FLAG) src/solution3.cpp -o bin/$@
poj2538:
	g++ $(GCC_FLAG) src/poj_2538_47percentAC.cpp -o bin/$@
solution1:
	g++ $(GCC_FLAG) src/solution1.cpp -o bin/$@
solution8:
	g++ $(GCC_FLAG) src/solution8.cpp -o bin/$@
poj2386:
	g++ $(GCC_FLAG) src/poj_2386_49percentAC.cpp -o bin/$@
clean:
	cd bin;rm $(ALL_PROGRAMS);
