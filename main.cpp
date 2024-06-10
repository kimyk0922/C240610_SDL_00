#include"SDL.h"
#include <iostream>

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

using namespace std;

SDL_Window* MyWindow;
SDL_Renderer* MyRenderer;




void Input();
void Tick();
void Render();
void Term();

int SDL_main(int argc , char* argv[])
{                                             //    SDL_Init(SDL_INIT_EVERYTHING) : 모든 것을 초기화

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)    //    초기화 할 수 없을 시 오류 메시지를 띄우는 설정.
    {  //   SDL_Quit();와 SET

        cout << "Init error" << endl;

    }

                                              //  SDL_CreateWindow("Simple GameEngine", 100, 100, 640, 480, SDL_WINDOW_OPENGL);

    SDL_Window* MyWindow = SDL_CreateWindow("Simple GameEngine", 100, 100, 640, 480, SDL_WINDOW_OPENGL);
//  SDL_DestroyWindow(MyWindow);와 SET.

    SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
//  Render에 대한 설정. (어떤 것을 띄울 것인가, 몇번째 그래픽 카드를 사용할 것인가 등)
//  SDL_DestroyRenderer(MyRenderer);와 SET.

    srand((unsigned int)(time(0)));

/*
    int R = rand() % 256;
    int G = rand() % 256;
    int B = rand() % 256;
*/                          //  이곳에 들어가면 랜덤으로 한 색상식 초기화

    bool IsRunning = true;

    SDL_Event MyEvent;

    while (IsRunning)
    {

        SDL_PollEvent(&MyEvent);

        Tick();

/*
        switch (MyEvent.type)
        {

            case SDL_QUIT:                          //  실행 된 Window 창을 끌 수 있게 설정.
                IsRunning = false;
                break;

            case SDL_MOUSEBUTTONDOWN:               //  Mouse button click을 인식 되도록 설정.
                cout << "Mouse Button Down" << endl;
                break;

        }
*/  



        Render();
/*
//       int R = rand() % 256;
//       int G = rand() % 256;
//       int B = rand() % 256;

//      이곳에 적용 시 계속 색상을 바꿔가며 초기화

        SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);     //  초기화 화면 색상 설정.
                                                            //  위의 RGB 변수로 넣어줄 시 초기화 색상이 달라짐.
        SDL_RenderClear(MyRenderer);

        //  Render
        SDL_SetRenderDrawColor(MyRenderer, R, G, B, 0);

        SDL_Rect MyRect;
        MyRect.x = rand() % 640;
        MyRect.y = rand() % 480;
        MyRect.w = rand() % 640;
        MyRect.h = rand() % 480;

        SDL_RenderFillRectF(MyRenderer, MyRect);

        SDL_RenderClear(MyRenderer , &MyRect);

        SDL_RenderPresent(MyRenderer);

 */

    }


    Term();

    return 0;
}




void Init()
{




}



void Input()
{

    SDL_PollEvent(&MyEvent);

}

void Tick()
{

    switch (MyEvent.type)
    {

    case SDL_QUIT:                          //  실행 된 Window 창을 끌 수 있게 설정.
        IsRunning = false;
        break;

    case SDL_MOUSEBUTTONDOWN:               //  Mouse button click을 인식 되도록 설정.
        cout << "Mouse Button Down" << endl;
        break;

    case SDL_KEYDOWN:                       //  keyboard로 인식 설정.
        switch (MyEvent.key.keysym.sym)
        {

        case SDLK_ESCAPE:                   //  ESC key로 종료 되도록 설정.
            IsRunning = false;
            break;

        }

    }

}


void Render()
{

  
        int R = rand() % 256;
        int G = rand() % 256;
        int B = rand() % 256;
//      이곳에 적용 시 계속 색상을 바꿔가며 초기화 


    SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);     //  초기화 화면 색상 설정.
    //  위의 RGB 변수로 넣어줄 시 초기화 색상이 달라짐.
    SDL_RenderClear(MyRenderer);

    //  Render
    SDL_SetRenderDrawColor(MyRenderer, R, G, B, 0);

    SDL_Rect MyRect;
    MyRect.x = rand() % 640;
    MyRect.y = rand() % 480;
    MyRect.w = rand() % 640;
    MyRect.h = rand() % 480;

    SDL_RenderFillRect(MyRenderer, &MyRect);        //  F가 붙으면 실수 표현

//  SDL_RenderClear(MyRenderer, &MyRect);

//  원 그리기

    SDL_SetRenderDrawColor(MyRenderer, R, G, B, 0);

    SDL_Rect MyRect;
    MyRect.x = rand() % 640;
    MyRect.y = rand() % 480;
    MyRect.w = rand() % 640;
    MyRect.h = rand() % 480;

    int X1 = 0;
    int Y1 = 0;
    int X2 = 0;
    int Y2 = 0;

    int CenterOfCircleX = rand() % 640; //  320;
    int CenterOfCircleY = rand() % 480; //  240;
    int Radius = rand() % 100 + 10;     //   30;


//    int X = 0;
//    int Y = 0;
//    int CenterOfCircleX = rand() % 320;
//    int CenterOfCircleY = rand() % 240;
//    int Radius = rand() % 110;


    for (int Size = 0; Size < Radius; ++Size)
    {

        for (int i = 0; i < 360; ++i)
        {

         //  X = SDL_sinf(3.14f * 180 * i) * Size;
         //  X = SDL_cosf(3.14f * 180 * i) * Size;

         //  SDL_RenderDrawPoint(MyRenderer, X + CenterOfCircleX, Y + CenterOfCircleY);
            
            X1 = static_cast<int> (SDL_sinf(3.14f * 180 * i) * Size);
            Y1 = static_cast<int> (SDL_sinf(3.14f * 180 * i) * Size);
            X2 = static_cast<int> (SDL_cosf(3.14f * 180 * i + 1) * Size);
            Y2 = static_cast<int> (SDL_cosf(3.14f * 180 * i + 1) * Size);

            SDL_RenderDrawLine(MyRenderer, X1 + CenterOfCircleX, Y1 + CenterOfCircleY, X2 + CenterOfCircleX, Y2 + CenterOfCircleY);
        }

    }
    SDL_RenderPresent(MyRenderer);
    
}

void Term()
{

    SDL_DestroyRenderer(MyRenderer);
    SDL_DestroyWindow(MyWindow);

    SDL_Quit();

}

