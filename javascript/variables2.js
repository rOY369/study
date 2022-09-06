/*
    Difference between var and let
        - cannot redeclare variables using let
        - can reinitialize, redeclare using var
        - can reinitialize without using var or let

        - inside function, var or let will make a locally scoped variable
        - without using var or let it is a global scoped variable
        - var puts variables in function scope
        - let puts variables in block scope

*/

var x = 0 ;
var x = 1 ;

y = 0 ;
y = 1 ;

let z = 0 ;
z = "Hi" ;

console.log(x,y,z) ;

function f() 
{
    a = 1 ;
    console.log(z) ;
}

f() ;
console.log(a) ;

function f2()
{
    for (var i = 0 ; i <= 4 ; i++) // Function Scope 
    {
        console.log(i) ;
    }
    
    console.log(i) ;

    for (let j = 0 ; j <= 4 ; j++) // Block Scope
    {
        console.log(j) ;
    }

    console.log(j) ;

}

f2() ;
