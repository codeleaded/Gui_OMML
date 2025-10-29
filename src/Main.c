#if defined(__linux__) && !defined(_WIN32)
    #include "/home/codeleaded/System/Static/Library/OMML.h"
    //#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#elif defined(_WIN32) || defined(_WIN64)
    #include "/home/codeleaded/System/Static/Library/OMML.h"
    //#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
    //#include "F:/home/codeleaded/System/Static/Library/OMML.h"
    //#include "F:/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#elif defined(__APPLE__)
    #error "Apple not supported!"
#else
    #error "Platform not supported!"
#endif

// OMML omml;
// void Setup(AlxWindow* w){
//     omml = OMML_New((Rect){ 10.0f,10.0f,500.0f,1000.0f });
// 	OMML_File(&omml,"./data/Text.omml");
// }
// void Update(AlxWindow* w){
//     Clear(BLACK);
// }
// void Delete(AlxWindow* w){
//     OMML_Free(&omml);
// }
// int main(){
//     if(Create("Office Math Markup Language (OMML)",2500,1300,1,1,Setup,Update,Delete))
//         Start();
//     return 0;
// }

int main(){
    OMML omml = OMML_New("./code/Main.omml","./bin");
	OMML_Build(&omml);
	OMML_Free(&omml);
    return 0;
}