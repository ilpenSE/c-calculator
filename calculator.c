#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LENGTH 256
#define PI 3.14159265358979323846 // Pi number
#define E  2.71828182845904523536 // Euler number
#define PHI 1.61803398875 // Golden ratio

// Function prototypes
double parse_expression(const char** expr);
double parse_term(const char** expr);
double parse_factor(const char** expr);
double parse_number(const char** expr);
double log_base(double value, double base);
double nth_root(double value, double n);
double log_naturalis(double value);

// Starts with function
int starts_with(const char* pre, const char* str) {
    return strncmp(pre, str, strlen(pre)) == 0;
}

// Expression evaluator
double evaluate_expression(const char* expression) {
    char cleaned_expr[MAX_EXPR_LENGTH];
    int j = 0;

    // Create an array with clearing spaces
    for (int i = 0; expression[i] != '\0'; i++) {
        if (!isspace(expression[i])) {
            cleaned_expr[j++] = expression[i];
        }
    }
    cleaned_expr[j] = '\0'; // Null terminator

    const char* expr = cleaned_expr;
    return parse_expression(&expr);
}

// Expression solvers
double parse_expression(const char** expr) {
    double result = parse_term(expr);
    while (**expr == '+' || **expr == '-') {
        char op = *(*expr)++;
        double term = parse_term(expr);
        if (op == '+') result += term;
        else if (op == '-') result -= term;
    }
    return result;
}

double parse_term(const char** expr) {
    double result = parse_factor(expr);
    while (**expr == '*' || **expr == '/' || **expr == '%' || **expr == '^') {
        char op = *(*expr)++;
        double factor = parse_factor(expr);
        if (op == '*') result *= factor;
        else if (op == '/') result /= factor;
        else if (op == '%') result = fmod(result, factor);
        else if (op == '^') result = pow(result, factor);
    }
    return result;
}

double parse_factor(const char** expr) {
    if (**expr == '(') {
        (*expr)++;
        double result = parse_expression(expr);
        if (**expr == ')') (*expr)++;
        return result;
    }

    // Trigonometric functions
    if (starts_with("sin", *expr)) {
        *expr += 3;
        return sin(parse_factor(expr));
    }
    if (starts_with("cos", *expr)) {
        *expr += 3;
        return cos(parse_factor(expr));
    }
    if (starts_with("tan", *expr)) {
        *expr += 3;
        return tan(parse_factor(expr));
    }
    if (starts_with("cot", *expr)) {
        *expr += 3;
        return 1 / tan(parse_factor(expr));
    }
    if (starts_with("sec", *expr)) {
        *expr += 3;
        return 1 / cos(parse_factor(expr));
    }
    if (starts_with("csc", *expr)) {
        *expr += 3;
        return 1 / sin(parse_factor(expr));
    }

    // Inverse trigonometric functions
    if (starts_with("arcsin", *expr)) {
        *expr += 6;
        return asin(parse_factor(expr));
    }
    if (starts_with("arccos", *expr)) {
        *expr += 6;
        return acos(parse_factor(expr));
    }
    if (starts_with("arctan", *expr)) {
        *expr += 6;
        return atan(parse_factor(expr));
    }
    if (starts_with("arccot", *expr)) {
        *expr += 6;
        return atan(1 / parse_factor(expr));
    }
    if (starts_with("arcsec", *expr)) {
        *expr += 6;
        return acos(1 / parse_factor(expr));
    }
    if (starts_with("arccsc", *expr)) {
        *expr += 6;
        return asin(1 / parse_factor(expr));
    }


    // Logarithms
    if (starts_with("log10", *expr)) {
        *expr += 5;
        return log10(parse_factor(expr));
    }
    if (starts_with("log", *expr)) {
        *expr += 3;
        double value = parse_expression(expr);
        if (**expr == ',') (*expr)++;
        double base = parse_expression(expr);
        if (**expr == ')') (*expr)++;
        return log_base(value, base);
    }
    if (starts_with("ln", *expr)) {
        *expr += 2;
        return log_naturalis(parse_factor(expr));
    }

    // Roots
    if (starts_with("nthroot", *expr)) {
        *expr += 7;
        double n = parse_expression(expr);
        if (**expr == ',') (*expr)++;
        double value = parse_expression(expr);
        if (**expr == ')') (*expr)++;
        return nth_root(value, n);
    }
    if (starts_with("sqrt", *expr)) {
        *expr += 4;
        return sqrt(parse_factor(expr));
    }

    // Constants
    if (starts_with("pi", *expr)) {
        *expr += 2;
        return PI;
    }
    if (starts_with("e", *expr)) {
        *expr += 1;
        return E;
    }
    if (starts_with("phi", *expr)) {
        *expr += 3;
        return PHI;
    }
    return parse_number(expr);
}

double parse_number(const char** expr) {
    while (isspace(**expr)) (*expr)++;
    char* end;
    double result = strtod(*expr, &end);
    *expr = end;
    return result;
}

// Logarithm on specified base
double log_base(double base, double value) {
    return log(value) / log(base);
}

// Logarithmus naturalis
double log_naturalis(double value) {
    return log_base(value, E);
}

// Nth root
double nth_root(double value, double n) {
    return pow(value, 1.0 / n);
}

int main() {
    char expression[MAX_EXPR_LENGTH];
    printf("Type any expression: ");
    fgets(expression, MAX_EXPR_LENGTH, stdin);

    double result = evaluate_expression(expression);
    printf("Result: %f\n", result);

    system("pause");
    return 0;
}