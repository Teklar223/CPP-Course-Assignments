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

        // these are implemented here since they are classic setters/getters and there shouldn't normally be any reason to overload them.

        const vector<vector<double>>& get_matrix() const
        {
            return this->matrix;
        }
        void set_matrix(const vector<vector<double>> &mat)
        {
            (this->matrix) = mat;
        }
        int get_row() const
        {
            return row;
        }
        void set_row(int num)
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

        // 'Helpers'

        double get_element_at(unsigned int row, unsigned int column) const;
        void check_dimensions(const Matrix &mat) const;
        void check_multiplication_dimensions(const Matrix &mat) const; // different rules when multiplying two matrices
        Matrix &add_matrix(const Matrix &mat) const;
        Matrix &add_scalar(const double &scalar) const;
        Matrix &multiply_matrix(const Matrix &mat) const;
        Matrix &multiply_scalar(const double &scalar) const;
        string to_string() const;

        // Matrix & operator () (); // flexible method() decleration example
        Matrix &operator=(const Matrix &mat);

        Matrix &operator+();
        Matrix &operator+(const Matrix &mat) const;
        Matrix &operator+(const double &scalar) const;
        Matrix &operator+=(const Matrix &mat);
        Matrix &operator+=(const double &scalar);
        Matrix &operator++(int a); // a++
        Matrix &operator++();      // ++a

        Matrix &operator-();
        Matrix &operator-(const Matrix &mat) const;
        Matrix &operator-(const double &scalar) const;
        Matrix &operator-=(const Matrix &mat);
        Matrix &operator-=(const double &scalar);
        Matrix &operator--(int a); // a--
        Matrix &operator--();      //--a

        Matrix &operator*(const Matrix &mat) const;
        Matrix &operator*(const double &scalar) const;
        Matrix &operator*=(const Matrix &mat);
        Matrix &operator*=(const double &scalar);

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
        //friend Matrix &operator*(int num, const Matrix &mat);
        friend Matrix &operator*(double num, const Matrix &mat);
        friend Matrix &operator+(int num, const Matrix &mat);
    };
}

#endif