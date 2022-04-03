#ifndef _MATRIX
#define _MATRIX

#include <vector> // include is here instead of in .cpp - every matrix will need this library!
#include <iostream>
using namespace std;

namespace zich
{

    class Matrix
    {

    public:
        Matrix(int row, int col);
        Matrix(const vector<double> &vect, int row, int col);
        Matrix(const vector<vector<double>> &vect, int row, int col);
        Matrix(const Matrix &mat);

        ~Matrix();

        // Matrix & operator () (); // flexible method() example

        Matrix &operator+();
        Matrix &operator+(Matrix &mat) const;
        Matrix &operator+(double scalar) const;
        Matrix &operator+=(Matrix &mat) const;
        Matrix &operator+=(double scalar) const;
        Matrix &operator++() const; // TODO: void?

        Matrix &operator-();
        Matrix &operator-(Matrix &mat) const;
        Matrix &operator-(double scalar) const;
        Matrix &operator-=(Matrix &mat) const;
        Matrix &operator-=(double scalar) const;
        Matrix &operator--() const; // TODO: void?s

        Matrix &operator*(Matrix &mat) const;
        Matrix &operator*(double scalar) const;
        Matrix &operator*=(Matrix &mat) const;
        Matrix &operator*=(double scalar) const;

        bool operator<(Matrix &mat) const;
        bool operator<=(Matrix &mat) const;

        bool operator==(Matrix &mat) const;
        bool operator!=(Matrix &mat) const;

        bool operator>(Matrix &mat) const;
        bool operator>=(Matrix &mat) const;

        /**
         * left all friend method implementation to .cpp files like the other methods.
         **/

        friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
        friend void operator>>(std::istream &in, const Matrix &mat);
        friend Matrix &operator*(int num, const Matrix &mat);
        friend Matrix &operator*(double num, const Matrix &mat);

        vector<vector<double>> & get_matrix(){
            return this->matrix;
        }

        void set_matrix(vector<vector<double>> mat){
            this->matrix = mat;
        }

        int get_row()
        {
            return row;
        }

        void set_row(int num)
        {
            this->row = num;
        }

        int get_col()
        {
            return col;
        }

        void set_row(int num)
        {
            this->col = num;
        }

        Matrix &add_matrices(const Matrix &mat1, const Matrix &mat2);

        Matrix &add_scalar(const Matrix &mat, double scalar);

    private:
        vector<vector<double>> matrix;
        int row;
        int col;
    };
}

#endif