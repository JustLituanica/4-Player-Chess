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

struct poz
{
    int x, y;
};

int  size = 65, x = 0, y = 0;
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

int Move = 0; // 0 raudoni, 1 melyni, 2 geltoni, 3 zali

int main()
{
    RenderWindow window(VideoMode(910, 910), "4 player chess");

    bool isFullscreen = true;
    int lenght = 14;

    Texture brd; //lentos textura (board)
    Texture p1, p2, p3, p4; //pestininko textura (pawn)
    Texture k1, k2, k3, k4; //arklio textura (knight)
    Texture b1, b2, b3, b4; //rikio textura (bishop)
    Texture r1, r2, r3, r4; //boksto textura (rook)
    Texture q1, q2, q3, q4; //karalienes textura (queen)
    Texture king1, king2, king3, king4; //karaliaus textura

    brd.loadFromFile("images/Board.png");

    p1.loadFromFile("images/Pawns/PawnRed.png");
    p2.loadFromFile("images/Pawns/PawnBlue.png");
    p3.loadFromFile("images/Pawns/PawnYellow.png");
    p4.loadFromFile("images/Pawns/PawnGreen.png");

    k1.loadFromFile("images/Knights/KnightRed.png");
    k2.loadFromFile("images/Knights/KnightBlue.png");
    k3.loadFromFile("images/Knights/KnightYellow.png");
    k4.loadFromFile("images/Knights/KnightGreen.png");

    b1.loadFromFile("images/Bishops/BishopRed.png");
    b2.loadFromFile("images/Bishops/BishopBlue.png");
    b3.loadFromFile("images/Bishops/BishopYellow.png");
    b4.loadFromFile("images/Bishops/BishopGreen.png");

    r1.loadFromFile("images/Rooks/RookRed.png");
    r2.loadFromFile("images/Rooks/RookBlue.png");
    r3.loadFromFile("images/Rooks/RookYellow.png");
    r4.loadFromFile("images/Rooks/RookGreen.png");

    q1.loadFromFile("images/Queens/QueenRed.png");
    q2.loadFromFile("images/Queens/QueenBlue.png");
    q3.loadFromFile("images/Queens/QueenYellow.png");
    q4.loadFromFile("images/Queens/QueenGreen.png");

    king1.loadFromFile("images/Kings/KingRed.png");
    king2.loadFromFile("images/Kings/KingBlue.png");
    king3.loadFromFile("images/Kings/KingYellow.png");
    king4.loadFromFile("images/Kings/KingGreen.png");

    Sprite Board(brd);

    Sprite RedPawn(p1);
    Sprite BluePawn(p2);
    Sprite YellowPawn(p3);
    Sprite GreenPawn(p4);

    Sprite RedKnight(k1);
    Sprite BlueKnight(k2);
    Sprite YellowKnight(k3);
    Sprite GreenKnight(k4);

    Sprite RedBishop(b1);
    Sprite BlueBishop(b2);
    Sprite YellowBishop(b3);
    Sprite GreenBishop(b4);

    Sprite RedRook(r1);
    Sprite BlueRook(r2);
    Sprite YellowRook(r3);
    Sprite GreenRook(r4);

    Sprite RedQueen(q1);
    Sprite BlueQueen(q2);
    Sprite YellowQueen(q3);
    Sprite GreenQueen(q4);

    Sprite RedKing(king1);
    Sprite BlueKing(king2);
    Sprite YellowKing(king3);
    Sprite GreenKing(king4);

    float dx = 0, dy = 0;
    int PieceMoved = 0;

    while (window.isOpen()) {

        Vector2i pos = Mouse::getPosition(window);
        x = pos.x / size;
        y = pos.y / size;

        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {

                window.close();
            }
        }
        window.clear();

        if (event.type == Event::MouseButtonPressed)
        {
            std::cout << "x=" << x << " y=" << y << "\n";
            std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
            std::cout << "board[y][x]=" << board[y][x] << "\n";
            std::cout << "\n";
        }

        if (event.type == Event::MouseButtonReleased)
        {
            if (event.key.code == Mouse::Left)
            {

            }
        }

        //=========== Vaizdas ============
        window.clear();
        window.draw(Board);

        for (int i = 0; i < lenght; i++)
        {
            for (int j = 0; j < lenght; j++)
            {

                if (board[i][j] != 0)
                {
                    //====== Pestiinkai lentoje =====================
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
                    //===============================================

                    //========= Arkliai lentoje =====================
                    if (board[i][j] == KnightRed)
                    {
                        RedKnight.setPosition(j * size, i * size);
                        window.draw(RedKnight);
                    }

                    if (board[i][j] == KnightBlue)
                    {
                        BlueKnight.setPosition(j * size, i * size);
                        window.draw(BlueKnight);
                    }

                    if (board[i][j] == KnightYellow)
                    {
                        YellowKnight.setPosition(j * size, i * size);
                        window.draw(YellowKnight);
                    }

                    if (board[i][j] == KnightGreen)
                    {
                        GreenKnight.setPosition(j * size, i * size);
                        window.draw(GreenKnight);
                    }
                    //===============================================

                    //========== Rikiai lentoje =====================
                    if (board[i][j] == BishopRed)
                    {
                        RedBishop.setPosition(j * size, i * size);
                        window.draw(RedBishop);
                    }

                    if (board[i][j] == BishopBlue)
                    {
                        BlueBishop.setPosition(j * size, i * size);
                        window.draw(BlueBishop);
                    }

                    if (board[i][j] == BishopYellow)
                    {
                        YellowBishop.setPosition(j * size, i * size);
                        window.draw(YellowBishop);
                    }

                    if (board[i][j] == BishopGreen)
                    {
                        GreenBishop.setPosition(j * size, i * size);
                        window.draw(GreenBishop);
                    }

                    //===============================================

                    //========== Bokstai lentoje ====================
                    if (board[i][j] == RookRed)
                    {
                        RedRook.setPosition(j * size, i * size);
                        window.draw(RedRook);
                    }

                    if (board[i][j] == RookBlue)
                    {
                        BlueRook.setPosition(j * size, i * size);
                        window.draw(BlueRook);
                    }

                    if (board[i][j] == RookYellow)
                    {
                        YellowRook.setPosition(j * size, i * size);
                        window.draw(YellowRook);
                    }

                    if (board[i][j] == RookGreen)
                    {
                        GreenRook.setPosition(j * size, i * size);
                        window.draw(GreenRook);
                    }

                    //===============================================

                    //========= Karalienes lentoje ==================
                    if (board[i][j] == QueenRed)
                    {
                        RedQueen.setPosition(j * size, i * size);
                        window.draw(RedQueen);
                    }

                    if (board[i][j] == QueenBlue)
                    {
                        BlueQueen.setPosition(j * size, i * size);
                        window.draw(BlueQueen);
                    }

                    if (board[i][j] == QueenYellow)
                    {
                        YellowQueen.setPosition(j * size, i * size);
                        window.draw(YellowQueen);
                    }

                    if (board[i][j] == QueenGreen)
                    {
                        GreenQueen.setPosition(j * size, i * size);
                        window.draw(GreenQueen);
                    }

                    //===============================================

                    //========== Karaliai lentoje ===================
                    if (board[i][j] == KingRed)
                    {
                        RedKing.setPosition(j * size, i * size);
                        window.draw(RedKing);
                    }

                    if (board[i][j] == KingBlue)
                    {
                        BlueKing.setPosition(j * size, i * size);
                        window.draw(BlueKing);
                    }

                    if (board[i][j] == KingYellow)
                    {
                        YellowKing.setPosition(j * size, i * size);
                        window.draw(YellowKing);
                    }

                    if (board[i][j] == KingGreen)
                    {
                        GreenKing.setPosition(j * size, i * size);
                        window.draw(GreenKing);
                    }

                    //===============================================
                }
            }
        }

        window.display();
    }

    return 0;
}