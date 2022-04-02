#include "Matrix.hpp"
#include <iostream>
using namespace std;
using namespace zich;

namespace zich{
    
    class Matrix{

        vector<vector<double>> matrix;

        Matrix(int row, int col){

        }

        Matrix(vector<double, allocator<double>> &vect, int row, int col){
            
        }

        Matrix(const vector<vector<double>> &mat){

        }

        ~Matrix(){

        }

        Matrix & operator () (Matrix &mat) const{

        }

        Matrix & operator+(Matrix &mat) const{ // TODO: unary plus.

        }

        Matrix & operator+=(Matrix &mat) const{

        }

        Matrix & operator - (Matrix &mat) const{ // TODO: unary minus.

        }

        Matrix & operator -= (Matrix &mat) const{

        }

        Matrix & operator * (Matrix &mat) const{

        }

        Matrix & operator *= (Matrix &mat) const{

        }

        Matrix & operator < (Matrix &mat) const{

        }

        Matrix & operator <= (Matrix &mat) const{

        }

        Matrix & operator == (Matrix &mat) const{

        }

        Matrix & operator != (Matrix &mat) const{

        }

        Matrix & operator > (Matrix &mat) const{

        }

        Matrix & operator >= (Matrix &mat) const{

        }

        Matrix & operator << (Matrix &mat) const{

        }

        Matrix & operator >>(Matrix &mat) const{

        }

        friend void operator << (istream &in, const Matrix &mat){
            //in >> mat;  // TODO
        }

        friend void operator << (const Matrix &mat, istream &in){
            //in >> mat; // TODO
        }

        friend void operator >> (ostream &out, const Matrix &mat){
            out << "TODO";
        }

        friend void operator >> (const Matrix &mat, ostream &out){
            out << "TODO";
        }


    };
}