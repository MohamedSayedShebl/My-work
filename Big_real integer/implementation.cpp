#include <bits/stdc++.h>
#include "Big.h"
using namespace std;

BigReal::BigReal(double Number) {
    num="0.0";
    real="0";
    decimal="0";
    sign='+';
}

BigReal::BigReal(char k, string z) {
    if (isValidReal(k, z)) {  // Check if the input is a valid BigReal number.
        num = z;
        sign = k;

        // Extract the 'real' and 'decimal' parts from 'num'.
        for (int i = 0; i < find(num.begin(), num.end(), '.') - num.begin(); ++i)
            real.push_back(num[i]);

        for (int i = find(num.begin(), num.end(), '.') - num.begin() + 1; i < num.size(); ++i)
            decimal.push_back(num[i]);

        // Check if the 'decimal' part is all zeros and erasing it if it is.
        bool allZero = true;
        for (int i = 0; i < decimal.size(); ++i) {
            if (decimal[i] != '0') {
                allZero = false;
                break;
            }
        }
        if (allZero)
            decimal.erase(0, decimal.size());

        // Remove trailing zeros in 'decimal' using reverse iteration.
        for (int i = decimal.size() - 1; i >= 0; --i) {
            if (decimal[i] == '0')
                decimal.pop_back();
            else if (decimal[i] != '0')
                break;
        }
    } else {
        // If the input is invalid, prompt the user for valid input.
        // Loop until valid input is provided.
        string Number;
        char k;

        cout<<"invalid Input\n";
        cout<<"please enter a valid BigReal number\n";

        cout<<"please enter the sign of the BigReal number:\n";
        cin>>k;

        cout<<"please enter the BigReal number:\n";
        cin>>Number;


        while (!isValidReal(k,Number)){

            cout<<"invalid Input\n";
            cout<<"please enter a valid BigReal number\n";

            cout<<"please enter the sign of the BigReal number:\n";
            cin>>k;

            cout<<"please enter the BigReal number:\n";
            cin>>Number;
        }

        num=Number;
        sign=k;

        for (int i = 0; i < find(num.begin(),num.end(),'.')-num.begin() ; ++i)
            real.push_back(num[i]);


        for (int i=find(num.begin(),num.end(),'.')-num.begin()+1; i<num.size() ; ++i)
            decimal.push_back(num[i]);



    }
}

bool BigReal::isValidReal(char k, string Number) {
    if (k != '+' && k != '-') {
        return false;  // Invalid sign.
    }

    for (int i = 0; i < Number.size(); ++i) {
        if ((Number[i] > '9' || Number[i] < '0') && Number[i] != '.') {
            return false;  // Invalid character in the number.
        }
    }

    if (count(Number.begin(), Number.end(), '.') > 1) {
        return false;  // More than one decimal point.
    }

    if (Number[Number.size() - 1] == '.') {
        return false;  // Decimal point at the end of the number.
    } else {
        string realPart;
        for (int i = 0; i < find(Number.begin(), Number.end(), '.') - Number.begin(); ++i)
            realPart.push_back(Number[i]);

        if (realPart.size() > 1 && count(Number.begin(), Number.end(), '.') == 0 && realPart[0] == '0') {
            return false;  // Leading zero in a non-floating point number.
        } else if (realPart.size() > 1 && count(Number.begin(), Number.end(), '.') == 1 && realPart[0] == '0') {
            return false;  // Leading zero in a floating point number.
        }
    }

    return true;  // Input is a valid BigReal number.
}

ostream &operator<<(ostream &out, const BigReal num) {
    if (num.sign == '-')
        out << '-' << num.num;  // Output with a negative sign.
    else
        out << num.num;  // Output without a negative sign.
    return out;
}

BigReal::BigReal(const BigReal &other) {
    // Copy constructor to create a copy of 'other BigReal number'.
    num = other.num;
    real = other.real;
    decimal = other.decimal;
    sign = other.sign;
}

void BigReal::setNum(char k, string Number) {
    if (isValidReal(k, Number)) {
        num = Number;
        sign = k;

        // Extract the 'real' and 'decimal' parts from 'num'.
        for (int i = 0; i < find(num.begin(), num.end(), '.') - num.begin(); ++i)
            real.push_back(num[i]);

        for (int i = find(num.begin(), num.end(), '.') - num.begin() + 1; i < num.size(); ++i)
            decimal.push_back(num[i]);
    } else {
        // If the input is invalid, prompt the user for valid input.
        // Loop until valid input is provided.
        string Number;
        char k;

        cout<<"invalid Input\n";
        cout<<"please enter a valid BigReal number\n";

        cout<<"please enter the sign of the BigReal number:\n";
        cin>>k;

        cout<<"please enter the BigReal number:\n";
        cin>>Number;


        while (!isValidReal(k,Number)){

            cout<<"invalid Input\n";
            cout<<"please enter a valid BigReal number\n";

            cout<<"please enter the sign of the BigReal number:\n";
            cin>>k;

            cout<<"please enter the BigReal number:\n";
            cin>>Number;
        }

        num=Number;
        sign=k;

        for (int i = 0; i < find(num.begin(),num.end(),'.')-num.begin() ; ++i)
            real.push_back(num[i]);


        for (int i=find(num.begin(),num.end(),'.')-num.begin()+1; i<num.size() ; ++i)
            decimal.push_back(num[i]);



    }
}


int BigReal::get_sign() {
    if (sign == '+')
        return 1;  // Return 1 for positive sign.
    return -1;     // Return -1 for negative sign.
}

BigReal BigReal::operator=(const BigReal &other){
    num = other.num;
    real = other.real;
    decimal = other.decimal;
    sign = other.sign;
// Return the object other.
    return other;
}

BigReal BigReal::operator+(const BigReal &other) {

    // Copy the real and decimal parts of the current and other BigReal numbers.
    string real1 = real;
    string real2 = other.real;
    int n;
    string decimal1 = decimal;
    string decimal2 = other.decimal;
    int y;

    // Perform a custom function 'fun' to prepare the real and decimal parts.
    fun(real1, real2, n, decimal1, decimal2, y);

    // Calculate the total number of digits required for addition and initialize remainder.
    int count = n + y + 1;
    int rem = 0;

    string num1;
    string num2;
    string add;

    // Check if both numbers have the same sign.
    if ((sign == '+' && other.sign == '+') || (sign == '-' && other.sign == '-'))
    {
        // Combine real and decimal parts into two strings with a decimal point.
        num1 = real1 + '.' + decimal1;
        num2 = real2 + '.' + decimal2;

        // Perform addition from the rightmost digit to the left.
        for (int i = count - 1; i >= 0; --i)
        {
            if (num1[i] == '.' && num2[i] == '.')
                add.push_back('.');
            else
            {
                int sum = (int(num1[i]) - 48) + (int(num2[i]) - 48) + rem;
                if (sum <= 9)
                {
                    add.push_back(char(48 + sum));
                    rem = 0;
                }
                else
                {
                    rem = 1;
                    string tem = to_string(sum);
                    add.push_back(tem[1]);
                }
            }
        }

        // Handle any remaining carry and format the result.
        if (rem == 1)
            add.push_back('1');
        reverse(add.begin(), add.end());
        if (add[add.size() - 1] == '.')
        {
            add.pop_back();
        }
        if (add[0] == '.')
        {
            add.insert(0, "0");
        }
        // Determine the sign of the result and return a new BigReal object.
        if (sign == '+' && other.sign == '+')
        {
            return BigReal('+', add);
        }
        else if (sign == '-' && other.sign == '-')
        {
            return BigReal('-', add);
        }
    }
    else if ((sign == '+' && other.sign == '-') || (sign == '-' && other.sign == '+'))
    {
        // Check the relative magnitude of the two numbers.
        if (BigReal('+', num) > BigReal('+', other.num))
        {
            num1 = real1 + '.' + decimal1;
            num2 = real2 + '.' + decimal2;
        }
        else if (BigReal('+', num) < BigReal('+', other.num))
        {
            num1 = real2 + '.' + decimal2;
            num2 = real1 + '.' + decimal1;
        }
        else
        {
            num1 = real1 + '.' + decimal1;
            num2 = real2 + '.' + decimal2;
        }

        // Perform subtraction from the rightmost digit to the left.
        for (int i = count - 1; i >= 0; --i)
        {
            if (num1[i] == '.' && num2[i] == '.')
            {
                add.push_back('.');
            }
            else
            {
                int dif = (int(num1[i]) - 48) - (int(num2[i]) - 48);

                if (dif >= 0)
                {
                    add.push_back(char(dif + 48));
                }
                else if (dif < 0)
                {
                    for (int j = i - 1; j >= 0; --j)
                    {
                        if (num1[j] != '0' && num1[j] != '.')
                        {
                            num1[j] = char(int(num1[j]) - 1);
                            break;
                        }
                        else if (num1[j] == '0')
                        {
                            num1[j] = '9';
                        }
                    }
                    string temp = "1";
                    temp.push_back(num1[i]);
                    dif = stoi(temp) - (int(num2[i]) - 48);
                    add.push_back(char(dif + 48));
                }
            }
        }

        // Handle any leading zeros, remove trailing decimal point, and format the result.
        reverse(add.begin(), add.end());
        if (add[add.size() - 1] == '.')
            add.pop_back();
        if (add.size() > 1 && add[1] != '.')
        {
            while (*add.begin() == '0' && add.size() > 1)
            {
                add.erase(0, 1);
            }
        }
        if (add[0] == '.')
            add.insert(0, "0");

        // Determine the sign of the result and return a new BigReal object.
        if (BigReal('+', num) > BigReal('+', other.num))
        {
            return BigReal(sign, add);
        }
        else if (BigReal('+', num) < BigReal('+', other.num))
        {
            return BigReal(other.sign, add);
        }
        else
        {
            return BigReal('+', add);
        }
    }
}

BigReal BigReal::operator-(const BigReal &other) {

    // Copy the real and decimal parts of the current and other BigReal numbers.
    string real1 = real;
    string real2 = other.real;
    int n;

    string decimal1 = decimal;
    string decimal2 = other.decimal;
    int y;

    // Perform a custom function 'fun' to prepare the real and decimal parts.
    fun(real1, real2, n, decimal1, decimal2, y);

    // Calculate the total number of digits required for subtraction.
    int count = n + y + 1;

    string num1;
    string num2;
    string subtract;

    // Check if both numbers have the same positive sign.
    if (sign == '+' && other.sign == '+')
    {
        // Determine the relative magnitude of the two numbers.
        if (BigReal(sign, num) > other)
        {
            num1 = real1 + '.' + decimal1;
            num2 = real2 + '.' + decimal2;
        }
        else if (BigReal(sign, num) < other)
        {
            num1 = real2 + '.' + decimal2;
            num2 = real1 + '.' + decimal1;
        }
        else
        {
            num1 = real1 + '.' + decimal1;
            num2 = real2 + '.' + decimal2;
        }

        // Perform subtraction from the rightmost digit to the left.
        for (int i = count - 1; i >= 0; --i)
        {
            if (num1[i] == '.' && num2[i] == '.')
            {
                subtract.push_back('.');
            }
            else
            {
                int dif = (int(num1[i]) - 48) - (int(num2[i]) - 48);
                if (dif >= 0)
                {
                    subtract.push_back(char(dif + 48));
                }
                else if (dif < 0)
                {
                    // Borrow from the next digit if necessary.
                    for (int j = i - 1; j >= 0; --j)
                    {
                        if (num1[j] != '0' && num1[j] != '.')
                        {
                            num1[j] = char(int(num1[j]) - 1);
                            break;
                        }
                        else if (num1[j] == '0')
                        {
                            num1[j] = '9';
                        }
                    }
                    string temp = "1";
                    temp.push_back(num1[i]);
                    dif = stoi(temp) - (int(num2[i]) - 48);
                    subtract.push_back(char(dif + 48));
                }
            }
        }

        // Reverse and format the result, considering leading zeros and trailing decimal point.
        reverse(subtract.begin(), subtract.end());
        if (subtract[subtract.size() - 1] == '.')
            subtract.pop_back();
        if (subtract[1] != '.')
        {
            while (*subtract.begin() == '0' && subtract.size() > 1)
            {
                subtract.erase(0, 1);
            }
        }
        if (subtract[0] == '.')
            subtract.insert(0, "0");
// Determine the sign of the result and return a new BigReal object.
        if (BigReal(sign, num) > other)
        {
            return BigReal('+', subtract);
        }
        else if (BigReal(sign, num) < other)
        {
            return BigReal('-', subtract);
        }
        else
        {
            return BigReal('+', subtract);
        }
    }

        // Check if both numbers have the same negative sign.
    else if (sign == '-' && other.sign == '-')
    {
        // Determine the relative magnitude of the two numbers.
        if (BigReal('+', num) > BigReal('+', other.num))
        {
            num1 = real1 + '.' + decimal1;
            num2 = real2 + '.' + decimal2;
        }
        else if (BigReal('+', num) < BigReal('+', other.num))
        {
            num1 = real2 + '.' + decimal2;
            num2 = real1 + '.' + decimal1;
        }
        else
        {
            num1 = real1 + '.' + decimal1;
            num2 = real2 + '.' + decimal2;
        }

        // Perform subtraction from the rightmost digit to the left.
        for (int i = count - 1; i >= 0; --i)
        {
            if (num1[i] == '.' && num2[i] == '.')
            {
                subtract.push_back('.');
            }
            else
            {
                int dif = (int(num1[i]) - 48) - (int(num2[i]) - 48);
                if (dif >= 0)
                {
                    subtract.push_back(char(dif + 48));
                }
                else if (dif < 0)
                {
                    // Borrow from the next digit if necessary.
                    for (int j = i - 1; j >= 0; --j)
                    {
                        if (num1[j] != '0' && num1[j] != '.')
                        {
                            num1[j] = char(int(num1[j]) - 1);
                            break;
                        }
                        else if (num1[j] == '0')
                        {
                            num1[j] = '9';
                        }
                    }
                    string temp = "1";
                    temp.push_back(num1[i]);
                    dif = stoi(temp) - (int(num2[i]) - 48);
                    subtract.push_back(char(dif + 48));
                }
            }
        }

// Reverse and format the result, considering leading zeros and trailing decimal point.
        reverse(subtract.begin(), subtract.end());
        if (subtract[subtract.size() - 1] == '.')
            subtract.pop_back();
        if (subtract[1] != '.')
        {
            while (*subtract.begin() == '0' && subtract.size() > 1)
            {
                subtract.erase(0, 1);
            }
        }
        if (subtract[0] == '.')
            subtract.insert(0, "0");

        // Determine the sign of the result and return a new BigReal object.
        if (BigReal('+', num) < BigReal('+', other.num))
        {
            return BigReal('+', subtract);
        }
        else if (BigReal('+', num) > BigReal('+', other.num))
        {
            return BigReal('-', subtract);
        }
        else
        {
            return BigReal('+', subtract);
        }
    }

        // Check if the first number is positive and the second number is negative.
    else if (sign == '+' && other.sign == '-')
    {
        int rem = 0;
        num1 = real1 + '.' + decimal1;
        num2 = real2 + '.' + decimal2;

        // Perform addition from the rightmost digit to the left.
        for (int i = count - 1; i >= 0; --i)
        {
            if (num1[i] == '.' && num2[i] == '.')
            {
                subtract.push_back('.');
            }
            else
            {
                int sum = (int(num1[i]) - 48) + (int(num2[i]) - 48) + rem;

                if (sum <= 9)
                {
                    subtract.push_back(char(48 + sum));
                    rem = 0;
                }
                else
                {
                    rem = 1;
                    string tem = to_string(sum);
                    subtract.push_back(tem[1]);
                }
            }
        }

        // Reverse and format the result, considering leading zeros and trailing decimal point.
        reverse(subtract.begin(), subtract.end());

        if (rem == 1)
        {
            subtract.push_back('1');
        }

        if (subtract[subtract.size() - 1] == '.')
        {
            subtract.pop_back();
        }

        if (subtract[0] == '.')
        {
            subtract.insert(0, "0");
        }

        // Return a new BigReal object with a positive sign, as the first number is larger.
        return BigReal('+', subtract);
    }

        // Check if the first number is negative and the second number is positive.
    else if (sign == '-' && other.sign == '+')
    {
        int rem = 0;
        num1 = real1 + '.' + decimal1;
        num2 = real2 + '.' + decimal2;

        // Perform addition from the rightmost digit to the left.
        for (int i = count - 1; i >= 0; --i)
        {
            if (num1[i] == '.' && num2[i] == '.')
            {
                subtract.push_back('.');
            }
            else
            {
                int sum = (int(num1[i]) - 48) + (int(num2[i]) - 48) + rem;

                if (sum <= 9)
                {
                    subtract.push_back(char(48 + sum));
                    rem = 0;
                }
                else
                {
                    rem = 1;
                    string tem = to_string(sum);
                    subtract.push_back(tem[1]);
                }
            }
        }

        // Reverse and format the result, considering leading zeros and trailing decimal point.
        reverse(subtract.begin(), subtract.end());

        if (rem == 1)
        {
            subtract.push_back('1');
        }

        if (subtract[subtract.size() - 1] == '.')
        {
            subtract.pop_back();
        }

        if (subtract[0] == '.')
        {
            subtract.insert(0, "0");
        }

        // Return a new BigReal object with a negative sign, as the second number is larger.
        return BigReal('-', subtract);
    }
}

bool BigReal::operator<(const BigReal &anotherReal) {
    // Check if the signs are different; positive number < negative number is false.
    if (sign == '+' && anotherReal.sign == '-')
        return false;

        // Check if the signs are different; negative number < positive number is true.
    else if (sign == '-' && anotherReal.sign == '+')
        return true;

    // Extract real and decimal parts and their sizes.
    string real1 = real;
    string real2 = anotherReal.real;
    int n;

    string decimal1 = decimal;
    string decimal2 = anotherReal.decimal;
    int y;

    // Perform a custom function 'fun' to prepare the real and decimal parts.
    fun(real1, real2, n, decimal1 , decimal2 , y);

    // Compare real parts based on sign.
    for (int i = 0; i < n; ++i) {
        if (real1[i] < real2[i] && (anotherReal.sign == '+' && sign == '+'))
            return true; // Current real is less than another real.

        else if (real1[i] > real2[i] && (anotherReal.sign == '+' && sign == '+'))
            return false; // Current real is greater than another real.

        else if (real1[i] < real2[i] && (anotherReal.sign == '-' && sign == '-'))
            return false; // Current real is greater than another real (negative numbers).

        else if (real1[i] > real2[i] && (anotherReal.sign == '-' && sign == '-'))
            return true; // Current real is less than another real (negative numbers).
    }

    // Compare decimal parts based on sign.
    for (int i = 0; i < y; ++i) {
        if (decimal1[i] > decimal2[i] && (anotherReal.sign == '+' && sign == '+'))
            return false; // Current real is greater than another real.

        else if (decimal1[i] < decimal2[i] && (anotherReal.sign == '+' && sign == '+'))
            return true; // Current real is less than another real.

        else if (decimal1[i] > decimal2[i] && (anotherReal.sign == '-' && sign == '-'))
            return true; // Current real is less than another real (negative numbers).

        else if (decimal1[i] < decimal2[i] && (anotherReal.sign == '-' && sign == '-'))
            return false; // Current real is greater than another real (negative numbers).
    }

    // If none of the above conditions match, return false.
    return false;
}

bool BigReal::operator>(const BigReal &anotherReal) {
    // Check if the signs are different; positive number > negative number is true.
    if (sign == '+' && anotherReal.sign == '-')
        return true;

        // Check if the signs are different; negative number > positive number is false.
    else if (sign == '-' && anotherReal.sign == '+')
        return false;

    // Extract real and decimal parts and their sizes.
    string real1 = real;
    string real2 = anotherReal.real;
    int n;

    string decimal1 = decimal;
    string decimal2 = anotherReal.decimal;
    int y;

    // Perform a custom function 'fun' to prepare the real and decimal parts.
    fun(real1, real2, n, decimal1 , decimal2 , y);

    // Compare real parts based on sign.
    for (int i = 0; i < n; ++i) {
        if (real1[i] > real2[i] && (anotherReal.sign == '+' && sign == '+'))
            return true; // Current real is greater than another real.

        else if (real1[i] < real2[i] && (anotherReal.sign == '+' && sign == '+'))
            return false; // Current real is less than another real.

        else if (real1[i] > real2[i] && (anotherReal.sign == '-' && sign == '-'))
            return false; // Current is less real than another real (negative numbers).

        else if (real1[i] < real2[i] && (anotherReal.sign == '-' && sign == '-'))
            return true; // Current real is greater than another real (negative numbers).
    }

    // Compare decimal parts based on sign.
    for (int i = 0; i < y; ++i) {
        if (decimal1[i] > decimal2[i] && (anotherReal.sign == '+' && sign == '+'))
            return true; // Current real is greater than another real.

        else if (decimal1[i] < decimal2[i] && (anotherReal.sign == '+' && sign == '+'))
            return false; // Current real is less than another real.

        else if (decimal1[i] > decimal2[i] && (anotherReal.sign == '-' && sign == '-'))
            return false; // Current real is less than another real (negative numbers).

        else if (decimal1[i] < decimal2[i] && (anotherReal.sign == '-' && sign == '-'))
            return true; // Current real is greater than another real (negative numbers).
    }

    // If none of the above conditions match, return false.
    return false;
}

bool BigReal::operator==(const BigReal &anotherReal) {
    // Check if signs are different; if they are, the numbers are not equal.
    if (sign != anotherReal.sign)
        return false;

    // Extract real and decimal parts and their sizes.
    string real1 = real;
    string real2 = anotherReal.real;
    int n;

    string decimal1 = decimal;
    string decimal2 = anotherReal.decimal;
    int y;

    // Perform a custom function 'fun' to prepare the real and decimal parts.
    fun(real1,real2, n, decimal1 , decimal2 ,y);

    // Compare real parts.
    for (int i = 0; i < n; ++i) {
        if (real1[i] != real2[i])
            return false; // Current real part is not equal to another's real part.
    }

    // Compare decimal parts.
    for (int i = 0; i < y; ++i) {
        if (decimal1[i] != decimal2[i])
            return false; // Current decimal part is not equal to another's decimal part.
    }

    // If none of the above conditions match, the numbers are equal.
    return true;
}
void fun(string &real1, string &real2, int &n, string &decimal1, string &decimal2, int &y) {
    // This custom function prepares the real and decimal parts for comparison or arithmetic operations.

    // Check and normalize the sizes of the real parts for comparison.
    if (real1.size() > real2.size()) {
        // If the first real part is longer, set the size 'n' to the length of the first real part.
        n = real1.size();

        // Calculate the difference in lengths.
        int z = real1.size() - real2.size();

        // Pad the second real part with leading '0's to make both real parts of the same size.
        while (z--)
            real2.insert(0, string(1, '0'));
    }
    else if (real1.size() < real2.size()) {
        // If the second real part is longer, set the size 'n' to the length of the second real part.
        n = real2.size();

        // Calculate the difference in lengths.
        int z = real2.size() - real1.size();

        // Pad the first real part with leading '0's to make both real parts of the same size.
        while (z--)
            real1.insert(0, string(1, '0'));
    }
    else {
        // If both real parts have the same size, set 'n' to that size.
        n = real1.size();
    }

    // Check and normalize the sizes of the decimal parts for comparison.
    if (decimal1.size() > decimal2.size()) {
        // If the first decimal part is longer, set the size 'y' to the length of the first decimal part.
        y = decimal1.size();

        // Calculate the difference in lengths.
        int z = decimal1.size() - decimal2.size();

        // Pad the second decimal part with '0's to make both decimal parts of the same size.
        while (z--)
            decimal2.push_back('0');
    }
    else if (decimal1.size() < decimal2.size()) {
        // If the second decimal part is longer, set the size 'y' to the length of the second decimal part.
        y = decimal2.size();

        // Calculate the difference in lengths.
        int z = decimal2.size() - decimal1.size();

        // Pad the first decimal part with '0's to make both decimal parts of the same size.
        while (z--)
            decimal1.push_back('0');
    }
    else {
        // If both decimal parts have the same size, set 'y' to that size.
        y = decimal1.size();
    }
}

