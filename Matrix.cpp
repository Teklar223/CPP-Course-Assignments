#include "Matrix.hpp"
using namespace zich;
using zich::Matrix;

namespace zich
{
    Matrix::Matrix() // emty constructor fills all with 0
    {
        vector<vector<double>> vec(0, vector<double>(0, 0));
        this->matrix = vec;
        this->row = 0;
        this->col = 0;
    }

    Matrix::Matrix(int row, int col) // emty constructor fills all with 0
    {
        // https://stackoverflow.com/questions/65311502/how-to-initialize-vector-of-a-vector-with-custom-values
        vector<vector<double>> vec((unsigned long)row, vector<double>((unsigned long)col, 0));
        this->matrix = vec;
        this->row = row;
        this->col = col;
    }

    Matrix::Matrix(const vector<double> &vect, int row, int col)
    {
        vector<vector<double>> vec((unsigned long)row, vector<double>((unsigned long)col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                vec[(unsigned long)i][(unsigned long)j] = vect.at((unsigned long)(i * row + j));
            }
        }

        this->matrix = vec;
        this->row = row;
        this->col = col;
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

    Matrix::~Matrix()
    {
        // not implemented
    }

    Matrix &Matrix::operator+()
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }
    Matrix &Matrix::operator+(Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            printf("row-%d,col-%d,matrow-%d,matcol-%d", this->get_row(), this->get_col(), mat.get_row(), mat.get_col());
            throw invalid_argument{"row: " + to_string(this->get_row()) + "col: " + to_string(this->get_col()) + "matrow: " + to_string(mat.get_row()) + "matcol: " + to_string(mat.get_col())};
        }
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator+(double scalar) const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator+=(Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator+=(double scalar) const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator++() const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    } // TODO: void?

    Matrix &Matrix::operator-()
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator-(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator-(double scalar) const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator-=(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator-=(const double scalar) const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator--() const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    } // TODO: void?s

    Matrix &Matrix::operator*(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator*(double scalar) const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator*=(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator*=(double scalar) const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    bool Matrix::operator<(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        return true; // not implemented
    }
    bool Matrix::operator<=(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        return true; // not implemented
    }

    bool Matrix::operator==(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        return true; // not implemented
    }
    bool Matrix::operator!=(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        return true; // not implemented
    }

    bool Matrix::operator>(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
        return true; // not implemented
    }
    bool Matrix::operator>=(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }

        return true; // not implemented
    }

    ostream &operator<<(ostream &out, const Matrix &mat)
    {
        return out; // not implemented
    }

    void operator>>(istream &in, const Matrix &mat)
    {
    }

    Matrix &operator*(int num, const Matrix &mat)
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }
    Matrix &operator*(double num, const Matrix &mat)
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &operator+(int num, const Matrix &mat)
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    // privates:

    /*
    Matrix &add_matrices(const Matrix &mat1, const Matrix &mat2)
    {

    }

    Matrix &add_scalar(const Matrix &mat, double scalar)
    {

    }
    */
}