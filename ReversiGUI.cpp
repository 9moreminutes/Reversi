#include <stdlib.h>
#include <iostream>
#include <FL/Fl.H>  
#include <FL/Fl_Window.H>  
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include "Fl_Image_button.H"
//#include "Client.h"

int board[8][8];
//Client client;

void but_cb( Fl_Widget* o, void*) {
	Fl_Image_Button* b=(Fl_Image_Button*)o;
	switch ((*b).getcol())
	{
	case 0:
		//client.makeMove((*b).getrow(),'a');
		break;
	case 1:
		//client.makeMove((*b).getrow(),'b');
		break;
	case 2:
		//client.makeMove((*b).getrow(),'c');
		break;
	case 3:
		//client.makeMove((*b).getrow(),'d');
		break;
	case 4:
		//client.makeMove((*b).getrow(),'e');
		break;
	case 5:
		//client.makeMove((*b).getrow(),'f');
		break;
	case 6:
		//client.makeMove((*b).getrow(),'g');
		break;
	case 7:
		//client.makeMove((*b).getrow(),'h');
		break;
	}
	// Read client buffer?
	/*client.getBoard();
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = client.grid[i][j];*/
	//b->label(":)"); //redraw not necessary
	std::string s;
	switch (board[(*b).getrow()][(*b).getcol()])
	{
	case 0:
		//(*b).up_image(new Fl_JPEG_Image("Empty.jpg"));
		s = "Empty.jpg";
		break;
	case 1:
		//(*b).up_image(new Fl_JPEG_Image("White.jpg"));
		s = "White.jpg";
		break;
	case 2:
		//(*b).up_image(new Fl_JPEG_Image("Black.jpg"));
		s = "Black.jpg";
		break;
	}
	
	//(*b).up_image(new Fl_JPEG_Image(s.c_str()));
	//b->redraw();
}

void clearBoard()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = 0;
}

class Tile
{
public:
	int row, col, id;
	Fl_Image_Button* but;

	Tile(void) {}
	Tile(int x, int y, int width, int height, int r, int c)
	{
		row = r;
		col = c;
		id = board[r][c];
		but = new Fl_Image_Button(x,y,width,height,row,col,":(");
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
			new Tile(x,y,50,50,i++,j);
		}
		j++;
	}
}

int main(int argc, char **argv)  
{ 
	clearBoard();
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

