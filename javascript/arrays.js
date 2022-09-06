// Arrays can be used to store multiple data 
var myArray = [1,2,3,"four"] ;

// They are mutable
myArray[0] = "one" ;
console.log(myArray) ;

// Nested Arrays
var nestedArray = [1,2,3,[4,5,6],7] ;
console.log(nestedArray[3][1]) ; // equals 5

// Append to Arrays
myArray.push(5) ;
console.log(myArray) ;

// Remove last item from Array
var removedItem = myArray.pop() ;
console.log(removedItem) ;

// Remove first item
var removedFirstItem = myArray.shift() ;
console.log(removedFirstItem) ; 

// Add item to beginning
myArray.unshift(1) ;

// Convert Array to String
console.log(JSON.stringify(myArray)) ;