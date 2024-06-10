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
{                                             //    SDL_Init(SDL_INIT_EVERYTHING) : ��� ���� �ʱ�ȭ

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)    //    �ʱ�ȭ �� �� ���� �� ���� �޽����� ���� ����.
    {  //   SDL_Quit();�� SET

        cout << "Init error" << endl;

    }

                                              //  SDL_CreateWindow("Simple GameEngine", 100, 100, 640, 480, SDL_WINDOW_OPENGL);

    SDL_Window* MyWindow = SDL_CreateWindow("Simple GameEngine", 100, 100, 640, 480, SDL_WINDOW_OPENGL);
//  SDL_DestroyWindow(MyWindow);�� SET.

    SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
//  Render�� ���� ����. (� ���� ��� ���ΰ�, ���° �׷��� ī�带 ����� ���ΰ� ��)
//  SDL_DestroyRenderer(MyRenderer);�� SET.

    srand((unsigned int)(time(0)));

/*
    int R = rand() % 256;
    int G = rand() % 256;
    int B = rand() % 256;
*/                          //  �̰��� ���� �������� �� ����� �ʱ�ȭ

    bool IsRunning = true;

    SDL_Event MyEvent;

    while (IsRunning)
    {

        SDL_PollEvent(&MyEvent);

        Tick();

/*
        switch (MyEvent.type)
        {

            case SDL_QUIT:                          //  ���� �� Window â�� �� �� �ְ� ����.
                IsRunning = false;
                break;

            case SDL_MOUSEBUTTONDOWN:               //  Mouse button click�� �ν� �ǵ��� ����.
                cout << "Mouse Button Down" << endl;
                break;

        }
*/  



        Render();
/*
//       int R = rand() % 256;
//       int G = rand() % 256;
//       int B = rand() % 256;

//      �̰��� ���� �� ��� ������ �ٲ㰡�� �ʱ�ȭ

        SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);     //  �ʱ�ȭ ȭ�� ���� ����.
                                                            //  ���� RGB ������ �־��� �� �ʱ�ȭ ������ �޶���.
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

    case SDL_QUIT:                          //  ���� �� Window â�� �� �� �ְ� ����.
        IsRunning = false;
        break;

    case SDL_MOUSEBUTTONDOWN:               //  Mouse button click�� �ν� �ǵ��� ����.
        cout << "Mouse Button Down" << endl;
        break;

    case SDL_KEYDOWN:                       //  keyboard�� �ν� ����.
        switch (MyEvent.key.keysym.sym)
        {

        case SDLK_ESCAPE:                   //  ESC key�� ���� �ǵ��� ����.
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
//      �̰��� ���� �� ��� ������ �ٲ㰡�� �ʱ�ȭ 


    SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);     //  �ʱ�ȭ ȭ�� ���� ����.
    //  ���� RGB ������ �־��� �� �ʱ�ȭ ������ �޶���.
    SDL_RenderClear(MyRenderer);

    //  Render
    SDL_SetRenderDrawColor(MyRenderer, R, G, B, 0);

    SDL_Rect MyRect;
    MyRect.x = rand() % 640;
    MyRect.y = rand() % 480;
    MyRect.w = rand() % 640;
    MyRect.h = rand() % 480;

    SDL_RenderFillRect(MyRenderer, &MyRect);        //  F�� ������ �Ǽ� ǥ��

//  SDL_RenderClear(MyRenderer, &MyRect);

//  �� �׸���

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

