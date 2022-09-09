// Random Decimal
var randomDecimal = Math.random();
console.log(randomDecimal);

// Random Integer
var randomNumBetween0and9 = Math.floor(Math.random() * 10);
console.log(randomNumBetween0and9);

// Random Integer withing range
function integerWithinRange(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}
console.log(integerWithinRange(5, 20));

// Convert string to integer
function strToInt(str) {
    return parseInt(str);
}
console.log(strToInt("56"));
console.log(strToInt("Hello")); // Prints NaN (Not a Number)

// Using parseInt with radix
var binToInt = parseInt("10011", 2); // Default is base 10
console.log(binToInt);
