#include "Color.h"
#include "Pixel.h"
#include "Image.h"

Image* composite(float Alpha,Image *i1,Image *i2)
{
    Image *img=new Image(i1->getHeight(),i1->getWidth());
    for(int i=0;i<(i1)->getHeight();i++)
    {
        for(int j=0;j<(i1)->getWidth();j++)
        {
            Color c1=(i1)->getPix()[i][j].getCol();
            Color c2=(i2)->getPix()[i][j].getCol();
            int r,g,b;
            r=(((1-Alpha)*c1.getRed())+(Alpha*c2.getRed()));
            g= (((1-Alpha)*c1.getGreen())+(Alpha*c2.getGreen()));
            b= (((1-Alpha)*c1.getBlue())+(Alpha*c2.getBlue()));
            Color new_c(r,g,b);
            (img)->getPix()[i][j].setCol(new_c);
        }
    }
    // cout<<*img;
    return img;
}
Image* reflection( Image* ii)
{
    int h=(*ii).getHeight();
    int w=(*ii).getWidth();
    Image *ir=new Image(h,w);
    // cout<<h<<endl;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            // cout<<j<<endl;
            Color *c=new Color(ii->getPix()[i][j].getCol().getRed(),(ii)->getPix()[i][j].getCol().getGreen(),(ii)->getPix()[i][j].getCol().getBlue());
            (*ir).getPix()[i][w-1-j].setCol(*c);
            // cout<<ir->getPix()[i][w-j-1].getCol()<<endl;
            // cout << i <<" "<< j << endl;
            // cout << i << " "<< w-1-j << endl << endl;
        }
    }
    // cout<<ir;
    return ir;
}
