#ifndef A2_TASK2__S19_S20__20220290__20220017___20220499_BIG_H
#define A2_TASK2__S19_S20__20220290__20220017___20220499_BIG_H


using namespace std;



class BigReal final{

private:
    string num;
    string real;
    string decimal;
    char sign;


    bool isValidReal(char k,string Number);

public:

    explicit BigReal (double Number = 0.0);

    BigReal(char k ,string Number);

    BigReal(const BigReal& other);

    void setNum(char k,string Number);

    int get_sign();

    BigReal operator= (const BigReal &other);

    BigReal operator+ (const BigReal &other);

   BigReal operator- (const BigReal &other);

   bool operator <(const BigReal &anotherReal);

   bool operator >(const BigReal &anotherReal);

   bool operator ==(const BigReal &anotherReal);

   friend ostream & operator <<(ostream  &out,const BigReal x);



};

ostream &operator<<(ostream &out, BigReal num);

void fun(string &real1,string &real2,int &n ,string &decimal1,string &decimal2,int &y);



#endif //A2_TASK2__S19_S20__20220290__20220017___20220499_BIG_H
