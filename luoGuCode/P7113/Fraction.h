#ifndef gcd
int gcd(int x,int y)    {
    if(x % y==0)
        return y;
    return gcd(y,x%y);
}
#endif

class Fraction  {
private:
    int denominator;
    int numerator;
    
public:
    int getdeno()   {return denominator;}
    int getnumer()  {return numerator;}
    void simplify() {
        int ngcd = gcd(denominator,numerator);
        denominator = denominator/ngcd;
        numerator = numerator/ngcd;
    }
    Fraction operator+(const  Fraction& b)  {
        Fraction fra;
        fra.denominator = this->denominator * b.denominator;
        fra.numerator = \
        this->numerator * b.denominator + \
        b.numerator * this->denominator;
        return fra;
    }
    
    Fraction operator=(const Fraction& b)   {
        this->denominator = b.denominator;
        this->numerator = b.numerator;
        return *this;
    } 
    void AddFra(int x,int y)
    {
        this->numerator = x;
        this->denominator = y;
    }
};