#include<iostream>
#include<math.h>
using namespace std;

class ColourChanging{
    public:
    double red;
    double blue;
    double green;
    void getHSB();
};

void ColourChanging :: getHSB(){
    red = red / 255;
    blue = blue / 255;
    green = green / 255;

    double cmax = max(red, max(blue, green));
    double cmin = min(red, min(blue, green));
    double diff = cmax - cmin;
    double h = -1, s = -1;

    #if defined()
    
    
    
    #endif // 
    
}

void ColorChecking(double red, double blue, double green){
    red = red / 255;
    blue = blue / 255;
    green = green / 255;

    double cmax = max(red, max(green, blue));
    double cmin = min(red, min(blue, green));
    double diff = cmax - cmin;
    double h = -1, s = -1;

    if(cmax == cmin){
        h = 0;
    }
    else if(cmax == red){
        h = fmod(60 * ((green - blue) / diff) + 360, 360);
    }
    else if(cmax == green){
        h = fmod(60 * ((blue - red) / diff) + 360, 360);
    }
    else if(cmax == blue){
        h = fmod(60 * ((red - green) /diff)+ 360, 360);
    }
    else if(cmax == 0){
        s= 0 ;

    }
    else{
        s = ((diff / cmax)*100 );
    }
    double v=  cmax *100 ;
    cout<< "("<<h<<","<<s<<","<<v<<")"<<endl;

}

int main() {
    ColorChecking(100, 150 , 200);
    return 0;
}