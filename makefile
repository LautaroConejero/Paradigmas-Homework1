local:
	g++ -g -std=c++17 -Wall -Wconversion -Wno-sign-conversion -Werror -Wl,--wrap=malloc -o main main.cpp Ej_1/matrices.cpp
    
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
    
	rm main