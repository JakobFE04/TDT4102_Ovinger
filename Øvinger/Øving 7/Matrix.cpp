#include "Matrix.h"

// BEGIN: 2b
Matrix::Matrix(int nRows, int nColumns){
    rows = nRows;
    columns = nColumns;
    matrix = new double[nRows * nColumns];
    for (int i=0; i < rows; i++){
        for (int j=0; j < columns; j++){
            matrix[i*columns+j] = 0;
        }
    }
}
// END: 2b
Matrix::Matrix(int nRows) : Matrix::Matrix(nRows,nRows){
    for (int i=0; i < nRows; i++){
        matrix[(i*columns+i)] = 1;
    }
}
Matrix::~Matrix(){
    delete matrix;
    matrix = nullptr;
}
// BEGIN: 2c
double Matrix::get(int row, int col) const{
    //std::cout<<row<<","<<col<<std::endl;
    return matrix[(row*columns+col)];
}
void Matrix::set(int row, int col, double value){
    matrix[row*columns+col] = value;
}
// END: 2c

// Her kan du gjøre 2d (frivillig):

// BEGIN: 2e
int Matrix::getRows() const{
    return rows;
}
int Matrix::getColumns() const{
    return columns;
}
// END: 2e


// BEGIN: 2f
std::ostream& operator<<(std::ostream& os, const Matrix& rhs){
    for (int i = 0; i < rhs.getRows(); i++){
        os << "|";
        for (int j = 0; j < rhs.getColumns(); j ++){
            os << rhs.get(i,j) << ",";
        }
        os << "|" << std::endl;
    }
    return os;
}
// END: 2f


// BEGIN: 4a
Matrix::Matrix(const Matrix& rhs) : Matrix(rhs.getRows(), rhs.getColumns()){
    for (int i=0; i < rows; i++){
        for (int j=0; j < columns; j++){
            this->set(i, j, rhs.get(i,j));
        }
    }
}
// END: 4a

// BEGIN: 4b
Matrix& Matrix::operator=(const Matrix& rhs){
    rows = rhs.getRows();
    columns = rhs.getColumns();
    matrix = new double[rows * columns];
    //std::cout<<"=op"<<std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            //std::cout<<i<<","<<j<<std::endl;
            matrix[(j + i * columns)] = rhs.get(i, j);
        }
    }
    return *this;
}

// END: 4b


// BEGIN: 5a
Matrix& Matrix::operator+=(const Matrix& rhs){
    //std::cout<<"+=op"<<std::endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j ++){
            //std::cout<<i<<","<<j<<std::endl;
            this->set(i, j, (get(i,j)+rhs.get(i, j)));
            //std::cout << this->get(i,j);
        }
    }
    return *this;
}
// END: 5a

// BEGIN: 5b
Matrix& Matrix::operator+(const Matrix &rhs){
    *this += rhs;
    return *this;
}
// END: 5b


void testMatrix() {
    Matrix A{2,2};
    A.set(0,0,1.0);
    A.set(0,1,2.0);
    A.set(1,0,3.0);
    A.set(1,1,4.0);

    Matrix B{2,2};
    B.set(0,0,4.0);
    B.set(0,1,3.0);
    B.set(1,0,2.0);
    B.set(1,1,1.0);

    Matrix C{2,2};
    C.set(0,0,1.0);
    C.set(0,1,3.0);
    C.set(1,0,1.5);
    C.set(1,1,2.0);


    //std::cout << C.getRows() << std::endl;
    // std::cout << C.getColumns() << std::endl;
    // std::cout <<A;
    // std::cout <<B;
    // std::cout <<C;
    A += B + C;
    std::cout << A << std::endl;
    //std::cout << A << std::endl;
    //std::cout << "Poop" << std::endl;
}

// Her kan du gjøre 5d (frivillig):