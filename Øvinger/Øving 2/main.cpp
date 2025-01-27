//handout oving 2

#include "std_lib_facilities.h"
#include "AnimationWindow.h"


void inputAndPrintInteger() {
    // BEGIN: 1b
    int input;
    cout << "Skriv inn et tall: ";
    cin >> input;
    cout << "Du skrev: " << input << endl;
    // END: 1b
}

int inputInteger() {
    // BEGIN: 1c
    int input;
    cout << "Skriv inn et tall: ";
    cin >> input;
    return input;
    // END: 1c
}

void printSumOfInputIntegers() {
    // BEGIN: 1d
    int n_1;
    n_1 = inputInteger();
    int n_2;
    n_2 = inputInteger();
    cout << "Summen av tallene: " << n_1+n_2 << endl;
    // END: 1d
}

bool isOdd(int n) {
    // BEGIN: 1f
    if (n % 2){
        return 1;
    }
    return 0;
    // END: 1f
}

void inputIntegersAndPrintSum() {
    // BEGIN: 2a
    int number_of_int;
    int sum = 0;
    cout << "Hvor mange tall? ";
    cin >> number_of_int;
    for(int i = 0; i < number_of_int; i++)
    {
        int Integer = 0;
        cout << "Skriv inn et tall: ";
        cin >> Integer;
        sum = sum + Integer;
    }
    cout << "Summen av tallene er: " << sum << endl;
    // END: 2a
}

void inputIntegersAndPrintSumUntilStopped() {
    // BEGIN: 2b
    int input = 1;
    int sum = 0;
    while(input){
        cout << "Skriv inn et tall: ";
        cin >> input;
        sum += input;
    }
    cout << "Summen av tallene er " << sum << endl;
    // END: 2b
}

double inputDouble() {
    // BEGIN: 2d
    double input;
    cout << "Skriv inn et desimaltall: ";
    cin >> input;
    return input;
    // END: 2d
}

void convertNOKtoEUR() {
    // BEGIN: 2e
    double nok = 0; 
    while (nok <= 0){
        nok = inputDouble();
    }
    double eur = 10.50;
    cout << fixed << showpoint;
    cout << setprecision(2) << nok << "kr er lik "<< setprecision(2) << nok / eur << " euro." << endl;
    // END: 2e
}

void printMultiplicationTable() {
    // BEGIN: 2g
    int height;
    int width; 
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;
    for (int h = 1; h <= height; h++){
        for (int w = 1; w <= width; w ++){
            cout << left << setw(4) << w*h;
        }
        cout << endl;
    }
    // END: 2g
}

double discriminant(double a, double b, double c) {
    // BEGIN: 3a
    double value;
    double B;
    B = pow(b,2);
    value = B-(4*a*c);
    return value;
    // END: 3a
}

void printRealRoots(double a, double b, double c) {
    // BEGIN: 3b
    double root;
    double value;
    double discriminant_value;
    discriminant_value = discriminant(a,b,c);
    root = sqrt(discriminant_value)/(2*a);
    value = -b/(2*a);
    if (discriminant_value > 0){
        cout << "Løsning 1: " << value + root << endl;
        cout << "Løsning 2: " << value - root << endl;
    }
    else if (discriminant_value == 0){
        cout << "Løsningen er: " << value << endl;
    }
    else {
        cout << "Ingen løsninger." << endl;
    }

    // END: 3b
}

void solveQuadraticEquations() {
    // BEGIN: 3c
    double a = 0;
    double b = 0;
    double c = 0;
    cout << "Skriv inn a: ";
    cin >> a;
    cout << "Skriv inn b: ";
    cin >> b;
    cout << "Skriv inn c: ";
    cin >> c;
    printRealRoots(a,b,c);
    // END: 3c
}

void pythagoras() {
    // BEGIN: 4a
    // Alle deloppgaver i 4 skal løses her
    int w = 1000;
    int h = 800;
    TDT4102::AnimationWindow win{100,100, w, h, "Pythagoras"};

    Point point1{400,300};
    Point point2{500,400};
    Point point3{400,400};
    win.draw_triangle(point1,point2,point3, Color::green);
    win.draw_quad(Point{400, 300}, Point{500,200}, Point{600, 300}, Point{500, 400}, Color::red);
    win.draw_quad(Point{400, 400}, Point{500, 400}, Point{500, 500}, Point{400, 500}, Color::blue);
    win.draw_quad(Point{300, 300}, Point{400, 300}, Point{400, 400}, Point{300, 400}, Color::orange);
    

    win.wait_for_close();
    // END: 4a
}

vector<int> calculateBalance(int amount, int rate, int years) {
    // BEGIN: 5a
    double rente;
    vector<int> s(years+1);
    s.at(0) = amount;
    for (int i=1; i<=years+1; i++){
        rente = pow(1+static_cast<double>(rate)/100,i);
        s.at(i) = s.at(i-1) * rente;
    }
    cout << "calculate balance ok" << endl;
    return s;
    // END: 5a
}

void printBalance(vector<int> balanceVec) {
    // BEGIN: 5b
    cout << left << setw(10) << "År" << "Saldo" << endl;
    for (int i = 0; i < balanceVec.size(); i++){
        cout << left << setw(10) << i << balanceVec.at(i) << endl;
    }
    // END: 5b
}

int main() {
    // Oppgave 1a
    // BEGIN: 1a
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= v.size(); i++) {
        cout << v.at(i) << endl;
    }
        int input;
        cout << "Hvilken funksjon vil du teste?\n"
        << "inputAndPrintInteger 1)\n"
        << "inputInteger 2) \n"
        << "printSumOfInputIntegers 3) \n"
        << "isOdd 4) \n"
        << "inputIntegersAndPrintSum 5) \n"
        << "inputIntegersAndPrintSumUntilStopped 6) \n"
        << "inputDouble 7) \n"
        << "convertNOKtoEUR 8) \n"
        << "printMultiplicationTable 9) \n"
        << "discriminant 10) \n"
        << "printRealRoots 11) \n"
        << "solveQuadraticEquations 12) \n"
        << "pythagoras 13) \n"
        << "calculateBalance 14) \n"
        << "printBalance 15) \n" << endl;
        std::cin >> input;

        switch (input)
        {
        case 1:
            inputAndPrintInteger();
            break;
        case 2:
            int number;
            number =  inputInteger();
            cout << "Du skrev: " << number;
            break;
        case 3:
            printSumOfInputIntegers();
            break;
        case 4:
            for(int i=0; i < 16; i++){
                cout << "Is odd? " << i << " " << (isOdd(i) ? "true": "false") << endl;
            }
            break;
        case 5:
            inputIntegersAndPrintSum();
            break;
        case 6:
            inputIntegersAndPrintSumUntilStopped();
            break;
        case 7:
            double desimaltall;
            desimaltall = inputDouble();
            cout << "Du skrev: " << desimaltall;
            break;
        case 8:
            convertNOKtoEUR();
            break;
        case 9:
            printMultiplicationTable();
            break;
        case 10:
            cout << discriminant(2.2,5.5,1.4);
            break;
        case 11:
            printRealRoots(2.2,5.5,1.4);
            break;
        case 12:
            solveQuadraticEquations();
            break;
        case 13:
            pythagoras();
            break;
        case 14:
            calculateBalance(5000, 3, 10);
            break;
        case 15:
            printBalance(calculateBalance(5000, 3, 10));
            break;
        }
    
    // END: 1a
    // Her kan du teste funksjonene dine ved hjelp av menysystem som beskrevet. 
    // NB: Denne delen av koden blir IKKE automatisk rettet.
    return 0;
}
