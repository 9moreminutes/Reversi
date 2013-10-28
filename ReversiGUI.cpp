#include <stdlib.h>
#include <iostream>
#include <FL/Fl.H>  
#include <FL/Fl_Window.H>  
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Image.H>

int board[8][8];

void but_cb( Fl_Widget* o, void*) {
	Fl_Button* b=(Fl_Button*)o;
	b->label(":)"); //redraw not necessary
	b->redraw();
}

class Tile
{
public:
	int row, col, id;
	Fl_Button* but;

	Tile(void) {}
	Tile(int x, int y, int width, int height, int r, int c, int status)
	{
		row = r;
		col = c;
		id = status;
		but = new Fl_Button(x,y,width,height,":(");
		(*but).callback(but_cb);
	}

};

void drawBoard()
{
	int i,j;
	i = j = 0;
	for (int y = 20; y < 420; y+=50)
	{
		for (int x = 20; x < 420; x+=50)
		{
			new Tile(x,y,50,50,i++,j,0);
		}
		j++;
	}
}

int main(int argc, char **argv)  
{ 
  
	Fl_Window *window = new Fl_Window(800,600);  
	Fl_Box *box = new Fl_Box(20,500,260,100,"START!");  
	box->box(FL_UP_BOX);  
	box->labelsize(36);  
	box->labelfont(FL_BOLD+FL_ITALIC);  
	box->labeltype(FL_SHADOW_LABEL);
	drawBoard();

	window->end();  
	window->show(argc, argv);  
	return Fl::run();  
}

