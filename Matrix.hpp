#ifndef _MATRIX
#define _MATRIX

#include <vector>   // include is here instead of in .cpp - every matrix will need this library!
#include <iostream> //same
using namespace std;

namespace zich
{

    class Matrix
    {
    private:
        vector<vector<double>> matrix;
        int row;
        int col;

    public:
        Matrix();
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
        Matrix &operator++(int a) const;
        Matrix &operator++() const;

        Matrix &operator-();
        Matrix &operator-(const Matrix &mat) const;
        Matrix &operator-(const double scalar) const;
        Matrix &operator-=(const Matrix &mat) const;
        Matrix &operator-=(const double scalar) const;
        Matrix &operator--(int a) const; // a--
        Matrix &operator--() const;      //--a

        Matrix &operator*(const Matrix &mat) const;
        Matrix &operator*(const double scalar) const;
        Matrix &operator*=(const Matrix &mat) const;
        Matrix &operator*=(const double scalar) const;

        bool operator<(const Matrix &mat) const;
        bool operator<=(const Matrix &mat) const;

        bool operator==(const Matrix &mat) const;
        bool operator!=(const Matrix &mat) const;

        bool operator>(const Matrix &mat) const;
        bool operator>=(const Matrix &mat) const;

        /**
         * left all friend method implementation to .cpp files like the other methods.
         **/

        friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
        friend void operator>>(std::istream &in, const Matrix &mat);
        friend Matrix &operator*(int num, const Matrix &mat);
        friend Matrix &operator*(double num, const Matrix &mat);
        friend Matrix &operator+(int num, const Matrix &mat);

        const vector<vector<double>> get_matrix()
        {
            return this->matrix;
        }

        void set_matrix(vector<vector<double>> &mat)
        {
            (this->matrix) = mat;
        }

        int get_row() const
        {
            return row;
        }

        void Matrix::set_row(int num)
        {
            this->row = num;
        }

        int get_col() const
        {
            return col;
        }

        void set_col(int num)
        {
            this->col = num;
        }

        Matrix &add_matrices(const Matrix &mat1, const Matrix &mat2);

        Matrix &add_scalar(const Matrix &mat, double scalar);
    };
}

#endif