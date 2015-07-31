clear
g++ -std=c++11 ssvep.cpp -Wall -o ssvep -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread
./ssvep 50 &
./ssvep 75 &
./ssvep 100 &
./ssvep 150 &
