// Length of a string
var lengthStr = 0 ;
str = "Nischay" ;
lengthStr = str.length ;
console.log(lengthStr) ;

// Parts of a string
var firstLetter = str[0] ; // Zero base Indexing 
console.log(firstLetter) ;

// Immutability of Strings
str[0] = "H" ; // This will not change the string
console.log(str) ;
