#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h" 
/*if you " " instead of <> then the compiler searches for the header file in
   current dictionary first, if it's not found, it searches in the system 
   included directories.
*/
using namespace std;

/*
 A base class for all Rubiks Cube Model. There are various representations for Rubiks Cube.
 Each one has it's own special ways of definitions
 This class provides a shared functionlity between all models
 we'll benchmark all models observe which one is better for performance.
*/
 
class RubiksCube{

 public:
       enum class FACE{
          UP,
          LEFT,
          FRONT,
          RIGHT,
          BACK,
          DOWN
       };
       enum class COLOR {
          WHITE,
          GREEN,
          RED,
          BLUE,
          ORANGE,
          YELLOW
       };
       enum class MOVE {
          L, LPRIME, L2,
          R, RPRIME, R2,
          U, UPRIME, U2,
          D, DPRIME, D2,
          F, FPRIME, F2,
          B, BPRIME, B2
       };


       /*
       Returns the color of the cell at(row,col) in face.
       If Rubik's Cube face is pointing at you, then the row numbering starts from 
       Top to Bottom and column numbering starts from left to right.
       The rows and colums are 0-indexed.
       @param face, row, and column index
       */  
      virtual COLOR getColor(FACE face, unsigned row, unsigned col) const =0;
      

      /*
      Returns the first letter of the given COLOR
      eg: for COLOR::GREEN , it returns 'G'
      */
     static char getColorLetter(COLOR color);


     /*  
     Returns true if  Rubik Cube is solved, otherwise return false
     */
     virtual bool  isSolved() const =0;

     /*
     Return the move in the string format.
     */
    static string getMove(MOVE ind);

    /*
     * Print the RUbik Cube in Planar Format.
     * 
     * The cube is laid out as folows
     * 
     * The sides:
     *    U
     *  L F R B
     *    D
     * 
     * Color wise:
     * 
     *        W W W
     *        W W W
     *        W W W 
     * 
     * G G G  R R R  B B B  O O O
     * G G G  R R R  B B B  O O O
     * G G G  R R R  B B B  O O O 
     * 
     *        Y Y Y
     *        Y Y Y 
     *        Y Y Y
     * 
     * row and column numberings:
     * rx-> row numbering
     * cx-> column numbering
     * bx-> both row and column numbering
     *   
     *            b0 c1 c2
     *            r1  .  .
     *            r2  .  .
     * 
     * b0 c1 c2   b0 c1 c2   b0 c1 c2    b0 c1 c2
     * r1  .  .   r1  .  .   r1  .  .    r1  .  .
     * r2  .  .   r2  .  .   r2  .  .    r2  .  .
     *    
     *            b0 c1 c2
     *            r1  .  .
     *            r2  .  .
    */
    void print() const;

    /*
    * Randomly shuffle the cube with 'times' moves and returns the moves performed.
    */
   vector<MOVE> randomShuffleCube(unsigned int times);

   /*
    Perform moves on the rubik cube
   */
   RubiksCube &move(MOVE ind);

   /*
    Invert a move
   */
   RubiksCube &invert(MOVE ind);

   /*
      Rotational moves on the rubik cubes
    *
    *  F, F', F2,
    *  U, U', U2,
    *  L, L', L2,
    *  D, D', D2,
    *  R, R', R2,
    *  B, B', B2
    * 
   */
    virtual RubiksCube &f()=0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;

    string getCornerColorString (uint8_t ind) const;
    uint8_t getCornerIndex(uint8_t ind) const;
    uint8_t getCornerOrientation(uint8_t ind) const;

};


#endif //RUBIKS_CUBE__SOLVER_RUBIKSCUBE_H