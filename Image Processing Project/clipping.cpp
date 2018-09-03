
#include "clipping.h"

clipping :: clipping(Image *i,int w,int h) :Image(h,w)
	{
		 this->w=(*i).getWidth();
		 this->h=(*i).getHeight();
	}

Image* clipping :: Clipping(Image *ii)
	{
		Image *ic=new Image(h,w);
        Image *ig;
        ig=generate_image1();
        generate_image(1,-1,ig);//quadrant 1
        generate_image(-1,-1,ig);// quadrant 2
        generate_image(-1,1,ig);// quadrant 3
        generate_image(1,1,ig);// quadrant 4
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if((*ig).getPix()[i][j].getCol().getRed()==255 && (*ig).getPix()[i][j].getCol().getBlue()==255 && (*ig).getPix()[i][j].getCol().getGreen()==255)
                {
                        Color *c=new Color((ii->getPix()[i][j].getCol().getRed()),(ii)->getPix()[i][j].getCol().getGreen(),(ii)->getPix()[i][j].getCol().getBlue());
                        (*ic).getPix()[i][j].setCol(*c);
                }
                else
                {
                    Color *c=new Color(255,255,255);
                    (*ic).getPix()[i][j].setCol(*c);
                }
            }
        }
        return ic;
	}
Image* clipping :: generate_image1()
	{
        int xc,yc;
		// xc=x-cordinate of circle centre
		// yc=y-cordinate of circle centre
        Image *ig=new Image(h,w);
        //cout <<"ll" << endl;
        //cout <<w<<h<<endl;
		xc=floor(w*0.5);
		yc=floor(h*0.5);
		float r=min((float)xc*0.25,(float)yc*0.25);
      //  cout << r << endl;
      for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
        		if(check(r,j,i,xc,yc))
				{
					// fill white color
        			Color *c=new Color(255,255,255);
                    (*ig).getPix()[i][j].setCol(*c);
        		}
				else
				{

                    // fill black color
                    Color *c=new Color(0,0,0);
                    (*ig).getPix()[i][j].setCol(*c);
                }
        	}
		}
        return (ig);
	}
void clipping :: generate_image(int n,int m,Image *ii)
	{
        int xc,yc;
		// xc=x-cordinate of circle centre
		// yc=y-cordinate of circle centre
		//. (-1,1)    (1,1)
		//	(-1,-1)   (1,-1)
		xc=floor(w*0.5+n*0.25*w);
		yc=floor(h*0.5+m*0.25*h);
        float r=min((2*xc/(n+2))*0.25,(2*yc/(m+2))*0.25);
		for(int i=h*0.25*(m+1);i<(h/2)+h*0.25*(m+1);i++)
		{
			for(int j=w*0.25*(n+1);j<(w/2)+w*0.25*(n+1);j++)
			{
				if(check(r,j,i,xc,yc))
				{
					// fill white color
                    Color *c=new Color(255,255,255);
                    (*ii).getPix()[i][j].setCol(*c);
				}
			}
		}

    }
	// checking if (i,j) lies inside the circle
bool clipping :: check(float r,int i,int j,int xc,int yc)
	{
		if(r > sqrt(pow(xc-i,2)+pow(yc-j,2)))
		{
			return true;// lies inside the circle
		}
		else
		{
			return false;// lies outside the circle
		}
	}
