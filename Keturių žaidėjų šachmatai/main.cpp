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

int  size = 74;
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
    RenderWindow window(VideoMode(700, 700), "4 player chess");

    bool isFullscreen = true;
    int lenght = 14;

    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25;

    t1.loadFromFile("images/Board.png");

    t2.loadFromFile("images/Pawns/PawnRed.png");
    t3.loadFromFile("images/Pawns/PawnBlue.png");
    t4.loadFromFile("images/Pawns/PawnYellow.png");
    t5.loadFromFile("images/Pawns/PawnGreen.png");

    t6.loadFromFile("images/Knights/KnightRed.png");
    t7.loadFromFile("images/Knights/KnightBlue.png");
    t8.loadFromFile("images/Knights/KnightYellow.png");
    t9.loadFromFile("images/Knights/KnightGreen.png");

    t10.loadFromFile("images/Bishops/BishopRed.png");
    t11.loadFromFile("images/Bishops/BishopBlue.png");
    t12.loadFromFile("images/Bishops/BishopYellow.png");
    t13.loadFromFile("images/Bishops/BishopGreen.png");

    t14.loadFromFile("images/Rooks/RookRed.png");
    t15.loadFromFile("images/Rooks/RookBlue.png");
    t16.loadFromFile("images/Rooks/RookYellow.png");
    t17.loadFromFile("images/Rooks/RookGreen.png");

    t18.loadFromFile("images/Queens/QueenRed.png");
    t19.loadFromFile("images/Queens/QueenBlue.png");
    t20.loadFromFile("images/Queens/QueenYellow.png");
    t21.loadFromFile("images/Queens/QueenGreen.png");

    t22.loadFromFile("images/Kings/KingRed.png");
    t23.loadFromFile("images/Kings/KingBlue.png");
    t24.loadFromFile("images/Kings/KingYellow.png");
    t25.loadFromFile("images/Kings/KingGreen.png");

    Sprite Board(t1);

    Sprite RedPawn(t2);
    Sprite BluePawn(t3);
    Sprite YellowPawn(t4);
    Sprite GreenPawn(t5);

    Sprite RedKnight(t6);
    Sprite BlueKnight(t7);
    Sprite YellowKnight(t8);
    Sprite GreenKnight(t9);

    Sprite RedBishop(t10);
    Sprite BlueBishop(t11);
    Sprite YellowBishop(t12);
    Sprite GreenBishop(t13);

    Sprite RedRook(t14);
    Sprite BlueRook(t15);
    Sprite YellowRook(t16);
    Sprite GreenRook(t17);

    Sprite RedQueen(t18);
    Sprite BlueQueen(t19);
    Sprite YellowQueen(t20);
    Sprite GreenQueen(t21);

    Sprite RedKing(t22);
    Sprite BlueKing(t23);
    Sprite YellowKing(t24);
    Sprite GreenKing(t25);

    sf::Event event;

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {

                window.close();
            }
        }
        window.clear();
        window.draw(Board);

        for (int i = 0; i < lenght; i++)
        {
            for (int j = 0; j < lenght; j++)
            {

                if (board[i][j] != 0)
                {
                    if (board[i][j] == PawnRed)
                    {
                        RedPawn.setPosition(j * size, i * size);
                        window.draw(RedPawn);
                    }

                    if (board[i][j] == PawnBlue)
                    {
                        BluePawn.setPosition(j * size, i * size);
                        window.draw(BluePawn);
                    }

                    if (board[i][j] == PawnYellow)
                    {
                        YellowPawn.setPosition(j * size, i * size);
                        window.draw(YellowPawn);
                    }

                    if (board[i][j] == PawnGreen)
                    {
                        GreenPawn.setPosition(j * size, i * size);
                        window.draw(GreenPawn);
                    }
                }
            }
        }

        window.display();
    }

    return 0;
}