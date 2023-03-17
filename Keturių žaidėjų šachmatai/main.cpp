#include  <SFML/Graphics.hpp>
#include <iostream>

#define PawnRed 1
#define PawnBlue -1
#define PawnYellow 2
#define PawnGreen -2

#define RookRed 3
#define RookBlue -3
#define RookYellow 4
#define RookGreen -4

#define KnightRed 5
#define KnightBlue -5
#define KnightYellow 6
#define KnightGreen -6

#define BishopRed 7
#define BishopBlue -7
#define BishopYellow 8
#define BishopGreen -8

#define QueenRed 9
#define QueenBlue -9
#define QueenYellow 10
#define QueenGreen -10

#define KingRed 11
#define KingBlue -11
#define KingYellow 12
#define KingGreen -12

using namespace sf;

int board[14][14] =
{ 
   55, 55, 55,    4, 6, 8, 12, 10, 8, 6, 4,   55, 55, 55, 
   55, 55, 55,    2, 2, 2, 2, 2, 2, 2, 2,     55, 55, 55, 
   55, 55, 55,    0, 0, 0, 0, 0, 0, 0, 0,     55, 55, 55, 

    -3, -1, 0,    0, 0, 0, 0, 0, 0, 0, 0,     0, -2, -4,
    -5, -1, 0,    0, 0, 0, 0, 0, 0, 0, 0,     0, -2, -6,
    -7, -1, 0,    0, 0, 0, 0, 0, 0, 0, 0,     0, -2, -8,
    -9, -1, 0,    0, 0, 0, 0, 0, 0, 0, 0,     0, -2, -12,
-   11, -1, 0,    0, 0, 0, 0, 0, 0, 0, 0,     0, -2, -10,
    -7, -1, 0,    0, 0, 0, 0, 0, 0, 0, 0,     0, -2, -8,
    -5, -1, 0,    0, 0, 0, 0, 0, 0, 0, 0,     0, -2, -6,
    -3, -1, 0,    0, 0, 0, 0, 0, 0, 0, 0,     0, -2, -4,

   55, 55, 55,    0, 0, 0, 0, 0, 0, 0, 0,     55, 55, 55, 
   55, 55, 55,    1, 1, 1, 1, 1, 1, 1, 1,     55, 55, 55, 
   55, 55, 55,    3, 5, 7, 9, 11, 7, 5, 3,    55, 55, 55, 

};

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "4 player chess", Style::Fullscreen);

    bool isFullscreen = true;

    Texture t1, t2;
    t1.loadFromFile("images/Board.png");
    t2.loadFromFile("images/PawnRed.png");

    Sprite board(t1);

    Sprite RedPawn(t2);

    sf::Event event;

    

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            switch (event.type)
            {
            case Event::KeyReleased:
                switch (event.key.code)
                {

                case Keyboard::Escape:

                    if (isFullscreen == true)
                    {
                        window.create(VideoMode(1040, 1040), "4 player chess");

                        isFullscreen == false;
                    }
                    else
                    {
                        window.create(VideoMode(1920, 1080), "4 player chess", Style::Fullscreen);

                        isFullscreen == true;
                    }

                    break;

                case Keyboard::F:
                    if (isFullscreen == true)
                    {
                        window.create(VideoMode(1920, 1080), "4 player chess", Style::Fullscreen);

                        isFullscreen == false;
                    }
                    else
                    {
                        window.create(VideoMode(1040, 1040), "4 player chess");

                        isFullscreen == true;
                    }

                    break;
                }
            }

            if (event.type == Event::Closed) {

                window.close();
            }
        }
        window.clear();
        window.draw(board);
        window.display();
    }

    return 0;
}