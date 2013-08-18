default: 
	g++ *.cpp -g -lsfml-system -lsfml-window -lsfml-graphics -lBox2D -llua -ldl -lm -o LLGE
	./LLGE

run:
	./LLGE	

lua:
	luac -o testc.lua test.lua
