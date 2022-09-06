function wasTrueOrFalse(inputVar)
{
    if (inputVar) // Checks the condition given in paranthesis
    {
        return "It is True." ; // Runs this if the condition is true
    }

    return "It is False." ; // Runs this if condition is false
}

var v = 12 ;
console.log(wasTrueOrFalse(v == 12)) ; 

/*
    The '==' symbol is the equality comparison operator
    There is a strict equality operator also '==='
    Difference :-
    "===" does not convert to a single type and compare but "==" does
    var v = 3
    v == 3     ----   true
    v == '3'   ----   true
    v === '3'  ----   false 
*/