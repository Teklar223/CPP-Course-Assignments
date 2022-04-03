#include "Matrix.hpp"
using namespace zich;
using zich::Matrix;

namespace zich
{

    Matrix::Matrix(int row, int col) // emty constructor fills all with 0
    {
        // https://stackoverflow.com/questions/65311502/how-to-initialize-vector-of-a-vector-with-custom-values
        vector<vector<double>> vec((unsigned long)row, vector<double>((unsigned long)col, 0));
        this->matrix = vec;
    }

    Matrix::Matrix(const vector<double> &vect, int row, int col)
    { /*
         vector<vector<double>> vec(row, vector<double>(col, 0));
         for(int i = 0; i < row; i++){
             for (int j = 0; j < col; j++){
                 vec[i][j] = vect.at(i*row + j);
             }
         }

         this->matrix = vec;*/
    }

    Matrix::Matrix(const vector<vector<double>> &vect, int row, int col)
    { /*
         vector<vector<double>> vec((unsigned long)row, vector<double>((unsigned long)col, 0));
         for(int i = 0; i < row; i++){
             for (int j = 0; j < col; j++){
                 vec[i][j] = vect.at(i).at(j);
             }
         }

         this->matrix = vec;*/
    }

    Matrix::Matrix(const Matrix &mat)
    {
        /*
        const vector<vector<double>> &vect = mat.matrix;
        int row = mat.row;
        int col = mat.col;

        vector<vector<double>> vec((unsigned long)row, vector<double>((unsigned long)col, 0));
        for(unsigned long i = 0; i < row; i++){
            for (unsigned long j = 0; j < col; j++){
                vec[i][j] = vect.at(i).at(j);
            }
        }

        this->matrix = vec;*/
    }

    Matrix::~Matrix() {}

    Matrix &Matrix::operator+()
    {
        Matrix mat = Matrix(*this); // this is a deep copy
        return mat;
    }
    Matrix &Matrix::operator+(Matrix &mat) const
    {
    }

    Matrix &Matrix::operator+(double scalar) const {}

    Matrix &Matrix::operator+=(Matrix &mat) const {}

    Matrix &Matrix::operator+=(double scalar) const {}

    Matrix &Matrix::operator++() const {} // TODO: void?

    Matrix &Matrix::operator-() {}
    Matrix &Matrix::operator-(Matrix &mat) const {}
    Matrix &Matrix::operator-(double scalar) const {}
    Matrix &Matrix::operator-=(Matrix &mat) const {}
    Matrix &Matrix::operator-=(double scalar) const {}
    Matrix &Matrix::operator--() const {} // TODO: void?s

    Matrix &Matrix::operator*(Matrix &mat) const {}
    Matrix &Matrix::operator*(double scalar) const {}
    Matrix &Matrix::operator*=(Matrix &mat) const {}
    Matrix &Matrix::operator*=(double scalar) const
    {
    }

    bool Matrix::operator<(Matrix &mat) const
    {
        return true; // not implemented
    }
    bool Matrix::operator<=(Matrix &mat) const
    {
        return true; // not implemented
    }

    bool Matrix::operator==(Matrix &mat) const
    {
        return true; // not implemented
    }
    bool Matrix::operator!=(Matrix &mat) const
    {
        return true; // not implemented
    }

    bool Matrix::operator>(Matrix &mat) const
    {
        return true; // not implemented
    }
    bool Matrix::operator>=(Matrix &mat) const
    {
        return true; // not implemented
    }

    ostream &operator<<(ostream &out, const Matrix &mat)
    {
        return out;
    }

    void operator>>(istream &in, const Matrix &mat)
    {
    }

    Matrix &operator*(int num, const Matrix &mat)
    {
    }
    Matrix &operator*(double num, const Matrix &mat)
    {
    }

    // privates:

    Matrix &add_matrices(const Matrix &mat1, const Matrix &mat2)
    {
        Matrix *mat = new Matrix(mat1);
        if ()
        {
            throw invalid_argument{"row or column mismatch"};
        }
        //Matrix ans = Matrix(mat1.row, mat1.col);
    }

    Matrix &add_scalar(const Matrix &mat, double scalar)
    {
    }

}