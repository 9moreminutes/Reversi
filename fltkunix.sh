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
g++ -o sample_main3 sample_main3.cpp Graph.cpp GUI.cpp Window.cpp -L/opt/csg/lib -lfltk -lfltk_images -lX11 -ljpeg
echo finsihed the command 
echo g++ -o sample_main3 sample_main3.cpp Graph.cpp GUI.cpp Window.cpp -L/opt/csg/lib -lfltk -lfltk_images -lX11 -ljpeg 
echo now run ./sample_main3 to start the program
