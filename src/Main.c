#if defined(__linux__) && !defined(_WIN32)
    #include "/home/codeleaded/System/Static/Library/OMML.h"
    #include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#elif defined(_WIN32) || defined(_WIN64)
    #include "/home/codeleaded/System/Static/Library/OMML.h"
    #include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
    //#include "F:/home/codeleaded/System/Static/Library/OMML.h"
    //#include "F:/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#elif defined(__APPLE__)
    #error "Apple not supported!"
#else
    #error "Platform not supported!"
#endif



OMML omml;
double TimePassed;

void Setup(AlxWindow* w){
    omml = OMML_New(700,1200,"./bin");

    TimePassed = 0.0;
}
void Update(AlxWindow* w){
    TimePassed += w->ElapsedTime;
    
    //printf("TP: %lf\n",TimePassed);
    if(TimePassed > 2.0){
        OMML_Src(&omml,"./code/Main.omml");
	    OMML_Build(&omml);
        TimePassed = 0.0;
    }

    Clear(BLACK);

    RenderSprite(&omml.gc,100.0f,50.0f);
}
void Delete(AlxWindow* w){
    Png_SaveARGB("./data/Output.png",omml.gc.img,omml.gc.w,omml.gc.h);
    OMML_Free(&omml);
}
int main(){
    if(Create("Office Math Markup Language (OMML)",900,1300,1,1,Setup,Update,Delete))
       Start();
    return 0;
}