// We can use ternary operator instead of if-else statements
// condition ? if-true-statement : else-statement ;

function checkEquality(a, b) {
    return a === b ? "Equal" : "Not Equal";
}
console.log(checkEquality(1, 2));

// Nested Ternary
function checkSign(num) {
    return num > 0 ? "Positive" : num < 0 ? "Negative" : "Zero";
}
console.log(checkSign(0));
