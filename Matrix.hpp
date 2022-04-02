#ifndef _MATRIX
#define _MATRIX

#include <vector>  // include is here instead of in .cpp - every matrix will need this library!

namespace zich{
    class Matrix{

        public:

        Matrix(int row, int col);
        Matrix(vector<double> &vect, int row, int col);
        Matrix(const vector<vector<double>> &mat);

        ~Matrix();

        Matrix & operator + (Matrix &mat) const;
        Matrix & operator + (double scalar) const;
        Matrix & operator += (Matrix &mat) const;
        Matrix & operator += (double scalar) const;
        Matrix & operator ++ () const;  // TODO: void?

        Matrix & operator - (Matrix &mat) const;
        Matrix & operator - (double scalar) const;
        Matrix & operator -= (Matrix &mat) const;
        Matrix & operator -= (double scalar) const;
        Matrix & operator -- () const;  // TODO: void?s

        Matrix & operator * (Matrix &mat) const;
        Matrix & operator * (double scalar) const;
        Matrix & operator *= (Matrix &mat) const;
        Matrix & operator *= (double scalar) const;

        Matrix & operator < (Matrix &mat) const;
        Matrix & operator <= (Matrix &mat) const;

        Matrix & operator == (Matrix &mat) const;
        Matrix & operator != (Matrix &mat) const;

        Matrix & operator > (Matrix &mat) const;
        Matrix & operator >= (Matrix &mat) const;

        friend void operator << (istream &in, const Matrix &mat);
        friend void operator << (const Matrix &mat, istream &in);
        friend void operator >> (ostream &out, const Matrix &mat);
        friend void operator >> (const Matrix &mat, ostream &out);

        private:

        vector<vector<double>> matrix;

    };
}

#endif