var myFirstString = "Hello" ;

// What if we want to use double quotes inside a string ?

/*
var doubleString = "Hi "Nischay"" ;
JS goes mad if you do this
*/

// Instead use the Escape Character '\'
// By using this the quotation inside string gets escaped
var doubleString = "Hi \"Nischay\"" ;
console.log(doubleString) ;

// We can also use backticks or single quotes for a string
var newString = 'Hi "Nischay"' ;
newString = `Hi "Nischay" 'Arora'` ;

// Concatenating Strings
var string1 = "Hi" + " Bro" ;
string1 += ", How are you ?" ;
console.log(string1) ;
