# Calculator
This calculator supports exponentials, nth roots, trigonometric and logarithmic functions.
## How to use
### 4 Operations
- Addination: +
- Subtraction: -
- Multiplication: *
- Division: /
- Modulo: %
### Exponentials
- Exponential: x^y
- Square Root: sqrt(x)
- Nth root: nthroot(n, x)
### Logarithm
- Log on a base 10: log10(x)
- Log on a base e (natural log): ln(x)
- Log on a specific base: log(base, x)
### Trigonometry
- Sine: sin(x)
- Cosine: cos(x)
- Tangent: tan(x)
- Cotangent: cot(x)
- Secant: sec(x)
- Cosecant: csc(x)
- Inverse sine: arcsin(x)
- Inverse cosine: arccos(x)
- Inverse tangent: arctan(x)
- Inverse cotangent: arccot(x)
- Inverse secant: arcsec(x)
- Inverse cosecant: arccsc(x)
### Constants
- Pi: pi (~3.141)
- E: e (~2.718)
- Golden Ratio: phi (~1.168)
## How It Works
First, the program takes your expression and clears the blanks. Then it takes the expression to `parse_expression`. In this section, the program takes again the expression to `parse_term`. Because multiplication, division, exponentiation comes before addination and subtraction. But in `parse_term` function, the program goes to `parse_factor` which solves trigonometric, logarithmic and root functions. After solving paranthesis and other functions, the program goes back to `parse_term` to handle multiplication, division etc. After this section, the program goes back to `parse_expression` and handles addination and subtraction. The final result will be showed on the screen. Here are a few examples:<br/>
### Example 1: `4 + 5 * (3 / sqrt(1)) / log10(100)`
- 1. Clearing the spaces: `4+5*(3/sqrt(1))/log10(100)`
- 2. Handling functions and paranthesis: `4+5*(3/1)/2` -> `4+5*3/2`
- 3. Handling multiplication, divison etc.: `4+5*1.5` -> `4+7.5`
- 4. Handling addination and subtraction: `11.5` (FINAL RESULT)
### Example 2: `4 + 2 * (sqrt(3) + 2) / ln(4)`
- 1. Clearing the spaces: `4+2*(sqrt(4)+2)/ln(e)`
- 2. Handling functions and paranthesis: `4+2*(2+2)/ln(e)` -> `4+2*4/ln(e)` -> `4+2*4/ln(2.71828182845904523536)` -> `4+2*4/1`
- 3. Handling multiplication, divison etc.: `4+8/1` -> `4+8`
- 4. Handling addination and subtraction: `12` (FINAL RESULT)
### Example 3: `5 * 4 + (log10(10) / 6^2) - sin(cos(pi))`
- 1. Clearing the spaces: `5*4+(log10(10)/6^2)-sin(cos(pi))`
- 2. Handling functions and paranthesis: `5*4+(1/6^2)-sin(cos(pi))` -> `5*4+(1/6^2)-sin(-1)` -> `5*4+(1/6^2)--0.841471` -> `5*4+(1/36)--0.841471` -> `5*4+0.027778--0.841471`
- 3. Handling multiplication, divison etc.: `20+0.027778--0.841471`
- 4. Handling addination and subtraction: `20.027778--0.841471` -> `20.869249` (FINAL RESULT)
