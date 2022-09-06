// Create a function 
function f1()
{
    console.log("This is a function !") ;
}

// Calling the function 
f1() ;

// We can also pass parameters in a function
function functionWithArgs(a,b) 
{ 
    console.log(a + b) ;
}

functionWithArgs(1,2) ;

// Global Scope
var globalVar = 5 ; // This var is scoped everywhere in this code

function f2()
{
    globalVar2 = 8 ; // Since we did not use var this is automatically a global var
    var Var3 = 9 ; // This var is scoped only to the function and cannot be accessed outside this   
}

f2() ;
console.log(globalVar2) ;
// Var3 is locally scoped to f2 