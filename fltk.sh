wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/fltk.h 
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/Graph.cpp
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/Graph.h
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/GUI.cpp
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/GUI.h
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/Point.h
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/sample_main3.cpp
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/Simple_window.h
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/std_lib_facilities.h
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/Window.cpp
wget http://courses.cs.tamu.edu/daugher/cpsc121/10fall/code/Window.h
g++ sample_main3.cpp Graph.cpp Window.cpp GUI.cpp -o sample_main3 -lfltk -lfltk_images 
echo finsihed the command 
echo g++ sample_main3.cpp Graph.cpp Window.cpp GUI.cpp -o sample_main3 -lfltk -lfltk_images
echo now run ./sample_main3 to start the program
