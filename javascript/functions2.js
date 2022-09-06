// Local scope is given precedence over Global scope

var v = 1 ; // Global var
function f1() 
{
    v = 2 ; // Local var
    return v ;
}

console.log(v) ; // Prints 1
console.log(f1()) ; // Prints 2

// If we don't specify the return value of a function it is undefined
// We can assign a var to a return value of a function
var returnVar = f1() ; 

